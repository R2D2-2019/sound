/// @file
/// @brief module class for sound playback module
/// @author Patrick Dekker
#pragma once
#include <base_module.hpp>
#include <hwlib.hpp>

namespace r2d2::demo {
    /**
     * @brief demo controller class for demo
     */
    class controller_c : public base_module_c {
    private:
        hwlib::pin_in &pin;
        const char c[155] = "H: d=4,o=5,b=108: 2a4, 2e, 2d#, 2b4, 2a4, 2c, 2d, 2a#4, 2e., e, 1f4, 1a4, 1d#, 2e., d, 2c., b4, 1a4, 1p, 2a4, 2e, 2d#, 2b4, 2a4, 2c, 2d, 2a#4, 2e., e, 1f4";
    public:
        /**
         * @brief constructor for controller c
         * @param comm
         * @param pin , pin_in for button
         */
        controller_c(base_comm_c & comm, hwlib::pin_in & pin)
            : base_module_c(comm), pin(pin) {}
        /**
         * @brief processes the code
         * @details if button is pressed it sends an rtttl string
         */
        void process() override {
            while (true) {
                if (!pin.read()) {
                    frame_rtttl_string_s rtttl_str;
                    
                    memcpy(&rtttl_str.rtttl_string, c, strlen(c) + 1);
                    comm.send<frame_rtttl_string_s>(rtttl_str);
                    hwlib::wait_ms(100);
                }
            }
        }
    };
}
