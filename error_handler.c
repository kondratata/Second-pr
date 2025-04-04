#include <stdio.h>
#include <stdlib.h>
void set_error_path(const char *path) {
    if (freopen(path, "w", stderr) == NULL) {
        perror("Не удалось перенаправить стандартный вывод ошибок.");
        exit(EXIT_FAILURE);
    }
}
