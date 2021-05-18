/**
 @file  parser.h
 @brief Ficheiro com as funções relativas a operacoes.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"
/**
 * \brief       Função que realiza a soma entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void soma (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);

    if (Y.type == LONG && X.type == LONG) {Y.LONG += X.LONG ; push(s,Y);}
    else if (Y.type == DOUBLE && X.type == LONG) {Y.DOUBLE += X.LONG; push(s,Y);}
    else if (Y.type == LONG && X.type == DOUBLE) {X.DOUBLE += Y.LONG; push(s,X);}
    else if (Y.type == DOUBLE && X.type == DOUBLE) {Y.DOUBLE += X.DOUBLE;push(s,Y);}
    else if (Y.type == ARRAY && X.type == ARRAY){
        int i ;
        STACK *y = Y.ARRAY;
        STACK *x = X.ARRAY;
        for (i = 0; i < y->n_elems ; i++){
            push(x,y->stack[i]);
            
        }
        push_ARRAY(s,X.ARRAY);
    }
}
/**
 * \brief       Função que realiza a diferença entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void menos (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    if (Y.type == LONG && X.type == LONG) push_LONG (s,X.LONG-Y.LONG);
    else if (Y.type == DOUBLE && X.type == LONG) push_DOUBLE (s,X.DOUBLE-Y.LONG);
    else if (Y.type == LONG && X.type == DOUBLE) push_DOUBLE (s,X.DOUBLE-Y.LONG);
    else push_DOUBLE (s,X.DOUBLE-Y.DOUBLE); 
}
/**
 * \brief       Função que realiza o produto entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void multiplicacao (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    if (Y.type == LONG && X.type == LONG) {Y.LONG *= X.LONG ; push(s,Y);}
    else if (Y.type == DOUBLE && X.type == LONG) {Y.DOUBLE *= X.LONG; push(s,Y);}
    else if (Y.type == LONG && X.type == DOUBLE) {X.DOUBLE *= Y.LONG; push(s,X);}
    else if (Y.type == DOUBLE && X.type == DOUBLE) {Y.DOUBLE *= X.DOUBLE;push (s,Y);}
    else if (Y.type == LONG && X.type == ARRAY){
        int i;
        for (i=0;i<Y.LONG;i++){
            push_ARRAY(s,X.ARRAY);
        }
    }
}
/**
 * \brief       Função que realiza a divisão entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void divisao (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    if (Y.type == LONG && X.type == LONG) push_LONG (s,X.LONG/Y.LONG);
    else if (Y.type == DOUBLE && X.type == LONG) push_DOUBLE (s,X.LONG/Y.DOUBLE);
    else if (Y.type == LONG && X.type == DOUBLE) push_DOUBLE (s,X.DOUBLE/Y.LONG);
    else {X.DOUBLE /= Y.DOUBLE;push (s,Y);}
}
/**
 * \brief       Função que retira uma unidade ao primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void decremento (STACK *s){
    DATA X = pop(s);
    if (X.type == LONG ){X.LONG--; push (s,X);}
    else if (X.type == DOUBLE ) {X.DOUBLE-- ; push (s,X);}
    else {X.CHAR-- ; push(s,X);}    
}
/**
 * \brief       Função que acrescenta uma unidade ao primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void aumento (STACK *s){
    DATA X = pop(s);
    if (X.type == LONG ) {X.LONG++; push (s,X);}
    else if (X.type == DOUBLE ) {X.DOUBLE++; push (s,X);}
    else if (X.type == CHAR) {X.CHAR++ ; push(s,X);}
    else if (X.type == ARRAY){
        DATA Y = pop(X.ARRAY);
        push_ARRAY(s,X.ARRAY);
        push(s,Y);
    } 
}
/**
 * \brief       Função que efetua o modulo entre os dois primeiros elementos do topo da stack 
 * @param s     Stack
 */ 
