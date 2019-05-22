#pragma once

#include <note_player.hpp>

namespace r2d2::sound {
    /**
     * class rtttl_player_c
     * Provides hardware I2C functionality to the arduino due.
     */
    class rtttl_player_c {
    private:
        note_player_c & player;
    public:
        /**
         * Constructor that makes player out of abstract class
         *
         * @param player - make player from note_player_c
         */
        rtttl_player_c(note_player_c & player);
        
        /**
         * Plays a song that is made from ceveral frequencies/notes
         * 
         * @param *s - ceveral frequencies/notes saved in a char that is playable with this function
         */
        void rtttl_play(const char *s);

    };
}
