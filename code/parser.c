/**
 @file  parser.h
 @brief Ficheiro com as funções relativas a parse
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "parser.h"
#include "operacoes.h"
/**
 * \brief       Função que obtem o token apos encontramos um delimitador
 * @param line  Linha
 * @param rest  Resto
 */ 
char *get_token(char *line, char **rest){
    char *delimitadores = " \t\n";
    while (strchr(delimitadores,*line)!= NULL && *line != '\0') line++;
    if (strlen(line) == 0) return NULL;
    char *str = strdup(line);
    int i = 0;
    for (i = 0;strchr(delimitadores,str[i]) == NULL;i++);
    str[i] = '\0';
    *rest = line + i + 1;
    return str;
}
/**
 * \brief       Função que responsavel pelo controlo dos parenteses retos
 * @param line  Linha
 * @param rest  Resto
 */ 
char *del_array(char *line,char **rest){
    int j=0,k=0,i=0;
    char *tok = (char*)malloc(sizeof(char)*strlen(line));
    for (i = 0 ; line[i]!='\0';i++){
        if (line[i] == ']'){
            if (j <= 1) break;
            j--;
        }else if (line[i] == '['){
            if (j > 0) {
                tok[k] = line[i];
                k++;
            }
            j++;
        }else{tok[k] = line[i]; k++;}
    }
    tok[k] = '\n';
    tok[k+1] = '\0';
    *rest = line + k +2;
    return tok; 
}
/**
 * \brief       Função que separa a string para obter os operandos e operedores
 * @param line  Linha
 * @param s     Stack
 */ 

STACK *parse(char *line,STACK *s){
    if (s == NULL) s = create_stack();
    char *delims = " \t\n";
    char *sobra;
    char *rest[strlen(line)+1];
    *rest = (char*)malloc(sizeof(char)*strlen(line));
    char *token = (char*)malloc(sizeof(char)*strlen(line));
    for(token = get_token(line,rest);token != NULL; token = get_token(line,rest)) {
        while (strchr(delims,*line)!= NULL && *line != '\0') line++;
        long val_i = strtol (token, &sobra, 10);
        if (strlen(sobra) == 0){
             MAKE_DATA (nome,LONG,val_i);
             push(s,nome); 
        }else {
                double val_d = strtod (token, &sobra);
                if(strlen(sobra)== 0){
                        MAKE_DATA (nome,DOUBLE,val_d);
                        push (s,nome);

                }else if (*line == '['){
                        STACK *novastack = create_stack();
                        novastack = parse(del_array(line,rest),novastack);
                        MAKE_DATA(Z,ARRAY,novastack);
                        push(s,Z);        
                }
                else {
                        switch(strchr("+-*/()%#,", *token) != NULL){
                             case 1 : Operacoesmat (s,*token);break;
                             default :
                                switch(strchr("&~^|;_\\@", *token) != NULL){
                                        case 1: Operacoesmat2 (s,*token);break;
                                        default:
                                                switch(strchr("l$fic", *token) != NULL){
                                                        case 1: Operacoesmat3 (s,*token);break;
                                                        default:
                                                                switch(strchr("?=><!", *token) != NULL){
                                                                        case 1 : Operacoesmat4 (s,*token);break;
                                                                        default:
                                                                                switch(strcmp(token, "e&") == 0){
                                                                                        case 1 : eshort(s);break;
                                                                                        default:
                                                                                                switch(strcmp(token, "e|") == 0){
                                                                                                    case 1 : oushort(s);break;
                                                                                                        default:
                                                                                                                switch(strcmp(token, "e>") == 0){
                                                                                                                        case 1 : emaior(s);break;
                                                                                                                        default:  
                                                                                                                                switch(strcmp(token, "e<") == 0){
                                                                                                                                        case 1 : emenor(s);break;
                                                                                                                                                default:
                                                                                                                                                        switch((strcmp(token, ":S") == 0) || (strcmp(token, ":A") == 0) ||(strcmp(token, ":B") == 0) ||(strcmp(token, ":C") == 0) || (strcmp(token, ":D") == 0) || (strcmp(token, ":E") == 0) || (strcmp(token, ":F") == 0) || (strcmp(token, ":N") == 0) || (strcmp(token, ":X") == 0) || (strcmp(token, ":Y") == 0) || (strcmp(token, ":Z") == 0)){
                                                                                                                                                                case 1 : pontosgeral(s,token);break;
                                                                                                                                                                default:
                                                                                                                                                                        switch((strcmp(token, "S") == 0) || (strcmp(token, "A") == 0) ||(strcmp(token, "B") == 0) ||(strcmp(token, "C") == 0) || (strcmp(token, "D") == 0) || (strcmp(token, "E") == 0) || (strcmp(token, "F") == 0) || (strcmp(token, "N") == 0) || (strcmp(token, "X") == 0) || (strcmp(token, "Y") == 0) || (strcmp(token, "Z") == 0)){
                                                                                                                                                                                case 1 :  geral(s,token);break;
                                                                                                                                                                                default: push_CHAR(s,*token);
                                                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                        }break;
                                                                                                                                                        }break;
                                                                                                                                }break;
                                                                                                                }break;
                                                                                                }break;
                                                                                }break;
                                                                }break;
                                                }break;
                                }break;
                                                                                                                
                        }
                }
        }
    line = *rest;    
    }
    return s;
}
        

     



