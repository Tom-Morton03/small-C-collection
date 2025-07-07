#include "common.h"

float compute(float operand1, float operand2, char operator)
{
    float result = 0;
    switch (operator)
    {
        case PLUS:
            result = operand2 + operand1;
            break;
        case MINUS:
            result = operand2 - operand1;
            break;
        case MULTIPLY:
            result = operand2 * operand1;
            break;
        case DIVIDE:
            result = operand2 / operand1;
            break;
    }
    return result;
}


// Takes the postfix expression as input. Iterates through it left-to-right: If the element is a number, add it to
// the stack, if it is an operator, pop the top two numbers off the stack and carry out the operation on them, putting
// the result back onto the stack. Repeat until whole expression has been parsed. Result should be the only element
// left on the stack.

float solve_postfix(Token* expr, int num_of_tokens)
{
    float stack[BUFFER_SIZE];
    int stack_counter = -1;

    for (int i = 0; i < num_of_tokens; i++)
    {
        if (expr[i].type == TOKEN_NUMBER)
        {
            stack_counter++;
            stack[stack_counter] = expr[i].value.number;
        }
        else
        {
            float stack_top = stack[stack_counter];
            float stack_next = stack[stack_counter - 1];
            stack_counter = stack_counter - 2;

            float result = compute (stack_top, stack_next, expr[i].value.operator);

            stack_counter++;
            stack[stack_counter] = result;
        }
    }

    return stack[0];
}


