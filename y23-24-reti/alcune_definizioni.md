# Reti 

## Capitolo 1

* **Host (Ospite)** / **End system (Sistema periferico)**  
Dispositivo collegato ad Internet. Host in quanto ospitano ed eseguono programmi applicativi (browsers, web servers, softwares di lettura e gestione della posta elettronica). 
Gli Hosts sono spesso suddivisi in due categorie: **Client** e **Server**. In maniera informale, i Clients sono host che richiedono servizi, come laptops, cellulari, e altro tipo di dispositivo elettronico personale, mentre i server si occupano di erogare servizi, e sono macchine usualmente piu' potenti che memorizzano e distribuiscono pagine web o flussi video. La maggior parte dei servers da cui riceviamo risultati di ricerche, email, pagine web e video, e' collocata in grandi **Data Centers**.
 

* **ISP**  
Internet Service Provider. Tramite cui i sistemi periferici accedono ad internet. 

* **Provider**  
Un insieme di commutatori a pacchetto e di collegaemtni

* **TCP**  
Transmission Control Protocol. Primo protocollo TCP/IP : 1983 come standard degli host ARPAnet (sostituisce NCP)

* **IP**  
Internet Protocol. Specifica il formato dei pacchetti scambiati tra router e sistemi periferici. 

* **IETF**  
Internet Engineering Task Force (Sviluppano gli standard di Internet

* **RFC**  
Request For Comment, le pubblicazioni sugli standard di Internet. Inizialmente si trattava di richieste generiche di commenti pe risolvere problemi di architettura sulle reti precedenti ad Internet. Sono tecniche e dettagliate. Definiscono protocolli come TCP, IP, HTTP, SMTP. Ne esistono piu' di novemila.  

* **Socket Interface (Interfaccia Socket)**   
Un insieme di regole che il programma mittente deve seguire in modo che i dati siano recapitati al programma di destinazione.
Specifica come un programma eseguito su un sistema periferico possa chiedere ad Internet di recapitare dati ad un programma eseguito su un altro sistema periferico. 

* **Protocollo**  
Un protocollo definisce il formato e l'ordine dei messaggi scambiati tra due o piu' entita' in comunicazione, cosi' come le azioni intraprese e in fase di trasmissione e/o ricezione di un messaggio o di un altro evento

* **Rete di Accesso (Access Network)**   
Reti che connettono fisicamente un sistema al suo **Edge Router (Router di bordo)**, ovvero il primo router sul percorso dal sistema di origine a qualsiasi altro sistema di destinazione al di fuori della stessa rete di accesso.

* **DSL**  
Digital Subscriber Line. Un tipo di accesso residenziale a larga banda molto diffuso, che viene fornito dalla stessa compagnia telefonica che gestisce anche il servizio di telefonia fissa. In questo modo, la compagnia telefonica assume anche il ruolo di **ISP**. Converte i dati digitali in toni ad alta frequenza per poterli trasmettere alla centrale locale sul cavo telefonico. 
(Si occupa del passaggio dal livello di Data Link al livello fisico.) 
Si dice ADSL --> Asymmetric perche' il downstream e upstream non sono uguali 

* **DSLAM**  
Digital Subscriber Line Access Multiplex, che si trova nella **centrale locale** della compagnia telefonica. Scambia dati con il modem DSL dell'utente attraverso la linea telefonica. I dati arrivano ad esso codificati su tre frequenze non sovrapposte:  
    * Canale downstream (verso l'abitazione) 50kHz / 1MHz
    * Canale upstream (verso il DSLAM) 4 - 50 kHz
    * Canale telefonico ordinario a due vie, 0 - 4 kHz  
In tale maniera, una telefonata e una connessione ad Internet possono condividere lo stesso collegamento. 

* **HFC**  
Hybrid Fiber Coax

* **CMTS**  
Cable Modem Termination System

* **FTTH**  
Fiber to the Home; fornire fibra ottica dalla centrale locale direttamente alle abitazioni. 
Una delle reti di distribuzioni della FTTH e' la **fibra diretta**, in cui una singola fibra collega la centrale all'abitazione. Di solito pero' e' condivisa.  
Due architetture gestiscono la suddivisione nelle diverse abitazioni degli utenti: la **AON** (active optical networks, ethernet commutate(?)) e la **PON** (Passive optical networks)(Usate nel servizio FIOS di Verizon).  

* **ONT**  
Optical Network Terminator, un terminatore ottico che e' in una abitazione, connesso a uno splitter (separatore ottico) di quartiere utilizzato nelle PON.  

* **OLT**  
Optical Line Terminator, situato nella centrale locale della compagnia telefonica, e' dove le linee di fibra ottica arrivano partendo dalle abitazioni. Fornisce la conversione tra segnali ottici ed elettrici. 

* **FWA**  
5G Fixed Wireless Access, che promette un accesso residenziale ad alta velocita' ma senza fare installare cavi costosi e soggetti a guasti. Utilizzando la tecnologia **Beam-Forming**, i dati vengono inviati in modalita' wireless dalla stazione di base al modem di casa. Un Router Wireless Wi-Fi e' collegato al modem in modo simile a come un routere wireless wifi e' collegato a un modem via cavo o DLS. 

* **LAN**  
Local Area Network. Un esempio di LAN e' Ethernet. Generalmente tra i 100Mbps e i 10Gbps. (i server di piu'). Le LAN wireless (Basate sulla tecnologia IEEE 802.11 anche detta Wi-Fi) sono molto diffuse.

* **UTP**  
Unshielded Twisted Pair, Doppino intrecciato non schermato, collegamento di comunicazione utilizzato comunemente per le LAN. 10Mbps - 10Gbps. 

* **Cavo Coassiale**  
Costituito da due conduttori di rame concentrici. Comune nei sistemi televisivi e nell'accesso ad internet via cavo. Puo' essere utilizzato come mezzo condiviso vincolato. Centinaia di Mbps.  

* **Fibra Ottica**  
Mezzo piu' veloce, conduce tramite impulsi di luce, fino a decine o centinaia di Gbps. Utilizzate nei grandi cavi intercontinentali e a lungo raggio, ma sono anche il mezzo piu' costoso.  

* **Canali Radio Terrestri**  
Distinguibili in distanze piccole (Bluetooth), locali (LAN wireless), e aree vaste (Tecnologie di accesso cellulare). 

* **Canali Radio Satellitari**  
Esistono quelli geostazionari (**GEO**, geostationary earth orbit) e quelli a bassa quota (**LEO**, low-earth orbiting). Spesso utilizzati quando i collegamenti via cavo non sono viabili.  

* **ARPA**  
Advanced Research Project Agency, MIT. Alcuni dei primi progetti di networking negli anni 60/70. Cessa di esistere negli anni 90.  


* **NCP**  
Network-Control Protocol, 1972, RFC 001. Primo protocollo tra i nodi ARPAnet.  

* **DNS**  
Domain Name System --> negli anni 80 si iniziano ad associare i nomi internet leggibili agli indirizzi a 32 bit di IP.  

* **World Wide Web** 
Nasce il web (89-91, al CERN da Tim Berners-Lee) e nuove applicazioni come motori di ricerca (google, bing), e-commerce (amazon, ebay), social networks (facebook).  

---

## Capitolo 2
  
* Parole chiave:    
  * Modello Client/Server
  * Modello Peer2Peer
  * Data centers (arcitetture che riescono a gestire grandissime quantita' di richieste)


* **Processi comunicanti** 
Programmi in esecuzione su sistemi che comunicano tra di loro tramite **Interprocess Communication**.  Tra sistemi diversi i processi possono comunicare scambiandosi **messaggi** attraverso la rete. 

* **Processi Client e Server**
Nel contesto di una sessione di comunicazione tra una coppia di processi, quello che avvia la comunicazione (contatta l'altro processo all'inizio della sessione) è indicato come client, mentre quello che attende di essere contattato per iniziare la connessione è detto server.  
  
* **Sockets** 
Una interfaccia software che permette ai processi di comunicare attraverso la rete. E' l'interfaccia tra il livello applicativo e il livello di trasporto all'interno di un host. Un progettista di una applicazione ha controllo totale sul livello applicativo della socket, ma poco sul livello di trasporto. Puo' però sceglierne il protocollo di trasporto e a volte determinare alcuni parametri come la dimensione massima del buffere e del segmento.  
  
* **Indirizzamento**  

Il destinatario del messaggio deve avere un indirizzo affinché il mittente possa recapitare ad esso messaggi. NOTA: l'indirizzo IP del server e' considerato fisso a differenza dei client, perche' deve essere noto ai client a priori. E' conosciuto dai DNS.  
Inoltre il mittente deve anche sapere il processo a cui fa riferimento (numero di porta di destinazione). Alcuner applicazioni hanno numeri specifici di porta. 
  



---
pg 69print (nice), 97 digital