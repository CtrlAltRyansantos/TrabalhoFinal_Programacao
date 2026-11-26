#ifndef FILA_FIFO_H
#define FILA_FIFO_H

typedef struct _no_fila{
    int chave;
    int valor;
    struct _no_fila *proximo;
} No_Fila;

typedef struct {
    No_Fila *head;
    No_Fila *tail;
    int tamanho;
} Fila;

Fila* f_inicializar (void);
int f_inserir (Fila *f, int chave, int valor);
int f_obter_proxima_chave (Fila *f);
int f_consultar_proxima_chave (Fila *f);
int f_consultar_proximo_valor (Fila *f);
int f_num_elementos (Fila *f);
int f_consultar_chave_por_posicao (Fila *f, int posicao);
int f_consultar_valor_por_posicao (Fila *f, int posicao);

No_Fila* cria_no(int chave, int valor);


#endif