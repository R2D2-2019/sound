#pragma once

namespace r2d2::sound {

    enum class note_frequencies : int {
        A4  = 440,
        A4s = 466,
        B4  = 494,
        C5  = 523,
        C5s = 554,
        E5  = 659,
        F5  = 698,
        F5s = 740,
        G5  = 784,
        G5s = 830,
        A5  = 880,
        A5s = 932,
        B5  = 987
    };

    struct note_s {

        int frequency;

        static const int dF = 1'000'000;

        static const int dH = dF / 2;
        static const int dQ = dF / 4;

        const int duration;

    };

    class note_player_c {
    public:
        virtual void play(const note_s & n) = 0;
    };
}