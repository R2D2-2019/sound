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
        hwlib::pin_out &power_pin;
        hwlib::pin_oc &volume_up_next_pin;
        hwlib::pin_oc &volume_down_prev_pin;
        hwlib::pin_oc &play_pause_mode_pin;
        hwlib::pin_oc &repeat_pin;

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
        void press_for(unsigned int milliseconds, hwlib::pin_oc &pin);

        /**
         * This function uses the press_for function to output a long press
         * command.
         *
         * @internal
         * @param pin The pin you want to use for the long press.
         */
        void long_press(hwlib::pin_oc &pin);

        /**
         * This function uses the press_for function to output a short press
         * command.
         *
         * @internal
         * @param pin The pin you want to use for the short press.
         */
        void short_press(hwlib::pin_oc &pin);

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
        mp3_player_c(hwlib::pin_out &power_pin,
                     hwlib::pin_oc &volume_up_next_pin,
                     hwlib::pin_oc &volume_down_prev_pin,
                     hwlib::pin_oc &play_pause_mode_pin,
                     hwlib::pin_oc &repeat_pin);
        // virtual ~mp3_player_c();

        /**
         * This function check whether there is a sound playing at the moment.
         *
         * @return A bool which indicated if there is a sound playing at the
         * moment.
         */
        bool is_playing();

        /**
         * This function outputs the play command if there is no song playing.
         *
         */
        virtual void power_on() override;

        /**
         * This function outputs the pause command if there is a song playing.
         *
         */
        virtual void power_off() override;

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