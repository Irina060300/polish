#include "header.h"

double create_stk(char *polish, t_numbers *stk, double x) {
    // printw("%s", polish);
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
    int min = 0;
    double y;
    for (double x = -8; x < 8; x += 0.1) {
        y = create_stk(polish, stk, x);
        if (y > max) {
            max = (int)ceil(y);
        }
        if (y < min) {
            min = (int)floor(y);
        }
    }
    if (max % 2 == 1) {
        max += 1;
    }
    if (!(min % 2 == 0)) {
        min += 1;
    }
    if (max > 8) {
        max = 8;
    }
    if (min < -8) {
        min = -8;
    }
    if (fabs((double)min) > max) {
        max = (int)fabs((double)min);
    }
    return max;
}

void result(char *polish, t_numbers *stk, char **pole) {
    create_pole(pole, polish, stk);
    double max = max_point(polish, stk);
    int count = 2;
    double y = 0;
    int point_count = 0;
    // for (double x = 0.0; x < 8.0 * pi + 8 * pi / (POLE_WIDTH - 3.0); x +=  8 * pi / (POLE_WIDTH - 3.0)) {
    for (double x = -8.0; x < 8.0; x += 0.1) {
        y = create_stk(polish, stk, x);
        if (isnan(y) == 0) {
            if (y <= 8 && y >= -8) {
                double h = ceil((POLE_HEIGHT - 2) / 2 - (POLE_HEIGHT - 2) / 2 / max * y);
                double c = floor((POLE_HEIGHT - 2) / 2 - (POLE_HEIGHT - 2) / 2 / max * y);
                if (y > pow(10, -10))
                    pole[(int)c][count] = '*';
                else if (y < -pow(10, -10)) {
                    pole[(int)h][count] = '*';
                } else {
                    pole[20][count] = '*';
                }
                point_count++;
            }
            // printw("%lf %d ", y, count);
            count++;
        } else {
            count++;
        }
    }
    if (point_count == 0) {
        printw("Out of E(y)");
    } else {
        printw("\n");
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        for (int i = 0; i < POLE_HEIGHT; i++) {
            for (int j = 0; j < POLE_WIDTH; j++) {
                if ((j == 0 || j == 1 || j == (POLE_WIDTH - 1) / 2 + 1) && i != POLE_HEIGHT - 1 && i != 20) {
                    if (j == 0 || j == 1) {
                        attron(COLOR_PAIR(1));
                        printw("%c", pole[i][j]);
                    } else if (pole[i][j] == '*') {
                        attron(COLOR_PAIR(4));
                        printw("%c", pole[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        printw("%c", pole[i][j]);
                    }
                } else if (i == POLE_HEIGHT - 1) {
                    attron(COLOR_PAIR(1));
                    printw("%c", pole[i][j]);
                } else if (i == 20 && j != 2 && j != POLE_WIDTH - 1) {
                    if (j == 1) {
                        attron(COLOR_PAIR(1));
                        printw("%c", pole[i][j]);
                    } else if (pole[i][j] == '*') {
                        attron(COLOR_PAIR(4));
                        printw("%c", pole[i][j]);
                    } else {
                        attron(COLOR_PAIR(3));
                        printw("%c", pole[i][j]);
                    }
                } else if (pole[i][j] == '*') {
                    attron(COLOR_PAIR(4));
                    printw("%c", pole[i][j]);
                } else {
                    attron(COLOR_PAIR(1));
                    printw("%c", pole[i][j]);
                }
            }
            printw("\n");
            attron(COLOR_PAIR(1));
        }
    }
}

int isnt_digit(char c) {
    int flag = 0;
    if (!(c == '+' || c == '-' || c == '*' || c == '/' || c == '~' || c == '^' ||
          c == 'h' || c == 'p' || c == 'q' || c == 't' || c == 'k' || c == 'l' || c == 'a'))
        flag++;
    return flag;
}

void calc(char c, t_numbers *stk) {
    double a, b;
    if (isnt_digit(c) == 0) {
        if (prior(c) == 2 || prior(c) == 3 || prior(c) == 6) {
            a = pop_numbers(stk);
            b = pop_numbers(stk);
            if (c == '+') push_numbers(stk, b + a);
            if (c == '-') push_numbers(stk, b - a);
            if (c == '*') push_numbers(stk, b * a);
            if (c == '/') {
                push_numbers(stk, b / a);
            }
            if (c == '^') push_numbers(stk, pow(b, a));

        } else {
            a = pop_numbers(stk);
            if (c == '~') push_numbers(stk, a - 2 * a);
            if (c == 'h') push_numbers(stk, sin(a));
            if (c == 'p') push_numbers(stk, cos(a));
            if (c == 'a') push_numbers(stk, fabs(a));
            if (c == 't') push_numbers(stk, tan(a));
            if (c == 'k') push_numbers(stk, pow(tan(a), -1));
            if (c == 'q') push_numbers(stk, sqrt(a));
            if (c == 'l') push_numbers(stk, log(a));
            // printw("%lf\n", stk->num[stk->top - 1]);
        }
    }
}

void create_pole(char **pole, char *polish, t_numbers *stk) {
    double max = max_point(polish, stk);
    stk->top = 0;
    for (int i = 0; i < POLE_HEIGHT; i++) {
        int k;
        for (int j = 0; j < POLE_WIDTH; j++) {
            if ((j != 0 && j != 1) && i != POLE_HEIGHT - 1) {
                if (j == 2 || j == POLE_WIDTH - 1 || j == (POLE_WIDTH - 1) / 2 + 1 || j == (POLE_WIDTH - 1) / 4 + 2 ||
                    j == (POLE_WIDTH - 1) / 4 * 3 + 2 || j == (POLE_WIDTH - 1) / 8 + 2 || j == (POLE_WIDTH - 1) / 8 * 3 + 2 ||
                    j == (POLE_WIDTH - 1) / 8 * 5 + 2 || j == (POLE_WIDTH - 1) / 8 * 7 + 2)
                    pole[i][j] = '|';
                else
                    pole[i][j] = '-';
            } else if (i == POLE_HEIGHT - 1) {
                if (j == 1 || j == (POLE_WIDTH - 1) / 8 + 1 || j == (POLE_WIDTH - 1) / 8 * 3 + 1 ||
                    j == (POLE_WIDTH - 1) / 8 * 3 + 1 || j == (POLE_WIDTH - 1) / 4 + 1)
                    pole[i][j] = '-';
                else if (j == 2 || j == POLE_WIDTH - 1)
                    pole[i][j] = '8';
                else if (j == (POLE_WIDTH - 1) / 8 + 2 || j == (POLE_WIDTH - 1) / 8 * 7 + 2)
                    pole[i][j] = '6';
                else if (j == (POLE_WIDTH - 1) / 8 * 3 + 2 || j == (POLE_WIDTH - 1) / 8 * 5 + 2)
                    pole[i][j] = '2';
                else if (j == (POLE_WIDTH - 1) / 4 + 2 || j == (POLE_WIDTH - 1) / 4 * 3 + 2)
                    pole[i][j] = '4';
                else if (j == (POLE_WIDTH - 1) / 2 + 1)
                    pole[i][j] = '0';
                else
                    pole[i][j] = ' ';
            } else if (j == 1 && i != 0 && i != (POLE_HEIGHT - 2) / 4 && i != (POLE_HEIGHT - 2) / 2 && i != (POLE_HEIGHT - 2) / 4 * 3 &&
                       i != POLE_HEIGHT - 2) {
                pole[i][j] = ' ';
            } else if (j == 1 && (i == 0 || i == POLE_HEIGHT - 2)) {
                k = 2 * max / 2;
                pole[i][j] = (char)k + 48;
            } else if (j == 1 && (i == (POLE_HEIGHT - 2) / 4 * 3 || i == (POLE_HEIGHT - 2) / 4)) {
                pole[i][j] = (char)k / 2 + 48;
            } else if (j == 1 && i == (POLE_HEIGHT - 2) / 2) {
                pole[i][j] = (int)'0';
            } else if (j == 0 && i != (POLE_HEIGHT - 2) / 4 * 3 && i != POLE_HEIGHT - 2) {
                pole[i][j] = ' ';
            } else if (j == 0 && (i == (POLE_HEIGHT - 2) / 4 * 3 || i == POLE_HEIGHT - 2)) {
                pole[i][j] = '-';
            } else
                pole[i][j] = '-';
        }
    }
}