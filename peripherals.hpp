#pragma once
#include "env.hpp"
#include "osal_class.hpp"

#if SITL
#include "disp_pc.hpp"
inline OSAL::disp_pc_t disp_pc;
inline OSAL::disp_backend_t *disp = &disp_pc;
#else
#include "disp_stm32.hpp"
inline OSAL::disp_stm32_t disp_stm32;
inline OSAL::disp_backend_t *disp = &disp_stm32;
#endif
