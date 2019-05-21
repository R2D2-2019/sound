#include <pin_out_note_player.hpp>

namespace r2d2::sound {

    pin_out_note_player_c::pin_out_note_player_c(hwlib::pin_out &lsp) :
        lsp(lsp)
    {}

    void pin_out_note_player_c::play(const note_s &n) {
        if (n.frequency == 0){
            hwlib::wait_us( n.duration );
        } else {
            auto end = hwlib::now_us() + n.duration;
            auto half_period = 1'000'000 / ( 2 * n.frequency );
            while ( end > hwlib::now_us()){
                lsp.write(1);
                hwlib::wait_us(half_period);
                lsp.write(0);
                hwlib::wait_us(half_period);
            }
        }
    }

}