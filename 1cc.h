#ifndef ONECC_H
#define ONECC_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // Integer
} NodeKind;

typedef struct Node Node;
struct Node {
  NodeKind kind; 
  Node *lhs;
  Node *rhs;
  long val;
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);

bool starts_with(char *p, char *q);

bool consume(char* op);
void expect(char* op);

int expect_number();
bool at_eof();

Token* tokenize();

extern char *user_input;
extern Token *token;

Node *expr();

void gen(Node *node);

#endif