/*
 * Copyright:      Fabian Maximilian Thiele  mailto:me@apetech.de
 * Author:         Fabian Maximilian Thiele
 * Remarks:        this Copyright must be included
 * known Problems: none
 * Version:        1.1
 * Description:    Graphic Library for KS0108- (and compatible) based LCDs
 * 
 */

#include "ioport.h"
#include <inttypes.h>
#include "ks0108.h"
#include "Comic_10.h"
#include "arial_bold_12.h"
#include "arial_bold_36.h"
#include "arial_bold_30.h"
#include "arial_18_not_prop.h"
#include "arial_24_not_prop.h"
#include "arial_30_not_prop.h"
#include "arial_24.h"

static lcdCoord		ks0108Coord;
//#define ks0108FontColor BLACK
static uint8_t ks0108FontColor;
static uint8_t *ks0108Font;

void ks0108Enable(void);
uint8_t ks0108DoReadData(uint8_t first);

void ks0108DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color) {
	uint8_t length, i, y, yAlt, xTmp, yTmp;
	int16_t m;
	
	//
	// vertical line
	//
	if(x1 == x2) {
		// x1|y1 must be the upper point
		if(y1 > y2) {
			yTmp = y1;
			y1 = y2;
			y2 = yTmp;
		}
		ks0108DrawVertLine(x1, y1, y2-y1, color);
	
	//
	// horizontal line
	//
	} else if(y1 == y2) {	
		// x1|y1 must be the left point
		if(x1 > x2) {
			xTmp = x1;
			x1 = x2;
			x2 = xTmp;
		}
		ks0108DrawHoriLine(x1, y1, x2-x1, color);
	
	//
	// schiefe line :)
	//
	} else {
		// angle >= 45�
		if((y2-y1) >= (x2-x1) || (y1-y2) >= (x2-x1)) {
			// x1 must be smaller than x2
			if(x1 > x2) {
				xTmp = x1;
				yTmp = y1;
				x1 = x2;
				y1 = y2;
				x2 = xTmp;
				y2 = yTmp;
			}
		
			length = x2-x1;		// not really the length :)
			m = ((y2-y1)*200)/length;
			yAlt = y1;
			
			for(i=0; i<=length; i++) {
				y = ((m*i)/200)+y1;
				
				if((m*i)%200 >= 100)
					y++;
				else if((m*i)%200 <= -100)
					y--;
				
				ks0108DrawLine(x1+i, yAlt, x1+i, y, color);
				
				if(length <= (y2-y1) && y1 < y2)
					yAlt = y+1;
				else if(length <= (y1-y2) && y1 > y2)
					yAlt = y-1;
				else
					yAlt = y;
			}
		
		// angle < 45�
		} else {
			// y1 must be smaller than y2
			if(y1 > y2) {
				xTmp = x1;
				yTmp = y1;
				x1 = x2;
				y1 = y2;
				x2 = xTmp;
				y2 = yTmp;
			}
			
			length = y2-y1;
			m = ((x2-x1)*200)/length;
			yAlt = x1;
			
			for(i=0; i<=length; i++) {
				y = ((m*i)/200)+x1;
				
				if((m*i)%200 >= 100)
					y++;
				else if((m*i)%200 <= -100)
					y--;
				
				ks0108DrawLine(yAlt, y1+i, y, y1+i, color);
				if(length <= (x2-x1) && x1 < x2)
					yAlt = y+1;
				else if(length <= (x1-x2) && x1 > x2)
					yAlt = y-1;
				else
					yAlt = y;
			}
		}
	}
}

void ks0108DrawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color) {
	ks0108DrawHoriLine(x, y, width, color);				// top
	ks0108DrawHoriLine(x, y+height, width, color);		// bottom
	ks0108DrawVertLine(x, y, height, color);			// left
	ks0108DrawVertLine(x+width, y, height, color);		// right
}

