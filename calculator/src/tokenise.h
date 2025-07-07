#ifndef TOKENISE_H

#define TOKENISE_H

#include "common.h"

char** split_string(char* str, int* num_of_tokens);



Token* tokenise(char** arr, int num_of_tokens);

#endif
