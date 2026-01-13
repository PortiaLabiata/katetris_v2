#pragma once
#include "keypad_class.hpp"

namespace IO {

class keypad_pc_t : public keypad_t {
public:
	keypad_pc_t() = default;
	~keypad_pc_t() = default;

	void init() override {}
	buttons_mask_t read() override;
};

}
