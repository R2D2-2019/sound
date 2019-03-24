#include "df_player.hpp"

namespace r2d2::sound {
    /*
    void df_player_c::set_time_out(unsigned long time_out_duration) {
        _time_out_duration = time_out_duration;
    }

    void df_player_c::uint16_to_array(uint16_t value, uint8_t *array) {
        *array = (uint8_t)(value >> 8);
        *(array + 1) = (uint8_t)(value);
    }

    uint16_t df_player_c::calculate_check_sum(uint8_t *buffer) {
        uint16_t sum = 0;
        for (int i = Stack_Version; i < Stack_CheckSum; i++) {
            sum += buffer[i];
        }
        return -sum;
    }

    void df_player_c::send_stack() {
        if (_sending[Stack_ACK]) { // if the ack mode is on wait until the last
                                   // transmition
            while (_is_sending) {
                delay(0);
                available();
            }
        }

#ifdef _DEBUG
        Serial.println();
        Serial.print(F("sending:"));
        for (int i = 0; i < DFPLAYER_SEND_LENGTH; i++) {
            Serial.print(_sending[i], HEX);
            Serial.print(F(" "));
        }
        Serial.println();
#endif
        _serial->write(_sending, DFPLAYER_SEND_LENGTH);
        _time_out_timer = millis();
        _is_sending = _sending[Stack_ACK];

        if (!_sending[Stack_ACK]) { // if the ack mode is off wait 10 ms after
            one
                // transmition.
                delay(10);
        }
    }

    void df_player_c::send_stack(uint8_t command) {
        send_stack(command, 0);
    }

    void df_player_c::send_stack(uint8_t command, uint16_t argument) {
        _sending[Stack_Command] = command;
        uint16_to_array(argument, _sending + Stack_Parameter);
        uint16_to_array(calculate_check_sum(_sending),
                        _sending + Stack_CheckSum);
        send_stack();
    }

    void df_player_c::send_stack(uint8_t command, uint8_t argumentHigh,
                                 uint8_t argumentLow) {
        uint16_t buffer = argumentHigh;
        buffer <<= 8;
        send_stack(command, buffer | argumentLow);
    }

    void df_player_c::enable_ack() {
        _sending[Stack_ACK] = 0x01;
    }

    void df_player_c::disable_ack() {
        _sending[Stack_ACK] = 0x00;
    }

    bool df_player_c::wait_available(unsigned long duration) {
        unsigned long timer = millis();
        if (!duration) {
            duration = _time_out_duration;
        }
        while (!available()) {
            if (millis() - timer > duration) {
                return false;
            }
            delay(0);
        }
        return true;
    }

    bool df_player_c::begin(Stream &stream, bool isACK, bool doReset) {
        _serial = &stream;

        if (isACK) {
            enable_ack();
        } else {
            disable_ack();
        }

        if (doReset) {
            reset();
            wait_available(2000);
            delay(200);
        } else {
            // assume same state as with reset(): online
            _handle_type = DFPlayerCardOnline;
        }

        return (read_type() == DFPlayerCardOnline) ||
               (read_type() == DFPlayerUSBOnline) || !isACK;
    }

    uint8_t df_player_c::read_type() {
        _is_available = false;
        return _handle_type;
    }

    uint16_t df_player_c::read() {
        _is_available = false;
        return _handle_parameter;
    }

    bool df_player_c::handle_message(uint8_t type, uint16_t parameter) {
        _received_index = 0;
        _handle_type = type;
        _handle_parameter = parameter;
        _is_available = true;
        return _is_available;
    }

    bool df_player_c::handle_error(uint8_t type, uint16_t parameter) {
        handle_message(type, parameter);
        _is_sending = false;
        return false;
    }

    uint8_t df_player_c::readCommand() {
        _is_available = false;
        return _handle_command;
    }

    void df_player_c::parse_stack() {
        uint8_t handleCommand = *(_received + Stack_Command);
        if (handleCommand ==
            0x41) { // handle the 0x41 ack feedback as a spcecial case, in case
            the
                // pollusion of _handle_command, _handle_parameter, and
                // _handle_type.
                _is_sending = false;
            return;
        }

        _handle_command = handleCommand;
        _handle_parameter = array_to_uint16(_received + Stack_Parameter);

        switch (_handle_command) {
        case 0x3D:
            handle_message(DFPlayerPlayFinished, _handle_parameter);
            break;
        case 0x3F:
            if (_handle_parameter & 0x01) {
                handle_message(DFPlayerUSBOnline, _handle_parameter);
            } else if (_handle_parameter & 0x02) {
                handle_message(DFPlayerCardOnline, _handle_parameter);
            } else if (_handle_parameter & 0x03) {
                handle_message(DFPlayerCardUSBOnline, _handle_parameter);
            }
            break;
        case 0x3A:
            if (_handle_parameter & 0x01) {
                handle_message(DFPlayerUSBInserted, _handle_parameter);
            } else if (_handle_parameter & 0x02) {
                handle_message(DFPlayerCardInserted, _handle_parameter);
            }
            break;
        case 0x3B:
            if (_handle_parameter & 0x01) {
                handle_message(DFPlayerUSBRemoved, _handle_parameter);
            } else if (_handle_parameter & 0x02) {
                handle_message(DFPlayerCardRemoved, _handle_parameter);
            }
            break;
        case 0x40:
            handle_message(DFPlayerError, _handle_parameter);
            break;
        case 0x3C:
        case 0x3E:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4E:
        case 0x4F:
            handle_message(DFPlayerFeedBack, _handle_parameter);
            break;
        default:
            handle_error(WrongStack);
            break;
        }
    }

    uint16_t df_player_c::array_to_uint16(uint8_t *array) {
        uint16_t value = *array;
        value <<= 8;
        value += *(array + 1);
        return value;
    }

    bool df_player_c::validate_stack() {
        return calculate_check_sum(_received) ==
               array_to_uint16(_received + Stack_CheckSum);
    }

    bool df_player_c::available() {
        while (_serial->available()) {
            delay(0);
            if (_received_index == 0) {
                _received[Stack_Header] = _serial->read();
#ifdef _DEBUG
                Serial.print(F("received:"));
                Serial.print(_received[_received_index], HEX);
                Serial.print(F(" "));
#endif
                if (_received[Stack_Header] == 0x7E) {
                    _received_index++;
                }
            } else {
                _received[_received_index] = _serial->read();
#ifdef _DEBUG
                Serial.print(_received[_received_index], HEX);
                Serial.print(F(" "));
#endif
                switch (_received_index) {
                case Stack_Version:
                    if (_received[_received_index] != 0xFF) {
                        return handle_error(WrongStack);
                    }
                    break;
                case Stack_Length:
                    if (_received[_received_index] != 0x06) {
                        return handle_error(WrongStack);
                    }
                    break;
                case Stack_End:
#ifdef _DEBUG
                    Serial.println();
#endif
                    if (_received[_received_index] != 0xEF) {
                        return handle_error(WrongStack);
                    } else {
                        if (validate_stack()) {
                            _received_index = 0;
                            parse_stack();
                            return _is_available;
                        } else {
                            return handle_error(WrongStack);
                        }
                    }
                    break;
                default:
                    break;
                }
                _received_index++;
            }
        }

        if (_is_sending && (millis() - _time_out_timer >= _time_out_duration)) {
            return handle_error(TimeOut);
        }

        return _is_available;
    }

    void df_player_c::next() {
        send_stack(0x01);
    }

    void df_player_c::previous() {
        send_stack(0x02);
    }

    void df_player_c::play(int file_number) {
        send_stack(0x03, file_number);
    }

    void df_player_c::volume_up() {
        send_stack(0x04);
    }

    void df_player_c::volume_down() {
        send_stack(0x05);
    }

    void df_player_c::volume(uint8_t volume) {
        send_stack(0x06, volume);
    }

    void df_player_c::eq(uint8_t eq) {
        send_stack(0x07, eq);
    }

    void df_player_c::loop(int file_number) {
        send_stack(0x08, file_number);
    }

    void df_player_c::output_device(uint8_t device) {
        send_stack(0x09, device);
        delay(200);
    }

    void df_player_c::sleep() {
        send_stack(0x0A);
    }

    void df_player_c::reset() {
        send_stack(0x0C);
    }

    void df_player_c::start() {
        send_stack(0x0D);
    }

    void df_player_c::pause() {
        send_stack(0x0E);
    }

    void df_player_c::play_folder(uint8_t folder_number, uint8_t file_number) {
        send_stack(0x0F, folder_number, file_number);
    }

    void df_player_c::output_setting(bool enable, uint8_t gain) {
        send_stack(0x10, enable, gain);
    }

    void df_player_c::enable_loop_all() {
        send_stack(0x11, 0x01);
    }

    void df_player_c::disable_loop_all() {
        send_stack(0x11, 0x00);
    }

    void df_player_c::play_mp3_folder(int file_number) {
        send_stack(0x12, file_number);
    }

    void df_player_c::advertise(int file_number) {
        send_stack(0x13, file_number);
    }

    void df_player_c::play_large_folder(uint8_t folder_number,
                                        uint16_t file_number) {
        send_stack(0x14, (((uint16_t)folder_number) << 12) | file_number);
    }

    void df_player_c::stop_advertise() {
        send_stack(0x15);
    }

    void df_player_c::stop() {
        send_stack(0x16);
    }

    void df_player_c::loopFolder(int folder_number) {
        send_stack(0x17, folder_number);
    }

    void df_player_c::random_all() {
        send_stack(0x18);
    }

    void df_player_c::enable_loop() {
        send_stack(0x19, 0x00);
    }

    void df_player_c::disable_loop() {
        send_stack(0x19, 0x01);
    }

    void df_player_c::enable_dac() {
        send_stack(0x1A, 0x00);
    }

    void df_player_c::disable_dac() {
        send_stack(0x1A, 0x01);
    }

    int df_player_c::read_state() {
        send_stack(0x42);
        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_volume() {
        send_stack(0x43);
        if (wait_available()) {
            return read();
        } else {
            return -1;
        }
    }

    int df_player_c::read_eq() {
        send_stack(0x44);
        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_file_counts(uint8_t device) {
        switch (device) {
        case DFPLAYER_DEVICE_U_DISK:
            send_stack(0x47);
            break;
        case dfplayer_device_sd:
            send_stack(0x48);
            break;
        case DFPLAYER_DEVICE_FLASH:
            send_stack(0x49);
            break;
        default:
            break;
        }

        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_current_file_number(uint8_t device) {
        switch (device) {
        case DFPLAYER_DEVICE_U_DISK:
            send_stack(0x4B);
            break;
        case dfplayer_device_sd:
            send_stack(0x4C);
            break;
        case DFPLAYER_DEVICE_FLASH:
            send_stack(0x4D);
            break;
        default:
            break;
        }
        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_file_counts_in_folder(int folder_number) {
        send_stack(0x4E, folder_number);
        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_folder_counts() {
        send_stack(0x4F);
        if (wait_available()) {
            if (read_type() == DFPlayerFeedBack) {
                return read();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }

    int df_player_c::read_file_counts() {
        return read_file_counts(dfplayer_device_sd);
    }

    int df_player_c::read_current_file_number() {
        return read_current_file_number(dfplayer_device_sd);
    }
    */
} // namespace r2d2::sound