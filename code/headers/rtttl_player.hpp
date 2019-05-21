#pragma once

#include <note_player.hpp>

namespace r2d2::sound {

    class rtttl_player_c {
    private:
        note_player_c & player;
    public:

        rtttl_player_c(note_player_c & player);
        void rtttl_play(const char *s);

    };
}