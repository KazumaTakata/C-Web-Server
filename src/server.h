#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "./token.h"

struct Lexer
{
    char *input_string;
    int position;
    int readPosition;
    char ch;
};

void readChar(struct Lexer *l)
{
    if (l->readPosition >= strlen(l->input_string))
    {
        l->ch = 0;
    }
    else
    {
        l->ch = l->input_string[l->readPosition];
    }
    l->position = l->readPosition;
    l->readPosition += 1;
};

struct Lexer *createLexer(char *input_string)
{
    struct Lexer *l = (struct Lexer *)malloc(sizeof(struct Lexer));
    l->position = 0;
    l->readPosition = 0;
    l->input_string = strdup(input_string);
    readChar(l);
    return l;
};

void skipWhitespace(struct Lexer *l)
{
    while (l->ch == ' ' || l->ch == '\t')
    {
        readChar(l);
    }
};

int isLetter(char ch)
{
    return ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r';
};

void slice_str(const char *str, char *buffer, size_t start, size_t end)
{
    size_t j = 0;
    for (size_t i = start; i <= end; ++i)
    {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
};

void readToken(struct Lexer *l, char buffer[])
{
    int po = l->position;
    while (isLetter(l->ch))
    {
        readChar(l);
    };
    slice_str(l->input_string, buffer, po, l->position - 1);
};

struct Token *nextToken(struct Lexer *l)
{

    struct Token *token;
    skipWhitespace(l);
    if (l->ch == '\r')
    {
        if (l->input_string[l->readPosition] == '\n')
        {
            char lit[] = "\r\n";
            token = createToken(DELIMITER, lit);
            readChar(l);
            readChar(l);
        }
    }
    else if (l->ch == 0)
    {
        token = createToken(EOFT, &l->ch);
        readChar(l);
    }
    else
    {
        const size_t len = strlen(l->input_string);
        char ident[len + 1];
        readToken(l, ident);
        token = createToken(NORMAL, ident);
    }

    // switch (l->ch)
    // {
    // case '\r':

    //     break;
    // case 0:
    //     token = createToken(EOFT, &l->ch);
    //     readChar(l);
    //     break;
    // case 1:
    //     token = createToken(EOFT, &l->ch);
    //     readChar(l);
    //     break;
    // case 3:
    //     const size_t len = strlen(l->input_string);
    //     char ident[len + 1];
    //     readToken(l, ident);
    //     token = createToken(NORMAL, ident);
    //     break;
    // }

    return token;
};

#endif