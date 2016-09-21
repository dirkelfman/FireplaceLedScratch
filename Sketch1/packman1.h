/* # Bitmap to RGB8 converter
   # created by S. Schuster, 04.2008 - www.zipfelmaus.com
   # include this file in your AVR project include directory
*/

#define image_width (10)
#define image_height (5)


uint32_t packman1Arr[]=
{
	0xff00001a, 0xff969621, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xff000000, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff00001a, 0xff969621, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a
};

uint32_t packman2Arr[]=
{
	0xff00001a, 0xff969621, 0xffe8e816, 0xffffff00, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xff000000, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xffe8e816, 0xffe8e816, 0xff848423, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xffe8e816, 0xffd1d100, 0xffa5a501, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff00001a, 0xff969621, 0xffe8e816, 0xffa3a300, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a 
};

uint32_t packman3Arr[] =
{
	0xff00001a, 0xff969621, 0xffe8e816, 0xffffff00, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xff000000, 0xffe8e816, 0xffe8e816, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xffe8e816, 0xffe8e816, 0xffd5d509, 0xffd5d509, 0xffd5d509, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff969621, 0xffe8e816, 0xffe8e816, 0xffd1d100, 0xff97970c, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a,
	0xff00001a, 0xff969621, 0xffe8e816, 0xff969621, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a, 0xff00001a 
};