void percentagem (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    push_LONG (s,X.LONG%Y.LONG);
}
/**
 * \brief       Função que efetua a exponenciação entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void esteg (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    if (Y.type == LONG && X.type == LONG) {Y.LONG = pow(X.LONG,Y.LONG); push(s,Y);}  
    else if (Y.type == DOUBLE && X.type == LONG) push_DOUBLE (s,pow(X.LONG,Y.DOUBLE));
    else if (Y.type == LONG && X.type == DOUBLE) push_DOUBLE (s,pow(X.DOUBLE,Y.LONG));
    else push_DOUBLE (s,pow(X.DOUBLE,Y.DOUBLE));
}
/**
 * \brief       Função que efetua a operação lógica E entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void icomercial (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    push_LONG  (s,Y.LONG&X.LONG);  
}
/**
 * \brief       Função que efetua a operação lógica not entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void tile (STACK *s){
    DATA X = pop(s);
    push_LONG (s,~X.LONG);  
}
/**
 * \brief       Função que efetua a operação lógica xor entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void acento (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    push_LONG  (s,Y.LONG^X.LONG); 
}
/**
 * \brief       Função que efetua a operação lógica ou entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void barra_vertical (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    push_LONG (s,Y.LONG|X.LONG); 
}
/**
 * \brief       Função que retira da stack o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void elimina (STACK *s){
    pop(s);
}
/**
 * \brief       Função que efetua a duplicação do primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void linhahori (STACK *s){
    DATA Y = pop(s);
        if (Y.type == LONG) {
            push_LONG (s,Y.LONG); 
            push_LONG (s,Y.LONG);
        }
        else if (Y.type == CHAR) {
            push_CHAR (s,Y.CHAR);
            push_CHAR (s,Y.CHAR);

        }
        else if (Y.type == DOUBLE) {
            push_DOUBLE (s,Y.DOUBLE);
            push_DOUBLE (s,Y.DOUBLE);
        }
        else  {
            push_STRING (s,Y.STRING);
            push_STRING (s,Y.STRING);
        }
}
/**
 * \brief       Função que efetua a troca entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void barrabarra (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
        push (s,Y);
        push (s,X);
}
/**
 * \brief       Função que realiza a rodagem entre os 3 primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void arouba (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    DATA Z = pop(s);
        push(s,X);
        push(s,Y);
        push(s,Z);
}
/**
 * \brief       Função que efetua a leitura de uma linha
 * @param s     Stack
 */ 
void ler_linhas (STACK *s){
    char *linha;
    linha = malloc(10240*sizeof(char));
    assert(fgets(linha, 10240, stdin) != NULL);
    linha[strlen(linha)-1] = 0;
    push_STRING (s,linha);
}
/**
 * \brief       Função que copia o elemento que se encontre na n-ésima posição
 * @param s     Stack
 */ 
void nelemento (STACK *s){
    DATA X = pop(s);
    STACK aux = *s;
    while (X.LONG!=0){
    pop(&aux);                                          
    X.LONG--;
    } 
    DATA Y = pop(&aux);
    switch(Y.type){
        case(LONG):
            push_LONG(s,Y.LONG);break;
        case(CHAR):
            push_CHAR(s,Y.CHAR);break;
        case(DOUBLE):
            push_CHAR(s,Y.DOUBLE);break;
        case(STRING):
            push_STRING(s,Y.STRING);break;
        default : break;
    }
}
/**
 * \brief       Função que converte o elemento do topo da stack para double
 * @param s     Stack
 */ 
void doubleconv (STACK *s){
    DATA Y = pop(s);
        if(Y.type == LONG){
            double k = (double) Y.LONG;
            push_DOUBLE (s,k);
        }else if (Y.type == CHAR){
            double k = (double) Y.CHAR;
            push_DOUBLE (s,k);
        }else if (Y.type == DOUBLE){
            push(s,Y);
        }
        else {
            char *sobradois;
            double r = strtod (Y.STRING,&sobradois);
            push_DOUBLE(s,r);
        }
}
/**
 * \brief       Função que converte o elemento do topo da stack para long
 * @param s     Stack
 */ 