void ks0108DrawRoundRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t radius, uint8_t color) {
  	int16_t tSwitch, x1 = 0, y1 = radius;
  	tSwitch = 3 - 2 * radius;
	
	while (x1 <= y1) {
	    ks0108SetDot(x+radius - x1, y+radius - y1, color);
	    ks0108SetDot(x+radius - y1, y+radius - x1, color);

	    ks0108SetDot(x+width-radius + x1, y+radius - y1, color);
	    ks0108SetDot(x+width-radius + y1, y+radius - x1, color);
	    
	    ks0108SetDot(x+width-radius + x1, y+height-radius + y1, color);
	    ks0108SetDot(x+width-radius + y1, y+height-radius + x1, color);

	    ks0108SetDot(x+radius - x1, y+height-radius + y1, color);
	    ks0108SetDot(x+radius - y1, y+height-radius + x1, color);

	    if (tSwitch < 0) {
	    	tSwitch += (4 * x1 + 6);
	    } else {
	    	tSwitch += (4 * (x1 - y1) + 10);
	    	y1--;
	    }
	    x1++;
	}
	  	
	ks0108DrawHoriLine(x+radius, y, width-(2*radius), color);			// top
	ks0108DrawHoriLine(x+radius, y+height, width-(2*radius), color);	// bottom
	ks0108DrawVertLine(x, y+radius, height-(2*radius), color);			// left
	ks0108DrawVertLine(x+width, y+radius, height-(2*radius), color);	// right
}

/*
 * Hardware-Functions 
 */
void ks0108FillRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color) {
	uint8_t mask, pageOffset, h, i, data;
	height++;
	
	pageOffset = y%8;
	y -= pageOffset;
	mask = 0xFF;
	if(height < 8-pageOffset) {
		mask >>= (8-height);
		h = height;
	} else {
		h = 8-pageOffset;
	}
	mask <<= pageOffset;
	
	ks0108GotoXY(x, y);
	for(i=0; i<=width; i++) {
		data = ks0108ReadData();
		
		if(color == BLACK) {
			data |= mask;
		} else {
			data &= ~mask;
		}

		ks0108WriteData(data);
	}
	
	while(h+8 <= height) {
		h += 8;
		y += 8;
		ks0108GotoXY(x, y);
		
		for(i=0; i<=width; i++) {
			ks0108WriteData(color);
		}
	}
	
	if(h < height) {
		mask = ~(0xFF << (height-h));
		ks0108GotoXY(x, y+8);
		
		for(i=0; i<=width; i++) {
			data = ks0108ReadData();
		
			if(color == BLACK) {
				data |= mask;
			} else {
				data &= ~mask;
			}
	
			ks0108WriteData(data);
		}
	}
}

//void ks0108InvertRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
//	uint8_t mask, pageOffset, h, i, data, tmpData;
//	height++;
//	
//	pageOffset = y%8;
//	y -= pageOffset;
//	mask = 0xFF;
//	if(height < 8-pageOffset) {
//		mask >>= (8-height);
//		h = height;
//	} else {
//		h = 8-pageOffset;
//	}
//	mask <<= pageOffset;
//	
//	ks0108GotoXY(x, y);
//	for(i=0; i<=width; i++) {
//		data = ks0108ReadData();
//		tmpData = ~data;
//		data = (tmpData & mask) | (data & ~mask);
//		ks0108WriteData(data);
//	}
//	
//	while(h+8 <= height) {
//		h += 8;
//		y += 8;
//		ks0108GotoXY(x, y);
//		
//		for(i=0; i<=width; i++) {
//			data = ks0108ReadData();
//			ks0108WriteData(~data);
//		}
//	}
//	
//	if(h < height) {
//		mask = ~(0xFF << (height-h));
//		ks0108GotoXY(x, y+8);
//		
//		for(i=0; i<=width; i++) {
//			data = ks0108ReadData();
//			tmpData = ~data;
//			data = (tmpData & mask) | (data & ~mask);
//			ks0108WriteData(data);
//		}
//	}
//}

void ks0108SetDot(uint8_t x, uint8_t y, uint8_t color) {
	uint8_t data;
	
	ks0108GotoXY(x, y-y%8);					// read data from display memory
	data = ks0108ReadData();
	
	if(color == BLACK) {
		data |= 0x01 << (y%8);				// set dot
	} else {
		data &= ~(0x01 << (y%8));			// clear dot
	}
	
	ks0108WriteData(data);					// write data back to display
}

//
// Font Functions
//

uint8_t ks0108ReadFontData(const uint8_t* ptr) {
	return (*ptr);
}

void ks0108SelectFont(uint8_t num, uint8_t color){
	ks0108FontColor = color;
	if(num == 1){
		ks0108Font = Comic_10;
	}else if(num == 2){
		ks0108Font = Arial_Bold_12;
	}else if(num == 3){
		ks0108Font = arial_18_not_prop;
	}else if(num == 4){
		ks0108Font = arial_24_not_prop;
	}else if(num == 5){
		ks0108Font = arial_30_not_prop;
	}
}

//void ks0108SelectFont(uint8_t* font, uint8_t color) {
//	ks0108Font = font;
//	ks0108FontColor = color;
//}

