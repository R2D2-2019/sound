#pragma once

#include "sound.hpp"
#include <array>
#include <hardware_usart.hpp>
#include <hwlib.hpp>

#define DFPLAYER_EQ_NORMAL 0
#define DFPLAYER_EQ_POP 1
#define DFPLAYER_EQ_ROCK 2
#define DFPLAYER_EQ_JAZZ 3
#define DFPLAYER_EQ_CLASSIC 4
#define DFPLAYER_EQ_BASS 5

#define DFPLAYER_DEVICE_U_DISK 1
#define dfplayer_device_sd 2
#define DFPLAYER_DEVICE_AUX 3
#define DFPLAYER_DEVICE_SLEEP 4
#define DFPLAYER_DEVICE_FLASH 5

#define DFPLAYER_RECEIVED_LENGTH 10
#define DFPLAYER_SEND_LENGTH 10

//#define _DEBUG

#define TimeOut 0
#define WrongStack 1
#define DFPlayerCardInserted 2
#define DFPlayerCardRemoved 3
#define DFPlayerCardOnline 4
#define DFPlayerPlayFinished 5
#define DFPlayerError 6
#define DFPlayerUSBInserted 7
#define DFPlayerUSBRemoved 8
#define DFPlayerUSBOnline 9
#define DFPlayerCardUSBOnline 10
#define DFPlayerFeedBack 11

#define Busy 1
#define Sleeping 2
#define SerialWrongStack 3
#define CheckSumNotMatch 4
#define FileIndexOut 5
#define FileMismatch 6
#define Advertise 7

#define Stack_Header 0
#define Stack_Version 1
#define Stack_Length 2
#define Stack_Command 3
#define Stack_ACK 4
#define Stack_Parameter 5
#define Stack_CheckSum 7
#define Stack_End 9

namespace r2d2::sound {
    class df_player_c {
        /* TO DO
        Stream *_serial;
        unsigned long _time_out_timer;
        unsigned long _time_out_duration = 500;
        uint8_t _received[DFPLAYER_RECEIVED_LENGTH];
        uint8_t _sending[DFPLAYER_SEND_LENGTH] = {0x7E, 0xFF, 06, 00, 01,
                                                  00,   00,   00, 00, 0xEF};
        uint8_t _received_index = 0;
        void send_stack();
        void send_stack(uint8_t command);
        void send_stack(uint8_t command, uint16_t argument);
        void send_stack(uint8_t command, uint8_t argumentHigh,
                       uint8_t argumentLow);
        void enable_ack();
        void disable_ack();
        void uint16_to_array(uint16_t value, uint8_t *array);
        uint16_t array_to_uint16(uint8_t *array);
        uint16_t calculate_check_sum(uint8_t *buffer);
        void parse_stack();
        bool validate_stack();
        uint8_t device = dfplayer_device_sd;
        */
    public:
        /* TO DO
        uint8_t _handle_type;
        uint8_t _handle_command;
        uint16_t _handle_parameter;
        bool _is_available = false;
        bool _is_sending = false;

        bool handle_message(uint8_t type, uint16_t parameter = 0);
        bool handle_error(uint8_t type, uint16_t parameter = 0);
        uint8_t handle_error();
        bool begin(Stream &stream, bool isACK = true, bool doReset = true);
        bool wait_available(unsigned long duration = 0);
        bool available();
        uint8_t read_type();
        uint16_t read();
        */

        /* needs refactoring
        void set_time_out(unsigned long time_out_duration);
        void next();
        void previous();
        void play(int file_number = 1);
        void volume_up();
        void volume_down();
        void volume(uint8_t volume);
        void eq(uint8_t eq);
        void loop(int file_number);
        void output_device(uint8_t device);
        void sleep();
        void reset();
        void start();
        void pause();
        void play_folder(uint8_t folder_number, uint8_t file_number);
        void output_setting(bool enable, uint8_t gain);
        void enable_loop_all();
        void disable_loop_all();
        void play_mp3_folder(int file_number);
        void advertise(int file_number);
        void play_large_folder(uint8_t folder_number, uint16_t file_number);
        void stop_advertise();
        void stop();
        void loopFolder(int folder_number);
        void random_all();
        void enable_loop();
        void disable_loop();
        void enable_dac();
        void disable_dac();
        int read_state();
        int read_volume();
        int read_eq();
        int read_file_counts(uint8_t device);
        int read_current_file_number(uint8_t device);
        int read_file_counts_in_folder(int folder_number);
        int read_file_counts();
        int read_folder_counts();
        int read_current_file_number();
        */
    };
} // namespace r2d2::sound