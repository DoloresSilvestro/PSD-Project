#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lezioni.h"

/* Lezione* creaLezione(const char* nome, struct tm dataOra, int maxPartecipanti)

Specifica Sintattica:
creaLezione(const char*, struct tm, int) -> Lezione*

Specifica Semantica:
creaLezione(nome, dataOra, maxPartecipanti) -> nuova

Pre-condizioni:
  - nome è una stringa valida terminata da '\0'.
  - maxPartecipanti è un intero positivo.
  - dataOra è una struttura struct tm ben definita che rappresenta la data e l'orario della lezione.

Post-condizioni:
  - Se i parametri sono validi e l’allocazione ha successo:
      - Viene creato un nuovo nodo Lezione con i valori passati.
      - Il campo partecipantiAttuali è inizializzato a 0.
      - Il campo nodoNext è inizializzato a NULL.
      - La funzione restituisce il puntatore al nuovo nodo.
  - Se nome è NULL o maxPartecipanti <= 0, la funzione restituisce NULL.
  - Se l’allocazione fallisce, viene stampato un messaggio di errore e la funzione restituisce NULL.
*/

Lezione* creaLezione(int id, const char* nome, const char* giorno, int durata, int maxPrenotazioni) {
        Lezione* nuovaLezione = calloc(1,sizeof(Lezione));
        if (!nuovaLezione) return NULL;

            nuovaLezione->id = id;
            strcpy(nuovaLezione->nome, nome);
            strcpy(nuovaLezione->giorno, giorno);
            nuovaLezione->durata = durata;
            nuovaLezione->maxPrenotazioni = maxPrenotazioni;
            nuovaLezione->partecipantiAttuali = 0;
            nuovaLezione->nodoNext = NULL;

        return nuovaLezione;
}
