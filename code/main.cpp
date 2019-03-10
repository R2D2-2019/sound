#include "hwlib.hpp"
#include "../headers/mp3_player.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    auto p = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto s = hwlib::target::pin_oc(hwlib::target::pins::d4);
    auto r = hwlib::target::pin_oc(hwlib::target::pins::d5);
    auto n = hwlib::target::pin_oc(hwlib::target::pins::d6);
    auto b = hwlib::target::pin_oc(hwlib::target::pins::d7);
    //auto sound_player = r2d2::sound::mp3_player_c(hwlib::target::pins::d3,
    //                                       hwlib::target::pins::d4,
    //                                       hwlib::target::pins::d5,
    //                                       hwlib::target::pins::d6,
    //                                       hwlib::target::pins::d7);
    while(1){
        
        hwlib::cout << "------\n";
        auto c = hwlib::cin.getc();
        if (c == 'p'){
            hwlib::cout << "Power-ON\n";
            p.write(1);
        }
        if (c == 'o'){
            hwlib::cout << "Power-OFF\n";
            p.write(0);
        }
        if (c == 's'){
            hwlib::cout << "Start stop\n";
            s.write(0);
            hwlib::wait_ms(500);
            s.write(1);
        }
        if (c == 'r'){
            hwlib::cout << "Repeat toggle\n";
            r.write(0);
            hwlib::wait_ms(500);
            r.write(1);
        }
        if (c == 'n'){
            hwlib::cout << "Next\n";
            n.write(0);
            hwlib::wait_ms(500);
            n.write(1);
        }
        if (c == 'b'){
            hwlib::cout << "back\n";
            b.write(0);
            hwlib::wait_ms(500);
            b.write(1);
        }
        if (c == '+'){
            hwlib::cout << "Volume UP\n";
            n.write(0);
            b.write(0);
            hwlib::wait_ms(1500);
            n.write(1);
            b.write(1);
        }
        if (c == '-'){
            hwlib::cout << "Volume Down\n";
            b.write(0);
            hwlib::wait_ms(2000);
            b.write(1);
        }
    }
    
}