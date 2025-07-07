#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"
#include "tokenise.h"
#include "postfix.h"
#include "solver.h"

// Follows a simple 6 step process
// 1. Ask user for input
// 2. Store input as a single string
// 3. Split the input into elements of numbers and operators (As strings)
// 4. Convert numbers as strings to floats in this array
// 5. Convert infix expression to postfix (Reverse Polish Notation)
// 6. Solve postfix expression
int main(void) 
{ 
    char input_str[BUFFER_SIZE];
    char **split_expr;
    int num_of_tokens;
    Token *tokenised_expr;
    Token *postfix_expr;
    float result;

    printf("Enter an expression: ");

    if (!fgets(input_str, sizeof(input_str), stdin)) { return 1; };

    // Takes input, splits into an array of strings of numbers and operators
    split_expr = split_string(input_str, &num_of_tokens);
    
    // Converts array of strings into array of numbers (floats) and operators (chars).
    tokenised_expr = tokenise(split_expr, num_of_tokens);

    // Converts infix expression to postfix (unambigous execution order)
    postfix_expr = infix_to_postfix(tokenised_expr, num_of_tokens);

    // Calculates answer from postfix expression
    result = solve_postfix(postfix_expr, num_of_tokens);
    printf("Answer: %f\n", result);

    // Freeing up memory
    for (int i = 0; i < num_of_tokens; i++)
    {
        free(split_expr[i]);
    }
    free(split_expr);
    free(tokenised_expr);
    free(postfix_expr);
    
    
    return 0; 
}




