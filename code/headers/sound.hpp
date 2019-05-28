/// @file
/// @brief module class for sound playback module
/// @author Patrick Dekker
#pragma once
#include <hwlib.hpp>
#include <base_module.hpp>
#include <rtttl_player.hpp>

namespace r2d2::sound {

class sound_c : public r2d2::base_module_c {
protected:
    rtttl_player_c &player;
public:
     sound_c(base_comm_c & comm, rtttl_player_c & player);

     void process() override;

};

} // namespace r2d2::sound
