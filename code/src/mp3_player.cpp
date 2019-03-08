#include "mp3_player.hpp"

#include <hwlib.hpp>
#include <cstring>

namespace r2d2::sound {
    mp3_player_c::mp3_player_c(hwlib::pin_out &volume_up_next_pin,
                               hwlib::pin_out &volume_down_prev_pin,
                               hwlib::pin_out &play_pause_mode_pin,
                               hwlib::pin_out &repeat_pin,
                               hwlib::pin_in &is_playing_pin)
        : volume_up_next_pin(volume_up_next_pin),
          volume_down_prev_pin(volume_down_prev_pin),
          play_pause_mode_pin(play_pause_mode_pin),
          repeat_pin(repeat_pin),
          is_playing_pin(is_playing_pin),
          current_song(0) {
        init();
    }

    // mp3_player_c::~mp3_player_c() {}

    void mp3_player_c::init() {
        volume_up_next_pin.write(1);
        volume_down_prev_pin.write(1);
        play_pause_mode_pin.write(1);
        repeat_pin.write(1);
        pause();
    }
    void mp3_player_c::press_for(unsigned int milliseconds,
                                 hwlib::pin_out &pin) {
        pin.write(0);
        hwlib::wait_ms(milliseconds);
        pin.write(1);
    }

    void mp3_player_c::long_press(hwlib::pin_out &pin) {
        press_for(2000, pin);
    }

    void mp3_player_c::short_press(hwlib::pin_out &pin) {
        press_for(500, pin);
    }

    bool mp3_player_c::is_playing() {
        if (!is_playing_pin.read()) {
            return false;
        }
        hwlib::wait_ms(1);
        if (!is_playing_pin.read()) {
            return false;
        }
        return true;
    }

    int mp3_player_c::get_id_by_name(const char *name) const {
        for (size_t id = 0; id < songs.size(); ++id) {
            if (strcmp(name, songs[id]) == 0) {
                return static_cast<int>(id);
            }
        }
        return -1;
    }

    void mp3_player_c::start(const char *name) {
        auto id = get_id_by_name(name);
        if (id == -1) {
            return;
        }
        if (current_song == id) {
            previous();
            // Might need a sleep here.
            next();
        } else if (id < current_song) {
            while (id < current_song) {
                previous();
            }
        } else {
            while (id > current_song) {
                next();
            }
        }
    }

    void mp3_player_c::play() {
        if (!is_playing()) {
            short_press(play_pause_mode_pin);
        }
    }

    void mp3_player_c::pause() {
        if (is_playing()) {
            short_press(play_pause_mode_pin);
        }
    }

    void mp3_player_c::previous() {
        short_press(volume_down_prev_pin);
        current_song--;
    }

    void mp3_player_c::next() {
        short_press(volume_up_next_pin);
        current_song++;
    }

    void mp3_player_c::volume_up() {
        long_press(volume_up_next_pin);
    }

    void mp3_player_c::volume_down() {
        long_press(volume_down_prev_pin);
    }

} // namespace r2d2::sound