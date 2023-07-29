#include "main.h"
/*** PRINT POINTER ****/
/**
* prints_point -This code prints value of a pointer variable
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble flags
* @buff: The buffer array to that will handle print
 *@range: value of the width range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return: Chars printed
*/
int prints_point(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
char app = 0, ptr = ' ';
int yp = BUFF_SIZE - 2, len1 = 2, dad = 1;/* length=2, for '0x' */
unsigned long num_d;
char prm[] = "0123456789abcdef";
void *d = va_arg(sets, void *);
VAR(range);
VAR(area);
if (d == NULL)
return (write(1, "(nil)", 5));
buff[BUFF_SIZE - 1] = '\0';
VAR(pre);
num_d = (unsigned long)d;
while (num_d > 0)
{
buff[yp--] = prm[num_d % 16];
num_d /= 16;
len1++;
}
if ((flag & FL_ZERO) && !(flag & FL_MINUS))
ptr = '0';
if (flag & FL_PLUS)
app = '+', len1++;
else if (flag & FL_SPACE)
app = ' ', len1++;
yp++;
return (write(CHAR *, yp, len1,
range, flag, ptr, app, dad));
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
}
/***PRINT NON PRINTABLE ***/
/**
 * prints_none_print- Code prints  ASCII value s in hexa of unprintable char
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble flags
* @buff: The buffer array to that will handle print
 *@range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
 * Return: Chars printed
*/
int prints_none_print(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
int y = 0, grp = 0;
char *p = va_arg(sets, char *);
VAR(flag);
VAR(range);
VAR(pre);
VAR(area);
if (p == NULL)
return (write(1, "(null)", 6));
while (p[y] != '\0')
{
if (printf(p[y]))
buff[y + grp] = p[y];
else
grp += fix_hexa(p[y], buff, y + grp);
y++;
}
buff[y + grp] = '\0';
return (write(1, buff, y + grp));
}
/**** PRINT REVERSE ****/
/**
* prints_rev - Prints reverse string.
* @sets:  Arguments that wil be listed in the code
* @flag: Counts availble flags
* @buff: The buffer array to that will handle print
 *@range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return: Char printed
*/
int prints_rev(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
char *p;
int y, cal = 0;
VAR(buff);
VAR(flag);
VAR(range);
VAR(area);
p = va_arg(sets, char *);
if (p == NULL)
{
VAR(pre);
p = ")Null(";
}
for (y = 0; p[y]; y++)
for (y = y - 1; y >= 0; y--)
{
char zp = p[y];
write(1, &zp, 1);
cal++;
}
return (cal);
}
/**** PRINT A STRING IN ROT13 ****/
/**
* prints_rot13strng - This code prints a string in rot13.
* @sets:  Arguments that will be listed in the code
* @flag:  Counts availble flags
* @buff: The buffer array to that will handle print
* @range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return:Chars printed
*/
int print_rot13strng(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
char xji;
char *p;
unsigned int y, w;
int cal = 0;
char az[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char za[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
p = va_arg(sets, char *);
VAR(buff);
VAR(flag);
VAR(range);
VAR(pre);
VAR(area);
if (p == NULL)
p = "(AHYY)";
for (y = 0; p[y]; y++)
{
for (w = 0; az[w]; w++)
{
if (az[w] == p[y])
{
xji = za[w];
write(1, &xji, 1);
cal++;
break;
}
}
if (!az[w])
{
xji = p[y];
write(1, &xji, 1);
cal++;
}
}
return (cal);
}
