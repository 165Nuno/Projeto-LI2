/**
 @file  parser.h
 @brief Ficheiro com as funções relativas a operacoes.c
 */
#ifndef PARSER_H_OPERATORS_H
#define PARSER_H_OPERATORS_H
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat (STACK *s,char token);
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat2 (STACK *s,char token);
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat3 (STACK *s,char token);
/**
 * \brief       Função que permite utilizar alguns operadores
 * @param s     Stack
 * @param token Token elemento
 */
void Operacoesmat4 (STACK *s,char token);
/**
 * \brief       Função que realiza a soma entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void soma(STACK *s);
/**
 * \brief       Função que realiza a diferença entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void menos(STACK*s);
/**
 * \brief       Função que realiza o produto entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void multiplicacao(STACK*s);
/**
 * \brief       Função que realiza a divisão entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void divisao(STACK*s);
/**
 * \brief       Função que retira uma unidade ao primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void decremento(STACK*s);
/**
 * \brief       Função que acrescenta uma unidade ao primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void aumento(STACK*s);
/**
 * \brief       Função que efetua o modulo entre os dois primeiros elementos do topo da stack 
 * @param s     Stack
 */ 
void percentagem(STACK*s);
/**
 * \brief       Função que efetua a exponenciação entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void esteg(STACK*s);
/**
 * \brief       Função que efetua a operação lógica E entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void icomercial(STACK*s);
/**
 * \brief       Função que efetua a operação lógica not entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void tile(STACK*s);
/**
 * \brief       Função que efetua a operação lógica xor entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void acento(STACK*s);
/**
 * \brief       Função que efetua a operação lógica ou entra os numeros binários dos dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void barra_vertical(STACK*s);
/**
 * \brief       Função que retira da stack o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void elimina(STACK*s);
/**
 * \brief       Função que efetua a duplicação do primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void linhahori(STACK*s);
/**
 * \brief       Função que efetua a troca entre os dois primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void barrabarra(STACK*s);
/**
 * \brief       Função que realiza a rodagem entre os 3 primeiros elementos do topo da stack
 * @param s     Stack
 */ 
void arouba(STACK*s);
/**
 * \brief       Função que efetua a leitura de uma linha
 * @param s     Stack
 */ 
void ler_linhas(STACK*s);
/**
 * \brief       Função que copia o elemento que se encontre na n-ésima posição
 * @param s     Stack
 */ 
void nelemento(STACK*s);
/**
 * \brief       Função que converte o elemento do topo da stack para double
 * @param s     Stack
 */ 
void doubleconv(STACK*s);
/**
 * \brief       Função que converte o elemento do topo da stack para long
 * @param s     Stack
 */ 
void longconv(STACK*s);
/**
 * \brief       Função que converte o elemento do topo da stack para char
 * @param s     Stack
 */ 
void operadorc(STACK*s);
/**
 * \brief       Função que coloca o maior dos dois primeiros elementos do topo da stack no topo da stack
 * @param s     Stack
 */ 
void emaior(STACK*s);
/**
 * \brief       Função que coloca o menor dos dois primeiros elementos do topo da stack no topo da stack
 * @param s     Stack
 */ 
void emenor(STACK*s);
/**
 * \brief       Função que realiza um if-then-else.Caso o terceiro elemento do topo da stack for diferente de zero devolve o segundo elemento do topo, caso contrário devolve o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void pontoi(STACK*s);
/**
 * \brief       Função que caso o segundo elemento do topo da stack seja 0 devolve-se a si mesmo, caso contrário devolve o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void eshort(STACK*s);
/**
 * \brief       Função que verifica se os dois primeiros elementos são diferentes de 0, caso isso aconteça devolve 0 , caso contrário devolve um desses elementos 
 * @param s     Stack
 */ 
void oushort(STACK*s);
/**
 * \brief       Função que verifica se os dois primeiros elementos do topo da stack são iguais
 * @param s     Stack
 */ 
void igual(STACK*s);
/**
 * \brief       Função que verifica se o segundo elemento do topo stack é maior que o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void maior(STACK*s);
/**
 * \brief       Função que verifica se o segundo elemento do topo stack é menor que o primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void menor(STACK*s);
/**
 * \brief       Função que efetua a negação do primeiro elemento do topo da stack
 * @param s     Stack
 */ 
void negacao(STACK*s);
/**
 * \brief       Função que efetua a virgula os elementos do topo da stack
 * @param s     Stack
 */ 
void virgula(STACK*s);
/**
 * \brief       Função que permite utilizar as variaveis e os seus valores 
 * @param s     Stack
 * @param token Token elemento
 */
void geral (STACK *s, char* token);
/**
 * \brief       Função que permite utilizar os tokens de 2 pontos
 * @param s     Stack
 * @param token Token elemento
 */
void pontosgeral (STACK *s, char* token);

#endif //PARSER_H_OPERATORS_H