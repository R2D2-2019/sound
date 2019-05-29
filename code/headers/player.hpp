/**
 * @file
 * @brief pure virtual player class
 * @author Patrick Dekker
 */
#pragma once

namespace r2d2::sound {
    /**
     * Class sound a pure virtual class for a player.
     */
    class player_c {
    public:
        /**
         * @brief This function plays the sound.
         *
         */
        virtual void play() = 0;
    };

} // namespace r2d2::sound
