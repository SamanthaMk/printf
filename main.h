#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define VAR(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FL_MINUS 1
#define FL_PLUS 2
#define FL_ZERO 4
#define FL_HASH 8
#define FL_SPACE 16

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

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
void pri_buff(char buff[], int *buff_np);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int prints_char1(va_list sets, char buff[],
        int range, int flag, int pre, int area);
int prints_string2(va_list sets, char buff[],
        int range, int pre, int flag, int area);
int prints_per_cent(va_list sets, char buff[],
        int range, int flag, int pre, int area);

/* Functions to print numbers */
int prints_int(va_list sets, char buff[],
        int area, int flag, int range, int pre);
int prints_binary(va_list sets, char buff[],
        int pre, int flag, int range, int area);
int prints_unsign_num(va_list sets, char buff[],
        int flag, int range, int pre, int area);
int prints_octa(va_list sets, char buff[],
        int flag, int range, int pre, int area);
int prints_hexa(va_list sets, char buff[],
        int flag, int range, int pre, int area);
int print_up_hexa(va_list sets, char buff[],
        int flag, int range, int pre, int area);
int print_hexa_lu(va_list sets, char prm[],
char buff[], int area, int flag, char flagx, int range, int pre);

/* Function to print non printable characters */
int prints_none_print(va_list sets, char buff[],
        int flag, int range, int pre, int area);

/* Funcion to print memory address */
int prints_point(va_list sets, char buff[],
        int flag, int range, int pre, int area);

/* Funciotns to handle other specifiers */
int flaged(const char *form, int *mx);
int get_width(const char *format, int *i, va_list list);
int find_pre(const char *form, int *ap, va_list st);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int prints_rev(va_list sets, char buff[],
        int flag, int range, int pre, int area);

/*Function to print a string in rot 13*/
int print_rot13strng(va_list sets, char buff[],
        int flag, int range, int pre, int area);

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

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
