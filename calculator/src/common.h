#ifndef COMMON_H

#define COMMON_H

#define BUFFER_SIZE 64

// Each token will hold either a float, or an operator (as a char).
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR 
} token_type;

typedef struct {
    token_type type;
    union {
        float number;
        char operator;
    } value;
} Token;

// Just an enum that holds the ASCII values for operators
typedef enum {
    PLUS = 43,
    MINUS = 45,
    MULTIPLY = 42,
    DIVIDE = 47 
} Operator;


int op_precedence(char op);

int is_operator(char ch);


#endif
