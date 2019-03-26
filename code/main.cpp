#include "../headers/df_player.hpp"
#include "../headers/mp3_player.hpp"
#include "hardware_usart.hpp"
#include "hwlib.hpp"

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    hwlib::cout << "this works on arduino\n";
    if (true) { // player is mp3 board
        r2d2::uart_ports_c port = r2d2::uart_ports_c::uart1;
        auto c = r2d2::hardware_usart_c(9600, port);
        char cc;
        // c.send()
        for (;;) {
            if (c.char_available()) {
                cc = c.getc();
                hwlib::cout << cc;
            }
        }
    } else { // player is mp3player
        auto power = hwlib::target::pin_out(hwlib::target::pins::d3);
        auto repeat = hwlib::target::pin_oc(hwlib::target::pins::d4);
        auto mode = hwlib::target::pin_oc(hwlib::target::pins::d5);
        auto prev = hwlib::target::pin_oc(hwlib::target::pins::d6);
        auto next = hwlib::target::pin_oc(hwlib::target::pins::d7);
        auto sound_player =
            r2d2::sound::mp3_player_c(power, next, prev, mode, repeat);
        while (1) { // demo for the mp3 shield
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
        }
    }
}