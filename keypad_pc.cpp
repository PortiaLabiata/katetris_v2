#include <SDL2/SDL.h>
#include "keypad_pc.hpp"
#include "mutex.hpp"
#include "mutex_class.hpp"

// FIXIT: duct tape
extern bool button_evt;
extern SDL_Keycode sym; 
extern OS::mutex_t mtx;

namespace IO {

using buttons_mask_t = keypad_t::buttons_mask_t;

// Here union doesn't actually do anything, 
// because I am lazy. Also, I just really like
// this pattern.
keypad_t::buttons_mask_t keypad_pc_t::read() {
	OS::lock_guard_t guard(mtx);
	buttons_mask_t mask = {0};
	if (!button_evt) {
		return mask;
	}
	button_evt = false;
	switch (sym) {
		case SDLK_d:
			mask.bits.right = 1;
			break;
		case SDLK_a:
			mask.bits.left = 1;
			break;
		case SDLK_w:
			mask.bits.up = 1;
			break;
		case SDLK_s:
			mask.bits.down = 1;
			break;
		case SDLK_SPACE:
			mask.bits.enter = 1;
			break;
		default:
			break;
	}
	return mask;
}

}
