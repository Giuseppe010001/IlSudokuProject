/*
  Progetto: IlSudoku;
  Descrizione:

  lo scopo del gioco e' quello di far compilare la griglia del Sudoku al giocatore.
  Il posizionamento della caselle va in ordine dall'alto verso il basso e da sinistra verso destra (dalla n. 1 alla n. 81).
  Il giocatore puo' scegliere quale casella compilare.
  Inoltre, il contenuto di una casella e' sovrascrivibile.
  Per vincere, il giocatore deve inserire i numeri nella griglia facendo in modo che questi non si ripetano in quella stessa riga, in quella stessa colonna e in quello stesso blocco 3x3.
  L'esito della partita verra' fornito una volta che sono state compilate tutte le caselle della griglia.

  Cognome Nome: Carlino Giuseppe;
  Data: 29/11/2024.


  Dizionario dati:
  Costanti N = 9, MAX = 9, MIN = 1;

  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  |Nome variabile           |     Tipo      |     Utilizzo     |      Descrizione                                                                                                                                                                                    |
  -----------------------------------------------------------------------------------------------------------------------------------y---------------------------------------------------------------------------------------------------------------------------------
  |blocco_1[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il primo sotto-blocco di valori della griglia                                                                                                        |
  |blocco_2[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il secondo sotto-blocco di valori della griglia                                                                                                      |
  |blocco_3[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il terzo sotto-blocco di valori della griglia                                                                                                        |
  |blocco_4[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il quarto sotto-blocco di valori della griglia                                                                                                       |
  |blocco_5[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il quinto sotto-blocco di valori della griglia                                                                                                       |
  |blocco_6[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il sesto sotto-blocco di valori della griglia                                                                                                        |
  |blocco_7[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il settimo sotto-blocco di valori della griglia                                                                                                      |
  |blocco_8[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il ottavo sotto-blocco di valori della griglia                                                                                                       |
  |blocco_9[]               |     Intero    |     Lavoro       |      Vettore di dimensione pari a N contenente il nono sotto-blocco di valori della griglia                                                                                                         |
  |blocco_tot_soluzione[]   |     Intero    |     Lavoro       |      Vettore di dimensione pari a N * N contenente tutta la griglia e quindi il contenuto dei nove sotto-blocchi caricati                                                                           |
  |blocco_tot_risolvere[]   |     Intero    |     Output       |      Vettore di dimensione pari a N * N contenente la griglia da far compilare al giocatore                                                                                                         |
  |blocco_tot_precompilato[]|     Intero    |     Lavoro       |      Vettore di dimensione pari a N * N contenente la griglia di caselle gia' precompilate e non                                                                                                    |
  |casella_scelta           |     Intero    |     Input        |      Variabile contenente il numero della casella che il giocatore desidera compilare                                                                                                               |
  |num_inserire             |     Intero    |     Input        |      Variabile contenente il valore del numero da inserire in quella determinata casella                                                                                                            |
  |flag_vuoto               |     Intero    |     Lavoro       |      Variabile sentinella in grado di rilevare caselle vuote all'interno della griglia                                                                                                              |
  |flag_diverso             |     Intero    |     Lavoro       |      Variabile sentinella in grado di rilevare una disuguaglianza tra il contenuto di una casella della griglia da far compilare e il contenuto di quella stessa casella ma della griglia risolutiva|
  |i_dim                    |     Intero    |     Lavoro       |      Variabile indice del vettore blocco_tot_risolvere[]                                                                                                                                            |
  --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h> // Includere la libreria standard STANDARD INPUT/OUTPUT
#include <stdlib.h> // Includere la libreria standard STANDARD LIBRARY
#include <time.h> // Includere la libreria time.h
#include <unistd.h> // Includere la libreria unistd.h

#define N 9 // Definizione della costante N di valore pari a 9
#define MAX 9 // Definizione della costante MAX di valore pari a 9
#define MIN 1 // Definizione della costante MIN di valore pari a 1


// Dichiarazione prototipi di funzioni e/o procedure
void caricamento_blocco_1(int *);
void caricamento_blocchi_marginali(int *, int *);
void caricamento_altri_blocchi(int *, int *);
void caricamento_righe_1_blocco_tot_soluzione(int *, int *, int *, int *, int *);
void caricamento_righe_2_blocco_tot_soluzione(int *, int *, int *, int *, int *);
void caricamento_righe_3_blocco_tot_soluzione(int *, int *, int *, int *, int *);
void caricamento_blocco_tot_risolvere(int *, int *, int *);
void stampa_blocco_tot_risolvere(int *);
int verifica_vuoto(int *);
int verifica_diverso(int *, int *);


int main() {

    // Dichiarazione variabili
    int i_dim, casella_scelta, num_inserire, flag_vuoto, flag_diverso;

    // Dichiarazione vettori
    int blocco_1[N], blocco_2[N], blocco_3[N], blocco_4[N], blocco_5[N], blocco_6[N], blocco_7[N], blocco_8[N], blocco_9[N], blocco_tot_soluzione[N * N], blocco_tot_risolvere[N * N], blocco_tot_precompilato[N * N];


    // Definizione di un valore Seed (Seme) da cui incominciare la generazione di numeri casuali
    srand((unsigned) time(NULL));


    // Titolo del software
    printf("++++++++++++++++++++++++++++++++++++IlSudoku++++++++++++++++++++++++++++++++++++\n\n");


    // Istruzioni finalizzate a garantire il corretto utilizzo del software
    printf("REGOLE:\n");
    printf("Lo scopo del gioco e' quello di far compilare la griglia del Sudoku al giocatore;\n");
    printf("Il posizionamento della caselle va in ordine dall'alto verso il basso e da sinistra verso destra (dalla n. 1 alla n. 81);\n");
    printf("Il giocatore puo' scegliere quale casella compilare;\n");
    printf("Inoltre, il contenuto di una casella e' sovrascrivibile (solo se non e' stata gia' precompilata);\n");
    printf("Per vincere, il giocatore deve inserire i numeri nella griglia facendo in modo che questi non si ripetano in quella stessa riga, in quella stessa colonna e in quello stesso blocco 3x3;\n");
    printf("L'esito della partita verra' fornito una volta che sono state compilate tutte le caselle della griglia.\n\n");


    // Fase di caricamento del vettore blocco_1[]
    caricamento_blocco_1(blocco_1);


    // Fase di caricamento del vettore blocco_2[]
    caricamento_altri_blocchi(blocco_2, blocco_1);

    // Fase di caricamento del vettore blocco_3[]
    caricamento_altri_blocchi(blocco_3, blocco_2);

    // Fase di caricamento del vettore blocco_4[]
    caricamento_blocchi_marginali(blocco_4, blocco_1);

    // Fase di caricamento del vettore blocco_5[]
    caricamento_altri_blocchi(blocco_5, blocco_4);

    // Fase di caricamento del vettore blocco_6[]
    caricamento_altri_blocchi(blocco_6, blocco_5);

    // Fase di caricamento del vettore blocco_7[]
    caricamento_blocchi_marginali(blocco_7, blocco_4);

    // Fase di caricamento del vettore blocco_8[]
    caricamento_altri_blocchi(blocco_8, blocco_7);

    // Fase di caricamento del vettore blocco_9[]
    caricamento_altri_blocchi(blocco_9, blocco_8);


    i_dim = 0;

    // Fase di caricamento della prima riga della griglia risolutiva del gioco
    caricamento_righe_1_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_1, blocco_2, blocco_3);

    // Fase di caricamento della seconda riga della griglia risolutiva del gioco
    caricamento_righe_2_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_1, blocco_2, blocco_3);

    // Fase di caricamento della terza riga della griglia risolutiva del gioco
    caricamento_righe_3_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_1, blocco_2, blocco_3);

    // Fase di caricamento della quarta riga della griglia risolutiva del gioco
    caricamento_righe_1_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_4, blocco_5, blocco_6);

    // Fase di caricamento della quinta riga della griglia risolutiva del gioco
    caricamento_righe_2_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_4, blocco_5, blocco_6);

    // Fase di caricamento della sesta riga della griglia risolutiva del gioco
    caricamento_righe_3_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_4, blocco_5, blocco_6);

    // Fase di caricamento della settima riga della griglia risolutiva del gioco
    caricamento_righe_1_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_7, blocco_8, blocco_9);

    // Fase di caricamento dell'ottava riga della griglia risolutiva del gioco
    caricamento_righe_2_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_7, blocco_8, blocco_9);

    // Fase di caricamento della nona riga della griglia risolutiva del gioco
    caricamento_righe_3_blocco_tot_soluzione(&i_dim, blocco_tot_soluzione, blocco_7, blocco_8, blocco_9);


    // Fase di caricamento della griglia da far risolvere al giocatore, contenente talvolta anche delle caselle vuote, rappresentate dal valore numerico 254
    caricamento_blocco_tot_risolvere(blocco_tot_soluzione, blocco_tot_risolvere, blocco_tot_precompilato);


    // Messaggio di introduzione ai valori contenuti nella griglia da far compilare
    printf("Ecco la griglia da compilare.\n");

    // Fase di visualizzazione della griglia da far compilare
    stampa_blocco_tot_risolvere(blocco_tot_risolvere);


    // Messaggio finalizzato a rendere chiara l'attesa a cui il giocatore deve sottostare
    printf("\n\nAttendere...");

    // Pausa di 7 secondi
    sleep(7);


    // Messaggio finalizzato a informare il giocatore che il gioco e' iniziato
    printf("\n\n\aChe il gioco del Sudoku abbia inizio!!!");


    printf("\n\n\n\n\n\n\n\n");


    // Ripetere questo ciclo fin quando all'interno della griglia del gioco vi si trova ancora una casella vuota
    do {
        printf("\n\n\n\n");


        // Inserire il numero della casella che si desidera compilare fin quando questo non e' compreso nell'intervallo [+1, +81] compresi e rispecchia una casella che e' stata gia' precompilata
        do {
            printf("Inserire la casella che si desidera compilare: ");
            scanf("%d", &casella_scelta);

            if (casella_scelta < 1 || casella_scelta > 81) {
                printf("\aAttenzione! Inserire solo numeri compresi tra 1 e 81 compresi.\n\n"); // Lasciare un messaggio di errore nel caso in cui la condizione di cui sopra non venisse rispettata
            } else {
                if (blocco_tot_precompilato[casella_scelta - 1] == -1) {
                    printf("\aAttenzione! Compilare solo le caselle che non sono state precompilate.\n\n"); // Lasciare un diverso messaggio di errore nel caso in cui fosse vera l'altra condizione
                }
            }
        } while (casella_scelta < 1 || casella_scelta > 81 || blocco_tot_precompilato[casella_scelta - 1] == -1);


        // Inserire un numero da impostare in quella casella fin quando questo non e' contenuto nell'intervallo [+1, +9] compresi
        do {
            printf("\nInserire un numero nella casella n. %d: ", casella_scelta);
            scanf("%d", &num_inserire);

            if (num_inserire < 1 || num_inserire > 9) {
                printf("\aAttenzione! Inserire solo numeri compresi tra 1 e 9 compresi.\n\n"); // Lasciare un messaggio di errore nel caso in cui la condizione di cui sopra non venisse rispettata
            }
        } while (num_inserire < 1 || num_inserire > 9);


        // Inserire il valore di num_inserire nella cella del vettore di indice pari a casella_scelta - 1 (questo perche' casella_scelta indica una posizione e non un indice)
        blocco_tot_risolvere[casella_scelta - 1] = num_inserire;


        // Fase di visualizzazione della griglia aggiornata all'ultimo valore inserito dall'utente in quella determinata casella
        stampa_blocco_tot_risolvere(blocco_tot_risolvere);


        // 0: false; 1: true.
        flag_vuoto = verifica_vuoto(blocco_tot_risolvere);
    } while (flag_vuoto);


    // 0: false; 1: true
    flag_diverso = verifica_diverso(blocco_tot_soluzione, blocco_tot_risolvere);


    printf("\n\n\n\n");


    // Se flag_diverso = 1 (quindi se nella griglia da risolvere e' stato trovato un elemento diverso da quello contenuto nella griglia risolutiva)
    if (flag_diverso) {
        printf("Esito: spiacente, ma hai perso."); // Comunicare al giocatore che ha perso

        // Altrimenti
    } else {
        printf("\aEsito: complimenti! Hai vinto!"); // Comunicare al giocatore che ha vinto
    }


    // Andare a capo per due volte
    printf("\n\n");

    // Mettere in pausa il software alla fine della sua esecuzione
    printf("Premere un tasto per continuare . . .");
    getchar();
    getchar();

    // Chiudere la funzione main
    return 0;
}


// Procedura finalizzata a caricare il vettore blocco_1[]
void caricamento_blocco_1(int pblocco_1[]) {
    int i, j, num_predefinito;

    for (i = 0; i < N; i++) {

        // Generazione di un numero casuale compreso nell'intervallo [+1, +9] compresi
        num_predefinito = rand() % (MAX - MIN + 1) + MIN;

        // Valutare la presenza di elementi ripetuti solo dopo la prima estrazione effettuata
        if (i > 0) {
            j = 0;

            // Ciclo che si ripete ogni qualvolta si trova un valore ripetuto, cioe' ogni qualvolta il valore di num_predefinito e' uguale al valore alla locazione di indice j del vettore blocco_1[], fino a quando il valore di j e' minore di quello di i, corrispondente all'indice dell'ultima locazione da riempire
            // L'utilizzo di un ciclo while e' dovuto al fatto che si vuole incrementare l'indice j solo a determinate condizioni, e non ad ogni ripetizione del ciclo come accadrebbe per un ciclo for
            while (j < i) {
                if (num_predefinito == pblocco_1[j]) { // Nel caso in cui questa condizione risulti vera
                    j = 0; // Riportare l'indice j a 0, quindi riscansionare nuovamente il vettore blocco_1[] utilizzando questo indice
                    num_predefinito = rand() % (MAX - MIN + 1) + MIN; // Generazione di un altro numero casuale compreso nell'intervallo [+1, +9] compresi
                } else { // Altrimenti
                    j++; // Confrontare il valore di num_predefinito con il valore di blocco_1[] alla locazione successiva di indice j
                }
            }

            // Quindi memorizzare il valore di num_predefinito alla locazione di indice i del vettore blocco_1[] nel caso la condizione del ciclo di cui sopra risulti falsa
            pblocco_1[i] = num_predefinito;
        } else {

            // Memorizzare il primo valore num_predefinito alla locazione di indice i = 0 del vettore blocco_1[]
            pblocco_1[i] = num_predefinito;
        }
    }
}

// Procedura finalizzata a caricare tutti i blocchi che si trovano sul margine a sinistra nella griglia
void caricamento_blocchi_marginali(int pblocco_caricare[], int pblocco_usare_1[]) {
    int i;

    for (i = 0; i < N; i++) {
        if (i == 0 || i == 3 || i == 6) {
            pblocco_caricare[i] = pblocco_usare_1[i + 2];
        } else {
            pblocco_caricare[i] = pblocco_usare_1[i - 1];
        }
    }
}

// Procedura finalizzata a caricare tutti gli altri vettori blocco_n[]
void caricamento_altri_blocchi(int pblocco_caricare[], int pblocco_usare_2[]) {
    int i;

    for (i = 0; i < N; i++) {
        if (i > 2) {
            pblocco_caricare[i] = pblocco_usare_2[i - 3];
        } else {
            pblocco_caricare[i] = pblocco_usare_2[i + 6];
        }
    }
}

// Procedura finalizzata a caricare la prima riga di ogni trio di blocchi
void caricamento_righe_1_blocco_tot_soluzione(int *pi_dim, int pblocco_tot_soluzione[], int pblocco_usare_1_1[], int pblocco_usare_1_2[], int pblocco_usare_1_3[]) {
    int i;

    for (i = 0; i < N; i++) {
        if (i > 5) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_1_3[i - 6];
            *pi_dim = *pi_dim + 1;
        } else if (i > 2) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_1_2[i - 3];
            *pi_dim = *pi_dim + 1;
        } else {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_1_1[i];
            *pi_dim = *pi_dim + 1;
        }
    }
}

// Procedura finalizzata a caricare la seconda riga di ogni trio di blocchi
void caricamento_righe_2_blocco_tot_soluzione(int *pi_dim, int pblocco_tot_soluzione[], int pblocco_usare_2_1[], int pblocco_usare_2_2[], int pblocco_usare_2_3[]) {
    int i;

    for (i = 3; i < N + 3; i++) {
        if (i > 8) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_2_3[i - 6];
            *pi_dim = *pi_dim + 1;
        } else if (i > 5) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_2_2[i - 3];
            *pi_dim = *pi_dim + 1;
        } else {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_2_1[i];
            *pi_dim = *pi_dim + 1;
        }
    }
}

// Procedura finalizzata a caricare la terza riga di ogni trio di blocchi
void caricamento_righe_3_blocco_tot_soluzione(int *pi_dim, int pblocco_tot_soluzione[], int pblocco_usare_3_1[], int pblocco_usare_3_2[], int pblocco_usare_3_3[]) {
    int i;

    for (i = 6; i < N + 6; i++) {
        if (i > 11) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_3_3[i - 6];
            *pi_dim = *pi_dim + 1;
        } else if (i > 8) {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_3_2[i - 3];
            *pi_dim = *pi_dim + 1;
        } else {
            pblocco_tot_soluzione[*pi_dim] = pblocco_usare_3_1[i];
            *pi_dim = *pi_dim + 1;
        }
    }
}

// Procedura finalizzata a caricare il vettore blocco_tot_risolvere[]
void caricamento_blocco_tot_risolvere(int pblocco_tot_soluzione[], int pblocco_tot_risolvere[], int pblocco_tot_precompilato[]) {
    int i, spazio_predefinito;

    for (i = 0; i < N * N; i++) {
        spazio_predefinito = rand() % 3 + 1;
        if (spazio_predefinito < 3) {
            pblocco_tot_risolvere[i] = pblocco_tot_soluzione[i];
            pblocco_tot_precompilato[i] = -1;
        } else {
            pblocco_tot_risolvere[i] = 254;
            pblocco_tot_precompilato[i] = 0;
        }
    }
}

// Procedura finalizzata a stampare il contenuto del vettore blocco_tot_risolvere[]
void stampa_blocco_tot_risolvere(int pblocco_tot_risolvere[]) {
    int i;

    for (i = 0; i < N * N; i++) {

        // Scrivere dei caratteri "|" nella griglia che riescano a dividerla in tre colonne
        if (i % 3 == 0 && i != 0 && i != 9 && i != 18 && i != 27 && i != 36 && i != 45 && i != 54 && i != 63 && i != 72) {
            printf("|  ");
        }

        // Scrivere anche dei trattini in modo da simulare delle linee orizzontali che dividano, insieme ai caratteri "|", la griglia nei suoi nove sotto-blocchi
        if (i % 9 == 0 && i != 0) {
            printf("\n");
            if (i % 27 == 0) {
                printf("-------------------------------\n");
            }
        }

        // Condizione utile a capire se bisogna scrivere un valore numerico o una casella vuota
        if (pblocco_tot_risolvere[i] == 254) {
            printf("%c  ", pblocco_tot_risolvere[i]);
        } else {
            printf("%d  ", pblocco_tot_risolvere[i]);
        }
    }
}

// Funzione finalizzata a verificare che nel vettore blocco_tot_risolvere[] ci sia il valore 254 (corrispondente alla casella vuota nel gioco)
int verifica_vuoto(int pblocco_tot_risolvere[]) {
    int i, F = 0;

    for (i = 0; i < N * N && !F; i++) {
        if (pblocco_tot_risolvere[i] == 254) {
            F = 1;
        }
    }

    if (F) {
        return 1;
    } else {
        return 0;
    }
}

// Funzione finalizzata a verificare che la griglia compilata dal giocatore coincida con quella della soluzione
int verifica_diverso(int pblocco_tot_soluzione[], int pblocco_tot_risolvere[]) {
    int i, F = 0;

    // Portare a 1 il valore di flag_diverso nel caso in cui venisse trovato nella griglia da risolvere un elemento diverso da quello presente nella griglia risolutiva
    for (i = 0; i < N * N && !F; i++) {
        if (pblocco_tot_soluzione[i] != pblocco_tot_risolvere[i]) {
            F = 1;
        }
    }

    return F;
}