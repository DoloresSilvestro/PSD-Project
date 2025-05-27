#include "abbonamenti.h"

/*
Abbonamento* creaAbbonamento(const char* codiceFiscale, TipoAbbonamento tipo)
Specifica Sintattica:
	creaAbbonamento(const char*, TipoAbbonamento) -> Abbonamento*

Specifica Semantica:
	creaAbbonamento(codiceFiscale, tipo) -> lista

Precondizioni:
1. codiceFiscale è una stringa valida (non NULL).
2. tipo è un valore valido dell'enumerazione TipoAbbonamento.

Postcondizioni:
Le funzione restituisce un puntatore a un nodo Abbonamento allocato e inizializzato correttamente,
oppure NULL in caso di errore.
*/

Abbonamento* creaAbbonamento(const char* codiceFiscale, TipoAbbonamento tipo) {
	Abbonamento* nuovo = (Abbonamento*)calloc(1, sizeof(Abbonamento));
		if (!nuovo) return NULL;

			strncpy(nuovo->codiceFiscale, codiceFiscale, sizeof(nuovo->codiceFiscale) - 1);
			nuovo->codiceFiscale[sizeof(nuovo->codiceFiscale) - 1] = '\0';
			nuovo->tipo = tipo;
			time_t now = time(NULL);
			nuovo->dataInizio = *localtime(&now);
			nuovo->dataFine = nuovo->dataInizio;

		if (tipo == MENSILE) {
			nuovo->dataFine.tm_mon += 1;
		} else if (tipo == ANNUALE) {
			nuovo->dataFine.tm_year += 1;
		}
		mktime(&nuovo->dataFine);
		nuovo->nodoNext = NULL;
		return nuovo;
}

/*
Abbonamento* aggiungiAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento tipo)
Specifica Sintattica:
	aggiungiAbbonamento(Abbonamento*, const char*, TipoAbbonamento) -> Abbonamento*

Specifica Semantica:
	aggiungiAbbonamento(lista, codiceFiscale, tipo) -> esito

Precondizioni:
1. lista può essere NULL o una lista valida.
2. codiceFiscale dev'essere una stringa terminata con '\0'.
3. tipo dev'essere un valore corretto.

Postcondizioni:
La funzione restituisce la nuova lista con l’abbonamento aggiunto in testa.
In caso in cui l'allocazione della memoria fallisce,
viene restituita la lista originale senza alcuna modifica.
*/

Abbonamento* aggiungiAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento tipo) {
	Abbonamento* nuovo = creaAbbonamento(codiceFiscale, tipo);
		if (!nuovo) return lista;

		nuovo->nodoNext = lista;
		return nuovo;
}

/*
Abbonamento* modificaAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento nuovoTipo)
Specifica Sintattica:
	modificaAbbonamento(Abbonamento*, const char*, TipoAbbonamento) -> Abbonamento*
Specifica Semantica:
	modificaAbbonamento(lista, codiceFiscale, nuovoTipo) -> esito

Pre-condizioni:
1. lista è una lista inizializzata corettamente o NULL.
2. codiceFiscale dev'essere una stringa valida.

Post-condizioni:
La funzione, se trova il nodo corrispondente al cliente interessato, modifica le sue informazioni relative
al tipo di abbonamento e la durata.
In caso in cui il cliente non è presente nella lista, la funzione non apporta nessuna modifica.
 */

Abbonamento* modificaAbbonamento(Abbonamento* lista, const char* codiceFiscale, TipoAbbonamento nuovoTipo) {
    Abbonamento* nodoCorrente = lista;

    while (nodoCorrente != NULL) {
        if (strcmp(nodoCorrente->codiceFiscale, codiceFiscale) == 0) {
            nodoCorrente->tipo = nuovoTipo;
            nodoCorrente->dataFine = nodoCorrente->dataInizio;

            if (nuovoTipo == MENSILE) {
                nodoCorrente->dataFine.tm_mon += 1;
            } else if (nuovoTipo == ANNUALE) {
                nodoCorrente->dataFine.tm_year += 1;
            }
            mktime(&nodoCorrente->dataFine);

            return lista;
        }
        nodoCorrente = nodoCorrente->nodoNext;
    }

    return lista;
}
