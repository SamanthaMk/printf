#include "main.h"
/*** PRINT UNSIGNED NUMBER ***/
/**
* prints_unsign_num -Code's function prints the unsigned number
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble  flags
* @buff: Buffer array to that will handle print
* @range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return: Value of chars printed
  */
int prints_unsign_num(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
int y = BUFF_SIZE - 2
unsigned long int gig = va_arg(types, unsigned long int);
gig = converted_area_sign(gig, area);
if (gig == 0)
buff[y--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (gig > 0)
{
buff[y--] = (gig % 10) + '0';
gig /= 10;
}
y++;
return (write_sign(0, y, buff, flag, range, pre, area));
}
/*** PRINTS UNSIGNED NUMBER IN OCTAL  ***/
/**
* print_octa - Code will print unsigned number in octal form
* @sets:  Arguments that wil be listed in the code
* @flag:  Counts availble  flags
* @buff: * The buffer array to that will handle print
 *@range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
  * Return: Octal number
*/
int print_octa(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
int y = BUFF_SIZE - 2;
unsigned long int gig = va_arg(sets, unsigned long int);
unsigned long int num3 = gig;
VAR(range);
gig = convert_size_ sign(gig, area);
if (gig == 0)
buff[y--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (gig > 0)
{
buffer[y--] = (gig % 8) + '0';
gig /= 8
}
if (flag & FL_HASH && num3 != 0)
buffer[y--] = '0';
y++;
return (write_sign(0, y, buff, flag, range, pre, area));
}
/*** PRINTS UNSIGNED NUM IN HEXADECIMAL ***/
/**
* prints_hexa - Prints an unsigned number in hexadecimal
* prints_octa - Code will print unsigned number in octal form
* @sets:  Arguments that wil be listed in the code
* @flag:  Counts availble flags
* @buff: The buffer array to that will handle print
* @range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* Return: Num in Hexadecimal
*/
int prints_hexa(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
return (print_hexa(sets, "0123456789abcdef", buff,
flag, 'x', range, pre, area));
}
/*** PRINTS UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
* print_up_hexa - Code unsigned num in upper hexadecimal
* @sets:  Arguments that wil be listed in the code
* @flag:  Counts availble flags
* @buff: * The buffer array to that will handle print
 *@range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
 * Return: Chars printed
 */
int print_up_hexa(va_list sets, char buff[],
int flag, int range, int pre, int area)
{
return (print_hexa(types, "0123456789ABCDEF", buff,
flag, 'X', range, pre, area));
}
/********* PRINTS HEXA NUM IN LOWER OR UPPER ***********/
/**
* print_hexa_lu - Code prints hexadecimal in lower or upper case
* @sets: Arguments that wil be listed in the code
* @flag: Counts availble flags
* @buff: The buffer array to that will handle print
* @range: value of the range
* @pre: Will be the precision in the code
* @area: The area size of the specifier
* @prm: This is array of values to map the number to
* @flagx: this Calculates active flags available
* Return: Chars printed
*/
int print_hexa_lu(va_list sets, char prm[], char buff[],
int area, int flag, char flagx, int range, int pre)
{
int y = BUFF_SIZE - 2;
unsigned long int gig = va_arg(sets, unsigned long int);
unsigned long int num3 = gig;
VAR(range);
gig = convert_area_sign(num, size);
if (gig == 0)
buff[y--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (gig > 0)
{
buff[y--] = prm[gig % 16];
gig /= 16;
}
if (flag & FL_HASH && num3 != 0)
{
buff[y--] = flagx;
buffer[y--] = '0';
}
y++;
return (write_sign(0, y, buff, flag, range, pre, area));
}
