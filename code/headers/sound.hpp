/// @file
/// @brief module class for sound playback module
/// @author Patrick Dekker
#pragma once
#include <hwlib.hpp>
#include <base_module.hpp>
#include <rtttl_player.hpp>

namespace r2d2::sound {

    /**
     * @brief sound base module for sound playback
     *
     */
    class sound_c : public r2d2::base_module_c {
    protected:
        rtttl_player_c &player;
    public:
        /**
         * @brief constructor for sound_c
         * @param comm
         * @param player , a rtttl_player
         */
        sound_c(base_comm_c & comm, rtttl_player_c & player);

        /**
         * @brief process is the process function
         * @details listens for the correct frame and plays an rtttl string if it is send
         */
        void process() override;

};

} // namespace r2d2::sound