void longconv (STACK *s){
    DATA Y = pop(s);
    if (Y.type == CHAR) {
        long r = (long) Y.CHAR;
        push_LONG(s, r);
    }else if (Y.type == DOUBLE){
        long r = (long) Y.DOUBLE;
        push_LONG (s,r);
    }
    else if (Y.type == LONG) { long r = (long) Y.LONG; push_LONG(s,r);}

    else {
        char *sobradois;
        long r = strtol (Y.STRING,&sobradois,10);
        push_LONG(s,r);
    }

}
/**
 * \brief       Função que converte o elemento do topo da stack para char
 * @param s     Stack
 */ 
void operadorc (STACK *s){
    DATA Y = pop(s);
    if (Y.type == LONG) {
        char r = (char) Y.LONG;
        push_CHAR(s, r);
    }
    else push (s,Y);
}
/**
 * \brief       Função que coloca o maior dos dois primeiros elementos do topo da stack no topo da stack
 * @param s     Stack
 */ 
void emaior (STACK *s) {
        DATA Y = pop (s);
        DATA X = pop (s);
        if (Y.type == LONG && X.type == LONG){
            if (Y.LONG > X.LONG) push_LONG(s,Y.LONG);
            else push_LONG(s,X.LONG);
        }else if (Y.type == DOUBLE && X.type == LONG){
            if (Y.DOUBLE > X.LONG) push_DOUBLE(s,Y.DOUBLE);
            else push_LONG(s,X.LONG);
        }else if (X.type == DOUBLE && Y.type == LONG){
            if (Y.LONG > X.DOUBLE) push_LONG(s,Y.LONG);
            else push_DOUBLE(s,X.DOUBLE);
        }else if (X.type == DOUBLE && Y.type == DOUBLE){
            if (Y.DOUBLE > X.DOUBLE) push_DOUBLE(s,Y.DOUBLE);
            else push_DOUBLE(s,X.DOUBLE);
        }else if (Y.type == CHAR && X.type == LONG){
            if (Y.CHAR > X.LONG) push_CHAR(s,Y.CHAR);
            else push_LONG(s,X.LONG);
        }else if (Y.type == CHAR && X.type == DOUBLE){
            if (Y.CHAR > X.DOUBLE) push_CHAR(s,Y.CHAR);
            else push_DOUBLE(s,X.DOUBLE);
        }else if (Y.type == LONG && X.type == CHAR){
            if (Y.LONG > X.CHAR) push_LONG(s,Y.LONG);
            else push_CHAR(s,X.CHAR);
        }else if (Y.type == DOUBLE && X.type == CHAR){
            if (Y.DOUBLE > X.CHAR) push_DOUBLE(s,Y.DOUBLE);
            else push_CHAR(s,X.CHAR);
        }else if (Y.type == CHAR && X.type == CHAR){
            if (Y.CHAR > X.CHAR) push_CHAR(s,Y.CHAR);
            else push_CHAR(s,X.CHAR);
        }
}
/**
 * \brief       Função que coloca o menor dos dois primeiros elementos do topo da stack no topo da stack
 * @param s     Stack
 */ 
