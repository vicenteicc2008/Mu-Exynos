#ifndef _PLATFORM_UTILS_H_
#define _PLATFORM_UTILS_H_

#define TLMM_ADDR 0x0F100000

#define TLMM_ADDR_OFFSET_FOR_PIN(x) (0x1000 * x)

#define TLMM_PIN_CONTROL_REGISTER 0
#define TLMM_PIN_IO_REGISTER 4
#define TLMM_PIN_INTERRUPT_CONFIG_REGISTER 8
#define TLMM_PIN_INTERRUPT_STATUS_REGISTER 0xC
#define TLMM_PIN_INTERRUPT_TARGET_REGISTER TLMM_PIN_INTERRUPT_CONFIG_REGISTER

#define LID0_GPIO38_STATUS_ADDR                                               \
  (TLMM_ADDR + TLMM_ADDR_OFFSET_FOR_PIN(38) + TLMM_PIN_IO_REGISTER)

#endif /* _PLATFORM_UTILS_H_ */