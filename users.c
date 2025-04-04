#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void list_users() {
    char *fp = "/etc/passwd";
    FILE *file = fopen(fp, "r");
    char buffer[256];

    if (file) {
        while (fgets(buffer, 256, file) != NULL) {
            char *username = strtok(buffer, ":");
            char *l = strtok(NULL, ":");
            char *numb = strtok(NULL, ":");
            char *w = strtok(NULL, ":");
            char *home_dir = strtok(NULL, ":");
            char *home_dir1 = strtok(NULL, ":");

            if (numb != NULL) {
                char *endptr;
                long F = strtol(numb, &endptr, 10); // Преобразование строки в long
                if (endptr != numb && F >= 1000) { // Проверка на успешное преобразование и значение UID
                    if (strncmp(home_dir, "/home/", 6) == 0)
                  printf("%s\t\t%s\t\n",username, home_dir);
                 if (strncmp(home_dir1, "/home/", 6) == 0)
                  printf("%s\t\t%s\t\n",username, home_dir1);
                }
            }
        }
        fclose(file);
    } else {
        perror("Ошибка открытия файла");
    }
    
    return ;
}
