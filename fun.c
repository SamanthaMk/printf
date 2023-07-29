#include "main.h"
/*** PRINTS CHAR ****/
/**
* prints_char1 - This code will print chars available
* @range: value of the width
* @pre: This will be the precision
* @sets : Arguments to be listed
* @area: the value of the area size
* @buff: The buffer array to that will handle print
* @flag: Counts all flags available
* Return: Chars printed
*/
int prints_char1(va_list sets, char buff[],
int range, int flag, int pre, int area)
{
char pxc = va_arg(sets, int);
return (handle(pxc, buff, flag, range, pre, area));
}
/*** PRINT A STRING ***/
/**
* prints_string2 - Code is responsible for printing a string
* @sets: Arguments that wil be listed in the code
*@buff: The buffer array to that will handle print
* @flag:  Counts working flags
*@range: value of the range.
*@pre: Will be the precision in the code
* @area: The area size of the specifier
* Return:Chars printed
*/
int prints_string2(va_list sets, char buff[],
int range, int pre, int flag, int area)
{
int ep, height = 0;
char *res = va_arg(sets, char *);
VAR(flag);
VAR(buff);
VAR(area);
VAR(pre);
VAR(range);
if (res == NULL)
{
res = "(null)";
if (pre >= 6)
res = "      ";
}
while (res[height] != '\0')
height++;
if (pre >= 0 && pre < height)
height = pre;
if (range > height)
{
if (flag & FL_MINUS)
{
write(1, &res[0], height);
for (ep = range - height; ep > 0; ep--)
write(1, " ", 1);
return (range);
}
else
{
for (ep = range - height; ep > 0; ep--)
write(1, " ", 1);
write(1, &res[0], height);
return (range);
}
}
return (write(1, res, height));
}
/*** PRINTS THE PERCENT SIGN ***/
/**
* prints_per_cent - This code's function prints the % sign
* @sets:  Arguments that wil be listed in the code
* @buff: The buffer array to that will handle print
* @range: value of the range.
* @pre: Will be the precision in the code
* @flag: Counts all flags available
* @area:  The area size of the specifier
* Return: Char printed
*/
int prints_per_cent(va_list sets, char buff[],
int range, int flag, int pre, int area)
{
VAR(sets);
VAR(buff);
VAR(flag);
VAR(range);
VAR(pre);
VAR(area);
return (write(1, "%%", 1));
}
/*** PRINT INTEGER ***/
/**
* prints_int - This Code function will print int
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble  flags
* @buff: Is the buffer array to that will handle print
 *@range: value of the range
* @pre: Will be the precision in the code
* @area:  The area size of the specifier
* Return: Number of chars printed
*/
int prints_int(va_list sets, char buff[],
int area, int flag, int range, int pre)
{
int minus = 0;
int z = BUFF_SIZE - 2;
long int k = va_arg(sets, long int);
unsigned long int gig;
k = convert_num_size(area); // Fixed the syntax error here
if (k == 0)
buff[z--] = '0';
buff[BUFF_SIZE - 1] = '\0';
gig = (unsigned long int)k;
if (k < 0)
{
gig = (unsigned long int)((-1) * k);
minus = 1;
}
while (gig > 0)
{
buff[z--] = (gig % 10) + '0';
gig /= 10;
}
z++;
return (prints_int(minus, z, buff, flag, range, pre, area));
}
/*** PRINT BINARY ***/
/**
* prints_binary - Codes function prints the unsigned number
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble  flags
* @buff: The buffer array to that will handle print
* @range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return: Chars printed in binary
*/
int prints_binary(va_list sets, char buff[],
int pre, int flag, int range, int area)
{
int cal;
unsigned int xn, f, c, num2;
unsigned int pt[32];
VAR(flag);
VAR(buff);
VAR(range);
VAR(area);
VAR(pre);
xn = va_arg(sets, unsigned int);
f = 2147483648; /* (2 ^ 31) */
pt[0] = xn / f;
for (c = 1; c < 32; c++)
{
f /= 2;
pt[c] = (xn / f) % 2;
}
for (c = 0, num2 = 0, cal = 0; c < 32; c++)
{
num2 += pt[c];
if (num2 || c == 31)
{
char zp = '0' + pt[c];
write(1, &zp, 1);
cal++;
}
}
return (cal);
}
