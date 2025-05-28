#ifndef LEZIONI_H
#define LEZIONI_H

/* La struttura Lezione rappresenta un singolo nodo di una lista collegata che gestisce le lezioni disponibili in palestra. Gli elementi principali sono:
	id: identificativo univoco della lezione;
	nome: nome della lezione (es. "Yoga", "Pilates");
	giorno: giorno della settimana in cui si tiene la lezione;
	durata: durata della lezione espressa in minuti;
	maxPartecipanti: numero massimo di partecipanti consentiti per la lezione;
	nodoNext: puntatore al nodo successivo della lista, per gestire dinamicamente l'elenco delle lezioni.
*/

typedef struct Lezione {
    int id;
    char nome[30];
    char giorno[30];
    int durata;
    int maxPartecipanti;
    struct Lezione* nodoNext;
} Lezione;

Lezione* creaLezione(int id, const char* nome, const char* giorno, int durata, int maxPrenotazioni);
Lezione* aggiungiLezione(Lezione* testaLista, Lezione* nuovaLezione);
Lezione* cercaLezione(Lezione* testaLista, int id);
void modificaLezione(Lezione* lezione, const char* nome, const char* giorno, int durata, int maxPrenotazioni);
Lezione* rimuoviLezione(Lezione* testaLista, int id);
void stampaLezioni(Lezione* testaLista);
void liberaLezioni(Lezione* testaLista);

#endif
