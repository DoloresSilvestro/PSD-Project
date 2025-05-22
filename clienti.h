#ifndef CLIENTI_h
#define CLIENTI_H

#define DIM_TABELLA 97

typedef struct Cliente {
    char codiceFiscale[17];
    char nome[30];
    char cognome[30];
    struct Cliente* nodoNext;
} Cliente;
