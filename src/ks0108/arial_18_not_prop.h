

/*
 *
 * arial_18_not_prop
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : arial_18_not_prop.h
 * Date                : 15.01.2014
 * Font size in bytes  : 13962
 * Font width          : 10
 * Font height         : 18
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>

#ifndef ARIAL_18_NOT_PROP_H
#define ARIAL_18_NOT_PROP_H

#define ARIAL_18_NOT_PROP_WIDTH 10
#define ARIAL_18_NOT_PROP_HEIGHT 18

static uint8_t arial_18_not_prop[] = {
    0x36, 0x8A, // size
    0x0A, // width
    0x12, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x02, 0x05, 0x0A, 0x09, 0x0E, 0x0B, 0x02, 0x05, 0x05, 
    0x05, 0x0A, 0x02, 0x05, 0x02, 0x05, 0x09, 0x09, 0x09, 0x09, 
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x02, 0x02, 0x09, 0x09, 
    0x09, 0x08, 0x11, 0x0B, 0x0A, 0x0B, 0x0B, 0x0A, 0x09, 0x0C, 
    0x0B, 0x02, 0x07, 0x0B, 0x08, 0x0D, 0x0B, 0x0C, 0x0A, 0x0C, 
    0x0C, 0x0A, 0x0A, 0x0B, 0x0B, 0x11, 0x0B, 0x0C, 0x0A, 0x04, 
    0x05, 0x04, 0x07, 0x0A, 0x03, 0x08, 0x08, 0x07, 0x08, 0x08, 
    0x05, 0x08, 0x08, 0x02, 0x03, 0x08, 0x02, 0x0C, 0x08, 0x08, 
    0x08, 0x08, 0x05, 0x07, 0x04, 0x08, 0x09, 0x0D, 0x08, 0x09, 
    0x08, 0x06, 0x02, 0x06, 0x0A, 0x0A, 
    
    // font data
    0xFE, 0xFE, 0x37, 0x37, 0x00, 0x00, // 33
    0x3E, 0x3E, 0x00, 0x3E, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x30, 0x30, 0xB0, 0xF8, 0xFE, 0x36, 0xB0, 0xF8, 0xFE, 0x36, 0x06, 0x36, 0x3F, 0x0F, 0x06, 0x36, 0x3F, 0x0F, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0x38, 0x7C, 0x66, 0xC6, 0xFF, 0xC6, 0x86, 0x8C, 0x08, 0x0C, 0x1C, 0x38, 0x30, 0xFF, 0x31, 0x39, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 36
    0x7C, 0xFE, 0x82, 0x82, 0xFE, 0x7C, 0xC0, 0xF0, 0x7C, 0x8E, 0x82, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x1E, 0x07, 0x01, 0x1F, 0x3F, 0x20, 0x20, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
    0x00, 0x80, 0xBC, 0xFE, 0xC6, 0xE6, 0x3E, 0x1C, 0x00, 0x00, 0x00, 0x0E, 0x1F, 0x39, 0x30, 0x31, 0x33, 0x1E, 0x1C, 0x1F, 0x33, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
    0x3E, 0x3E, 0x00, 0x00, 0x00, 0x00, // 39
    0xC0, 0xF0, 0x38, 0x04, 0x02, 0x1F, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, // 40
    0x02, 0x04, 0x38, 0xF0, 0xC0, 0x00, 0x00, 0xE0, 0x7F, 0x1F, 0x80, 0x40, 0x00, 0x00, 0x00, // 41
    0x04, 0x34, 0x0E, 0x34, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x80, 0x80, 0x80, 0x80, 0xF8, 0xF8, 0x80, 0x80, 0x80, 0x80, 0x01, 0x01, 0x01, 0x01, 0x1F, 0x1F, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0xB0, 0x70, 0x00, 0x00, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x30, 0x30, 0x00, 0x00, // 46
    0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x30, 0x3E, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xF8, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x00, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 48
    0x30, 0x18, 0x0C, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 49
    0x18, 0x1C, 0x0E, 0x06, 0x06, 0x8E, 0xFC, 0x78, 0x00, 0x30, 0x3C, 0x3C, 0x36, 0x33, 0x31, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 50
    0x08, 0x0C, 0x06, 0xC6, 0xC6, 0xFC, 0xB8, 0x00, 0x00, 0x0C, 0x1C, 0x30, 0x30, 0x30, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 51
    0x00, 0x80, 0xE0, 0x70, 0x1C, 0xFE, 0xFE, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x06, 0x3F, 0x3F, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
    0xF0, 0xFE, 0x4E, 0x66, 0x66, 0x66, 0xC6, 0x80, 0x00, 0x0C, 0x1C, 0x30, 0x30, 0x30, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 53
    0xF0, 0xFC, 0x8E, 0xC6, 0xC6, 0xC6, 0x8C, 0x08, 0x00, 0x07, 0x1F, 0x39, 0x30, 0x30, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 54
    0x06, 0x06, 0x06, 0x86, 0xE6, 0x76, 0x1E, 0x06, 0x00, 0x00, 0x00, 0x3C, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x38, 0xFC, 0xC6, 0xC6, 0xC6, 0xC6, 0xFC, 0x38, 0x00, 0x0F, 0x1F, 0x30, 0x30, 0x30, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 56
    0x78, 0xFC, 0x86, 0x86, 0x86, 0xC6, 0xFC, 0xF8, 0x00, 0x08, 0x18, 0x31, 0x31, 0x31, 0x38, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 57
    0x30, 0x30, 0x30, 0x30, 0x00, 0x00, // 58
    0x30, 0x30, 0xB0, 0x70, 0x00, 0x00, // 59
    0x80, 0xC0, 0x40, 0x60, 0x60, 0x20, 0x30, 0x30, 0x18, 0x00, 0x01, 0x01, 0x03, 0x03, 0x02, 0x06, 0x06, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x18, 0x30, 0x30, 0x20, 0x60, 0x60, 0x40, 0xC0, 0x80, 0x0C, 0x06, 0x06, 0x02, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0x18, 0x1C, 0x0E, 0x06, 0x86, 0xCE, 0x7C, 0x38, 0x00, 0x00, 0x36, 0x37, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0x80, 0xE0, 0x70, 0x18, 0x8C, 0xCC, 0xE6, 0x36, 0x36, 0x76, 0xE6, 0xF6, 0x3C, 0x1C, 0x38, 0xF0, 0xE0, 0x1F, 0x7F, 0xE0, 0xC0, 0x8F, 0xBF, 0x38, 0x30, 0x10, 0x3C, 0x3F, 0x31, 0x30, 0x98, 0xDC, 0xCF, 0x43, 0x00, 0x00, 0x00, 0x40, 0x40, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x40, 0x40, 0x00, 0x00, // 64
    0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x30, 0x3E, 0x0F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0F, 0x3E, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xFC, 0x38, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 66
    0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0C, 0x1C, 0x18, 0x03, 0x0F, 0x1C, 0x18, 0x30, 0x30, 0x30, 0x30, 0x18, 0x1C, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x06, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 69
    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x06, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xE0, 0xF8, 0x1C, 0x0C, 0x06, 0x06, 0x86, 0x86, 0x86, 0x8C, 0x9C, 0x90, 0x03, 0x0F, 0x1C, 0x18, 0x30, 0x30, 0x31, 0x31, 0x31, 0x19, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
    0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
    0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x1C, 0x3C, 0x30, 0x30, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 74
    0xFE, 0xFE, 0xC0, 0xE0, 0xF0, 0xB8, 0x1C, 0x0E, 0x06, 0x02, 0x00, 0x3F, 0x3F, 0x01, 0x00, 0x01, 0x03, 0x0F, 0x1E, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 75
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 76
    0xFE, 0xFE, 0x1E, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xFC, 0x1E, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, 0x0F, 0x3E, 0x30, 0x3E, 0x0F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
    0xFE, 0xFE, 0x1C, 0x38, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0E, 0x1C, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
    0xE0, 0xF8, 0x1C, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xE0, 0x03, 0x0F, 0x1C, 0x18, 0x30, 0x30, 0x30, 0x30, 0x18, 0x1C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
    0xFE, 0xFE, 0x86, 0x86, 0x86, 0x86, 0x86, 0xCE, 0xFC, 0x78, 0x3F, 0x3F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0, 0x03, 0x0F, 0x1C, 0x38, 0x30, 0x30, 0x34, 0x3C, 0x18, 0x3C, 0x27, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xEE, 0x7C, 0x38, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1E, 0x3C, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
    0x38, 0x7C, 0xCC, 0xC6, 0xC6, 0x86, 0x86, 0x8E, 0x1C, 0x18, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0x31, 0x31, 0x39, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 83
    0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0F, 0x1F, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 85
    0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x00, 0x00, 0x01, 0x0F, 0x3E, 0x30, 0x3E, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x06, 0xFE, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0x7E, 0x06, 0x7E, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xFE, 0x06, 0x00, 0x00, 0x0F, 0x3F, 0x30, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x3F, 0x30, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
    0x00, 0x02, 0x06, 0x1E, 0xF8, 0xE0, 0xF8, 0x1E, 0x06, 0x02, 0x00, 0x20, 0x30, 0x3C, 0x0F, 0x07, 0x00, 0x07, 0x0F, 0x3C, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
    0x02, 0x06, 0x1E, 0x38, 0xF0, 0xC0, 0xC0, 0xF0, 0x38, 0x1E, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x06, 0x06, 0x06, 0x86, 0xE6, 0x76, 0x3E, 0x0E, 0x06, 0x30, 0x38, 0x3E, 0x37, 0x33, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 90
    0xFE, 0xFE, 0x06, 0x06, 0xFF, 0xFF, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, // 91
    0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, // 92
    0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, // 93
    0x80, 0xF0, 0x3C, 0x06, 0x3C, 0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, // 95
    0x02, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x40, 0x60, 0x30, 0x30, 0xB0, 0xB0, 0xF0, 0xE0, 0x1E, 0x3F, 0x33, 0x33, 0x31, 0x19, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 97
    0xFE, 0xFE, 0x60, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0x3F, 0x3F, 0x18, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 98
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x70, 0x60, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x38, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 99
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xFE, 0xFE, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x18, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 100
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x70, 0xE0, 0x80, 0x0F, 0x1F, 0x3B, 0x33, 0x33, 0x33, 0x1B, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 101
    0x30, 0xFC, 0xFE, 0x36, 0x36, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 102
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xF0, 0xF0, 0x8F, 0x9F, 0x38, 0x30, 0x30, 0x98, 0xFF, 0xFF, 0x40, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x40, 0x00, // 103
    0xFE, 0xFE, 0x60, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 104
    0xF6, 0xF6, 0x3F, 0x3F, 0x00, 0x00, // 105
    0x00, 0xF6, 0xF6, 0x00, 0xFF, 0xFF, 0xC0, 0xC0, 0x40, // 106
    0xFE, 0xFE, 0x80, 0xC0, 0x60, 0x70, 0x30, 0x10, 0x3F, 0x3F, 0x01, 0x03, 0x0F, 0x3C, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 107
    0xFE, 0xFE, 0x3F, 0x3F, 0x00, 0x00, // 108
    0xF0, 0xF0, 0x60, 0x30, 0x30, 0xF0, 0xC0, 0x60, 0x30, 0x30, 0xF0, 0xE0, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 110
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 111
    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0xFF, 0xFF, 0x18, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 112
    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xF0, 0xF0, 0x0F, 0x1F, 0x38, 0x30, 0x30, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, // 113
    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114
    0xE0, 0xF0, 0xB0, 0x30, 0x30, 0x70, 0x60, 0x18, 0x39, 0x31, 0x33, 0x37, 0x3E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 115
    0x30, 0xFE, 0xFE, 0x30, 0x00, 0x3F, 0x3F, 0x30, 0x00, 0x00, 0x00, 0x00, // 116
    0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x1F, 0x3F, 0x30, 0x30, 0x30, 0x18, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 117
    0x30, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x30, 0x00, 0x01, 0x07, 0x1E, 0x38, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 118
    0x70, 0xF0, 0x80, 0x00, 0x00, 0xE0, 0x70, 0xE0, 0x00, 0x00, 0x80, 0xF0, 0x70, 0x00, 0x03, 0x1F, 0x38, 0x3F, 0x03, 0x00, 0x03, 0x3F, 0x38, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
    0x10, 0x70, 0xE0, 0x80, 0x80, 0xE0, 0x70, 0x10, 0x20, 0x38, 0x1C, 0x07, 0x07, 0x1C, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 120
    0x30, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x30, 0x00, 0x00, 0x03, 0x8F, 0xFC, 0x7E, 0x0F, 0x01, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x40, 0x00, 0x00, 0x00, 0x00, // 121
    0x30, 0x30, 0x30, 0x30, 0xB0, 0xF0, 0xF0, 0x70, 0x38, 0x3C, 0x3E, 0x37, 0x33, 0x31, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 122
    0x00, 0x80, 0xFC, 0xFE, 0x06, 0x06, 0x03, 0x07, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xC0, 0xC0, // 123
    0xFE, 0xFE, 0xFF, 0xFF, 0xC0, 0xC0, // 124
    0x06, 0x06, 0xFE, 0xFC, 0x80, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x07, 0x03, 0xC0, 0xC0, 0xC0, 0x40, 0x00, 0x00, // 125
    0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x3F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 127
    
};

#endif
