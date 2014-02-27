

/*
 *
 * Arial_24
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Arial_24.h
 * Date                : 28.08.2008
 * Font size in bytes  : 23670
 * Font width          : 10
 * Font height         : 24
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

#ifndef ARIAL_24_H
#define ARIAL_24_H

#define ARIAL_24_WIDTH 10
#define ARIAL_24_HEIGHT 24

static const uint8_t Arial_24[] = {
    0x5C, 0x76, // size
    0x0A, // width
    0x18, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x02, 0x06, 0x0D, 0x0B, 0x13, 0x0E, 0x02, 0x06, 0x06, 
    0x08, 0x0C, 0x02, 0x07, 0x02, 0x07, 0x0B, 0x06, 0x0B, 0x0B, 
    0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x02, 0x02, 0x0B, 0x0B, 
    0x0B, 0x0B, 0x16, 0x0F, 0x0D, 0x0F, 0x0E, 0x0D, 0x0C, 0x10, 
    0x0D, 0x02, 0x09, 0x0E, 0x0A, 0x0F, 0x0D, 0x11, 0x0D, 0x11, 
    0x0E, 0x0E, 0x0E, 0x0D, 0x0F, 0x17, 0x0F, 0x10, 0x0E, 0x04, 
    0x07, 0x04, 0x0A, 0x0D, 0x04, 0x0B, 0x0B, 0x0A, 0x0B, 0x0B, 
    0x07, 0x0B, 0x0A, 0x02, 0x04, 0x0A, 0x02, 0x10, 0x0A, 0x0B, 
    0x0B, 0x0B, 0x06, 0x0A, 0x07, 0x0A, 0x0B, 0x11, 0x0B, 0x0A, 
    0x0A, 0x06, 0x02, 0x06, 0x0C, 0x0C, 
    
    // font data
    0xFE, 0xFE, 0x3F, 0x3F, 0x03, 0x03, // 33
    0x7E, 0x7E, 0x00, 0x00, 0x7E, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0xC0, 0xC0, 0xC0, 0xC0, 0xF8, 0xFE, 0xC6, 0xC0, 0xC0, 0xF8, 0xFE, 0xC6, 0xC0, 0x30, 0x30, 0xF0, 0xFF, 0x3F, 0x30, 0x30, 0xF0, 0xFF, 0x3F, 0x30, 0x30, 0x30, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0x78, 0xFC, 0x8C, 0x86, 0x06, 0xFF, 0x06, 0x06, 0x0C, 0x1C, 0x10, 0x60, 0xE0, 0xC1, 0x01, 0x03, 0xFF, 0x03, 0x06, 0x86, 0xFC, 0x78, 0x00, 0x01, 0x01, 0x03, 0x03, 0x0F, 0x03, 0x03, 0x01, 0x01, 0x00, // 36
    0xF8, 0xFC, 0x06, 0x02, 0x02, 0x06, 0xFC, 0xF8, 0x00, 0x00, 0xC0, 0xF0, 0x3C, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x02, 0x83, 0xE1, 0xF8, 0x3C, 0x0F, 0x03, 0xF8, 0xFC, 0x06, 0x02, 0x02, 0x06, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00, // 37
    0x00, 0x00, 0x38, 0xFC, 0xCE, 0x86, 0x86, 0xCE, 0xFC, 0x38, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xCE, 0x07, 0x03, 0x03, 0x07, 0x8E, 0xB8, 0xF0, 0xF0, 0xFC, 0x88, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x03, 0x03, 0x01, // 38
    0x7E, 0x7E, 0x00, 0x00, 0x00, 0x00, // 39
    0x00, 0xE0, 0xF8, 0x1C, 0x06, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1F, 0x38, 0x60, 0x40, // 40
    0x02, 0x06, 0x1C, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x40, 0x60, 0x38, 0x1F, 0x07, 0x00, // 41
    0x08, 0x48, 0xF8, 0x3E, 0x3E, 0xF8, 0x48, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x00, 0x33, 0x1F, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 46
    0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x00, 0xE0, 0xFE, 0x1F, 0x03, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xE0, 0x3F, 0xFF, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xFF, 0x3F, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 48
    0x60, 0x70, 0x30, 0x18, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 49
    0x30, 0x3C, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0x00, 0x80, 0xC0, 0x60, 0x30, 0x38, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // 50
    0x10, 0x1C, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x8C, 0xFC, 0x78, 0x00, 0x60, 0xE0, 0x80, 0x00, 0x03, 0x03, 0x03, 0x03, 0x86, 0xFC, 0x78, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 51
    0x00, 0x00, 0x00, 0xC0, 0xE0, 0x78, 0x1C, 0xFE, 0xFE, 0x00, 0x00, 0x38, 0x3C, 0x3F, 0x33, 0x30, 0x30, 0x30, 0xFF, 0xFF, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, // 52
    0x00, 0xF8, 0xFE, 0x86, 0xC6, 0xC6, 0xC6, 0xC6, 0x86, 0x06, 0x00, 0x63, 0xE3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0xFF, 0x3E, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 53
    0xC0, 0xF8, 0x3C, 0x0C, 0x86, 0x86, 0x86, 0x86, 0x0E, 0x1C, 0x18, 0x3F, 0xFF, 0xC6, 0x83, 0x01, 0x01, 0x01, 0x01, 0x83, 0xFF, 0x7C, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 54
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0xE6, 0x36, 0x1E, 0x06, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x00, 0x78, 0xFC, 0x8E, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0x78, 0x00, 0x78, 0xFC, 0x86, 0x03, 0x03, 0x03, 0x03, 0x03, 0x86, 0xFC, 0x78, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, // 56
    0xF0, 0xF8, 0x1C, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1C, 0xF8, 0xE0, 0xC1, 0xC7, 0x86, 0x0C, 0x0C, 0x0C, 0x0C, 0x86, 0xE3, 0xFF, 0x1F, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, // 57
    0x60, 0x60, 0x00, 0x00, 0x03, 0x03, // 58
    0x60, 0x60, 0x00, 0x00, 0x33, 0x1F, // 59
    0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0x40, 0x60, 0x60, 0x30, 0x02, 0x07, 0x05, 0x0D, 0x0D, 0x08, 0x18, 0x10, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x30, 0x60, 0x60, 0x40, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x60, 0x30, 0x30, 0x10, 0x18, 0x18, 0x0D, 0x0D, 0x05, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0x30, 0x38, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x0E, 0x8C, 0xFC, 0x70, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3C, 0x0E, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0x00, 0x80, 0xE0, 0x70, 0x38, 0x1C, 0x8C, 0xCC, 0xE6, 0x66, 0x66, 0x66, 0xC6, 0x86, 0xEE, 0xEC, 0x1C, 0x38, 0x70, 0xE0, 0x80, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x7C, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xFF, 0x1F, 0x00, 0x80, 0xC0, 0xF0, 0x7F, 0x1F, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x18, 0x39, 0x31, 0x33, 0x63, 0x63, 0x61, 0x61, 0x61, 0x63, 0x63, 0x63, 0x31, 0x31, 0x18, 0x18, 0x0C, 0x04, // 64
    0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x3E, 0x06, 0x3E, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x3F, 0x1F, 0x19, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x3F, 0xF8, 0xE0, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 65
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8C, 0xFC, 0x78, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x8F, 0xFC, 0x78, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, // 66
    0xC0, 0xF0, 0x78, 0x1C, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0C, 0x1C, 0x38, 0x20, 0x1F, 0x7F, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0x30, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, // 67
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0x38, 0xF0, 0xC0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x7F, 0x1F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, // 68
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // 69
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xC0, 0xF0, 0x78, 0x1C, 0x0C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x0C, 0x1C, 0x38, 0x20, 0x1F, 0x7F, 0xF0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x06, 0x06, 0x86, 0x86, 0x86, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, // 71
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 72
    0xFE, 0xFE, 0xFF, 0xFF, 0x03, 0x03, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, // 74
    0xFE, 0xFE, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x06, 0x02, 0x00, 0xFF, 0xFF, 0x0E, 0x07, 0x03, 0x07, 0x0F, 0x1E, 0x78, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x02, // 75
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // 76
    0xFE, 0xFE, 0x1E, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFC, 0x1E, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x7E, 0xF0, 0x00, 0xF0, 0x7E, 0x0F, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 77
    0xFE, 0xFE, 0x1C, 0x38, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1E, 0x38, 0xE0, 0xC0, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, // 78
    0xC0, 0xF0, 0x78, 0x1C, 0x0C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x0C, 0x1C, 0x78, 0xF0, 0x80, 0x1F, 0x7F, 0xF0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xF0, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, // 79
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0xFF, 0xFF, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xC0, 0xF0, 0x78, 0x1C, 0x0C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x0C, 0x1C, 0x78, 0xF0, 0xC0, 0x1F, 0x7F, 0xF0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x60, 0x60, 0xC0, 0xC0, 0xC0, 0xF0, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x07, 0x06, // 81
    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x8E, 0xFC, 0xF8, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0F, 0x3F, 0x7B, 0xF1, 0xC1, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x02, // 82
    0x00, 0x70, 0xFC, 0x8C, 0x86, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0C, 0x1C, 0x38, 0x30, 0x30, 0xF0, 0xC1, 0x81, 0x83, 0x03, 0x03, 0x03, 0x03, 0x07, 0x86, 0xCE, 0xFC, 0x78, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, // 83
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x3F, 0xFF, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xFF, 0x7F, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 85
    0x02, 0x1E, 0xFC, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFC, 0x1E, 0x02, 0x00, 0x00, 0x00, 0x03, 0x1F, 0xFC, 0xE0, 0x80, 0xE0, 0xFC, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x06, 0x7E, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF8, 0x7E, 0x06, 0x00, 0x00, 0x0F, 0xFF, 0xF8, 0x00, 0xF0, 0xFE, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x01, 0x1F, 0xFE, 0xF0, 0x00, 0xF8, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, // 87
    0x00, 0x02, 0x06, 0x1E, 0x3C, 0x70, 0xE0, 0x80, 0xE0, 0xF8, 0x3C, 0x1E, 0x06, 0x02, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF8, 0x3C, 0x1F, 0x03, 0x1F, 0x3C, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0x02, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x02, // 88
    0x02, 0x06, 0x0E, 0x38, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0xC0, 0xE0, 0x78, 0x3C, 0x1E, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xFF, 0xFF, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0xC6, 0xE6, 0x76, 0x1E, 0x0E, 0x06, 0x00, 0x80, 0xC0, 0x70, 0x38, 0x1C, 0x0E, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // 90
    0xFE, 0xFE, 0x06, 0x06, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0x7F, 0x60, 0x60, // 91
    0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1F, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 92
    0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x60, 0x60, 0x7F, 0x7F, // 93
    0x00, 0x80, 0xF0, 0x7C, 0x0E, 0x0E, 0x7C, 0xF0, 0x80, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, // 95
    0x02, 0x06, 0x0E, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x80, 0xC0, 0xC0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0xE1, 0xF1, 0x98, 0x18, 0x18, 0x0C, 0x8C, 0xCC, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x03, 0x02, // 97
    0xFE, 0xFE, 0x80, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0x3E, 0x03, 0x03, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 98
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x7F, 0xFF, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xC1, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, // 99
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xC0, 0x80, 0xFE, 0xFE, 0x3E, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x03, 0x03, // 100
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x7F, 0xFF, 0xCC, 0x8C, 0x0C, 0x0C, 0x0C, 0x8C, 0x8D, 0xCF, 0x4F, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 101
    0x60, 0x60, 0xFC, 0xFE, 0x66, 0x66, 0x66, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, // 102
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xC0, 0x80, 0xE0, 0xE0, 0x3E, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0xFF, 0x18, 0x38, 0x71, 0x63, 0x63, 0x63, 0x63, 0x71, 0x38, 0x3F, 0x0F, // 103
    0xFE, 0xFE, 0x80, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 104
    0xE6, 0xE6, 0xFF, 0xFF, 0x03, 0x03, // 105
    0x00, 0x00, 0xE6, 0xE6, 0x00, 0x00, 0xFF, 0xFF, 0x60, 0x60, 0x7F, 0x3F, // 106
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60, 0x20, 0x00, 0xFF, 0xFF, 0x0C, 0x0E, 0x1F, 0x79, 0xE0, 0xC0, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, // 107
    0xFE, 0xFE, 0xFF, 0xFF, 0x03, 0x03, // 108
    0xE0, 0xE0, 0xC0, 0x40, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 109
    0xE0, 0xE0, 0x80, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, // 110
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x7F, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0x7F, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 111
    0xE0, 0xE0, 0x80, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0x3E, 0x7F, 0x7F, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, // 112
    0x00, 0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xC0, 0x80, 0xE0, 0xE0, 0x3F, 0xFF, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x7F, 0x7F, // 113
    0xE0, 0xE0, 0xC0, 0x60, 0x60, 0x60, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, // 114
    0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xC0, 0x80, 0xC3, 0xC7, 0x8E, 0x0C, 0x0C, 0x1C, 0x1C, 0x98, 0xF9, 0xF1, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, // 115
    0x60, 0x60, 0xFC, 0xFE, 0x60, 0x60, 0x60, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, // 116
    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xFF, 0xFF, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x03, 0x03, // 117
    0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x60, 0x00, 0x03, 0x0F, 0x7C, 0xF0, 0x80, 0xF0, 0x7C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, // 118
    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x07, 0x3F, 0xF8, 0x80, 0xF8, 0x3E, 0x07, 0x00, 0x07, 0x3E, 0xF8, 0x80, 0xF8, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, // 119
    0x20, 0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x20, 0x00, 0x00, 0xC1, 0xE3, 0x7F, 0x1C, 0x7E, 0xE3, 0xC1, 0x00, 0x00, 0x02, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, // 120
    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x60, 0x00, 0x07, 0x1F, 0xF8, 0xE0, 0xC0, 0xFC, 0x3F, 0x07, 0x00, 0x00, 0x60, 0x60, 0x70, 0x3F, 0x0F, 0x01, 0x00, 0x00, 0x00, // 121
    0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0, 0x60, 0x00, 0xC0, 0xE0, 0x70, 0x3C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // 122
    0x00, 0x00, 0xFC, 0xFE, 0x06, 0x06, 0x18, 0x3C, 0xE7, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x7F, 0x60, 0x60, // 123
    0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, // 124
    0x06, 0x06, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xF7, 0x3C, 0x18, 0x60, 0x60, 0x7F, 0x3F, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x03, 0x03, 0x03, 0x06, 0x06, 0x0C, 0x0C, 0x0C, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03 // 127
    
};

#endif
