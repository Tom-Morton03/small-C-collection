#include <stdlib.h>

#include "common.h"


// Takes in an infix expression in the form of tokens. Converts infix expression to postfix using an operator stack
// Follows this process:
//  - Initialise a postfix expression and an operator stack (The postfix expression is what will be returned)
//  - Go through infix expression, left-to-right
//  - If element is a number, just append it to the postfix expression
//  - If element is an operator:
//        -> If the operator stack is empty, or if the precendence of the operator is greater than that of the operator
//           currently on top of the operator stack, push the current operator to the operator stack
//        -> Else, pop the operator stack onto the postfix expression until the precedence of the top of the stack is no
//           longer greater than the current operator. Then push current operator onto the operator stack.
// Once looped through, there may still be operators in the stack. Just pop them onto the postfix expression until they've
// all been popped.
Token* infix_to_postfix(Token* infix, int num_of_tokens)
{
    Token *postfix = malloc(num_of_tokens * sizeof(Token));
    Token *operator_stack = malloc(num_of_tokens * sizeof(Token));
    
    int postfix_counter = 0;
    int stack_counter = -1;

    for (int i = 0; i < num_of_tokens; i++)
    {
        if (infix[i].type == TOKEN_NUMBER)
        {
            postfix[postfix_counter] = infix[i];
            postfix_counter++;
        }
        else
        {
            int current_precedence = op_precedence(infix[i].value.operator);
            int stack_precedence = op_precedence(operator_stack[stack_counter].value.operator);

            if (stack_counter == -1 || current_precedence > stack_precedence)
            {
                stack_counter++;
                operator_stack[stack_counter] = infix[i];
            }
            else
            {
                while (stack_precedence >= current_precedence && stack_counter > -1)
                {
                    postfix[postfix_counter++] = operator_stack[stack_counter--];
                    stack_precedence = op_precedence(operator_stack[stack_counter].value.operator);
                }
                stack_counter++;
                operator_stack[stack_counter] = infix[i];
            }
        }
    }

    while (stack_counter > -1)
    {
        postfix[postfix_counter++] = operator_stack[stack_counter--];
    }

    return postfix;
}

// Input is an operator. Higher precedence operator is indicated by a higher number - for easy comparisons
int op_precedence(char op)
{
    switch (op)
    {
        case DIVIDE:
            return 4;
        case MULTIPLY:
            return 3;
        case PLUS:
            return 2;
        case MINUS:
            return 1;
        default:
            return -1;
    }
}


