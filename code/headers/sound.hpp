#pragma once

namespace r2d2::sound {
    /**
     * Class sound a pure virtual class for sound.
     */
    class sound_c {
    public:
        /**
         * This function starts playing a sound using a name.
         *
         * @param name The name of the sound you want to play.
         */
        virtual void start(const char *name) = 0;

        /**
         * This function resumes the sound if on pause.
         *
         */
        virtual void play() = 0;

        /**
         * This function pauses the sound if playing.
         *
         */
        virtual void pause() = 0;

        /**
         * This function goes to the previous sound and plays it.
         *
         */
        virtual void previous() = 0;

        /**
         * This function goes to the next sound and plays it.
         *
         */
        virtual void next() = 0;

        /**
         * This function increases the volume of the sound.
         *
         */
        virtual void volume_up() = 0;

        /**
         * This function decreases the volume of the sound.
         *
         */
        virtual void volume_down() = 0;
    };

} // namespace r2d2::sound