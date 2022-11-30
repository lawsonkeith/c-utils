/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define NANO_FIXED 1
#define NANO_NORMAL 0
#define SUPERFIXED 0 // print + on positive numbers

void nano_s8_print (char i,char fixed);
void nano_s16_print (short int i,char fixed);
void nano_s32_print ( int i,char fixed);

void nano_u8_print (unsigned char i,char fixed);
void nano_u16_print (unsigned short int i,char fixed);
void nano_u32_print (unsigned  int i,char fixed);
void nano_newline(void);

int
main ()
{
 

  nano_s16_print (0xffff,NANO_FIXED);
  nano_newline();
  nano_s16_print (0xffff,NANO_NORMAL);
  nano_newline();
  
  nano_u16_print (0xffff,NANO_FIXED);
  nano_newline();
  nano_u16_print (0xffff,NANO_NORMAL);
  nano_newline();
  
  return 0;
}

void nano_newline(void)
{
    putchar ('\n');
}


void
nano_s8_print (char i,char fixed)
{
  char divisor = 100; // 3 digits
  char num;
  
  if (i < 0)
  {
    putchar ('-');
    i *= -1;
  }
  #if SUPERFIXED == 1
  else
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}

void
nano_u8_print (unsigned char i,char fixed)
{
  unsigned char divisor = 100; // 3 digits
  unsigned char num;
  
  #if SUPERFIXED == 1
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}

void
nano_s16_print (short int i,char fixed)
{
  short int divisor = 10000; // 5 digits
  short int num;
  
  if (i < 0)
  {
    putchar ('-');
    i *= -1;
  }
  #if SUPERFIXED == 1
  else
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}

void
nano_u16_print (unsigned short int i,char fixed)
{
  unsigned short int divisor = 10000; // 5 digits
  unsigned short int num;
  
  #if SUPERFIXED == 1
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}

void
nano_s32_print (int i,char fixed)
{           
  int divisor = 1000000000; // 10 digits
  int num;
  
  if (i < 0)
  {
    putchar ('-');
    i *= -1;
  }
  #if SUPERFIXED == 1
  else
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}

void
nano_u32_print (unsigned int i,char fixed)
{           
  unsigned int divisor = 1000000000; // 10 digits
  unsigned int num;
  
  #if SUPERFIXED == 1
  {
      putchar ('+');
  }
  #endif
  
  do
  {
    num = i / divisor;
    if(fixed || num != 0)
        putchar (num + 48);
    i -= num * divisor;
    divisor /= 10;
  }
  while (divisor > 0);
}