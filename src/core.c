#include "core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void check_path_string(char *path) {
    int length = strlen(path);

    if (path[length - 1] != '/') {
        printf("[!] - '/' WAS ADDED TO THE END OF PATH!\n");

        strncat(path, "/", 4);
    }
}

void gen_clang_format_by_path(char *path) {
    struct stat sb;

    check_path_string(path);

    if (stat(path, &sb) == 0) {
        printf("[+] - Path is valid!\n");

        strcat(path, ".clang-format");

        FILE *fptr = fopen(path, "w");

        if (fptr != NULL) {
            fputs("---\nBasedOnStyle: Google\nIndentWidth: 4\nColumnLimit: 110", fptr);

            printf("[!] - .clang-format CREATED IN: %s\n", path);

        } else {
            exit(1);
        }
    } else {
        printf("[-] - Invalid path!\n");
        gen_clang_format_cwd();
    }
}

void gen_clang_format_cwd() {
    FILE *fptr = fopen(".clang-format", "w");

    if (fptr != NULL) {
        fputs("---\nBasedOnStyle: Google\nIndentWidth: 4\nColumnLimit: 110", fptr);

        printf("[!] - .clang-format CREATED IN CURRENT DIR\n");

    } else {
        exit(1);
    }
}
