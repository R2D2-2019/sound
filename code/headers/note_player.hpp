#pragma once

namespace r2d2::sound {
    /**
     * enum class note_frequencies
     * Data class to store frequencies that are assigned to notes.
     */
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
    
    /**
     * struct notes_s
     * Defines the data from a note_s
     */
    struct note_s {
        /**
         * frequency number int
         * @internal
         */    
        int frequency;
        
        /**
         * dF - durationFull
         * @internal
         */  
        static const int dF = 1'000'000;
        
        /**
         * dH - durationHalf
         * @internal
         */  
        static const int dH = dF / 2;
        
        /**
         * dQ - durationQuarter
         * @internal
         */          
        static const int dQ = dF / 4;
        
        /**
         * duration of the note_s / frequency
         * @internal
         */  
        const int duration;

    };
    
    /**
     * class note_player_c
     * Abstract class with play
     */  
    class note_player_c {
    public:
        /**
         * virtual play
         * 
         * @param n - values from the class const note_s need to be used to override
         */ 
        virtual void play(const note_s & n) = 0;
    };
}
