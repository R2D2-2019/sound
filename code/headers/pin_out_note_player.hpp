/**
 * @file
 * @brief pin_out_note_player class
 * @details can play notes via an hwlib::pin_out
 * @author Patrick Dekker
 * @author David de Jong
 */
#pragma once

#include <note_player.hpp>
#include <hwlib.hpp>

namespace r2d2::sound {
    
    /**
     * @brief class pin_out_note_player_c
     * @details Provides hardware connection to the arduino due with lsp.
     */
    class pin_out_note_player_c : public note_player_c{
    private:
        hwlib::pin_out &lsp;
    public:
        
        /**
         * @brief Constructor for the lsp pin
         * 
         * @param lsp - hwlib::pin_out pin for writing output to lsp.
         */
        pin_out_note_player_c(hwlib::pin_out &lsp);

        /**
         * @brief Plays a note n
         * @details Plays note n by setting pin lsp from 0 to 1 in the correct frequency
         *
         * @param n - A note with specific values that can be played.
         */
        void play(const note_s &n) override;

    };
}
