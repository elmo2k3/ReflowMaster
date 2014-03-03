#include "settings.h"

struct _settings settings;

void settings_init()
{
    settings.temperature = 20;
    settings.on = 0;
    settings.net.dhcp = 1;
    settings.net.ip1 = 172;
    settings.net.ip2 = 28;
    settings.net.ip3 = 1;
    settings.net.ip4 = 209;
    settings.net.gw1 = 172;
    settings.net.gw2 = 28;
    settings.net.gw3 = 1;
    settings.net.gw4 = 1;
    settings.net.netmask1 = 255;
    settings.net.netmask2 = 255;
    settings.net.netmask3 = 0;
    settings.net.netmask4 = 0;
}
