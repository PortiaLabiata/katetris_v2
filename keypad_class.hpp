#pragma once
#include <stdint.h>

namespace IO {

class keypad_t {
public:
	union buttons_mask_t {
		uint8_t mask;
		struct __attribute__((packed)) {
			uint8_t up : 1;
			uint8_t down : 1;
			uint8_t left : 1;
			uint8_t right : 1;
			uint8_t enter : 1;
		} bits;
	};
	keypad_t() = default;
	virtual ~keypad_t() {};

	virtual void init() = 0;
	virtual buttons_mask_t read() = 0;
protected:
	buttons_mask_t mask;
};

}
