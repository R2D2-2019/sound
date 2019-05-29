#include <comm.hpp>
#include <hwlib.hpp>
#include <pin_out_note_player.hpp>
#include <rtttl_player.hpp>
#include <sound.hpp>

int main(void) {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    auto lsp = hwlib::target::pin_out(hwlib::target::pins::d7);
    auto pl = r2d2::sound::pin_out_note_player_c(lsp);
    auto player = r2d2::sound::rtttl_player_c(pl);

    r2d2::comm_c comm;
    r2d2::sound::sound_c module(comm, player);

    for (;;) {
        module.process();
    }
}
