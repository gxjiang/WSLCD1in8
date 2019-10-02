#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

//data
#define UBYTE   unsigned char
#define UWORD   unsigned int

//Define the full screen height length of the display
#define LCD_WIDTH  160  //LCD width
#define LCD_HEIGHT  128 //LCD height

enum LCD_COLOR {
    WHITE = 0xFFFF,
    BLACK = 0x0000,
    BLUE = 0x001F,
    BRED = 0XF81F,
    GRED = 0XFFE0,
    GBLUE = 0X07FF,
    RED = 0xF800,
    MAGENTA = 0xF81F,
    GREEN = 0x07E0,
    CYAN = 0x7FFF,
    YELLOW = 0xFFE0,
    BROWN = 0XBC40,
    BRRED = 0XFC07,
    GRAY = 0X8430
};

enum DOT_PIXEL{
    DOT_PIXEL_1 = 1,
    DOT_PIXEL_2,
    DOT_PIXEL_3,
    DOT_PIXEL_4
};

enum LINE_STYLE {
    LINE_SOLID = 0,
    LINE_DOTTED,
};

enum DRAW_FILL {
    DRAW_EMPTY = 0,
    DRAW_FULL,
};

class LCD_Driver{
private:
	void LCD_SPI_Init(void);
	void LCD_Reset(void);
	void LCD_InitReg(void);
	
	void LCD_WriteReg(UBYTE Reg);
    void LCD_WriteData_8Bit(UBYTE Data);
    void LCD_WriteData_Buf(UWORD Buf,unsigned long Len);

    void LCD_SetWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend);
    void LCD_SetCursor(UWORD X, UWORD Y);
    void LCD_SetColor(UWORD Color ,UWORD Xnum, UWORD Ynum);
	
	void LCD_SetPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color);
public:
	void LCD_Init(void);
	
	void LCD_SetBL(int Lev);

    void LCD_Clear(UWORD Color);
    void LCD_ClearBuf(void);

    void LCD_Display(void);
    void LCD_DisplayWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend);
    
	void LCD_DrawPoint(int x, int y, int Color, int Dot);
	void LCD_DisChar_1207(int Xchar, int Ychar, int Char_Offset, int Color);
};

static const unsigned char Font12_Table[] = 
{
//"你",                                                //GB_12   24字节一个汉字字模
0x12,0x00,0x12,0x00,0x27,0xF0,0x24,0x20,
      0x69,0x40,0xA1,0x00,0x25,0x40,0x25,0x20,
      0x29,0x10,0x31,0x10,0x25,0x00,0x22,0x00,

//"好", 
0x20,0x00,0x27,0xE0,0x20,0x40,0xF8,0x80,
      0x48,0x80,0x48,0xA0,0x57,0xF0,0x50,0x80,
      0x30,0x80,0x28,0x80,0x4A,0x80,0x81,0x00,

//"江", 
0x40,0x00,0x20,0x40,0x0F,0xF0,0x81,0x00,
      0x51,0x00,0x11,0x00,0x21,0x00,0x21,0x00,
      0xC1,0x00,0x41,0x20,0x5F,0xF0,0x40,0x00,

//"天", 
0x00,0x40,0x7F,0xE0,0x04,0x00,0x04,0x00,
      0xFF,0xF0,0x04,0x00,0x04,0x00,0x06,0x00,
      0x09,0x00,0x10,0x80,0x20,0x70,0xC0,0x20,

//"珩", 
0x02,0x20,0xF5,0xF0,0x28,0x00,0x22,0x20,
      0xF3,0xF0,0x26,0x20,0x2A,0x20,0x22,0x20,
      0x32,0x20,0xC2,0x20,0x02,0x20,0x02,0x60
};

// 汉字表：
// 你好江天珩


#endif



