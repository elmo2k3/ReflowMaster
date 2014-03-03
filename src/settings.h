#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <stdint.h>

struct _network_settings{
    uint8_t dhcp;
    uint8_t ip1;
    uint8_t ip2;
    uint8_t ip3;
    uint8_t ip4;
    uint8_t netmask1;
    uint8_t netmask2;
    uint8_t netmask3;
    uint8_t netmask4;
    uint8_t gw1;
    uint8_t gw2;
    uint8_t gw3;
    uint8_t gw4;
};

struct _settings{
    int32_t temperature;
    int32_t on;
    struct _network_settings net;
};

extern struct _settings settings;

void settings_init(void);

#endif

