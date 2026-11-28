#include <stdio.h>
#include <stdlib.h>
#include "fila_fifo.h"


Fila* f_inicializar (void){
    Fila *fila;
    fila = (Fila *)(malloc(sizeof(Fila)));
    fila->head = NULL;
    fila->tamanho = 0;

    return fila;
}

/* void f_inicializar(Fila **f) {
    *f = (Fila *) malloc(sizeof(Fila));

    (*f)->head = NULL;
    (*f)->tamanho = 0;
} */

No_Fila* cria_no(int chave, int valor){
    No_Fila *no;
    no = (No_Fila *)(malloc(sizeof(No_Fila)));

    if(no != NULL){
        no->chave = chave;
        no->valor = valor;
        no->proximo = NULL;
    }
    else{
        return cria_no(chave, valor);
    }
    return no;
}


int f_inserir (Fila *fila, int chave, int valor){
    No_Fila *no;
    no = cria_no(chave, valor);

    if(no == NULL){
        return 0;
    }

    if(checa_unicidade(fila->head, chave)){
        return 0;
    }

    if(fila->tamanho == 0){
        fila->tail = no;
        fila->head = no;
    }
    else{
        fila->tail->proximo = no;
        fila->tail = no;
    }
    fila->tamanho++;
    return 1;
}
    

int f_obter_proxima_chave (Fila *fila){
    No_Fila *aux;
    int chave;

    if (fila->tamanho == 0) {
        return -1;
    }

    chave = f_consultar_proxima_chave(fila);
    fila->head = aux->proximo;

    if(fila->head == NULL){
        fila->tail = NULL;
    }

    fila->tamanho--;
    free(aux);
    return chave;
}


int f_consultar_proxima_chave (Fila *fila){
    if(fila != NULL){
        return fila->head->chave;
    }   
    else{
        return -1;
    }
}

int f_consultar_proximo_valor (Fila *fila){
    if(fila != NULL){
        return fila->head->valor;
    }   
    else{
        return -1;
    }
}

int f_num_elementos (Fila *fila){
    if(fila != NULL){
        return fila->tamanho;
    }   
    else{
        return 0;
    }
}

int f_consultar_chave_por_posicao (Fila *fila, int posicao){
    No_Fila *atual;
    int i;

    atual = fila->head;

    if(posicao > fila->tamanho || posicao < 1){
        return -1;
    }

    for(i = 1; i < posicao; i++){
        atual = atual->proximo;
    }
    return atual->chave;
}

int f_consultar_valor_por_posicao (Fila *fila, int posicao){
    No_Fila *atual;
    int i;

    atual = fila->head;

    if(posicao > fila->tamanho || posicao < 1){
        return -1;
    }

    for(i = 1; i < posicao; i++){
        atual = atual->proximo;
    }
    return atual->valor;
}

int checa_unicidade(No_Fila *no, int key) { 
    if (no == NULL) {
        return 1; /* chegou ao final sem encontrar a chave */
    }
    if (no->chave == key) {
        return 0;  
    }
    return checa_unicidade(no->proximo, key); /* continua verificando recursivamente */
}