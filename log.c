#include <stdio.h>
#include <stdlib.h>

void set_log_path(const char *path) {
    if (freopen(path, "w", stdout) == NULL) {
        perror("Не удалось перенаправить стандартный вывод.");
        exit(EXIT_FAILURE);
    }
}
