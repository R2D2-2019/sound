/// @file
/// @brief rtttl player class to play rtttl strings
/// @author Patrick Dekker
/// @author David de Jong
#pragma once

#include <player.hpp>
#include <note_player.hpp>

namespace r2d2::sound {
    /**
     * @brief class rtttl_player_c
     */
    class rtttl_player_c : public player_c {
    private:
        note_player_c & player;
        const char *s;
    public:
        /**
         * @brief Constructor that makes player out of abstract class
         *
         * @param player - make player from note_player_c
         */
        rtttl_player_c(note_player_c & player);
        
        /**
         * @brief Plays a song that is made from several frequencies/notes
         * 
         * @param *s - several frequencies/notes saved in a char that is playable with this function
         */
        void play() override;


        void set_rtttl(const char *c);

    };
}
