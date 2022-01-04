//
//  AutomaticLightingControl_1.c
//  
//
//  Created by Samuel Oluwadare Folorunsho on 1/4/22.
//

#include "AutomaticLightingControl_1.h"

//lcd module interface
// Lcd pinout settings
sbit LCD_RS at RD1_bit;
sbit LCD_EN at RD2_bit;
sbit LCD_D7 at RD6_bit;
sbit LCD_D6 at RD5_bit;
sbit LCD_D5 at RD4_bit;
sbit LCD_D4 at RC7_bit;

// Pin direction
sbit LCD_RS_Direction at TRISD1_bit;
sbit LCD_EN_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD6_bit;
sbit LCD_D6_Direction at TRISD5_bit;
sbit LCD_D5_Direction at TRISD4_bit;
sbit LCD_D4_Direction at TRISC7_bit;
#define aux portb.f5
#define button_1 portb.f1
#define button_2 portb.f2
#define button_3 portb.f3
#define button_4 portb.f4
#define power_button portb.f0
#define load portb.f6
#define LDR portB.f7
#define light portc.f2
#define fan portc.f3
#define backlight portd.f7
void routine_1(void);
void routine_2(void);
void routine_3(void);
void routine_4(void);
void shut_down(void);
int i,t,counter;//int variables
char j,k;
const char character[] = {31,31,31,31,31,31,31,31};
const char character_2[] = {10,21,10,21,17,10,21,10};
void CustomChar(char pos_row, char pos_char);
void CustomChar_2(char pos_row, char pos_char);
void main(void)
{
mas_ref:
lcd_init();//initializes the lcd with default 16x2 settings
lcd_cmd(_lcd_cursor_off);
lcd_cmd(_lcd_clear);
load=0;
//data direction assignment
TRISD.F7=0;
TRISB=0X3F;
backlight=0;
TRISB.f7=1;
for(;;)
{
if(power_button)
{
delay_ms(100);
if(power_button)
{
backlight=1;
lcd_cmd(_lcd_clear);
lcd_out(1,6,"Hello!");
delay_ms(1000);
lcd_cmd(_lcd_clear);
lcd_out(1,2,"Please Select");
delay_ms(1000);
ref_k:
lcd_cmd(_lcd_clear);
load=0;
lcd_out(1,1,"1:Week1 2:Week2");
lcd_out(2,1,"3:Week3 4:Week4");
ref_q:
for(;;)
{
 if(button_1)//1st week
 {
lcd_cmd(_lcd_clear);
  delay_ms(50);
  routine_1();
  delay_ms(50);
  load=0;
  goto ref_q;
 }
 if(button_2)//2nd week
 {
  lcd_cmd(_lcd_clear);

  delay_ms(50);
  routine_2();
  delay_ms(50);
   load=0;
  goto ref_q;
 }
 if(button_3)//3rd week
 {
  lcd_cmd(_lcd_clear);
  delay_ms(50);
  routine_3();
  delay_ms(50);
  load=0;
   goto ref_q;
 }
 if(button_4)//4th week
 {
  lcd_cmd(_lcd_clear);
  delay_ms(50);
  routine_4();
  delay_ms(50);

   load=0;
   goto ref_q;
 }
 if(aux)
 {
 goto ref_k;
 }
 if(power_button)
{
delay_ms(50);
shut_down();
goto
mas_ref;
}
}
}
if(power_button)
{
delay_ms(50);
shut_down();
goto
mas_ref;
}
}
}
}
//functions
void routine_1(void)//1st week
{
lcd_cmd(_lcd_return_home);
ref_1: lcd_out(1,1,"WEEK 1");
lcd_out(2,1,"TIME : +9 Hours");
CustomChar_2(1,16);
delay_ms(1000);
for(;;)
 {
 if(LDR==0)
 {
delay_ms(100);
load=1;
for(t=0;t<3240000;t++)
{
delay_ms(1);
 if(t==3239999)
 {
 goto ref_1;
 }
   if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
}
 if(LDR==0)
 {
 delay_ms(1800000);
 }
}
else
 {
 delay_ms(100);
 load=0;
 }
  if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
   if(power_button)
 {
 goto loop;
 }
}
loop:{}
 }
void routine_2(void)//2nd week
{
ref_2:
lcd_cmd(_lcd_return_home);
lcd_out(1,1,"WEEK 2");
lcd_out(2,1,"TIME : +7 Hours");
CustomChar_2(1,15);
delay_ms(50);
CustomChar_2(1,16);
delay_ms(1000);
for(;;)
 {
 if(LDR==0)
 {
delay_ms(100);
load=1;
for(t=0;t<2520000;t++)
{
delay_ms(1);
 if(t==2519999)
 {
 goto ref_2;
 }
   if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
}
 if(LDR==0)
 {
 delay_ms(2520000);
 }
}
else
 {
 delay_ms(100);
 load=0;
 }
  if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
   if(power_button)
 {
 goto
 loop;
 }
}
loop:{}
}
void routine_3(void)//3rd week
{
ref_4:
lcd_cmd(_lcd_return_home);
lcd_out(1,1,"WEEK 3");
lcd_out(2,1,"TIME : +6 Hours");
CustomChar_2(1,14);
delay_ms(50);
CustomChar_2(1,15);
delay_ms(50);
CustomChar_2(1,16);
delay_ms(1000);
for(;;)
{
 if(LDR==0)
 {
 delay_ms(100);
load=1;

for(t=0;t<2160000;t++)
{
delay_ms(1);
 if(t==2159999)
 {
 goto ref_4;
 }
   if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
}
 if(LDR==0)
 {
 delay_ms(2880000);
 }
}
else
 {
 delay_ms(100);
 load=0;
 }
  if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
   if(power_button)
 {
 goto
 loop;
 }
}
loop:{}
 }
 void routine_4(void)//4th week
{
ref_3:
lcd_cmd(_lcd_return_home);
lcd_out(1,1,"WEEK 4");
lcd_out(2,1,"TIME : +5 Hours");
CustomChar_2(1,13);
delay_ms(50);
CustomChar_2(1,14);
delay_ms(50);
CustomChar_2(1,15);
delay_ms(50);
CustomChar_2(1,16);
delay_ms(1000);
for(;;)
 {
 if(LDR==0)
 {
delay_ms(100);
load=1;
for(t=0;t<1800000;t++)
{
delay_ms(1);
 if(t==1799999)
 {
 goto ref_3;
 }
   if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
}
 if(LDR==0)
 {
 delay_ms(3240000);
 }
}
else
 {
 delay_ms(100);
 load=0;
 }
  if(button_1||button_2||button_3||button_4||aux||power_button)
 {
 goto loop;
 }
   if(power_button)
 {
 goto
 loop;
 }
}
loop:{}
}
void CustomChar(char pos_row, char pos_char) {
    Lcd_Cmd(120);
    for (j = 0; j<=7; j++) Lcd_Chr_CP(character[j]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    Lcd_Chr(pos_row, pos_char, 7);
}
void CustomChar_2(char pos_row, char pos_char) {
    Lcd_Cmd(120);
    for (k = 0; k<=7; k++) Lcd_Chr_CP(character_2[k]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    Lcd_Chr(pos_row, pos_char, 7);
}
 void shut_down(void)
 {
 lcd_cmd(_lcd_clear);
 delay_ms(100);
 lcd_out(1,4,"Goodbye...");
 delay_ms(500);
 lcd_cmd(_lcd_clear);
 load=0;
 delay_ms(1000);
 backlight=0;
 }
