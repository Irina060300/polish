#ifndef HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define NMAX 300

typedef struct signes {
    char sig[NMAX];
    int top;
} signes;

typedef struct numbers {
    double num[NMAX];
    int top;
} numbers;

void init_signes(signes *stack);
void init_numbers(numbers *stack);

void push_signes(signes *stack, char c);
void push_numbers(numbers *stack, double c);

char pop_signes(signes *stack);
double pop_numbers(numbers *stack);

void input(char *data);
void change_str(char *data, char *new_data);
int prior(char c);

void change_unar_minus(char *data);
void change_sin(char *data);
void change_cos(char *data);
void change_tg(char *data);
void change_ctg(char *data);
void change_sqrt(char *data);
void change_ln(char *data);
void delete_spaces (char *data, char *new_data);
int check_data(char *new_data);
void check_extra_symbols(char *new_data);
int check_brackets(char *new_data);
int check_sin(char *new_data);
int check_cos(char *new_data);
int check_tg(char *new_data);
int check_ctg(char *new_data);
int check_sqrt(char *new_data);
int check_ln(char *new_data);
int check_operators(char *new_data);
int check_x(char *new_data);
int check_point(char *new_data);
void polish_get(signes *stack, char *new_data, char *polish);

#endif  // HEADER_H_
