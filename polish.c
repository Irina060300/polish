#include "header.h"
int prior(char c) {
    int priority = 0;
    if (c == '(' || c == ')') {
        priority = 1;
    } else if (c == '+' || c == '-') {
        priority = 2;
    }else if (c == '*' || c == '/') {
        priority = 3;
    } else if (c == 'h' || c == 'c' || c == 't' || c == 'k' || c == 'q' || c == 'l') {
        priority = 4;
    } else if (c == '~') {
        priority = 5;
    }
    return priority;
}

void polish_get(signes *stack, char *new_data, char *polish) {
    int j = 0;
    char c = 0;
    
    for (size_t i = 0; i < strlen(new_data); i++) {
        c = new_data[i];
        if (!prior(c) && c != '\n') {
            polish[j] = c;
            j++;
        } else {
            if (c == '(') {
                push_signes(stack, c);
                continue;
            }
            
            if (c == ')') {
                while (stack->sig[stack->top-1] != '(') {
                    polish[j] = pop_signes(stack);
                    j++;
                }
                pop_signes(stack);
                continue;
            }
            while (stack->top != 0 && prior(c) <= prior(stack->sig[stack->top - 1])) {
                polish[j] = pop_signes(stack);
                j++;
            }
            push_signes(stack, c);
            printf("%s\n", polish);
        }
        while (stack->top > 0) {
            polish[j] = pop_signes(stack);
            j++;
        }
    }
    polish[j] = '\0';
}
