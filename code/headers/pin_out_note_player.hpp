#pragma once

#include <note_player.hpp>
#include <hwlib.hpp>

namespace r2d2::sound {


    class pin_out_note_player_c : public note_player_c{
    private:
        hwlib::pin_out &lsp;
    public:
        pin_out_note_player_c(hwlib::pin_out &lsp);

        void play(const note_s &n) override;

    };
}