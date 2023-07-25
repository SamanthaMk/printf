#include "main.h"
/**
* flaged - This code has functions that will handle flags.
* @form: The arguments that will be displayed in a string
* @mx: value that takes parameter.
* Return: Flag:
*/
int flaged(const char *form, int *mx)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int gm;
int ip;
int flag = 0;
const int FLAG_A[] = {FL_MINUS, FL_PLUS, FL_ZERO, FL_HASH, FL_SPACE, 0};
const char FLAG_X[] = {'-', '+', '0', '#', ' ', '\0'};
for (ip = *mx + 1; form[ip] != '\0'; ip++)
{
for (gm = 0; FLAG_X[gm] != '\0'; gm++)
if (form[ip] == FLAG_X[gm])
{
flag |= FLAG_A[gm];
break;
}
if (FLAG_X[gm] == 0)
break;
}
*mx = ip - 1;
return (flag);
}