void emenor (STACK *s){
DATA Y = pop (s);
DATA X = pop (s);
    if (Y.type == LONG && X.type == LONG){
        if (Y.LONG < X.LONG) push_LONG(s,Y.LONG);
        else push_LONG(s,X.LONG);
    }else if (Y.type == DOUBLE && X.type == LONG){
    if (Y.DOUBLE < X.LONG) push_DOUBLE(s,Y.DOUBLE);
        else push_LONG(s,X.LONG);
    }else if (X.type == DOUBLE && Y.type == LONG){
        if (Y.LONG < X.DOUBLE) push_LONG(s,Y.LONG);
        else push_DOUBLE(s,X.DOUBLE);
    }else if (X.type == DOUBLE && Y.type == DOUBLE){
        if (Y.DOUBLE < X.DOUBLE) push_DOUBLE(s,Y.DOUBLE);
        else push_DOUBLE(s,X.DOUBLE);
    }else if (Y.type == CHAR && X.type == LONG){
        if (Y.CHAR < X.LONG) push_CHAR(s,Y.CHAR);
        else push_LONG(s,X.LONG);
    }else if (Y.type == CHAR && X.type == DOUBLE){
        if (Y.CHAR < X.DOUBLE) push_CHAR(s,Y.CHAR);
        else push_DOUBLE(s,X.DOUBLE);
    }else if (Y.type == LONG && X.type == CHAR){
        if (Y.LONG < X.CHAR) push_LONG(s,Y.LONG);
        else push_CHAR(s,X.CHAR);
    }else if (Y.type == DOUBLE && X.type == CHAR){
        if (Y.DOUBLE < X.CHAR) push_DOUBLE(s,Y.DOUBLE);
        else push_CHAR(s,X.CHAR);
    }else if (Y.type == CHAR && X.type == CHAR){
        if (Y.CHAR < X.CHAR) push_CHAR(s,Y.CHAR);
        else push_CHAR(s,X.CHAR);
    }
}
/**
 * \brief       Função que realiza um if-then-else.Caso o terceiro elemento do topo da stack for diferente de zero devolve o segundo elemento do topo, caso contrário devolve o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void pontoi (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    DATA Z = pop (s);
    if (Z.type == LONG) {
        if (Z.LONG != 0 && X.type == LONG) push_LONG(s,X.LONG);
        else if (Z.LONG != 0 && X.type == DOUBLE) push_DOUBLE(s,X.DOUBLE);
        else if (Z.LONG == 0 && Y.type == LONG) push_LONG(s,Y.LONG);
        else if (Z.LONG == 0 && Y.type == DOUBLE) push_DOUBLE(s,Y.DOUBLE);
    }else if (Z.type == DOUBLE){
        if (Z.DOUBLE != 0 && X.type == LONG) push_LONG(s,X.LONG);
        else if (Z.DOUBLE != 0 && X.type == DOUBLE) push_DOUBLE(s,X.DOUBLE);
        else if (Z.DOUBLE == 0 && Y.type == LONG) push_LONG(s,Y.LONG);
        else if (Z.DOUBLE == 0 && Y.type == DOUBLE) push_DOUBLE(s,Y.DOUBLE);
    }
}
/**
 * \brief       Função que caso o segundo elemento do topo da stack seja 0 devolve-se a si mesmo, caso contrário devolve o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void eshort (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    if (Y.type == LONG && X.type == LONG){
        if (X.LONG != 0) push_LONG(s,Y.LONG);
        else push_LONG(s,X.LONG);
    }else if (Y.type == DOUBLE && X.type == LONG){
        if (X.LONG !=0) push_DOUBLE(s,Y.DOUBLE);
        else push_LONG(s,X.LONG);      
    }else if (Y.type == CHAR && X.type == LONG){
        if (X.LONG !=0) push_CHAR(s,Y.CHAR);
        else push_LONG(s,X.LONG);
    }
}
/**
 * \brief       Função que verifica se os dois primeiros elementos são diferentes de 0, caso isso aconteça devolve 0 , caso contrário devolve um desses elementos 
 * @param s     Stack
 */ 
