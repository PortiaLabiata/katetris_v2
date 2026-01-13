#pragma once
#include "env.hpp"
#include "keypad_class.hpp"

#if SITL
#include "keypad_pc.hpp"
inline IO::keypad_pc_t keypad_pc;
inline IO::keypad_t *keypad = &keypad_pc;
#else
#include "keypad_stm32.hpp"
inline IO::keypad_stm32_t keypad_stm32;
inline IO::keypad_t *keypad = &keypad_stm32;
#endif
