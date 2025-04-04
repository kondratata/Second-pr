#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "error_handler.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *error_path = NULL;
    int users_flag = 0;
    int processes_flag = 0;
    // Определение длинных опций
    struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"error", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0}
    };

    // Обработка опций
    while ((opt = getopt_long(argc, argv, "uphl:e:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'u':
                users_flag = 1;
                if (log_path) {
                    set_log_path(log_path);}
                break;
            case 'p':
                processes_flag = 1;
                if (log_path) {
                    set_log_path(log_path);}
                break;
            case 'h':
                print_help();
                return 0;
            case 'l':
                log_path = optarg;
                set_log_path(log_path);
                break;
            case 'e':
                error_path = optarg;
                set_error_path(error_path);
                break;
            default:
                print_help();
                return 1;
        }
    }
    if (error_path) {
        set_log_path(error_path);
        }

    if (users_flag) {
        list_users(); // Вывод списка пользователей
    }
    if (processes_flag) {
        list_processes  (); // Вывод списка процессов
    }

    // Если не было указано ни одной команды, выводим справку
    if (optind == 1 && !users_flag && !processes_flag) {
        print_help();
    }
    return 0;
}
