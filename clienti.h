#ifndef CLIENTI_h
#define CLIENTI_H

#define DIM_TABELLA 97

typedef struct Cliente {
    char codiceFiscale[17];
    char nome[30];
    char cognome[30];
    struct Cliente* nodoNext;
} Cliente;

/*
La struttura Cliente rappresenta un singolo nodo della lista collegata associata a ciascuna posizione della tabella hash.
Gli elementi principali sono:
• Codice Fiscale: stringa identificativa univoca del cliente;
• nome, cognome: dati anagrafici;
• nodoNext: puntatore al nodo successivo, per la gestione delle collisioni mediante lista collegata.
*/


