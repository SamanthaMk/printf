#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

<<<<<<< HEAD

#define VAR(x) (void)(x)

=======
#define UNUSED(x) (void)(x)
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816
#define BUFF_SIZE 1024


/* FLAGS */
<<<<<<< HEAD

#define FL_MINUS 1

#define FL_PLUS 2

#define FL_ZERO 4

#define FL_HASH 8

#define FL_SPACE 16
=======
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

<<<<<<< HEAD

int printf(const char *format, ...);

int handle_print(const char *fmt, int *i,

va_list st, char buff[], int flag, int range, int pre, int area);
=======
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816

/****************** FUN.C ******************/


<<<<<<< HEAD
/* Funtions to prints chars and strings */

int prints_char1(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int prints_string2(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int prints_per_cent(va_list sets, char buff[],

        int flag, int range, int pre, int area);


/* Functions to prints numbers */

int prints_int(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int prints_binary(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int prints_unsign_num(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int print_octa(va_list sets, char buff[],
	int flag, int range, int pre, int area);

int prints_hexa(va_list sets, char buff[],

        int flag, int range, int pre, int area);

int print_up_hexa(va_list sets, char buff[],

        int flag, int range, int pre, int area);
=======
/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[]
	int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816


int print_hexa_lu(va_list sets, char prm[],

char buff[], int flag, char flagx, int range, int pre, int area);

<<<<<<< HEAD

/* Function to prints non printable characters */

int prints_none_print(va_list sets, char buff[],

        int flag, int range, int pre, int area);


/* Funcion to print memory address */

int prints_point(va_list sets, char buff[],

        int flag, int range, int pre, int area);


/* Functions to handle other specifiers */

int flaged(const char *form, int *mx);

int get_width(const char *format, int *i, va_list list);

int find_pre(const char *form, int *ap, va_list st);

=======
/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
<<<<<<< HEAD

int prints_rev(va_list sets, char buff[],

        int flag, int range, int pre, int area);


/*Function to print a string in rot 13*/

int print_rot13strng(va_list sets, char buff[],

        int flags, int range, int pre, int area);

=======
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
>>>>>>> 93066b1bc0c1457c335627bc23efb708e6c49816

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int printedx(char);

int fix_hexa(char);
/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
