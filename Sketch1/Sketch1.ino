/*
 Name:		Sketch1.ino
 Created:	9/19/2016 6:57:54 AM
 Author:	user
*/

// the setup function runs once when you press reset or power the board
#include <Adafruit_WS2801.h>
#include <Arduino.h>
#include "packman1.h"
#include <math.h>
#include "Numbers.h"
#include <TimeLib.h>



/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels!


Designed specifically to work with the Adafruit RGB Pixels!
12mm Bullet shape ----> https://www.adafruit.com/products/322
12mm Flat shape   ----> https://www.adafruit.com/products/738
36mm Square shape ----> https://www.adafruit.com/products/683

These pixels use SPI to transmit the color data, and have built in
high speed PWM drivers for 24 bit color per pixel
2 pins are required to interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by David Kavanagh (dkavanagh@gmail.com).
BSD license, all text above must be included in any redistribution

*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
uint8_t dataPin = 11;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 13;    // Green wire on Adafruit Pixels

uint8_t width = 10;
uint8_t height = 5;

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801((uint16_t)width, (uint16_t)height, dataPin, clockPin, (uint8_t)0U);

void setup() {

	strip.begin();
	setTime(12, 39, 0, 12, 12, 2016);
	randomSeed(analogRead(0));
	// Update LED contents, to start they are all 'off'
	strip.show();
}


void loop() {
	// Some example procedures showing how to display to the pixels
	//drawX(7, 7, 100);
	// bounce(7, 6, 50);

	//bing2(70);
	packman(200);
	//bing(70);

	DrawTime(250);

	//DrawTime(200);
	//DrawTime(200);
	//packman(200);
	//DrawTime(2000);
	bing(70);
}

void DrawTime(int pause)
{
	Serial.println("hello");

	int i, bgColor, wheelPos, x, step, dir = 1, y = -1, bump;
	step = 5;
	wheelPos = random(0, 255);


	int offset = 0;
	int h = hourFormat12();
	int m = minute();

	Serial.print(h);





	int h1 = h / 10;
	int h2 = h % 10;
	int m1 = m / 10;
	int m2 = m % 10;



	for (int shift = width-1 ; ; shift--)
	{
		offset = 0;
		Serial.print("i=");
		Serial.print(i);

		for (int i = 0; i < width*height; i++)
		{
			bgColor = Wheel(random(10) + 120);
			strip.setPixelColor(i, bgColor);
		}

		if (h1 > 0)
		{
			offset += WriteNumberImage(h1, offset + shift);
		}
		offset += WriteNumberImage(h2, offset + shift);
		offset += WriteNumberImage(-1, offset + shift);

		offset += WriteNumberImage(m1, offset + shift);
		offset += WriteNumberImage(m2, offset + shift);
		strip.show();


		delay(pause);
		if (offset + shift < 2)
		{
			break;
		}
	}
}

int widthOfNumber(int num)
{
	return  (num == 1|| num == -1) ? 1 : 3;
}
void packman(uint8_t wait)
{
	int offset;
	//for (int i = 0; i < 10; i++)
	//{
		for (int j = -5; j < 12; j++)
		{
			
			ImageArray( packman1Arr, j);
			Dot(j);
			strip.show();
			delay(wait);
			ImageArray( packman2Arr, j);
			Dot(j);
			strip.show();
			delay(wait);
			ImageArray( packman3Arr, j );
			Dot(j+1);
			strip.show();
			delay(wait);
			ImageArray( packman2Arr, j);
			Dot(j+1);
			strip.show();
			delay(wait);
		}
	//}

}


void Dot(int offset)
{

	int y = height / 2 , x = 0;
	
	for (x = (offset + 4); x < width; x += 1)
	{
		if (x % 2 ==1)
		{
			strip.setPixelColor(x, y, 0xccccff);
		}
	}
	
	
}


