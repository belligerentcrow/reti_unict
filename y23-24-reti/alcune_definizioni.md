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
Transmission Control Protocol

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

 
