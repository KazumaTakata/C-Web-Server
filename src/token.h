#ifndef TOKEN_H
#define TOKEN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum TokenType
{
    DELIMITER,
    NORMAL,
    EOFT
};

// enum TokenType LookupIdent(char *ident);

struct Token
{
    enum TokenType Type;
    char *Literal;
};

// enum TokenType LookupIdent(char *ident)
// {

//     if (strcmp("return", ident) == 0)
//     {
//         return RETURN;
//     }
//     else if (strcmp(ident, "int") == 0)
//     {
//         return INT;
//     }
//     else
//     {
//         return IDENT;
//     }
// }

struct Token *createToken(enum TokenType type, char *literal)
{
    struct Token *t = (struct Token *)malloc(sizeof(struct Token));
    t->Type = type,
    t->Literal = strdup(literal);
    return t;
};

#endif