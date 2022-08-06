#include "header.h"

int main() {
    char data[NMAX];
    char new_data[NMAX];
    char polish[NMAX];
    signes stack;
    init_signes(&stack);
    input(data);
    change_str(data, new_data);
    check_extra_symbols(new_data);
    if (check_data(new_data) == 0){
        printf("%s\n", new_data);
        polish_get(&stack, new_data, polish);
        printf("%s", polish);
    }
    else printf("mistake");
    return 0;
}
