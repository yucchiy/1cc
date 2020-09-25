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

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    for (int i = 0; code[i] != NULL; i++) {
        gen(code[i]);

        printf("    pop rax\n");
    }

    printf("    ret\n");

    return 0;
}