#include <stdio.h>
#include <stdlib.h>
#include "logtree.h"

#define DEBUG 1

void log_inicializar(Log **l) {
    *l = NULL;
}

Log* _cria_no(int conta, int classe, int timer, int caixa) {
    Log *no = malloc(sizeof(Log));

    if (no == NULL) {
       return _cria_no(conta, classe, timer, caixa);
    }

    no->conta = conta;
    no->classe = classe;
    no->timer = timer;
    no->caixa = caixa;

    no->esq = NULL;
    no->dir = NULL;

    return no;
}

void log_registrar(Log **l, int conta, int classe, int timer, int caixa) {
    Log *novo;

    if (l == NULL) {
        printf("ERRO AO REGISTRAR: log nao inicializado\n");
        return;
    }

    if (*l == NULL) {
        novo = _cria_no(conta, classe, timer, caixa);
        *l = novo;
        return;
    }
    
    if (conta < (*l)->conta) {
        if ((*l)->esq == NULL) {
            novo = _cria_no(conta, classe, timer, caixa);
            (*l)->esq = novo;
            return; 
        }        
        log_registrar((*l)->esq, conta, classe, timer, caixa);   
    } else if (conta > (*l)->conta) {
        if ((*l)->dir == NULL) {
            novo = _cria_no(conta, classe, timer, caixa);
            (*l)->dir = novo;
            return;
        }
        log_registrar((*l)->dir, conta, classe, timer, caixa);
    } else {
        printf("ERRO AO REGISTRAR: conta ja existente\n");
    }
}

float log_media_por_classe(Log *l, int classe) {
    int soma, qtde;

    if (l == NULL) return 0.0;

    soma = log_obter_soma_por_classe(l, classe);
    qtde = log_obter_contagem_por_classe(l, classe);

    return (float) soma / qtde;
}

int log_obter_soma_por_classe(Log *l, int classe) {
    if (l == NULL || l->classe != classe) {
        return 0;
    }

    return l->timer
         + log_obter_soma_por_classe(l->esq, classe) 
         + log_obter_soma_por_classe(l->dir, classe);
}

int log_obter_contagem_por_classe(Log *l, int classe) {
    if (l == NULL || l->classe != classe) {
        return 0;
    }

    return 1
         + log_obter_contagem_por_classe(l->esq, classe)
         + log_obter_contagem_por_classe(l->dir, classe);
}