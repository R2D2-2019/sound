#include <sound.hpp>

namespace r2d2::sound {
    sound_c::sound_c(base_comm_c &comm, r2d2::sound::rtttl_player_c &player):
        base_module_c(comm), player(player) {

        //Set up for listeners
        comm.listen_for_frames({
            r2d2::frame_type::RTTTL_STRING
        });
    }

    void sound_c::process() {
        while (comm.has_data()) {
            auto frame = comm.get_data();

            if (frame.request) {
                hwlib::cout << 1;
                continue;
            }

            const auto data = frame.as_frame_type<
                frame_type::RTTTL_STRING
            >();

            player.rtttl_play(data.rtttl_string);

        }
    }

}