int ks0108PutChar(char c) {
	uint8_t width = 0;
	uint8_t height = ks0108ReadFontData(ks0108Font+FONT_HEIGHT);
	uint8_t bytes = (height+7)/8;
	
	uint8_t firstChar = ks0108ReadFontData(ks0108Font+FONT_FIRST_CHAR);
	uint8_t charCount = ks0108ReadFontData(ks0108Font+FONT_CHAR_COUNT);
	
	uint16_t index = 0;
	uint8_t x = ks0108Coord.x, y = ks0108Coord.y;
	
	if(c == ' ') ks0108Coord.x+=6;
	if(c < firstChar || c >= (firstChar+charCount)) {
		return 1;
	}
	c-= firstChar;
	
	// read width data, to get the index
	for(uint8_t i=0; i<c; i++) {
		index += ks0108ReadFontData(ks0108Font+FONT_WIDTH_TABLE+i);
	}
	index = index*bytes+charCount+FONT_WIDTH_TABLE;
	width = ks0108ReadFontData(ks0108Font+FONT_WIDTH_TABLE+c);
	
	// last but not least, draw the character
	for(uint8_t i=0; i<bytes; i++) {
		uint8_t page = i*width;
		for(uint8_t j=0; j<width; j++) {
			uint8_t data = ks0108ReadFontData(ks0108Font+index+page+j);
			
			if(height < (i+1)*8) {
				data >>= (i+1)*8-height;
			}
			
			if(ks0108FontColor == BLACK) {
				ks0108WriteData(data);
			} else {
				ks0108WriteData(~data);
			}
		}
		// 1px gap between chars
		if(ks0108FontColor == BLACK) {
			ks0108WriteData(0x00);
		} else {
			ks0108WriteData(0xFF);
		}
		ks0108GotoXY(x, ks0108Coord.y+8);
	}
	ks0108GotoXY(x+width+1, y);
	
	return 0;
}

void ks0108Puts(char* str) {
	int x = ks0108Coord.x;
	while(*str != 0) {
		if(*str == '\n') {
			ks0108GotoXY(x, ks0108Coord.y+ks0108ReadFontData(ks0108Font+FONT_HEIGHT));
		} else {
			ks0108PutChar(*str);
		}
		str++;
	}
}

uint8_t ks0108CharWidth(char c) {
	uint8_t width = 0;
	uint8_t firstChar = ks0108ReadFontData(ks0108Font+FONT_FIRST_CHAR);
	uint8_t charCount = ks0108ReadFontData(ks0108Font+FONT_CHAR_COUNT);

	if(c == ' ') return 6;
	// read width data
	if(c >= firstChar && c < (firstChar+charCount)) {
		c -= firstChar;
		width = ks0108ReadFontData(ks0108Font+FONT_WIDTH_TABLE+c)+1;
	}
	
	return width;
}

uint16_t ks0108StringWidth(char* str) {
	uint16_t width = 0;
	
	while(*str != 0) {
		width += ks0108CharWidth(*str++);
	}
	
	return width;
}

void ks0108GotoXY(uint8_t x, uint8_t y) {
	uint8_t chip = CHIP1, cmd;
	
	if(x > 127) x = 0;								// ensure that coordinates are legal
	if(y > 63)  y = 63;
	
	ks0108Coord.x = x;								// save new coordinates
	ks0108Coord.y = y;
	ks0108Coord.page = y/8;
	
	if(x >= 64) {									// select the right chip
		x -= 64;
		chip = CHIP2;
	}
	cmd = LCD_SET_ADD | x;
	ks0108WriteCommand(cmd, chip);					// set x address on active chip
	
	cmd = LCD_SET_PAGE | ks0108Coord.page;			// set y address on both chips
	ks0108WriteCommand(cmd, CHIP1);
	ks0108WriteCommand(cmd, CHIP2);
}

