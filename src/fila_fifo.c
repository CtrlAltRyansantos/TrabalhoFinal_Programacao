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

No_Fila* cria_no(int chave, int valor){
    No_Fila *no;
    no = (No_Fila *)(malloc(sizeof(No_Fila)));

    if(no != NULL){
        no->chave = chave;
        no->valor = valor;
        no->proximo = NULL;
    }
    else{
        cria_no(chave, valor);
    }
    return no;
}


int f_inserir (Fila *fila, int chave, int valor){
    No_Fila *no;
    no = cria_no(chave, valor);

    if(fila->tamanho == 0){
        fila->tail = no;
        fila->head = no;
    }
    else{
        fila->tail->proximo = no;
        fila->tail = no;
    }
    fila->tamanho++;
}
    

int f_obter_proxima_chave (Fila *f);

int f_consultar_proxima_chave (Fila *f){
    if(f != NULL){
        return f->head->chave;
    }   
    else{
        return -1;
    }
}

int f_consultar_proximo_valor (Fila *f){
    if(f != NULL){
        return f->head->valor;
    }   
    else{
        return -1;
    }
}

int f_num_elementos (Fila *f){
    if(f != NULL){
        return f->tamanho;
    }   
    else{
        return 0;
    }
}

int f_consultar_chave_por_posicao (Fila *f, int posicao){
    No_Fila *atual;
    int i;

    atual = f->head;

    if(posicao > f->tamanho || posicao < 1){
        return -1;
    }

    for(i = 1; i < posicao; i++){
        atual = atual->proximo;
    }
    return atual->chave;
}

int f_consultar_valor_por_posicao (Fila *f, int posicao){
    No_Fila *atual;
    int i;

    atual = f->head;

    if(posicao > f->tamanho || posicao < 1){
        return -1;
    }

    for(i = 1; i < posicao; i++){
        atual = atual->proximo;
    }
    return atual->valor;
}

