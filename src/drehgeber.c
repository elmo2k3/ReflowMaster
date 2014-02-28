// code taken from http://www.mikrocontroller.net/articles/Drehgeber
#include "drehgeber.h"

#define DYNAMIK 5

static volatile int16_t enc_delta;      // -128 ... 127
static volatile int8_t last;

static volatile uint8_t lock;

void drehgeber_init(void)
{
    int8_t new;

    ioport_set_pin_dir(DREHGEBER_A, IOPORT_DIR_INPUT);
    ioport_set_pin_mode(DREHGEBER_A, IOPORT_MODE_PULLUP );
    ioport_set_pin_dir(DREHGEBER_B, IOPORT_DIR_INPUT);
    ioport_set_pin_mode(DREHGEBER_B, IOPORT_MODE_PULLUP );

    new = 0;
    if (PHASE_A)
        new = 3;
    if (PHASE_B)
        new ^= 1;               // convert gray to binary
    last = new;                 // power on state
    enc_delta = 0;
}

void drehgeber_work()           //call every 1ms
{
    static char enc_state = 0x01;
    static uint16_t enc_accel = 0;
    signed short ed;
    char i = 0;

    if(lock) return;

    if (enc_accel > 0)
        enc_accel--;

    if (PHASE_A)
        i = 1;
    if (PHASE_B)
        i ^= 3;                 // convert gray to binary
    i -= enc_state;             // difference new - last
    if (i & 1) {                // bit 0 = value (1)
        ed = enc_delta;
        if (enc_accel < (255 - DYNAMIK))
            enc_accel += DYNAMIK;
        enc_state += i;         // store new as next last
        if (i & 2)
            ed += 1 + (enc_accel >> 6); // bit 1 = direction (+/-)
        else
            ed -= 1 + (enc_accel >> 6);
        enc_delta = ed;
    }
}

int8_t drehgeber_read(void)     // read four step encoders
{
    int16_t val;
    
    lock = 1;
    val = enc_delta;
    enc_delta = val & 3;
    lock = 0;
    return (int8_t) (val >> 2);
}
