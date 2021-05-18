/**
 @file  stack.h
 @brief Ficheiro com as funções relativas á stack.c
 */
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <assert.h>

/*!
 * \typedef TYPE
 * \brief Utilizada para definir os diferentes tipos de variavel na nossa stack
 * \inpublicapi
 */
typedef enum {
    LONG = 1 , /**< tipo LONG ou 1 */
    DOUBLE = 2 , /**< tipo DOUBLE ou 2 */
    CHAR = 4 , /**< tipo CHAR ou 4 */
    STRING = 8,/**< tipo STRING ou 8 */
    ARRAY = 16 /**< tipo ARRAY ou 16 */
} TYPE; /**< TYPE */

/**
 * \def INTEGER
 * Permite definir o INTEGER como LONG ou CHAR
 */
#define INTEGER (LONG | CHAR)
/**
 * \def NUMBER
 * Permite definir o NUMBER como INTEGER ou DOUBLE
 */
#define NUMBER (INTEGER | DOUBLE)

/**
 * \def MAKE_DATA
 * Permite transformar um DATA no type que queremos
 */
#define MAKE_DATA(var, TYPE, valor) \
        DATA var;                   \
        var.TYPE = valor;           \
        var.type = TYPE;            \

/**
 * \typedef DATA
 * \struct data Utilizada para guardar algo que não sabemos e depois transformamos no TYPE que quisermos
 * \inpublicapi
 */
typedef struct data {
    TYPE type; /**< tipo que está presente num DATA */

    long LONG; /**< tipo LONG */
    double DOUBLE; /**< tipo DOUBLE */
    char CHAR; /**< tipo CHAR */
    char *STRING; /**< tipo STRING */
    struct stack *ARRAY; /**< tipo ARRAY */
} DATA; /**< DATA */

/**
 * \typedef STACK
 * \struct stack struct para definir a stack
 * \inpublicapi
 */
typedef struct stack {
    DATA *stack;  /**< DATA do pointer da stack que é necessário para armazenar as variaveis que temos na stack */
    int size; /**< tamanho da stack*/
    int n_elems; /**< numero de elementos */
    DATA var[26]; /**< array com 26 elementos que permite guardar variaveis do tipo DATA */
} STACK; /**< STACK */


/*
int has_type(DATA elem, int mask);
*/
/**
 * \brief       Função que cria uma stack com o tamanho de 100
 */
STACK *create_stack();
/**
 * \brief       Função que devolve para o topo da stack o elemento que passamos como argumento
 * @param s     Stack
 * @param elem  Elemento que queremos passar para o topo da Stack
 */
void push(STACK *s, DATA elem);
/**
 * \brief       Função que retira o elemento do topo da stack
 * @param s     Stack
 */
DATA pop(STACK *s);
/**
 * \brief       Função que mostra qual o elemento que se encontra no topo da stack
 * @param s     Stack
 */
DATA top(STACK *s);
/**
 * \brief       Função que verifica se a stack está vazia
 * @param s     Stack
 */
int is_empty(STACK *s);
/**
 * \brief       Função que permite dar print á nossa stack
 * @param s     Stack
 */
void print_stack(STACK *s);

/*!
 * \def STACK_OPERATION_PROMO
 * \brief Permite criar funcoes pop e push para cada TYPE
 */
#define STACK_OPERATION_PROTO(_type,_name)   \
    void push_##_name(STACK *s,_type val);   \
    _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)
STACK_OPERATION_PROTO(struct stack*,ARRAY)

#endif