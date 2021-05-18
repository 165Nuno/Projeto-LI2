/**
 @file  stack.h
 @brief Ficheiro com as funções relativas á stack.c
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
int has_type(DATA elem, int mask) {
    return (elem.type & mask) != 0;
}
*/
/**
 * \brief       Função que cria uma stack com o tamanho de 100
 */
STACK *create_stack() {
    STACK *s = (STACK *) calloc(1,sizeof(STACK));
    s->var[0].type = LONG;
    s->var[0].LONG = 10;
    s->var[1].type = LONG;
    s->var[1].LONG = 11;
    s->var[2].type = LONG;
    s->var[2].LONG = 12;
    s->var[3].type = LONG;
    s->var[3].LONG = 13;
    s->var[4].type = LONG;
    s->var[4].LONG = 14;
    s->var[5].type = LONG;
    s->var[5].LONG = 15;
    s->var[6].type = CHAR;
    s->var[6].CHAR = '\n';
    s->var[7].type = CHAR;
    s->var[7].CHAR = ' ';
    s->var[8].type = LONG;
    s->var[8].LONG = 0;
    s->var[9].type = LONG;
    s->var[9].LONG = 1;
    s->var[10].type = LONG;
    s->var[10].LONG = 2;
    s->var[11].type = CHAR;
    s->var[11].type = '\0';
    s->var[12].type = CHAR;
    s->var[12].type = '\0';
    s->size = 100;
    s->stack = (DATA *) calloc (s->size, sizeof(DATA));
    return s;
}
/**
 * \brief       Função que devolve para o topo da stack o elemento que passamos como argumento
 * @param s     Stack
 * @param elem  Elemento que queremos passar para o topo da Stack
 */
void push(STACK *s, DATA elem) {
    if(s->size == s->n_elems) {
        s->size += 100;
        s->stack = (DATA *) realloc(s->stack,s->size * sizeof(DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}
/**
 * \brief       Função que retira o elemento do topo da stack
 * @param s     Stack
 */
DATA pop(STACK *s){
    s->n_elems--;
    return s->stack[s->n_elems];
}
/**
 * \brief       Função que mostra qual o elemento que se encontra no topo da stack
 * @param s     Stack
 */
DATA top(STACK *s){
    return s->stack[s->n_elems -1];
}
/**
 * \brief       Função que verifica se a stack está vazia
 * @param s     Stack
 */
int is_empty(STACK *s) {
    return s->n_elems == 0;
}
/**
 * \brief       Função que permite dar print á nossa stack
 * @param s     Stack
 */
void print_stack(STACK *s) {
    for(int K = 0;K < s->n_elems;K++) {
        DATA elem = s->stack[K];
        TYPE type = elem.type;
        switch(type) {
            case LONG:
                printf("%ld", elem.LONG); break;
            case DOUBLE:
                printf("%g", elem.DOUBLE); break;
            case CHAR:
                printf("%c", elem.CHAR); break;
            case STRING:
                printf("%s", elem.STRING); break;
            case ARRAY:
                print_stack(elem.ARRAY);break;
        }
    }
}
/**
 * \def STACK_OPERATION
 * Macro que permite ter pop e push para cada TYPE
 */
#define STACK_OPERATION(_type,_name)              \
    void push_##_name(STACK *s, _type val) {      \
        DATA elem;                                \
        elem.type = _name;                        \
        elem._name = val;                         \
        push(s,elem);                             \
    }                                             \
    _type pop_##_name(STACK *s) {                 \
        DATA elem = pop (s);                      \
        assert(elem.type == _name);               \
        return elem._name;                        \
    }                                             

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
STACK_OPERATION(struct stack*,ARRAY)