int WriteNumberImage(int number, int offset)
{
	boolean* image = getNumberImage(number);
	int iwidth = widthOfNumber(number);
	
	int x, y,  wheelPos = random(0, 255), step = 1;
	

	Serial.print(" n=");
	//Serial.print(sizeof(&image));
	Serial.print(number);
	Serial.print(" W=");
	//Serial.print(sizeof(&image));
	Serial.print(iwidth);

	Serial.print(" o=");
	//Serial.print(sizeof(&image));
	Serial.print(offset);

	Serial.println();

	for (int i =0 ; i < height* iwidth; i ++)
	{
		bool b = image[i];
		y = i / iwidth;
		x = i % iwidth + offset;
		

		/*Serial.print(" x=");
		Serial.print(x);
		Serial.print(" y=");
		Serial.print(y);
		Serial.print(" b=");
		Serial.print(b);
		Serial.println();*/
		if (!b)
		{
			continue;
		}

		

		wheelPos += step;
		
		if (x < 0 || x >= width)
		{
			continue;
		}

		strip.setPixelColor(x, y, Wheel((wheelPos%20)+260));
		//strip.setPixelColor(x, y, 0);

	}


	return iwidth + 1;

	

}
void ImageArray( uint32_t *image, int offset)
{
	int x, y, dot = 0;
	uint32_t c;
	for (int i = 0; i < width*height; i++)
	{
		strip.setPixelColor(i, 0x00001a);
	}

	for (int i = 0; i < width*height; i++)
	{
		y = i / width;
		x = i % width + offset;
		
		
		c = image[i];
	
		if (x >= 0 && x < width )
		{
			strip.setPixelColor(x, y, c);
		}

		
		
	}
	//strip.show();
	
}

void bing2(uint8_t wait)
{
	int i, col, wheelPos, x, step, dir = 1, y = -1, bump;
	step = 1;
	wheelPos = random(0, 255);
	for (i = 100; i > 0; i--)
	{

		if (y==-1)
		{
			dir = 1;
		}
		else if (y == height)
		{
			dir = -1;
		}


		y = y + dir;
		//y = i%height;
		wheelPos = wheelPos + step;
		for (x = 0; x < width; x++)
		{
			strip.setPixelColor(x, y, Wheel(wheelPos-2*x*step));
		}

		strip.show();
		delay(wait);
		



	}
}

uint8_t writeNum(uint8_t, int num)
{
	return 0;
}

void bing(uint8_t wait)
{
	int i, col, wheelPos, y, step;
	step = 10;
	for( i =0; i < 50; i++)
	{
		
		wheelPos = random(0, 255);
		col = random(0, width);

		if (i % 2) {


			for (y = height; y >= 0; y--)
			{
				wheelPos = wheelPos + step;
				strip.setPixelColor(col, y, Wheel(wheelPos));
				strip.show();
				delay(wait);
			}
		}
		else {

			//wheelPos = random(0, 255);

			for (y = 0; y < height; y++)
			{
				wheelPos = wheelPos + step;
				strip.setPixelColor(col, y, Wheel(wheelPos));
				strip.show();
				delay(wait / 3);

			}
		}


	}

}

//class MatrixCell {
//	int height;
//};
//
//void matrix(uint8_t wait)
//{
//	int i, col, wheelPos, y, step;
//	step = 10;
//
//
//	for (i = 0; i < 50; i++)
//	{
//
//		wheelPos = random(0, 255);
//		col = random(0, width);
//
//		if (i % 2) {
//
//
//			for (y = height; y >= 0; y--)
//			{
//				wheelPos = wheelPos + step;
//				strip.setPixelColor(col, y, Wheel(wheelPos));
//				strip.show();
//				delay(wait);
//			}
//		}
//		else {
//
//			//wheelPos = random(0, 255);
//
//			for (y = 0; y < height; y++)
//			{
//				wheelPos = wheelPos + step;
//				strip.setPixelColor(col, y, Wheel(wheelPos));
//				strip.show();
//				delay(wait / 3);
//
//			}
//		}
//
//
//	}
//
//}

void drawX(uint8_t w, uint8_t h, uint8_t wait) {
	uint16_t x, y;
	for (x = 0; x < w; x++) {
		strip.setPixelColor(x, x, 255, 0, 0);
		
		strip.show();
		delay(wait);
	}
	for (y = 0; y < h; y++) {
		strip.setPixelColor(w - 1 - y, y, 0, 0, 255);
		strip.show();
		delay(wait);
	}

}

void bounce(uint8_t w, uint8_t h, uint8_t wait) {
	int16_t x = 1;
	int16_t y = 2;
	int8_t xdir = +1;
	int8_t ydir = -1;
	int j;
	for (j = 0; j < 256; j++) {
		x = x + xdir;
		y = y + ydir;
		
		if (x < 0) {
			x = -x;
			xdir = -xdir;
		}
		if (y < 0) {
			y = -y;
			ydir = -ydir;
		}
		if (x == w) {
			x = w - 2;
			xdir = -xdir;
		}
		if (y == h) {
			y = h - 2;
			ydir = -ydir;
		}
		strip.setPixelColor(x, y, Wheel(j));
		strip.show();
		delay(wait);
		strip.setPixelColor(x, y, 0, 0, 0);
	}
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
	if (WheelPos < 85) {
		return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	else if (WheelPos < 170) {
		WheelPos -= 85;
		return Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	else {
		WheelPos -= 170;
		return Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
}