void oushort (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    if (Y.type == LONG && X.type == LONG){
        if (X.LONG == 0 && Y.LONG == 0) push_LONG(s,Y.LONG);
        else if (X.LONG == 0 && Y.LONG != 0) push_LONG(s,Y.LONG);
        else if (X.LONG != 0 && Y.LONG == 0) push_LONG(s,X.LONG);
        else push_LONG(s,X.LONG);
    }else if (Y.type == DOUBLE && X.type == LONG){
        if (X.LONG == 0 && Y.DOUBLE == 0) push_LONG(s,Y.DOUBLE);
        else if (X.LONG == 0 && Y.DOUBLE != 0) push_LONG(s,Y.DOUBLE);
        else if (X.LONG != 0 && Y.DOUBLE == 0) push_LONG(s,X.LONG);
        else push_LONG(s,X.LONG);
    }else if (Y.type == LONG && X.type == DOUBLE){
        if (X.DOUBLE == 0 && Y.LONG == 0) push_LONG(s,Y.LONG);
        else if (X.DOUBLE == 0 && Y.LONG != 0) push_LONG(s,Y.LONG);
        else if (X.DOUBLE != 0 && Y.LONG == 0) push_LONG(s,X.DOUBLE);
        else push_LONG(s,X.DOUBLE);    
    }else if (Y.type == CHAR && X.type == LONG){
        if (X.LONG == 0 && Y.CHAR == 0) push_LONG(s,Y.CHAR);
        else if (X.LONG == 0 && Y.CHAR != 0) push_LONG(s,Y.CHAR);
        else if (X.LONG != 0 && Y.CHAR == 0) push_LONG(s,X.LONG);
        else push_LONG(s,X.LONG); 
    }     
}
/**
 * \brief       Função que verifica se os dois primeiros elementos do topo da stack são iguais
 * @param s     Stack
 */ 
