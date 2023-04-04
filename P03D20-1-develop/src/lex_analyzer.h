#ifndef SRC_LEX_ANALYZER_H_
#define SRC_LEX_ANALYZER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token {
    int type;
    char operation;
    double operand;
};

void shifter(char** copy, const char* temp, int* counter, char*** data);
int operation_type(char* data, char* oper, char** operations, int size);
void detect_unary_minus(struct token** dst, int n);
int lex_converter(struct token** dst, char** data, int n);
void char_cleaner(char** data, int n);
void get_lexems(char* str, char*** data, int* n);
int get_words(char* str, char*** lexems);
int get_lexors(char* str, int n, char** lexems, char*** data);

#endif  // SRC_LEX_ANALYZER_H_
