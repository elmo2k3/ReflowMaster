#include <stdio.h>
#include "ioport.h"
#include "page_misc.h"
#include "page_main.h"
#include "buttons.h"
#include "drehgeber.h"


#define TICK 0

uint8_t NUM_PAGES;
volatile uint8_t refreshFlags;

int8_t drehgeber_delta;
int8_t menu_position;
int8_t old_menu_position;
uint8_t focus_here;

//#define NUM_PAGES 4
static struct menuitem menu[] = {
//    Page Name | Number | Periodic | Drehgeber | Button | Init page
    {"Reflow Master", 0, update_main, main_drehgeber, main_button_pressed, page_main},
    {"Temperature Curve", 0, update_main, main_drehgeber, main_button_pressed, page_main}
};

void menu_init()
{
    //NUM_PAGES = sizeof(struct menuitem) * sizeof(menu);
    NUM_PAGES = 2;

    page_main_settings_init();
    
    draw_page_header(&menu[menu_position]);
    menu[menu_position].draw_func(&menu[menu_position]);
    focus_here = 1;

}

void menu_tick()
{
    refreshFlags |= (1 << TICK);
}

void menu_task()
{
    if ((drehgeber_delta = drehgeber_read())) {     // Drehgeber in action
        if (focus_here) {
            menu_position += drehgeber_delta;
            if (menu_position > (NUM_PAGES - 1))
                menu_position = NUM_PAGES - 1;
            if (menu_position < 0)
                menu_position = 0;
            if (menu_position != old_menu_position) {
                if (menu[menu_position].draw_func) {
                    menu[menu_position].draw_func(&menu
                                                  [menu_position]);
                }
                draw_page_header(&menu[menu_position]);
                old_menu_position = menu_position;
            }
        } else {
            if (menu[menu_position].drehgeber_func) {
                menu[menu_position].drehgeber_func(&menu
                                                   [menu_position],
                                                   drehgeber_delta);
            }
        }
    }
    if (get_key_press(KEY1)) { //button left +1
        if (menu[menu_position].taster_func) {
            focus_here =
                menu[menu_position].taster_func(&menu[menu_position],
                                                1);
        }
    }
    if (get_key_press(KEY2)) { //button right -1
        if (menu[menu_position].taster_func) {
            focus_here =
                menu[menu_position].taster_func(&menu[menu_position],
                                                2);
        }
    }
    if (get_key_press(KEY3)) { //button encoder
        if (menu[menu_position].taster_func) {
            focus_here =
                menu[menu_position].taster_func(&menu[menu_position],
                                                3);
        }
    }
    if (refreshFlags & (1 << TICK)) {
        if (menu[menu_position].refresh_func) {
            menu[menu_position].refresh_func(&menu[menu_position],
                                             TICK);
        }
        refreshFlags &= ~(1 << TICK);
    }
}
