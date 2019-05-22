#pragma once
#include <base_module.hpp>
#include <rtttl_player.hpp>

namespace r2d2::sound {
    /**
     * Class sound a pure virtual class for sound.
     */
class sound_c : public r2d2::base_module_c {
    protected:
        rtttl_player_c &player;\
    public:
        sound_c(base_comm_c & comm, rtttl_player_c & player);

        void process() override;

        /**
         * This function starts playing a sound using a name.
         *
         * @param name The name of the sound you want to play.
         */
     //   virtual void start(const char *name){};

        /**
         * This function turns on the mp3 player (Also starts music)
         *
         */
       // virtual void power_on(){};

        /**
         * This function turns off the mp3 player (Also stops music)
         *
         */
        //virtual void power_off(){};

        /**
         * This function resumes the sound if on pause.
         *
         */
        //virtual void play() = 0;

        /**
         * This function pauses the sound if playing.
         *
         */
        //virtual void pause() = 0;

        /**
         * This function goes to the previous sound and plays it.
         *
         */
        //virtual void previous() = 0;

        /**
         * This function goes to the next sound and plays it.
         *
         */
        //virtual void next() = 0;

        /**
         * This function increases the volume of the sound.
         *
         */
        //virtual void volume_up() = 0;

        /**
         * This function decreases the volume of the sound.
         *
         */
        //virtual void volume_down() = 0;

        /**
         * This function toggles repeat.
         *
         */
        //virtual void toggle_repeat() = 0;
    };

} // namespace r2d2::sound
