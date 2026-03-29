# Multi-threaded Safe Logger

Questo progetto si basa su un sistema che simula più componenti (thread) che tentano di scrivere log su una risorsa condivisa (console/file) simultaneamente (tramite **thread, mutex e gestione della concorrenza**).

---

## Obiettivi

- Gestione di thread multipli con `std::thread`.

- Prevenzione delle **Race Conditions** (competizione tra thread) tramite sincronizzazione.

- Utilizzo di **Mutex** (`std::mutex`) per garantire l'accesso esclusivo alla risorsa.

- Implementazione del pattern **RAII** per la gestione dei lock tramite `std::lock_guard`.



### Mutex & Lock Guard

Per evitare che i messaggi dei diversi thread si sovrappongano, ho utilizzato un `std::mutex`.
L'uso di `std::lock_guard<std::mutex>` assicura che il mutex venga rilasciato automaticamente non appena la funzione termina, prevenendo i **Deadlock**.

### Thread Join

Il sistema utilizza `.join()` per assicurarsi che il programma principale (`main`) attenda la fine del lavoro di tutti i thread prima di chiudersi, garantendo una terminazione pulita del processo.

---

## Struttura dei File

- `include/Logger.hpp`: Classe thread-safe per il logging.

- `src/main.cpp`: Simulazione di più thread che scrivono in parallelo.


