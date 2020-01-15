#include "stm32f3xx.h"
/* --- Delay based on SysTick ---
 *
 * Vinícius Müller Silveira - https://github.com/Vinimuller - 15/01/2020
 *
 * Perfomance notes of this lib running on stm32f334:
 * SysClock @ 72MHz:
 * - Delay_us(1) results in a 1.9uS delay
 * - Delay_us(5) results in a 5.3uS delay
 * - Delay_ms(1) results in a 1mS delay
 * - Delay_ms(5) results in a 5mS delay
 * SysClock @ 8MHz:
 * - Delay_us(1) results in a 5.3uS delay
 * - Delay_us(5) results in a 7.7uS delay
 * - Delay_us(50) results in a 50.8uS delay
 * - Delay_us(100) results in a 101.5uS delay
 * - Delay_ms(1) results in a 1mS delay
 * - Delay_ms(5) results in a 5mS delay
 */

#define DELAY_TICK_US 1000000   //Divisor factor to find how many ticks fits in 1uS
#define MIN_TICKS 40			//Min ticks that works without overloading the system

//Init SysTick
void delayInit(void);

// Do delay for mSecs milliseconds
void Delay_ms(const uint16_t mSecs);

// Do delay for uSecs microseconds
void Delay_us(const uint16_t uSecs);

static uint8_t dF;
static int32_t ticks;
