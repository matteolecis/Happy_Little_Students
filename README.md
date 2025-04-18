# Happy Little Students

## ENGLISH
**Happy Little Students** is a C game inspired by *Happy Little Dinosaurs*, developed as the final project for the **Programming Laboratory 1** course (B.Sc. in Computer Science, University of Cagliari, Academic Year 2023/2024).

The game blends university humor with strategic card‑game mechanics: players take on the role of students juggling CFU (university credits), “obstacle” cards and the risk of quitting their studies. Goal? Graduate by reaching **60 CFU**, or be the last student standing!

## Features Implemented

- **Manual mode** for 2–4 human players.  
- Full implementation of **CFU point cards** and **instant (CFU) cards** effects.  
- **Multiple save files** with custom names.  
- **Detailed log** of the match (`log.txt`), recording every action each turn.  
- **Binary save compatibility** (`savegame.sav`) following the specification.  
- Loading card decks and characters from text files (`carte.txt`, `ostacoli.txt`, `giocatori.txt`).

## Game Rules

- Each player is a student with unique bonuses/maluses.  
- On your turn you play one CFU card and try to avoid drawing an **obstacle** card.  
- CFU cards may have strategic effects: steal cards, swap, cancel effects, etc.  
- Instant CFU cards can be played in a special phase after the main scoring.  
- **Win** by:
  - Reaching **60 CFU**, or  
  - Being the last student who hasn’t quit.  
- **Lose** if:
  - You collect **3 obstacle cards** of the same type, or  
  - You collect **one obstacle of each type**.  
- **“Exam” cards** act as wildcards towards any obstacle type.

## Project Structure by Phase

### `faseUno/` – Game Setup Phase
- Show introduction and rules screen.  
- Load `giocatori.txt`, `carte.txt` and `ostacoli.txt`.  
- Initialize decks and player structs.  
- Assign characters randomly to each player.  
- Shuffle the CFU and obstacle decks.

### `faseDue/` – Turn Loop Phase
- Drive the main turn loop:
  - Start turn and display the obstacle card.  
  - Player actions: play CFU card, discard, view game state.  
  - Update each player’s temporary score.  
  - Reveal played cards simultaneously.  
- Organized into subfolders for each action:
  - `giocaCarta/`, `scartaTutteCarteCFU/`, `controllaCartePunto/`, etc.

### `faseTre/` – Resolution & Victory Phase
- Apply CFU card effects and character bonuses.  
- Calculate final turn scores.  
- Check win/lose conditions.  
- Handle tie‑breakers and allow playing instant CFU cards.  
- End the game and announce the winner(s).

## Save System

- Supports **multiple save files**:
  - Automatically saves at the end of each turn.  
  - Players choose a custom filename.  
  - On startup, you can load an existing save.  
- Uses the `savegame.sav` binary format defined in the project specification.

##  Match Log

All actions are recorded in `log.txt`, for example:

```txt
TURN 1: Matteo plays Clion
TURN 1: Alice plays Tastiera
TURN 2: Luca plays ChristmasSweater
```

## Requirements & Notes
- Complies with C99 standard.
- No external libraries required.
- All structs and file layouts match the binary save compatibility requirements.
- Code is documented using Doxygen-style comments.

---

# Happy Little Students

## ITALIAN

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

## Struttura del Progetto per Fasi

### `faseUno/` – Preparazione della Partita
- **Visualizza presentazione** e spiega le regole.
- Caricamento file `giocatori.txt`, `carte.txt`, `ostacoli.txt`.
- Inizializzazione mazzi e giocatori.
- Assegnazione casuale dei personaggi.
- Shuffle dei mazzi.

### `faseDue/` – Svolgimento dei Turni
- Gestione del ciclo dei turni:
  - Inizio turno e stampa carta ostacolo.
  - Scelte del giocatore: giocare carta, scartare, consultare informazioni.
  - Aggiornamento punteggi temporanei.
  - Rivelazione carte.
- Azioni organizzate in sottocartelle:
  - `giocaCarta/`, `scartaTutteCarteCFU/`, `controllaCartePunto/` ecc.

### `faseTre/` – Chiusura e Condizioni di Vittoria
- Applicazione effetti carte CFU.
- Calcolo punteggio finale del turno.
- Verifica condizioni di eliminazione o vittoria.
- Gestione spareggi e uso carte istantanee.
- Conclusione della partita e stampa vincitore.

## Salvataggi

Il gioco supporta **più file di salvataggio**:
- Ogni turno viene salvato automaticamente.
- L’utente può assegnare un nome personalizzato al file.
- All’avvio è possibile caricare un salvataggio precedente.

Formato conforme alla struttura `savegame.sav` descritta nelle specifiche.

## Log

Il file `log.txt` tiene traccia cronologica degli eventi della partita, ad esempio:
```
TURNO 1: Matteo gioca Clion
TURNO 1: Alice gioca Tastiera
TURNO 2: Luca gioca Maglione Natale ...
```

## Requisiti e note
- Standard C99.
- Non utilizza librerie esterne.
- Tutte le strutture rispettano l’ordine richiesto per compatibilità con i salvataggi.
- Codice commentato secondo standard Doxygen.

