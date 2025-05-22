/*
Cliente** inizializzaTabellaClienti()
Specifica Sintattica:
	inizializzaTabellaClienti() -> Cliente**

Specifica Semantica:
	inizializzaTabellaClienti() -> tabella

Pre-condizioni:
1. Nessuna.

Post-condizioni:
La funzione alloca dinamicamente un array di puntatori a Cliente, inizializzati a NULL,
e restituisce un puntatore a tale array, che rappresenta una tabella hash vuota.


unsigned int hash(const char* codiceFiscale)
Specifica Sintattica:
	hash(const char*) -> unsigned int

Specifica Semantica:
	hash(codiceFiscale) -> somma

Pre-condizioni:
1. codiceFiscale dev'essere una stringa valida terminata dal carattere '\0'.

Post-condizioni:
La funzione restituisce un intero non negativo compreso tra 0 e DIM_TABELLA - 1, ottenuto calcolando la
somma dei caratteri del codice fiscale e applicando l’operazione modulo DIM_TABELLA.


void inserisciCliente(Cliente** tabella, const char* codiceFiscale, const char* nome, const char* cognome)

Specifica Sintattica:
	inserisciCliente(Cliente**, const char*, const char*, const char*) -> void

Specifica Semantica:
	inserisciCliente(tabella, codiceFiscale, nome, cognome) -> void

Pre-condizioni:
1. La tabella hash deve essere già inizializzata correttamente.
2. Il parametro codiceFiscale deve essere una stringa terminata con '\0'.
3. Il parametro nome deve essere una stringa terminata con '\0'.
4. Il parametro cognome deve essere una stringa terminata con '\0'.

Post-condizioni:
La funzione, essendo void, non restituisce alcun valore, ma ha un side effect: alloca dinamicamente
un nuovo nodo di tipo Cliente contenente i dati forniti, che viene inserito
nella lista associata alla posizione calcolata nella tabella hash.


*/
