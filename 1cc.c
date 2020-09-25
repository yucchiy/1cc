#include "1cc.h"

char *user_input;
Token *token;

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Invalid number of argument passed.\n");
        return 1;
    }

    user_input = argv[1];
    token = tokenize();
    program();
    codegen();

    return 0;
}