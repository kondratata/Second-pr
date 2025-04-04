#include <stdio.h>

void print_help() {
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  -u, --users       List users and their home directories\n");
    printf("  -p, --processes   List running processes\n");
    printf("  -h, --help        Show this help message\n");
    printf("  -l, --log PATH    Redirect output to a log file\n");
    printf("  -e, --errors PATH Redirect errors to a file\n");
}
