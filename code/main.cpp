//#include "mp3_player.hpp"
#include <hwlib.hpp>
#include <rtttl_player.hpp>
#include <pin_out_note_player.hpp>
#include <sound.hpp>

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
    auto lsp = hwlib::target::pin_out( hwlib::target::pins::d7 );
    auto p = r2d2::sound::pin_out_note_player_c(lsp);
    auto player = r2d2::sound::rtttl_player_c(p);
    player.rtttl_play(let_it_be);

  /*  auto power = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto repeat = hwlib::target::pin_oc(hwlib::target::pins::d4);
    auto mode = hwlib::target::pin_oc(hwlib::target::pins::d5);
    auto prev = hwlib::target::pin_oc(hwlib::target::pins::d6);
    auto next = hwlib::target::pin_oc(hwlib::target::pins::d7);
    auto sound_player =
        r2d2::sound::mp3_player_c(power, next, prev, mode, repeat);
    while (true) { // demo for the mp3 shield
        hwlib::cout << "------\n";
        auto c = hwlib::cin.getc();
        if (c == 'p') {
            hwlib::cout << "Power-ON\n";
            sound_player.power_on();
        }
        if (c == 'o') {
            hwlib::cout << "Power-OFF\n";
            sound_player.power_off();
        }
        if (c == 's') {
            hwlib::cout << "Start stop\n";
            sound_player.pause();
        }
        if (c == 'r') {
            hwlib::cout << "Repeat toggle\n";
            sound_player.toggle_repeat();
        }
        if (c == 'n') {
            hwlib::cout << "Next\n";
            sound_player.next();
        }
        if (c == 'b') {
            hwlib::cout << "back\n";
            sound_player.previous();
        }
        if (c == '+') {
            hwlib::cout << "Volume UP\n";
            sound_player.volume_up();
        }
        if (c == '-') {
            hwlib::cout << "Volume Down\n";
            sound_player.volume_down();
        }
    }*/
}
