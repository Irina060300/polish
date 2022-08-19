#include "header.h"

double create_stk(char *polish, t_numbers *stk, double x) {
    size_t i;
    int j = 0;
    char num[NMAX];
    init_numbers(stk);
    if (strlen(polish) == 1) {
        num[0] = polish[0];
        if (num[0] != 'x')
            push_numbers(stk, atof(num));
        else
            push_numbers(stk, x);
    } else {
        // printf("polish %s\n", polish);
        for (i = 0; i < strlen(polish); i++) {
            char c = polish[i];
            if (isnt_digit(c) != 0 && c != '|' && c != '\n') {
                num[j] = polish[i];
                j++;
                if (i != strlen(polish) - 1) continue;
            }
            if (!(num[0] == '\0')) {
                if (num[0] == 'x')
                    push_numbers(stk, x);
                else
                    push_numbers(stk, atof(num));
            }
            calc(c, stk);
            j = 0;
            memset(num, 0, sizeof(num));
        }
    }

    return stk->num[stk->top - 1];
}
int max_point(char *polish, t_numbers *stk) {
    int max = 0;
    double y;
    for (double x = 0.0; x < 12.0 * pi + 12 * pi / (POLE_WIDTH - 3.0); x += 12 * pi / (POLE_WIDTH - 3.0)) {
        y = create_stk(polish, stk, x);
        if (y > max) {
            max = (int)ceil(y);
        }
    }
    if (max % 2 == 1) max +=1;
    if (max > 8) max = 8;
    return max;
}

void result(char *polish, t_numbers *stk, char **pole) {
    create_pole(pole, polish, stk);
    double max = max_point(polish, stk);
    int count = 2;
    double y = 0;
    int point_count = 0;
    for (double x = 0.0; x < 8.0 * pi + 8 * pi / (POLE_WIDTH - 3.0); x +=  8 * pi / (POLE_WIDTH - 3.0)) {
        y = create_stk(polish, stk, x);
        if (y <= 8 && y >= -8) {
            double h = rint((POLE_HEIGHT-1)/2 - (POLE_HEIGHT-1)/2/ max * y);
            if (y > pow(10, -6) || y < -pow(10, -6))
                pole[(int)h][count] = '*';
            else
                pole[20][count] = '*';
            point_count++;
        }
        count++;
    }
    if (point_count == 0) {
        printf("Out of E(y)");
    } else {
        printf("\n");
        for (int i = 0; i < POLE_HEIGHT; i++) {
            for (int j = 0; j < POLE_WIDTH; j++) {
                if (j != 0 && j != 1 && i != 20 && pole[i][j] != '*') {
                    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                    // ((7 << 4))| 1);
                    printf("%c", pole[i][j]);
                } else if (j != 0 && j != 1 && pole[i][j] == '*') {
                    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                    // ((7 << 4))| 0);
                    printf("%c", pole[i][j]);
                } else if (j != 0 && j != 1 && i == 20) {
                    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                    // ((7 << 4))| FOREGROUND_RED);
                    printf("%c", pole[i][j]);
                } else {
                    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                    // 0 | 15);
                    printf("%c", pole[i][j]);
                }
            }
            // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
            printf("\n");
        }
    }
}

int isnt_digit(char c) {
    int flag = 0;
    if (!(c == '+' || c == '-' || c == '*' || c == '/' || c == '~' ||
          c == 'h' || c == 'p' || c == 'q' || c == 't' || c == 'k' || c == 'l'))
        flag++;
    return flag;
}

void calc(char c, t_numbers *stk) {
    double a, b;
    if (isnt_digit(c) == 0) {
        if (prior(c) == 2 || prior(c) == 3) {
            a = pop_numbers(stk);
            b = pop_numbers(stk);
            if (c == '+') push_numbers(stk, b + a);
            if (c == '-') push_numbers(stk, b - a);
            if (c == '*') push_numbers(stk, b * a);
            if (c == '/') push_numbers(stk, b / a);
        } else {
            a = pop_numbers(stk);
            if (c == 'h') push_numbers(stk, sin(a));
            if (c == 'p') push_numbers(stk, cos(a));
            if (c == 't') push_numbers(stk, tan(a));
            if (c == 'k') push_numbers(stk, 1.0 / tan(a));
            if (c == 'q') push_numbers(stk, sqrt(a));
            if (c == 'l') push_numbers(stk, log(a));
            if (c == '~') push_numbers(stk, -a);
        }
    }
}

void create_pole(char **pole, char *polish, t_numbers *stk) {
    double max = max_point(polish, stk);
    for (int i = 0; i < POLE_HEIGHT; i++) {
        int k;
        for (int j = 0; j < POLE_WIDTH; j++) {
            if ((i == 0 || i == POLE_HEIGHT - 1) && j != 0 && j != 1 && j != 2 && j != POLE_WIDTH - 1) {
                pole[i][j] = '-';
            } else if (j == 2 || j == POLE_WIDTH - 1) {
                pole[i][j] = '|';
            } else if (j == 1 && i != 0 && i != (POLE_HEIGHT - 1) / 4 && i != (POLE_HEIGHT - 1)/ 2 && i != (POLE_HEIGHT - 1) / 4 * 3 &&
                       i != POLE_HEIGHT - 1) {
                pole[i][j] = ' ';
            } else if (j == 1 && (i == 0 || i == POLE_HEIGHT - 1)) {
                k = 2 * max / 2;
                pole[i][j] = (char)k+48;
            } else if (j == 1 && (i == (POLE_HEIGHT - 1) / 4 * 3 || i == (POLE_HEIGHT - 1)/ 4)) {
                pole[i][j] = (char)k/2+48;
            } else if (j == 1 && i == (POLE_HEIGHT - 1) / 2) {
                pole[i][j] = (int)'0';
            } else if (j == 0 && i != (POLE_HEIGHT - 1) / 4 * 3 && i != POLE_HEIGHT - 1) {
                pole[i][j] = ' ';
            } else if (j == 0 && (i == (POLE_HEIGHT - 1) / 4 * 3 || i == POLE_HEIGHT - 1)) {
                pole[i][j] = '-';
            } else
                pole[i][j] = '-';
        }
    }
}
