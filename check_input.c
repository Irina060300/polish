#include "header.h"

int check_data(char *new_data) {
    int flag = 0;
    for (size_t i = 0; i < strlen(new_data); i++) {
        if (new_data[i] == '!') {
            flag++;
        }
    }

    if (check_brackets(new_data) != 0) flag++;
    if (check_sin(new_data) != 0) flag++;
    if (check_cos(new_data) != 0) flag++;
    if (check_tg(new_data) != 0) flag++;
    if (check_ctg(new_data) != 0) flag++;
    if (check_sqrt(new_data) != 0) flag++;
    if (check_ln(new_data) != 0) flag++;
    if (check_operators(new_data) != 0) flag++;
    if (check_x(new_data) != 0) flag++;
    if (check_point(new_data) != 0) flag++;
    return flag;
}

void check_extra_symbols(char *new_data) {
    for (size_t i = 0; i < strlen(new_data); i++) {
        if ((new_data[i] >= '0' && new_data[i] <= '9') || new_data[i] == 'h' || new_data[i] == 'p' || new_data[i] == 'k' ||
            new_data[i] == 'q' || new_data[i] == 't' || new_data[i] == 'l' || new_data[i] == 'x' ||
            new_data[i] == '+' || new_data[i] == '-' || new_data[i] == '*' || new_data[i] == '/' ||
            new_data[i] == '~' || new_data[i] == ')' || new_data[i] == '(' || new_data[i] == '.') {
            continue;
        } else
            new_data[i] = '!';
    }
}

int check_brackets(char *new_data) {
    int flag = 0;
    size_t i;
    int count_open = 0, count_close = 0;
    for (i = 0; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == '(') break;
        if (new_data[i] == ')') {
            flag++;
            break;
        }
    }
    for (i = 0; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == '(') count_open++;
        if (new_data[i] == ')') count_close++;
        if (new_data[i] == '(' && new_data[i + 1] == ')') flag++;
    }
    if (new_data[i] == ')') count_close++;
    if (new_data[i] == '(') count_open++;
    if (count_open != count_close) flag++;
    // printf("brackets %d\n", flag);
    return flag;
}
int check_sin(char *new_data) {
    int flag = 0;
    if (new_data[0] == 'h') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 'h') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("sin %d\n", flag);
    return flag;
}
int check_cos(char *new_data) {
    int flag = 0;
    if (new_data[0] == 'p') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 'p') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("cos %d\n", flag);
    return flag;
}
int check_tg(char *new_data) {
    int flag = 0;
    if (new_data[0] == 't') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 't') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("tg %d\n", flag);
    return flag;
}
int check_ctg(char *new_data) {
    int flag = 0;
    if (new_data[0] == 'k') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 'k') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("ctg %d\n", flag);
    return flag;
}
int check_sqrt(char *new_data) {
    int flag = 0;
    if (new_data[0] == 'q') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 'q') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("sqrt %d\n", flag);
    return flag;
}
int check_ln(char *new_data) {
    int flag = 0;
    if (new_data[0] == 'l') {
        if (new_data[1] != '(') flag++;
    }
    size_t i = 0;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == 'l') {
            if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '~' || new_data[i - 1] == '*' ||
                  new_data[i - 1] == '/' || new_data[i - 1] == '(')) flag++;
            if (new_data[i + 1] != '(') flag++;
        }
    }
    // printf("ln %d\n", flag);
    return flag;
}

int check_operators(char *new_data) {
    int flag = 0;
    size_t i;
    if (new_data[0] == '+' || new_data[0] == '*' || new_data[0] == '/') flag++;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == '+' || new_data[i] == '-' || new_data[i] == '*' || new_data[i] == '/') {
            if (!(new_data[i - 1] == ')' || new_data[i - 1] == 'x' || (new_data[i - 1] >= '0' && new_data[i - 1] <= '9'))) {
                // printf("operators %d %lld\n", flag, i);
                flag++;
            }

            if (new_data[i + 1] == '(' || new_data[i + 1] == 'x' || new_data[i + 1] == 'h' || new_data[i + 1] == 'c' ||
                new_data[i + 1] == 't' || new_data[i + 1] == 'p' || new_data[i + 1] == 'k' || new_data[i + 1] == 'q' ||
                new_data[i + 1] == 'l' || (new_data[i + 1] >= '0' && new_data[i + 1] <= '9')) {
                continue;
            } else {
                // printf("operators %d %lld\n", flag, i);
                flag++;
            }
            if (new_data[i] == '~') {
                if (!(new_data[i + 1] >= '0' && new_data[i + 1] <= '9')) {
                    // printf("operators %d %lld\n", flag, i);
                    flag++;
                }
            }
        }
    }
    if (new_data[i] == '+' || new_data[i] == '-' || new_data[i] == '*' || new_data[i] == '/') flag++;
    // printf("operators %d\n", flag);
    return flag;
}

int check_x(char *new_data) {
    int flag = 0;
    size_t i;
    if (strlen(new_data) != 1) {
        if (new_data[0] == 'x') {
            if (!(new_data[1] == '+' || new_data[1] == '*' || new_data[1] == '*' || new_data[1] == '/')) flag++;
        }
        for (i = 1; i < strlen(new_data) - 1; i++) {
            if (new_data[i] == 'x') {
                if (!(new_data[i - 1] == '+' || new_data[i - 1] == '-' || new_data[i - 1] == '*' || new_data[i - 1] == '/' ||
                      new_data[i - 1] == '(' || new_data[i - 1] == '~')) flag++;
                if (!(new_data[i + 1] == '+' || new_data[i + 1] == '-' || new_data[i + 1] == '*' || new_data[i + 1] == '/' ||
                      new_data[i + 1] == ')')) flag++;
            }
        }
    }
    // printf("x %d\n", flag);
    return flag;
}

int check_point(char *new_data) {
    int flag = 0;
    size_t i;
    if (new_data[0] == '.') flag++;
    for (i = 1; i < strlen(new_data) - 1; i++) {
        if (new_data[i] == '.') {
            if (!(new_data[i - 1] >= '0' && new_data[i - 1] <= '9')) flag++;
            if (!(new_data[i + 1] >= '0' && new_data[i + 1] <= '9')) flag++;
        }
    }
    // printf("point %d\n", flag);
    return flag;
}
