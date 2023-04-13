//made by murkybee! 

#include <stdio.h>
#include <stdlib.h>
#include "core.h"

int main(int argc, char *argv[]) {

    (void)argc;

    if (argv[1] != NULL){
        gen_clang_format_by_path(argv[1]);
    } else {
        gen_clang_format_cwd();
    }

    return 0;
}
