#include "buttons.h"
#include "ioport.h"

//code taken from http://www.mikrocontroller.net/articles/Entprellung
//
static volatile uint32_t key_state;
static volatile uint32_t key_press;
static volatile uint32_t key_rpt;

static volatile uint8_t lock;

void buttons_init()
{
    ioport_set_port_dir(IOPORT_PIOA,KEY1|KEY2|KEY3, IOPORT_DIR_INPUT);
    ioport_set_port_mode(IOPORT_PIOA,KEY1|KEY2|KEY3, IOPORT_MODE_PULLUP | IOPORT_MODE_DEBOUNCE);
}

void buttons_every_10_ms()
{
    static uint32_t ct0, ct1, rpt;
    uint32_t i;

    i = key_state ^ ~ioport_get_port_level(IOPORT_PIOA,KEY1|KEY2|KEY3);
    ct0 = ~(ct0 & i);
    ct1 = ct0 ^ (ct1 & i);
    i &= ct0 & ct1;
    key_state ^= i;
    key_press |= key_state & i;

    if ((key_state & REPEAT_MASK) == 0) {
        rpt = REPEAT_START;
    }
    if (--rpt == 0) {
        rpt = REPEAT_NEXT;
        key_rpt |= key_state & REPEAT_MASK;
    }
}

///////////////////////////////////////////////////////////////////
//
// check if a key has been pressed. Each pressed key is reported
// only once
//
uint32_t get_key_press(uint32_t key_mask)
{
    lock = 1;
    key_mask &= key_press;      // read key(s)
    key_press ^= key_mask;      // clear key(s)
    lock = 0;
    return key_mask;
}

///////////////////////////////////////////////////////////////////
//
// check if a key has been pressed long enough such that the
// key repeat functionality kicks in. After a small setup delay
// the key is reported beeing pressed in subsequent calls
// to this function. This simulates the user repeatedly
// pressing and releasing the key.
//
uint32_t get_key_rpt(uint32_t key_mask)
{
    lock = 1;
    key_mask &= key_rpt;        // read key(s)
    key_rpt ^= key_mask;        // clear key(s)
    lock = 0;
    return key_mask;
}
