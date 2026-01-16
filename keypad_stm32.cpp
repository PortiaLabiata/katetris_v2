#include "keypad_stm32.hpp"
#include <gpio.hpp>

namespace IO {

void keypad_stm32_t::init() {
	line_up.cfg(HAL::linemode_t::in_pdown);
	line_down.cfg(HAL::linemode_t::in_pdown);
	line_left.cfg(HAL::linemode_t::in_pdown);
	line_right.cfg(HAL::linemode_t::in_pdown);
	line_return.cfg(HAL::linemode_t::in_pdown);
}

keypad_t::buttons_mask_t keypad_stm32_t::read() {
	buttons_mask_t mask = {0};
	return mask;
}

}
