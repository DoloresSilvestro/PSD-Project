#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lezioni.h"

/* Lezione* creaLezione(int id, const char* nome, const char* giorno, int durata, int maxPrenotazioni)

Specifica Sintattica:
creaLezione(int, const char*, const char*, int, int) -> Lezione*

Specifica Semantica:
creaLezione(id, nome, giorno, durata, maxPrenotazioni) -> nuova

Pre-condizioni:
  - nome e giorno sono stringhe valide terminate da '\0'.
  - durata e maxPrenotazioni sono interi positivi.
  - id è un intero positivo che identifica univocamente una lezione.

Post-condizioni:
  - Se i parametri sono validi e l’allocazione ha successo:
      - Viene creato un nuovo nodo Lezione con i valori passati.
      - Il campo partecipantiAttuali è inizializzato a 0.
      - Il campo nodoNext è inizializzato a NULL.
      - La funzione restituisce il puntatore al nuovo nodo.
  - Se l’allocazione fallisce, la funzione restituisce NULL.
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

/* Lezione* aggiungiLezione(Lezione *testaLista, Lezione *nuovaLezione)

Specifica Sintattica:
aggiungiLezione(Lezione*, Lezione*) -> Lezione*

Specifica Semantica:
aggiungiLezione(testaLista, nuovaLezione) -> nuovaLista

Pre-condizioni:
  - testaLista è un puntatore a una lista (anche vuota) di nodi di tipo Lezione.
  - nuovaLezione è un puntatore a un nodo Lezione già inizializzato (non NULL).

Post-condizioni:
  - Se testaLista è NULL, nuovaLezione diventa la nuova testa della lista.
  - Altrimenti, nuovaLezione viene inserita in coda alla lista.
  - Il campo nodoNext dell’ultimo nodo precedente viene aggiornato per puntare a nuovaLezione.
  - La funzione restituisce il puntatore alla testa della lista aggiornata.
  - Se nuovaLezione è NULL, la funzione restituisce testaLista senza modifiche.
*/

Lezione* aggiungiLezione(Lezione* testaLista, Lezione* nuovaLezione) {
    if (!nuovaLezione) return testaLista;

    if (!testaLista) return nuovaLezione;

    Lezione *nodoCorrente = testaLista;
    while (nodoCorrente->nodoNext) {
        nodoCorrente = nodoCorrente->nodoNext;
    }

    nodoCorrente->nodoNext = nuovaLezione;
    return testaLista;
}

/* void modificaLezione(Lezione *lezione, const char *nome, const char *giorno, int durata, int maxPrenotazioni)

Specifica Sintattica:
modificaLezione(Lezione*, const char*, const char*, int, int) -> void

Specifica Semantica:
modificaLezione(lezione, nome, giorno, durata, maxPrenotazioni)

Pre-condizioni:
  - lezione è un puntatore valido a un nodo Lezione esistente.
  - nome e giorno sono stringhe valide terminate da '\0'.
  - durata e maxPrenotazioni sono interi positivi e coerenti.

Post-condizioni:
  - I campi nome, giorno, durata e maxPrenotazioni della lezione vengono aggiornati con i nuovi valori passati.
  - La funzione non restituisce alcun valore.
  - Se lezione è NULL, la funzione non esegue alcuna modifica.
*/

void modificaLezione(Lezione* lezione, const char* nome, const char* giorno, int durata, int maxPrenotazioni) {
    if (!lezione) return;

    strncpy(lezione->nome, nome, sizeof(lezione->nome) - 1);
    lezione->nome[sizeof(lezione->nome) - 1] = '\0';

    strncpy(lezione->giorno, giorno, sizeof(lezione->giorno) - 1);
    lezione->giorno[sizeof(lezione->giorno) - 1] = '\0';

    lezione->durata = durata;
    lezione->maxPrenotazioni = maxPrenotazioni;
}

