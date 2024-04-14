# Table of Contents

1. [**Lezione 1**](01_04-03-24_reti.md#1-lezione----reti---04-03-24)
   1. [Informazioni del corso](01_04-03-24_reti.md#informazioni-del-corso)
   2. [Reti : Strutture a livelli](01_04-03-24_reti.md#reti--struttura-a-livelli)
      1. [Tipi di canali](01_04-03-24_reti.md#tipi-di-canali)
   3. [Tipi di comunicazione](01_04-03-24_reti.md#tipi-di-comunicazione)
   4. [Discussione di sicurezza informatica](01_04-03-24_reti.md#discussione-di-sicurezza-informatica)<br><br>

2. [**Lezione 2**](02_06-03-24_reti.md#2-lezione---reti-di-calcolatori)
   1. [Tipi di connessioni di rete: Broadcast / Point to point, ring, star, bus](02_06-03-24_reti.md#tipi-di-connessioni-di-rete)
   2. [Tipi di reti: Commutazione a pacchetto e a circuito, nozioni di storia di Internet](02_06-03-24_reti.md#tipi-di-reti)
      1. [Problemi della commutazione a pacchetti](02_06-03-24_reti.md#problemi-della-commutazione-a-pacchetti)
      2. [Circuiti Virtuali](02_06-03-24_reti.md#circuito-virtuale)
   3. [Sicurezza informatica e hacking](02_06-03-24_reti.md#sicurezza)
   4. [Dos/DDos](02_06-03-24_reti.md#attacco-dos)<br><br>
   
3. [**Lezione 3**](03_11-03-24_reti.md#3-lezione----reti)  
   1. [Livello Applicativo](03_11-03-24_reti.md#livello-applicativo)
      1. [Modello client-server](03_11-03-24_reti.md#modello-client---server)
      2. [Sincronizzazione](03_11-03-24_reti.md#sincronizzazione)
      3. [Socket](03_11-03-24_reti.md#socket)
      4. [Indirizzamento e Process IDs](03_11-03-24_reti.md#indirizzamento-e-process-ids)
      5. [Ports e comunicazione tra processi via rete](03_11-03-24_reti.md#ports-e-comunicazione-tra-processi-su-macchine-diverse-collegate-via-rete)
      6. [Protocolli e requisiti protocollo di comunicazione](03_11-03-24_reti.md#protocolli-e-requisiti-del-protocollo-di-comunicazione)
         1. [Data Integrity](03_11-03-24_reti.md#data-integrity)
         2. [Throughput](03_11-03-24_reti.md#throughput)
         3. [Timing](03_11-03-24_reti.md#timing)
         4. [Security](03_11-03-24_reti.md#sicurezza)
   2. [Livello di trasporto e protocolli](03_11-03-24_reti.md#livello-di-trasporto-e-protocolli)
   3. [Comunicazione ports e sistema operativo](03_11-03-24_reti.md#comunicazione-ports-e-sistema-operativo)
   4. [Esempio protocollo: Telnet](03_11-03-24_reti.md#esempio-di-protocollo-telnet)
      1. [Problemi Telnet](03_11-03-24_reti.md#problemi-telnet)
   5. [FTP - File Transfer Protocol](03_11-03-24_reti.md#ftp----file-transfer-protocol)
   6. [Protocolli con stato o senza stato](03_11-03-24_reti.md#protocolli-con-stato-o-senza-stato)
      1. [Protocollo HTTP: Storia, funzionamento, evoluzione](03_11-03-24_reti.md#protocollo-http-storia-funzionamento-evoluzione)<br><br>

4. [**Lezione 4**](04_15-03-24_reti.md#4-lezione----reti-di-calcolatori)
   1. [Stateful vs Stateless](04_15-03-24_reti.md#stateful-vs-stateless)
   2. [HTTP](04_15-03-24_reti.md#http)
       1. [URL](04_15-03-24_reti.md#url)
   3. [HTTP 2](04_15-03-24_reti.md#http-2)
   4. [Cookies](04_15-03-24_reti.md#cookies)<br><br>

5. [**Lezione 5**](05_18-03-24_reti.md#5-lezione----reti-di-calcolatori)
   1. [DHTML](05_18-03-24_reti.md#dhtml)
   2. [Proxy](05_18-03-24_reti.md#proxy)
   3. [SMTP](05_18-03-24_reti.md#smtp)
   4. [UUENCODE](05_18-03-24_reti.md#uuencode)
      1. [Mail(ing) Lists](05_18-03-24_reti.md#mailing-lists)
      2. [Server Email; problemi](05_18-03-24_reti.md#server-email-problemi)
   5. [DNS](05_18-03-24_reti.md#dns)<br><br>

6. [**Lezione 6**](06_22-03-24_reti.md#6-lezione----reti-di-calcolatori)
   1. [Livello di trasporto](06_22-03-24_reti.md#livello-di-trasporto)
   2. [Multiplexing e Demultiplexing](06_22-03-24_reti.md#multiplexing-e-demultiplexing)
      1. [UDP](06_22-03-24_reti.md#udp)
   3. [UDP](06_22-03-24_reti.md#udp)
   4. [RDT: Livelli di errore del TCP](06_22-03-24_reti.md#rdt-livelli-di-errore-del-tcp)<br><br>

7. [**Lezione 7**](07_04-03-24_reti.md#7-lezione----reti-di-calcolatori)
   1. [Recap lezione 6](07_04-03-24_reti.md#recap-lezione-6)
      1. [Rdt 3.0 -- errors AND package loss](07_04-03-24_reti.md#rdt-30----errors-and-package-loss)
   2. [Throughput](07_04-03-24_reti.md#throughput)
   3. [Protocollo **Stop and Wait**](07_04-03-24_reti.md#protocollo-stop-and-wait)
   4. [Protocollo Pipeline](07_04-03-24_reti.md#protocollo-pipeline)
      1. [Approccio gestione pipeline: **Go-Back-N**](07_04-03-24_reti.md#approccio-gestione-pipeline-go-back-n)
   5. [Selective repeat](07_04-03-24_reti.md#selective-repeat)
   6. [**Error rate**](07_04-03-24_reti.md#error-rate)
   7. [TCP vs UDP](07_04-03-24_reti.md#tcp-vs-udp)
   8. [TCP](07_04-03-24_reti.md#tcp)
   9. [TCP state model](07_04-03-24_reti.md#tcp-state-model)<br><br>

8.  [**Lezione 8**](08_05-04-24_reti.md#8-lezione----reti-di-calcolatori)
      1. [Pacchetto TCP](08_05-04-24_reti.md#pacchetto-tcp)
      2. [Timer](08_05-04-24_reti.md#timer)
         1. [RTT, SampleRTT, Estimated RTT, EWMA, RTO](08_05-04-24_reti.md#rtt-samplertt-estimated-rtt-ewma-rto)
         2. [Fast Retrasmit](08_05-04-24_reti.md#fast-retrasmit)
      3. [Controllo del flusso -- TCP flow control](08_05-04-24_reti.md#controllo-del-flusso----tcp-flow-control)
         1. [Algoritmo di Nagle](08_05-04-24_reti.md#algoritmo-di-nagle)
      4. [Agreeing to establish a connection](08_05-04-24_reti.md#agreeing-to-establish-a-connection)
         1. [Approccio 1974 : two-ways handshake.](08_05-04-24_reti.md#approccio-1974--two-ways-handshake)
         2. [Three Ways Handshake](08_05-04-24_reti.md#three-ways-handshake)
         3. [Come si sceglie un numero di sequenza?](08_05-04-24_reti.md#come-si-sceglie-un-numero-di-sequenza)<br><br>

9. [**Lezione 9**](09_10-04-24_reti.md#9-lezione----reti-di-calcolatori)
   1. [Recap lezione prima](09_10-04-24_reti.md#recap-lezione-prima)
   2. [Chiusura delle connessioni](09_10-04-24_reti.md#chiusura-delle-connessioni)
   3. [Altro sul TCP](09_10-04-24_reti.md#altro-sul-tcp)
   4. [**CONGESTIONE**](09_10-04-24_reti.md#congestione)
      1. [Scenario ideale : Due hosts, Modem buffer infinito](09_10-04-24_reti.md#scenario-ideale--due-hosts-modem-buffer-infinito)
      2. [Due hosts, buffer del modem finito](09_10-04-24_reti.md#due-hosts-buffer-del-modem-finito)
      3. [Scenario 3 -- vedi slide](09_10-04-24_reti.md#scenario-3----vedi-slide)
      4. [Approcci riguardo il controllo di congestione](09_10-04-24_reti.md#approcci-riguardo-il-controllo-di-congestione)
      5. [Approccio AIMD: Incremento additivo, decremento moltiplicativo](09_10-04-24_reti.md#approccio-aimd-incremento-additivo-decremento-moltiplicativo)
      6. [Approccio Slow Start](09_10-04-24_reti.md#approccio-slow-start)
      7. [Due versione del TCP: Tahoe, Reno](09_10-04-24_reti.md#due-versione-del-tcp-tahoe-reno)
      8. [implementazione](09_10-04-24_reti.md#implementazione)
      9. [Simulatore e grafi : Tahoe Vs Reno](09_10-04-24_reti.md#simulatore-e-grafi--tahoe-vs-reno)
      10. [Perche' Vegas non si usa?](09_10-04-24_reti.md#perche-vegas-non-si-usa)<br><br>

10. [**Lezione 10**](10_12-04-24_reti.md#10-lezione----reti-di-calcolatori)
- [Recap comprensivo -- congestione e soluzioni](10_12-04-24_reti.md#recap-comprensivo----congestione-e-soluzioni)
    - [note sul controllo congestione](10_12-04-24_reti.md#note-sul-controllo-congestione)
- [Dimostrazione della TCP fairness --  Spartizione di connessioni. Triangolo](10_12-04-24_reti.md#dimostrazione-della-tcp-fairness-----spartizione-di-connessioni-triangolo)
    - [Pero' ...](10_12-04-24_reti.md#pero-)
- [HTTP3.0](10_12-04-24_reti.md#http30)
    - [Caratteristiche](10_12-04-24_reti.md#caratteristiche)<br><br>