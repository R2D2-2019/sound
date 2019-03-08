#pragma once

#include "sound.hpp"

#include <array>
#include <hwlib.hpp>

namespace r2d2::sound {
    /**
     * Class mp3_player_c plays mp3 files.
     */
    class mp3_player_c : public sound_c {
    private:
        hwlib::pin_out &volume_up_next_pin;
        hwlib::pin_out &volume_down_prev_pin;
        hwlib::pin_out &play_pause_mode_pin;
        hwlib::pin_out &repeat_pin;
        hwlib::pin_in &is_playing_pin;

        int current_song = 0;
        const static size_t amount_of_songs = 3;

        std::array<const char *, amount_of_songs> songs{"song1", "song2",
                                                        "song3"};

        /**
         * This function initializes the mp3 player.
         *
         * @internal
         */
        void init();

        /**
         * This function simulates a button press for a given amount of
         * milliseconds.
         *
         * @internal
         * @param milliseconds The amount of milliseconds you want the pin to be
         * pressed.
         * @param pin The pin used for the press simulation.
         */
        void press_for(unsigned int milliseconds, hwlib::pin_out &pin);

        /**
         * This function uses the press_for function to output a long press
         * command.
         *
         * @internal
         * @param pin The pin you want to use for the long press.
         */
        void long_press(hwlib::pin_out &pin);

        /**
         * This function uses the press_for function to output a short press
         * command.
         *
         * @internal
         * @param pin The pin you want to use for the short press.
         */
        void short_press(hwlib::pin_out &pin);

    public:
        /**
         * This function constructs the mp3_player class.
         *
         * @param volume_up_next_pin The pin you want to use to control the
         * volume up and next.
         * @param volume_down_prev_pin The pin you want to use to control the
         * volume down and previous.
         * @param play_pause_mode_pin The pin you want to use to control the
         * play, pause and mode.
         * @param repeat_pin The pin you want to use to set on repeat.
         * @param is_playing_pin The pin you want to use to check if there is a
         * song playing.
         */
        mp3_player_c(hwlib::pin_out &volume_up_next_pin,
                     hwlib::pin_out &volume_down_prev_pin,
                     hwlib::pin_out &play_pause_mode_pin,
                     hwlib::pin_out &repeat_pin, hwlib::pin_in &is_playing_pin);
        // virtual ~mp3_player_c();

        /**
         * This function check whether there is a sound playing at the moment.
         *
         * @return A bool which indicated if there is a sound playing at the
         * moment.
         */
        bool is_playing();

        /**
         * This function gets the id of a sound.
         *
         * @internal
         * @param name The name of the you want to get the id of.
         * @return A int containing the id of the given name.
         */
        int get_id_by_name(const char *name) const;

        /**
         * This function starts a sound.
         *
         * @internal
         * @param name The name of the sound you want to start.
         */
        virtual void start(const char *name) override;

        /**
         * This function outputs the play command if there is no song playing.
         *
         */
        virtual void play() override;

        /**
         * This function outputs the pause command if there is a song playing.
         *
         */
        virtual void pause() override;

        /**
         * This function outputs the previous sound command.
         *
         */
        virtual void previous() override;

        /**
         * This function outputs the next sound command.
         *
         */
        virtual void next() override;

        /**
         * This function outputs the volume up command.
         *
         */
        virtual void volume_up() override;

        /**
         * This function outputs the volume down command.
         *
         */
        virtual void volume_down() override;
    };

} // namespace r2d2::sound