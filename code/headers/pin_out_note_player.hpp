#pragma once

#include <note_player.hpp>
#include <hwlib.hpp>

namespace r2d2::sound {
    
    /**
     * class pin_out_note_player_c
     * Provides hardware connection to the arduino due with lsp.
     */
    class pin_out_note_player_c : public note_player_c{
    private:
        hwlib::pin_out &lsp;
    public:
        
        /**
         * Constructor for the lsp pin
         * 
         * @param lsp - hwlib::pin_out pin for writing output to lsp.
         */
        pin_out_note_player_c(hwlib::pin_out &lsp);
        
        
        /**
         * Plays a note n with writing 1 or 0 to lsp.
         *
         * @param n - A note with specific values that can be played.
         */
        void play(const note_s &n) override;

    };
}
