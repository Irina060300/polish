#include "header.h"

int prior(char c) {
    int priority = 0;
    if (c == '(' || c == ')') {
        priority = 1;
    } else if (c == '+' || c == '-') {
        priority = 2;
    } else if (c == '*' || c == '/') {
        priority = 3;
    } else if (c == 'h' || c == 'p' || c == 't' || c == 'k' || c == 'q' || c == 'l' || c == 'a') {
        priority = 5;
    } else if (c == '~') {
        priority = 4;
    } else if (c == '^') {
        priority = 6;
    }
    return priority;
}

void polish_get(t_signes *stack, char *new_data, char *polish) {
    int j = 0;
    char c = 0;
    for (size_t i = 0; i < strlen(new_data); i++) {
        c = new_data[i];
        if (!(prior(c) && c != '\n')) {
            polish[j] = c;
            j++;
        } else {
            if (c == '(') {
                push_signes(stack, c);
                continue;
            }
            if (c == ')') {
                while (stack->sig[stack->top - 1] != '(') {
                    polish[j] = pop_signes(stack);
                    j++;
                }
                pop_signes(stack);
                continue;
            }
            while (stack->top > 0 && prior(c) <= prior(stack->sig[stack->top - 1])) {
                polish[j] = pop_signes(stack);
                // printw("%lld %c\n", i, polish[j]);
                j++;
            }
            push_signes(stack, c);
            if (prior(c) != 5 && prior(c) != 4)
                polish[j++] = '|';
        }
        // printw("%s --- ", polish);
    }

    while (stack->top > 0) {
        polish[j] = pop_signes(stack);
        j++;
    }
    polish[j] = '\0';
    //     printw("%s\n", polish);
}
