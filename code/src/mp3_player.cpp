#include "mp3_player.hpp"
#include <cstring>
#include <hwlib.hpp>

namespace r2d2::sound {
    mp3_player_c::mp3_player_c(hwlib::pin_out &power_pin,
                               hwlib::pin_oc &volume_up_next_pin,
                               hwlib::pin_oc &volume_down_prev_pin,
                               hwlib::pin_oc &play_pause_mode_pin,
                               hwlib::pin_oc &repeat_pin)
        : power_pin(power_pin),
          volume_up_next_pin(volume_up_next_pin),
          volume_down_prev_pin(volume_down_prev_pin),
          play_pause_mode_pin(play_pause_mode_pin),
          repeat_pin(repeat_pin) {
        init();
    }

    void mp3_player_c::init() {
        power_pin.write(false);
        volume_up_next_pin.write(true);
        volume_down_prev_pin.write(true);
        play_pause_mode_pin.write(true);
        repeat_pin.write(true);
        pause();
    }

    void mp3_player_c::press_for(unsigned int milliseconds,
                                 hwlib::pin_oc &pin) {
        pin.write(false);
        hwlib::wait_ms(milliseconds);
        pin.write(true);
    }

    void mp3_player_c::press_for(unsigned int milliseconds, hwlib::pin_oc &pin1,
                                 hwlib::pin_oc &pin2) {
        pin1.write(false);
        pin2.write(false);
        hwlib::wait_ms(milliseconds);
        pin1.write(true);
        pin2.write(true);
    }

    void mp3_player_c::short_press(hwlib::pin_oc &pin) {
        press_for(500, pin);
    }

    void mp3_player_c::short_press(hwlib::pin_oc &pin1, hwlib::pin_oc &pin2) {
        press_for(500, pin1, pin2);
    }

    void mp3_player_c::long_press(hwlib::pin_oc &pin) {
        press_for(1500, pin);
    }

    void mp3_player_c::long_press(hwlib::pin_oc &pin1, hwlib::pin_oc &pin2) {
        press_for(1500, pin1, pin2);
    }

    void mp3_player_c::power_on() {
        power_pin.write(true);
    }

    void mp3_player_c::power_off() {
        power_pin.write(false);
    }

    void mp3_player_c::play() {
        short_press(play_pause_mode_pin);
    }

    void mp3_player_c::pause() {
        short_press(play_pause_mode_pin);
    }

    void mp3_player_c::previous() {
        short_press(volume_down_prev_pin);
    }

    void mp3_player_c::next() {
        short_press(volume_up_next_pin);
    }

    void mp3_player_c::volume_up() {
        long_press(volume_up_next_pin, volume_down_prev_pin);
    }

    void mp3_player_c::volume_down() {
        long_press(volume_up_next_pin);
    }

    void mp3_player_c::toggle_repeat() {
        short_press(repeat_pin);
    }
} // namespace r2d2::sound