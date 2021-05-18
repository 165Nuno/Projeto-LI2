#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "parser.h"

/**
 * \brief    Função main que é a responsável pela a stack
 */
int main(void){
        STACK *s = create_stack();
        char line[10240];
        assert(fgets(line, 10240, stdin) != NULL);
        assert(line [strlen(line) - 1] == '\n');
        parse (line,s);
        print_stack(s);
        printf("\n");
        return 0;

        



}




