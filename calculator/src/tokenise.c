#include <stdlib.h>

#include "common.h"


// Takes the string in to_insert, and appends it into the next element of arr (position given by index)
void copy_string(char* arr, char* to_insert)
{
    int i = 0;
    while (to_insert[i] != '\0')
    {
        arr[i] = to_insert[i];
        i++;
    }
    arr[i] = '\0';
}


// Takes a string as input, converts it into an array of elements split by operators.
// e.g. "2+3" is split into ["2","+","3"]
char** split_string(char *str, int* num_of_tokens)
{
    char **tokens = malloc(BUFFER_SIZE * sizeof(char*));
    char *temp = malloc(BUFFER_SIZE * sizeof(char));
    int token_counter = 0;
    int temp_counter = 0;

    while (*str != '\0' && *str != '\n')
    {
        // A flag for if a '-' sign comes after another operator. Makes the next float negative
        int is_negative = (temp_counter == 0 && *str == MINUS) ? 1 : 0;

        if (!is_operator(*str) || is_negative)
        {
            temp[temp_counter] = *str;
            temp_counter++;
        }
        else
        {
            // Once operator hit, append the whole currently stored number to next element in token array 
            temp[temp_counter++] = '\0';
            tokens[token_counter] = malloc(temp_counter * sizeof(char));
            copy_string(tokens[token_counter],temp);
            temp_counter = 0;
            token_counter++;

            // Now append the operator to the array
            temp[0] = *str;
            temp[1] = '\0';
            tokens[token_counter] = malloc(2 * sizeof(char));
            copy_string(tokens[token_counter], temp);
            token_counter++;
        }
        str++;
    }

    // Deal with last token in expression
    temp[temp_counter] = '\0';
    tokens[token_counter] = malloc(temp_counter * sizeof(char));
    copy_string(tokens[token_counter],temp);

    *num_of_tokens = token_counter + 1;

    free(temp);

    return tokens;
}

// Just a boolean function for checking if a character is an operator
int is_operator(char ch)
{
    return (ch == PLUS || ch == MINUS || ch == MULTIPLY || ch == DIVIDE);
}


// Converts an array of strings, to an array of tokens. The key difference being that a
// token has a type - Either a number or an operator. Avoids future confusion when parsing
// numbers and operators together.
Token* tokenise(char** arr, int num_of_tokens)
{
    Token* tokenised = malloc(num_of_tokens * sizeof(Token));

    for (int i = 0; i < num_of_tokens; i++)
    {
        char *end_ptr;
        float value = strtof(arr[i], &end_ptr);
        if (*end_ptr == '\0')
        {
            tokenised[i].type = TOKEN_NUMBER;
            tokenised[i].value.number = value;
        } 
        else
        {
            tokenised[i].type = TOKEN_OPERATOR;
            tokenised[i].value.operator = arr[i][0];
        }
    }
    return tokenised;
}


