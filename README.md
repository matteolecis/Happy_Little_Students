# Happy Little Students

**Happy Little Students** è un gioco in C ispirato a *Happy Little Dinosaurs*, sviluppato come progetto per il corso di **Laboratorio di Programmazione 1** (CdL in Informatica, Università degli Studi di Cagliari, A.A. 2023/2024).

Il gioco unisce ironia universitaria e logiche da card game strategico: i giocatori impersonano studenti alle prese con CFU, carte ostacolo e la minaccia della rinuncia agli studi. Obiettivo? Laurearsi (cioè: arrivare a 60 CFU) o essere l’ultimo superstite!

## Funzionalità implementate

- Modalità **manuale** con 2-4 giocatori.
- Tutti gli **effetti delle carte CFU punto e istantanee** sono pienamente implementati.
- **Gestione salvataggi multipli** con nome personalizzato.
- **Log dettagliato** della partita (`log.txt`), con cronologia delle azioni turno per turno.
- **Compatibilità con salvataggio binario** (`savegame.sav`), come da specifica.
- Lettura dei mazzi e personaggi da file di testo (`carte.txt`, `ostacoli.txt`, `giocatori.txt`).

## Regole del gioco

- Ogni giocatore impersona uno studente con caratteristiche uniche (bonus/malus).
- Al proprio turno, si gioca una carta CFU e si cerca di evitare una **carta ostacolo**.
- Le carte CFU possono avere effetti strategici: rubare carte, scambiarle, annullare effetti, ecc.
- Alcune carte CFU sono istantanee e si giocano in fase speciale.
- Si può vincere:
  - Raggiungendo 60 CFU.
  - Rimanendo l’ultimo studente “in vita” (non rinunciatario).
- Si perde:
  - Se si accumulano 3 ostacoli dello stesso tipo.
  - Se si ottiene un ostacolo per ogni tipologia.
  - Le carte **ESAME** fungono da jolly per gli ostacoli.

## File Utilizzati

| File             | Descrizione |
|------------------|-------------|
| `main.c`         | Avvio del gioco, menu principale |
| `giocatore.c/.h` | Strutture e logica dei giocatori |
| `carte.c/.h`     | Gestione carte CFU e ostacolo |
| `logica.c/.h`    | Meccaniche di gioco, punteggi, vincitori |
| `salvataggi.c/.h`| Salvataggio/caricamento della partita |
| `log.c/.h`       | Scrittura nel file di log |
| `utils.c/.h`     | Funzioni di utilità varie |

## Salvataggi

Il gioco supporta **più file di salvataggio**:
- Ogni turno viene salvato automaticamente.
- L’utente può assegnare un nome personalizzato al file.
- All’avvio è possibile caricare un salvataggio precedente.

Formato conforme alla struttura `savegame.sav` descritta nelle specifiche.

## Log

Il file `log.txt` tiene traccia cronologica degli eventi della partita, ad esempio:

TURNO 1: Matteo gioca Clion TURNO 1: Alice gioca Tastiera TURNO 2: Luca gioca Maglione Natale ...

##Requisiti e note
-Standard C99.
-Non utilizza librerie esterne.
-Tutte le strutture rispettano l’ordine richiesto per compatibilità con i salvataggi.
-Codice commentato secondo standard Doxygen.

