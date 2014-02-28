#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include <stdint.h>

//code taken from http://www.mikrocontroller.net/articles/Entprellung

#define KEY1    PIO_PA18
#define KEY2    PIO_PA19
#define KEY3    PIO_PA20

#define REPEAT_MASK 0
#define REPEAT_START 50         // 500ms
#define REPEAT_NEXT 20          // 200ms

void buttons_init(void);
void buttons_every_10_ms(void);
uint32_t get_key_press(uint32_t key_mask);
uint32_t get_key_rpt(uint32_t key_mask);

#endif
