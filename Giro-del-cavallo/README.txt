    *********** 70% di probabilità di successo! ***********
  
    *********** Media basata su 10 risultati: 63 mosse. ***********

/*FUNZIONAMENTO DEL PROGRAMMA
 * 
 * Il seguente codice rappresenta la soluzione al problema proposto da Eulero del cavallo e della scacchiera:
 * riesce un cavallo a percorrere tutta la scacchiera senza tornare mai sui suoi passi facendo la classica mossa a "L"?
 * 
 * Il problema presentato da Eulero va risolto con una tattica speciale, infatti provando su una scacchiera reale a completare il giro del cavallo
 * possiamo notare che le caselle che prima possiamo occupare sono quelle centrali, mentre man mano che ci si avvicina ai bordi, e ancor di più
 * agli angoli, risulta più difficile accedervi.
 * Una tattica è chiaramente quella di entrare nelle caselle marginali della scacchiera appena possibile, così quando la scacchiera sarà congestionata
 * potremmo andare in quelle più facili da raggiungere. In questo modo il problema ha una buona probabilità di essere quasi risolto. 
 * Quindi, numerando le caselle dell'array rappresentante la scacchiera con il grado di accessibilità, ovvero il numero di caselle alle quali si 
 * può accedere se ci si trova su una determinata casella, possiamo sviluppare un algoritmo che è in grado di valutare quale casella, tra quelle
 * accessibili, abbia il grado di accessibilità più basso. Così il programma muoverà il cavallo in quella casella, che verrà marchiata con il valore
 * 1, il numero che contraddistingue le caselle visitate da quelle ancora da visitare. 
 * 
 * 
 * Ma ci vuole una tattica aggiuntiva, da applicare a quella sopra citata per avere più possibilità di conquistare tutte le 64 caselle:
 * il programma ha ancora solo il 30% di completare il giro del cavallo, perchè le caselle che rimangono escluse sono solitamente quelle 
 * centrali, dove per ironia della sorte, abbiamo il grado di accessibilità più alto, 8.
 * Allora mi sono ingegnato, e ho pensato che mettendo tre valori differenti di grado di accessibilità, che non sono i veri, potevo ingannare 
 * 
 * Nicolò Rossi, 17/12/2013
 * 
 * Attenzione: non so se il programma sia compatibile con tutti i sistemi linux, detto ciò assicuro che NON c'è compatibilità tra questo software e 
 * Windows.
 * 
 * 
 * *********** 70% di probabilità di successo! ***********
 * 
 * *********** Media basata su 10 risultati: 63 mosse. ***********
 * 
 * V. 3.1
 * 
 *
 * */



Compilazione del programma su Linux (x86 e x64)
Requisiti indispensabile: GCC


Per prima cosa spostiamoci nella cartella contenente il file sorgente del mio programma. 
Fatto ciò, aprite il terminale e digitate:

gcc -Wall giro-del-cavallo.c -o giro-del-cavallo

Attenzione: non cambiare nome alla source prima di questa fase.
Fatto questo, per eseguirlo basta digitare: 

./giro-del-cavallo


