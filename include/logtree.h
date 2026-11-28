#ifndef LOGTREE_H
#define LOGTREE_H

typedef struct _log {
    int conta;
    int classe;
    int timer;
    int caixa;
    struct _log *esq;
    struct _log *dir;
} Log;

void log_inicializar(Log **l);
void log_registrar(Log **l, int conta, int classe, int timer, int caixa);
float log_media_por_classe(Log *l, int classe);
int log_obter_soma_por_classe(Log *l, int classe);
int log_obter_contagem_por_classe(Log *l, int classe);

#endif