void ks0108Init() {
	ks0108Coord.x = 0;
	ks0108Coord.y = 0;
	ks0108Coord.page = 0;

	ks0108SelectFont(1,BLACK);
	
	ioport_set_pin_dir(D_I,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(EN,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(R_W,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(CSEL1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(CSEL2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(RES_PIN,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(D_I,1);

	_delay_ms(10);
	ioport_set_pin_level(RES_PIN,0);
	_delay_ms(50);
	ioport_set_pin_level(RES_PIN,1);
	_delay_ms(10);
	//LCD_RES_PORT |= (1<<RES_PIN);
	ks0108WriteCommand(LCD_ON, CHIP1);				// power on
	ks0108WriteCommand(LCD_ON, CHIP2);
	
	ks0108WriteCommand(LCD_DISP_START, CHIP1);		// display start line = 0
	ks0108WriteCommand(LCD_DISP_START, CHIP2);
	ks0108ClearScreen();							// display clear
	ks0108GotoXY(0,0);
}

void ks0108Enable() {
	ioport_set_pin_level(EN,1);
	//LCD_CMD_PORT |= 0x01 << EN;						// EN high level width: min. 450ns
	//_delay_us(1);
	for(volatile int i=0;i<5;i++);
	ioport_set_pin_level(EN,0);
	//LCD_CMD_PORT &= ~(0x01 << EN);
	//for(volatile uint8_t i=0; i<24; i++);			// a little delay loop (faster than reading the busy flag)
	_delay_us(1);
}

uint8_t ks0108DoReadData(uint8_t first) {
	uint8_t data;
	
	//LCD_DATA_DIR = 0x00;							// data port is input
	ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_INPUT);
	
	if(ks0108Coord.x < 64) {
		ioport_set_pin_level(CSEL2,0);
		ioport_set_pin_level(CSEL1,1);
		//LCD_CMD_PORT &= ~(0x01 << CSEL2);			// deselect chip 2
		//LCD_CMD_PORT |= 0x01 << CSEL1;				// select chip 1
	} else if(ks0108Coord.x >= 64) {
		ioport_set_pin_level(CSEL2,1);
		ioport_set_pin_level(CSEL1,0);
		//LCD_CMD_PORT &= ~(0x01 << CSEL1);			// deselect chip 1
		//LCD_CMD_PORT |= 0x01 << CSEL2;				// select chip 2
	}
	if(ks0108Coord.x == 64 && first) {				// chip2 X-address = 0
		ks0108WriteCommand(LCD_SET_ADD, CHIP2); 	// wuff wuff
	}
	
	ioport_set_pin_level(D_I,1);
	ioport_set_pin_level(R_W,1);
	//LCD_CMD_PORT |= 0x01 << D_I;					// D/I = 1
	//LCD_CMD_PORT |= 0x01 << R_W;					// R/W = 1
	
	ioport_set_pin_level(EN,1);
	for(volatile int i=0;i<5;i++);
	//LCD_CMD_PORT |= 0x01 << EN;						// EN high level width: min. 450ns
	//_delay_us(1);
	data = ioport_get_port_level(IOPORT_PIOA,0xFF);
	//data = LCD_DATA_IN;								// read Data			 
	
	ioport_set_pin_level(EN,0);
	//LCD_CMD_PORT &= ~(0x01 << EN);
	_delay_us(1);
	//LCD_DATA_DIR = 0xFF;
	ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_OUTPUT);
	
	ks0108GotoXY(ks0108Coord.x, ks0108Coord.y);
	
	return data;
}

uint8_t ks0108ReadData(void) {
	ks0108DoReadData(1);							// dummy read
	return ks0108DoReadData(0);						// "real" read
}

void ks0108WriteCommand(uint8_t cmd, uint8_t chip) {
	if(chip == CHIP1) {
		ioport_set_pin_level(CSEL2,0);
		ioport_set_pin_level(CSEL1,1);
		//LCD_CMD_PORT &= ~(0x01 << CSEL2);			// deselect chip 2
		//LCD_CMD_PORT |= 0x01 << CSEL1;				// select chip 1
	} else if(chip == CHIP2) {
		ioport_set_pin_level(CSEL2,1);
		ioport_set_pin_level(CSEL1,0);
		//LCD_CMD_PORT &= ~(0x01 << CSEL1);			// deselect chip 1
		//LCD_CMD_PORT |= 0x01 << CSEL2;				// select chip 2
	}
	
	ioport_set_pin_level(D_I,0);
	ioport_set_pin_level(R_W,0);
	//LCD_CMD_PORT &= ~(0x01 << D_I);					// D/I = 0
	//LCD_CMD_PORT &= ~(0x01 << R_W);					// R/W = 0
	ioport_set_port_level(IOPORT_PIOA,0xFF,cmd);
	//LCD_DATA_OUT = cmd;								// write command
	//LCD_DATA_DIR = 0xFF;							// data port is output
	ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_OUTPUT);
	ks0108Enable();									// enable
	//LCD_DATA_OUT = 0x00;
}

void ks0108WriteData(uint8_t data) {
	uint8_t displayData, yOffset;
	uint8_t di_temp,rw_temp,csel1_temp,csel2_temp,e_temp;

	if(ks0108Coord.x >= 128)
		return;

	if(ks0108Coord.x < 64) {
		ioport_set_pin_level(CSEL2,0);
		ioport_set_pin_level(CSEL1,1);
		//LCD_CMD_PORT &= ~(0x01 << CSEL2);			// deselect chip 2
		//LCD_CMD_PORT |= 0x01 << CSEL1;				// select chip 1
	} else if(ks0108Coord.x >= 64) {
		ioport_set_pin_level(CSEL2,1);
		ioport_set_pin_level(CSEL1,0);
		//LCD_CMD_PORT &= ~(0x01 << CSEL1);			// deselect chip 1
		//LCD_CMD_PORT |= 0x01 << CSEL2;				// select chip 2
	}
	if(ks0108Coord.x == 64)							// chip2 X-address = 0
		ks0108WriteCommand(LCD_SET_ADD, CHIP2);
	
	ioport_set_pin_level(D_I,1);
	ioport_set_pin_level(R_W,0);
	//LCD_CMD_PORT |= 0x01 << D_I;					// D/I = 1
	//LCD_CMD_PORT &= ~(0x01 << R_W);					// R/W = 0
	ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_OUTPUT);
	//LCD_DATA_DIR = 0xFF;							// data port is output
	
	
	yOffset = ks0108Coord.y%8;
	if(yOffset != 0) {
		// first page
		e_temp = ioport_get_pin_level(EN);
		rw_temp = ioport_get_pin_level(R_W);
		di_temp = ioport_get_pin_level(D_I);
		csel1_temp = ioport_get_pin_level(CSEL1);
		csel2_temp = ioport_get_pin_level(CSEL2);
		//cmdPort = LCD_CMD_PORT;						// save command port
		displayData = ks0108ReadData();

		ioport_set_pin_level(R_W,rw_temp);
		ioport_set_pin_level(D_I,di_temp);
		ioport_set_pin_level(CSEL1,csel1_temp);
		ioport_set_pin_level(CSEL2,csel2_temp);
		
		//if(cmdPort & (1<<R_W)) LCD_CMD_PORT |= (1<<R_W); else LCD_CMD_PORT &= ~(1<<R_W);
		//if(cmdPort & (1<<D_I)) LCD_CMD_PORT |= (1<<D_I); else LCD_CMD_PORT &= ~(1<<D_I);
		//if(cmdPort & (1<<CSEL1)) LCD_CMD_PORT |= (1<<CSEL1); else LCD_CMD_PORT &= ~(1<<CSEL1);
		//if(cmdPort & (1<<CSEL2)) LCD_CMD_PORT |= (1<<CSEL2); else LCD_CMD_PORT &= ~(1<<CSEL2);
		
		ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_OUTPUT);
		//LCD_DATA_DIR = 0xFF;						// data port is output
		
		displayData |= data << yOffset;
		//LCD_DATA_OUT = displayData;					// write data
		ioport_set_port_level(IOPORT_PIOA,0xFF,displayData);
		ks0108Enable();								// enable
		
		// second page
		ks0108GotoXY(ks0108Coord.x, ks0108Coord.y+8);
		
		displayData = ks0108ReadData();
		
		//LCD_CMD_PORT = cmdPort;						// restore command port
		ioport_set_pin_level(EN,e_temp);
		ioport_set_pin_level(R_W,rw_temp);
		ioport_set_pin_level(D_I,di_temp);
		ioport_set_pin_level(CSEL1,csel1_temp);
		ioport_set_pin_level(CSEL2,csel2_temp);
		ioport_set_port_dir(IOPORT_PIOA, 0xFF, IOPORT_DIR_OUTPUT);
		//LCD_DATA_DIR = 0xFF;						// data port is output
		
		displayData |= data >> (8-yOffset);
		ioport_set_port_level(IOPORT_PIOA,0xFF,displayData);
		//LCD_DATA_OUT = displayData;					// write data
		ks0108Enable();								// enable
		
		ks0108GotoXY(ks0108Coord.x+1, ks0108Coord.y-8);
	} else {
		ioport_set_port_level(IOPORT_PIOA,0xFF,data);
		//LCD_DATA_OUT = data;						// write data
		ks0108Enable();								// enable
		ks0108Coord.x++;
	}
	ioport_set_port_level(IOPORT_PIOA,0xFF,0);
	//LCD_DATA_OUT = 0x00;
}
