#ifndef ABBONAMENTI_H
#define ABBONAMENTI_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clienti.h"

typedef enum {
    MENSILE,
    ANNUALE
} TipoAbbonamento;

typedef struct Abbonamento {
    char codiceFiscale[17];
    TipoAbbonamento tipo;
    struct tm dataInizio;
    struct tm dataFine;
    struct Abbonamento* nodoNext;
} Abbonamento;

Abbonamento* creaAbbonamento(const char* codiceFiscale, TipoAbbonamento tipo);
Abbonamento* aggiungiAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento tipo);
Abbonamento* modificaAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento nuovoTipo);
Abbonamento* rimuoviAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento tipo);
Abbonamento* cercaAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento tipo);
void stampaAbbonamenti(Abbonamento* lista);
void liberaAbbonamenti(Abbonamento* lista);
int abbonamentoValido(Abbonamento* a);

#endif
