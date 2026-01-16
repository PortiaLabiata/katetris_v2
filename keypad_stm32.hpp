#pragma once
#include "keypad_class.hpp"
#include "gpio.hpp"

namespace IO {

class keypad_stm32_t : public keypad_t {
public:
	keypad_stm32_t() = default;
	~keypad_stm32_t() = default;

	void init() override;
	buttons_mask_t read() override;
private:
	HAL::ioline_t line_up{GPIOB, 15U};
	HAL::ioline_t line_down{GPIOB, 14U};
	HAL::ioline_t line_left{GPIOB, 13U};
	HAL::ioline_t line_right{GPIOA, 11U};
	HAL::ioline_t line_return{GPIOB, 12};
};

}