/* Lezione* rimuoviLezione(Lezione* testaLista, int id)

Specifica Sintattica:
rimuoviLezione(Lezione*, int) -> Lezione*

Specifica Semantica:
rimuoviLezione(testaLista, id) -> nuovaLista

Pre-condizioni:
  - testaLista è un puntatore a una lista (anche vuota) di nodi Lezione.
  - id è un intero positivo che identifica univocamente una lezione.

Post-condizioni:
  - Se esiste una lezione con l'id specificato, essa viene rimossa dalla lista e la memoria liberata.
  - Se la lezione da rimuovere era in testa, la nuova testa viene aggiornata.
  - Se l'id non è presente, la lista resta invariata.
  - Viene restituito il puntatore alla testa aggiornata della lista.
*/

Lezione* rimuoviLezione(Lezione* testaLista, int id) {
    Lezione* nodoCorrente = testaLista;
    Lezione* nodoPrecedente = NULL;

    while (nodoCorrente != NULL) {
        if (nodoCorrente->id == id) {
            if (nodoPrecedente == NULL) {
                // Rimozione in testa
                testaLista = nodoCorrente->nodoNext;
            } else {
                // Rimozione in mezzo o in coda
                nodoPrecedente->nodoNext = nodoCorrente->nodoNext;
            }
            free(nodoCorrente);
            break;
        }
        nodoPrecedente = nodoCorrente;
        nodoCorrente = nodoCorrente->nodoNext;
    }

    return testaLista;
}
/* Lezione* cercaLezione(Lezione *testaLista, int id)

Specifica Sintattica:
cercaLezione(Lezione*, int) -> Lezione*

Specifica Semantica:
cercaLezione(testaLista, id) -> lezioneTrovata

Pre-condizioni:
  - testaLista è un puntatore a una lista (anche vuota) di nodi Lezione.
  - id è un intero positivo che rappresenta un identificatore valido di una lezione.

Post-condizioni:
  - Se esiste un nodo nella lista con id corrispondente, viene restituito il puntatore a quel nodo.
  - Se non esiste alcun nodo con quell'id, viene restituito NULL.
*/

Lezione* cercaLezione(Lezione *testaLista, int id) {
    Lezione *nodoCorrente = testaLista;
    while (nodoCorrente) {
        if (nodoCorrente->id == id) {
            return nodoCorrente;
        }
        nodoCorrente = nodoCorrente->nodoNext;
    }
    return NULL;
}

/* void stampaLezioni(Lezione *testaLista)

Specifica Sintattica:
stampaLezioni(Lezione*) -> void

Specifica Semantica:
stampaLezioni(testaLista) -> stampa a schermo tutte le lezioni nella lista

Pre-condizioni:
  - testaLista è un puntatore a una lista (anche vuota) di nodi Lezione.

Post-condizioni:
  - Vengono stampati su console i dati di tutte le lezioni presenti nella lista.
  - Se la lista è vuota, non viene stampato nulla o si può prevedere un messaggio opzionale.
*/

void stampaLezioni(Lezione *testaLista) {
    Lezione *nodoCorrente = testaLista;
    while (nodoCorrente) {
        printf("ID: %d | Nome: %s | Giorno: %s | Durata: %d | Max: %d | Attuali: %d\n",
               nodoCorrente->id,
               nodoCorrente->nome,
               nodoCorrente->giorno,
               nodoCorrente->durata,
               nodoCorrente->maxPrenotazioni,
               nodoCorrente->partecipantiAttuali);
        nodoCorrente = nodoCorrente->nodoNext;
    }
}

/* void liberaLezioni(Lezione *testaLista)

Specifica Sintattica:
liberaLezioni(Lezione*) -> void

Specifica Semantica:
liberaLezioni(testaLista) -> libera la memoria allocata dinamicamente per ogni nodo della lista

Pre-condizioni:
  - testaLista è un puntatore a una lista (anche eventualmente vuota) di nodi Lezione allocati dinamicamente con malloc/calloc.

Post-condizioni:
  - Tutti i nodi della lista vengono liberati.
  - Non è più possibile accedere agli elementi della lista dopo l'esecuzione della funzione.
  - La memoria precedentemente occupata dai nodi viene rilasciata correttamente.
*/

void liberaLezioni(Lezione *testaLista) {
    Lezione *nodoCorrente = testaLista;
    while (nodoCorrente) {
        Lezione *temp = nodoCorrente;
        nodoCorrente = nodoCorrente->nodoNext;
        free(temp);
    }
}