void igual (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    long r = 1;
    long z = 0;
    if (Y.type == LONG && X.type == LONG){
        if (Y.LONG == X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == DOUBLE){
        if (Y.DOUBLE == X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == LONG){
        if (Y.DOUBLE == X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == DOUBLE){
        if (Y.LONG == X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == CHAR){
        if (Y.CHAR == X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == CHAR){
        if (Y.LONG == X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == LONG){
        if (Y.CHAR == X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == STRING && X.type == STRING){
        if (Y.STRING == X.STRING) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == ARRAY){
        STACK *x = X.ARRAY;
        push(s,x->stack[Y.LONG]); 
    }
}
/**
 * \brief       Função que verifica se o segundo elemento do topo stack é maior que o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void maior (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    long r = 1;
    long z = 0;
    if (Y.type == LONG && X.type == LONG){
        if (Y.LONG < X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == DOUBLE){
        if (Y.DOUBLE < X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == CHAR){
        if (Y.CHAR < X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == CHAR){
        if (Y.LONG < X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == LONG){
        if (Y.CHAR < X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == LONG){
        if (Y.DOUBLE < X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == DOUBLE){
        if (Y.LONG < X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == ARRAY){
        int i;
        STACK *x = X.ARRAY;
        for (i = x->n_elems-Y.LONG; i < x->n_elems ; i++){
            push(s,x->stack[i]);
        }
    }
}
/**
 * \brief       Função que verifica se o segundo elemento do topo stack é menor que o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void menor (STACK *s){
    DATA Y = pop (s);
    DATA X = pop (s);
    long r = 1;
    long z = 0;
    if (Y.type == LONG && X.type == LONG){
        if (Y.LONG > X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == DOUBLE){
        if (Y.DOUBLE > X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == CHAR){
        if (Y.CHAR > X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == CHAR){
        if (Y.LONG > X.CHAR) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == CHAR && X.type == LONG){
        if (Y.CHAR > X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == DOUBLE && X.type == LONG){
        if (Y.DOUBLE > X.LONG) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == DOUBLE){
        if (Y.LONG > X.DOUBLE) push_LONG (s,r);
        else push_LONG(s,z);
    }else if (Y.type == LONG && X.type == ARRAY){
        int i;
        STACK *x = X.ARRAY;
        for (i = 0; i < Y.LONG ; i++){
            push(s,x->stack[i]);
        }
    }
}
/**
 * \brief       Função que efetua a negação do primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void negacao (STACK *s){
    DATA Y = pop (s);
    long r = 1;
    long z = 0;
    if (Y.type == LONG ){
        if (Y.LONG != 0) push_LONG(s,z);
        else push_LONG(s,r);
    }else if (Y.type == DOUBLE ){
        if (Y.DOUBLE != 0) push_LONG(s,z);
        else push_LONG(s,r);
    }else if (Y.type == CHAR ){
        if (Y.CHAR != 0) push_LONG(s,z);
        else push_LONG(s,r);
    }
}
/**
 * \brief       Função que efetua a virgula os elementos do topo da stack
 * @param s     Stack
 */ 
void virgula (STACK *s){
    DATA X = pop(s);
    int contador;
    if (X.type == LONG ){
        STACK *x = create_stack();
        for (contador = 0;contador < X.LONG;contador++){
            push_LONG(x,contador);
        }
        push_ARRAY(s,x);
    }else if (X.type == ARRAY){
        STACK *x = X.ARRAY;
        push_LONG(s,x->n_elems);
    }
}
/**
 * \brief       Função que permite utilizar as variaveis e os seus valores 
 * @param s     Stack
 * @param token Token elemento
 */
void geral (STACK *s,char* token){
    switch (*token)
    {
        case 'A' : push(s,s->var[0]);break;
        case 'B' : push(s,s->var[1]);break;
        case 'C' : push(s,s->var[2]);break;
        case 'D' : push(s,s->var[3]);break;
        case 'E' : push(s,s->var[4]);break;
        case 'F' : push(s,s->var[5]);break;
        case 'N' : push(s,s->var[6]);break;
        case 'S' : push(s,s->var[7]);break;
        case 'X' : push(s,s->var[8]);break;
        case 'Y' : push(s,s->var[9]);break;
        case 'Z' : push(s,s->var[10]);break;
    }
}
/**
 * \brief       Função que permite utilizar os tokens de 2 pontos
 * @param s     Stack
 * @param token Token elemento
 */
void pontosgeral (STACK *s, char* token){
    DATA X = pop(s);
    push (s,X);
    switch (token[1])
    {
        case 'A' : s->var[0] = X;break;
        case 'B' : s->var[1] = X;break;
        case 'C' : s->var[2] = X;break;
        case 'D' : s->var[3] = X;break;
        case 'E' : s->var[4] = X;break;
        case 'F' : s->var[5] = X;break;
        case 'N' : s->var[6] = X;break;
        case 'S' : s->var[7] = X;break;
        case 'X' : s->var[8] = X;break;
        case 'Y' : s->var[9] = X;break;
        case 'Z' : s->var[10] = X;break;
    }
}
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat (STACK *s,char token){
    switch (token){
        case '+' : soma (s);break;
        case '-': menos (s);break;
        case '*' : multiplicacao (s);break;
        case '/' : divisao (s);break;
        case '(': decremento(s);break;
        case ')': aumento(s);break;
        case '%': percentagem(s);break;
        case '#': esteg(s);break;
        case ',': virgula(s);break;
    }
}
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat2 (STACK *s,char token){
    switch (token){
        case '&' : icomercial (s);break;                        
        case '~': tile (s);break;
        case '^' : acento (s);break;
        case '|' : barra_vertical (s);break;
        case ';': elimina(s);break;
        case '_': linhahori(s);break;
        case '\\': barrabarra(s);break;
        case '@': arouba(s);break;
    }
}
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat3 (STACK *s,char token){
    switch (token){
        case 'l' : ler_linhas(s);break;                        
        case '$': nelemento(s);break;
        case 'f' : doubleconv(s);break;
        case 'i' : longconv(s);break;
        case 'c': operadorc(s);break;
    }
}
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat4 (STACK *s,char token){
    switch (token){
        case '?' : pontoi (s);break;
        case '=': igual(s);break;
        case '>': maior(s);break;
        case '<': menor(s);break;
        case '!': negacao(s);break;
    }
}