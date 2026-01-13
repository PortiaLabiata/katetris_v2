#pragma once
#include "env.hpp"
#include "osal_class.hpp"

#if SITL
#include "osal_pc.hpp"
inline OSAL::osal_pc_t osal_pc;
inline OSAL::osal_backend_t *osal = &osal_pc;
#else
#include "osal_stm32.hpp"
inline OSAL::osal_stm32_t osal_stm32;
inline OSAL::osal_backend_t *osal = &osal_stm32;
#endif
