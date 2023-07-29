#include "main.h"
/**
 * find_pre - This function will calculate the printable precision
 * @form: Arguments that are formatted will be displayed in a string
 * @ap: Is the arguments to be printed in list form
 * @st: This is arguments in va_list form
 * Return: Specific precision
 */
int find_pre(const char *form, int *ap, va_list st)
{
int pre = -1;
int jk = *ap + 1;
if (form[jk] != '.')
return (pre);
pre = 0;
for (jk += 1; form[jk] != '\0'; jk++)
{
if (digit_check(form[jk]))
{
pre *= 10;
pre += form[jk] - '0';
}
else if (form[jk] == '*')
{
jk++;
pre = va_arg(st, int);
break;
}
else
break;
}
*ap = jk - 1;
return (pre);
}
