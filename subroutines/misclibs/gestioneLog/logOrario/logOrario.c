#include "logOrario.h"
void logOrario() {
    FILE *logFile;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    logFile = fopen("log.txt", "a"); // Apri il file in modalità append per aggiungere nuovi log
    if (logFile == NULL) {
        printf("Errore nell'apertura del file log.txt\n");
        exit(1);
    }

    fprintf(logFile, "Partita del: ");
    fprintf(logFile, "%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(logFile); // Chiudi il file
}