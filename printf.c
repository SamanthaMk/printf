#include "main.h"
void pri_buff(char buff[], int *buff_np);
/**
 * _printf - Code has function that produces output based on format
 * @format:  This is a character string 0 or more directive
 * Return: Print chars.
 */
int _printf(const char *format, ...)
{
int ixp, pr = 0, pri = 0;
int range, flag, pre, area, buff_np = 0;
va_list st;
char buff[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(st, format);
for (ixp = 0; format && format[ixp] != '\0'; ixp++)
{
if (format[ixp] != '%')
{
buff[buff_np++] = format[ixp];
if (buff_np == BUFF_SIZE)
pri_buff(buff, &buff_np);
/* This will write(1, &format[ixp], 1);*/
pri++;
}
else
{
pri_buff(buff, &buff_np);
flag = flaged(format, &ixp);
range = width(format, &ixp, st);
pre = find_pre(format, &ixp, st)
area = size(format, &ixp);
++ixp;
pr = handle(format, &ixp, st, buff, flag, range, pre, area);
if (pr == -1)
return (-1);
pri += pr;
}
}
pri_buff(buff, &buff_np);
va_end(st);
return (pri);
}
/**
*pri_buff - Code has printed contents of the buffer if in existance
* @buff: Is an array of chars
* @buff_np: representation the length.
*/
void pri_buff(char buff[], int *buff_np)
{
if (*buff_np > 0)
write(1, &buff[0], *buff_np);
*buff_np = 0;
}
