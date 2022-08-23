#include "header.h"

void (*change_funcs[])(char *) = {
    change_unar_minus,
    change_sqrt,
    change_sin,
    change_cos,
    change_ctg,
    change_tg,
    change_ln,
    change_mod,
    NULL};

void init_signes(t_signes *stack) {
    stack->top = 0;
}
void init_numbers(t_numbers *stack) {
    stack->top = 0;
}
void input(char *data) {
    printw("  ");
    scanw("%[^\n]%*c", data);
}
void push_signes(t_signes *stack, char c) {
    stack->sig[stack->top] = c;
    stack->top++;
}
void push_numbers(t_numbers *stack, double c) {
    stack->num[stack->top] = c;
    stack->top++;
}

char pop_signes(t_signes *stack) {
    if (stack->top > 0) {
        stack->top--;
    }
    return stack->sig[stack->top];
}

double pop_numbers(t_numbers *stack) {
    if (stack->top >= 0) {
        stack->top--;
    }
    return stack->num[stack->top];
}
void change_str(char *data, char *new_data) {
    for (int i = 0; change_funcs[i] != NULL; i++) {
        change_funcs[i](data);
    }
    delete_spaces(data, new_data);
}

void change_unar_minus(char *data) {
    if (data[0] == '-') {
        data[0] = '~';
    }
    size_t i;
    for (i = 0; i < strlen(data) - 1; i++) {
        if (data[i] == '(' && data[i + 1] == '-') {
            data[i + 1] = '~';
        }
    }
}

void change_sin(char *data) {
    size_t i = 0;
    if (strlen(data) > 2) {
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 's' && data[i + 1] == 'i' && data[i + 2] == 'n') {
                data[i] = 'h';
                data[i + 1] = ' ';
                data[i + 2] = ' ';
            }
        }
        data[i + 2] = '\0';
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'h') {
                if (!(data[i + 1] == ' ' && data[i + 2] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'h') {
            data[i] = '!';
        }
        if (data[i + 1] == 'h') {
            data[i + 1] = '!';
        }
    }
    if (strlen(data) == 2) {
        if (data[0] == 'h') {
            data[0] = '!';
        }
        if (data[1] == 'h') {
            data[1] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'h') {
            data[0] = '!';
        }
    }
}
void change_cos(char *data) {
    size_t i = 0;
    if (strlen(data) > 2) {
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'c' && data[i + 1] == 'o' && data[i + 2] == 's') {
                data[i] = 'p';
                data[i + 1] = ' ';
                data[i + 2] = ' ';
            }
        }
        data[i + 2] = '\0';
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'p') {
                if (!(data[i + 1] == ' ' && data[i + 2] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'p') {
            data[i] = '!';
        }
        if (data[i + 1] == 'p') {
            data[i + 1] = '!';
        }
    }
    if (strlen(data) == 2) {
        if (data[0] == 'p') {
            data[0] = '!';
        }
        if (data[1] == 'p') {
            data[1] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'p') {
            data[0] = '!';
        }
    }
}
void change_tg(char *data) {
    if (strlen(data) > 1) {
        size_t i = 0;
        for (i = 0; i < strlen(data) - 1; i++) {
            if (data[i] == 't' && data[i + 1] == 'g') {
                data[i] = 't';
                data[i + 1] = ' ';
            }
        }
        for (i = 0; i < strlen(data) - 1; i++) {
            if (data[i] == 't') {
                if (!(data[i + 1] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 't') {
            data[i] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 't') {
            data[0] = '!';
        }
    }
}
void change_ctg(char *data) {
    size_t i = 0;
    if (strlen(data) > 2) {
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'c' && data[i + 1] == 't' && data[i + 2] == 'g') {
                data[i] = 'k';
                data[i + 1] = ' ';
                data[i + 2] = ' ';
            }
        }
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'k') {
                if (!(data[i + 1] == ' ' && data[i + 2] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'k') {
            data[i] = '!';
        }
        if (data[i + 1] == 'k') {
            data[i + 1] = '!';
        }
    }
    if (strlen(data) == 2) {
        if (data[0] == 'k') {
            data[0] = '!';
        }
        if (data[1] == 'k') {
            data[1] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'k') {
            data[0] = '!';
        }
    }
}

void change_mod(char *data) {
    size_t i = 0;
    if (strlen(data) > 2) {
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'm' && data[i + 1] == 'o' && data[i + 2] == 'd') {
                data[i] = 'n';
                data[i + 1] = ' ';
                data[i + 2] = ' ';
            }
        }
        for (i = 0; i < strlen(data) - 2; i++) {
            if (data[i] == 'n') {
                if (!(data[i + 1] == ' ' && data[i + 2] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'n') {
            data[i] = '!';
        }
        if (data[i + 1] == 'n') {
            data[i + 1] = '!';
        }
    }
    if (strlen(data) == 2) {
        if (data[0] == 'n') {
            data[0] = '!';
        }
        if (data[1] == 'n') {
            data[1] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'n') {
            data[0] = '!';
        }
    }
}
void change_sqrt(char *data) {
    if (strlen(data) > 3) {
        size_t i = 0;
        for (i = 0; i < strlen(data) - 3; i++) {
            if (data[i] == 's' && data[i + 1] == 'q' && data[i + 2] == 'r' && data[i + 3] == 't') {
                data[i] = 'q';
                data[i + 1] = ' ';
                data[i + 2] = ' ';
                data[i + 3] = ' ';
            }
        }
        for (i = 0; i < strlen(data) - 3; i++) {
            if (data[i] == 'q') {
                if (!(data[i + 1] == ' ' && data[i + 2] == ' ' && data[i + 3] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'q') {
            data[i] = '!';
        }
        if (data[i + 1] == 'q') {
            data[i + 1] = '!';
        }
        if (data[i + 2] == 'q') {
            data[i + 2] = '!';
        }
    }
    if (strlen(data) == 3) {
        if (data[0] == 'q') {
            data[0] = '!';
        }
        if (data[1] == 'q') {
            data[1] = '!';
        }
        if (data[2] == 'q') {
            data[2] = '!';
        }
    }
    if (strlen(data) == 2) {
        if (data[0] == 'q') {
            data[0] = '!';
        }
        if (data[1] == 'q') {
            data[1] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'q') {
            data[0] = '!';
        }
    }
}
void change_ln(char *data) {
    if (strlen(data) > 1) {
        size_t i = 0;
        for (i = 0; i < strlen(data) - 1; i++) {
            if (data[i] == 'l' && data[i + 1] == 'n') {
                data[i] = 'l';
                data[i + 1] = ' ';
            }
        }
        for (i = 0; i < strlen(data) - 1; i++) {
            if (data[i] == 'l') {
                if (!(data[i + 1] == ' ')) {
                    data[i] = '!';
                }
            }
        }
        if (data[i] == 'l') {
            data[i] = '!';
        }
    }
    if (strlen(data) == 1) {
        if (data[0] == 'l') {
            data[0] = '!';
        }
    }
}
void delete_spaces(char *data, char *new_data) {
    size_t len = strlen(data), i = 0, j = 0;
    for (i = 0; i < len; i++) {
        if (data[i] != ' ') {
            new_data[j] = data[i];
            j++;
        }
    }
    new_data[j] = '\0';
}
