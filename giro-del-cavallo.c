/*FUNZIONAMENTO DEL PROGRAMMA
 * 
 * Il seguente codice rappresenta la soluzione al problema proposto da Eulero del cavallo e della scacchiera:
 * riesce un cavallo a percorrere tutta la scacchiera senza tornare mai sui suoi passi facendo la classica mossa a "L"?
 * 
 * Il problema presentato da Eulero va risolto con una tattica speciale, infatti provando su una scacchiera reale a completare il giro del cavallo
 * possiamo notare che le caselle che prima possiamo occupare sono quelle centrali, mentre man mano che ci si avvicina ai bordi, e ancor di pi�
 * agli angoli, risulta pi� difficile accedervi.
 * Una tattica � chiaramente quella di entrare nelle caselle marginali della scacchiera appena possibile, cos� quando la scacchiera sar� congestionata
 * potremmo andare in quelle pi� facili da raggiungere. In questo modo il problema ha una buona probabilit� di essere quasi risolto. 
 * Quindi, numerando le caselle dell'array rappresentante la scacchiera con il grado di accessibilit�, ovvero il numero di caselle alle quali si 
 * pu� accedere se ci si trova su una determinata casella, possiamo sviluppare un algoritmo che � in grado di valutare quale casella, tra quelle
 * accessibili, che ha il grado di accessibilit� pi� basso. Cos� il programma muover� il cavallo in quella casella, che verr� marchiata con il valore
 * 1, il numero che contraddistingue le caselle visitate da quelle ancora da visitare. 
 * 
 * Ho notato, per�, che con questo metodo solo 3 esecuzioni su 10 completavano il giro del cavallo. Ho dovuto quindi mettere dei valori di accessibilit� 
 * falsi ad alcune delle caselle centrali. Cos� facendo, sono arrivato a ottenere il 70% di possibilit� di successo del programma.
 *
 *
 *
 *          V 3.2.0                       10/07/2014
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int npos1, npos2;

int mossa_cavallo (int scacchiera [8] [8]);

int mossa_cavallo_usercontrol (int scacchiera [8] [8]);

int board_wr (int scacchiera [8] [8]);

int chooser (int pos1, int pos2, int board [8] [8]);

int main (void){
    int i,y; //i=riga            y=colonna
    int choose;   //variabile della scelta
    int board [8] [8];  //matrice rappresentante la scacchiera
    
    board_wr (board); //chiamata alla funzione che azzera la scacchiera
    
    printf("1. Immetti le coordinate di una casella (riga, INVIO, colonna). \nLa casella 0,0 e quella in alto a sinistra.\n\n2. Testa il programma con una casella random generata dal pc\n\n\n");
    scanf("%d", &choose);
    
    switch (choose){
           case 1:
                printf("\n\n\nDimmi la riga  \n");      
                scanf("%d",& i);
                    if(i>7){ //valutazione dell'input....
                        printf("Hai immesso un valore inesistente. Uscita...\n");
                        break;
                    }
                    
                printf("\n\n\nDimmi la colonna\n");
                scanf("%d",& y);
                    if(y>7){ //valutazione dell'input....
                                printf("Hai immesso un valore inesistente. Uscita...\n");
                                break;
                    }
                                           
                npos1=i; 
                npos2=y;
                mossa_cavallo_usercontrol(board);
                break;
                
                
           case 2:      
                mossa_cavallo(board); //chiamata alla funzione che fa muovere il cavallo
                break;
           
           default:     
                printf("ERRORE! Hai scelto un valore non valido! Uscita...\n");
                
    }
    

	system ("PAUSE");

return 0;
}

int board_wr (int scacchiera [8] [8]){ //funzione che scrive sulla scacchiera

	int i, j; //i=righe       j=colonne

	for ( j=0 ; j<=7; j++){ /*scrittura dei 4 sulla scacchiera*/
		for ( i=0 ; i<=7; i++){
			scacchiera [i] [j]=4;
		}
	}
	//scrittura dei 2
	scacchiera [0] [0]=2;
	scacchiera [0] [7]=2;
	scacchiera [7] [0]=2;
	scacchiera [7] [7]=2;
	
	
	//scrittura dei 3
	scacchiera [1] [0]=3;
	scacchiera [0] [1]=3;
	scacchiera [6] [0]=3;
	scacchiera [1] [7]=3;
	scacchiera [7] [6]=3;
	scacchiera [6] [7]=3;
	scacchiera [1] [7]=3;
	scacchiera [0] [6]=3;
	
	for ( j=2 ; j<=5; j++){ /*scrittura dei 9*/
		for ( i=2 ; i<=5; i++){
			scacchiera [i] [j]=9;
		}
	}
	
	//scrittura dei 6
	
	scacchiera [2] [1]=6;
	scacchiera [1] [2]=6;
	scacchiera [1] [3]=6;
	scacchiera [1] [4]=6;
	scacchiera [1] [5]=6;
	scacchiera [2] [6]=6;
	scacchiera [3] [6]=6;
	scacchiera [4] [6]=6;
	scacchiera [5] [6]=6;
	scacchiera [6] [5]=6;
	scacchiera [6] [4]=6;
	scacchiera [6] [3]=6;
	scacchiera [6] [2]=6;
	scacchiera [5] [1]=6;
	scacchiera [4] [1]=6;
	scacchiera [3] [1]=6;
	
	//test dei 10 nei 4 nel centro
	
	scacchiera [3] [3]=10;
	scacchiera [3] [4]=10;
	scacchiera [4] [3]=10;
	scacchiera [4] [4]=10;

	//8 agli angoli
	
	scacchiera [5] [5]=8;
	scacchiera [2] [5]=8;
	scacchiera [5] [2]=8;
	scacchiera [2] [2]=8;
	return scacchiera [8] [8];
}

int mossa_cavallo (int scacchiera [8] [8]){ //funzione addetta a far muovere il cavallo
	
	int i=0;
	int pos1, pos2;
	
	
	srand(time(NULL)); //Inseminazione. Da chiamare solo una volta
	//Generazione casuale della posizione 1 e 2
	pos1=rand () % 8;
	pos2=rand () % 8;
	
	
	while (npos1 != 90){ //ciclo del programma
		i++;
		
		printf("%d		%d\n", pos1, pos2);
		
		scacchiera [pos1] [pos2] =1;
		 
		chooser (pos1, pos2, scacchiera); //chiamata alla funzione chooser

		pos1=npos1;
		pos2=npos2;
		
		
}	

	if (i==64){
		printf("Caselle completate! Giro del cavallo risolto!\n");
	}
	else 
	printf("Non posso accedere a nessuna casella! Ciclo terminato!\n");
	
	
	printf("Ho completato %d passaggi\n",i);
			
	
	return scacchiera [8] [8];
	
}

int mossa_cavallo_usercontrol (int scacchiera [8] [8]){ //funzione addetta a far muovere il cavallo secondo le coordinate dell'utente
	
	int i=0;
	int pos1, pos2;
	
	
	pos1=npos1;
	pos2=npos2;
	
	//bsdbfdhbvhubhsbvdsbvdshbvhsfbvshbvsdbvsibvsbvsbvsvbsbv
	
	
	while (npos1 != 90){ //ciclo del programma
		i++;
		
		printf("%d		%d\n", pos1, pos2);
		
		scacchiera [pos1] [pos2] =1;
		 
		chooser (pos1, pos2, scacchiera); //chiamata alla funzione chooser

		pos1=npos1;
		pos2=npos2;
		
		
}	

	if (i==64){
		printf("Caselle completate! Giro del cavallo risolto!\n");
	}
	else 
	printf("Non posso accedere a nessuna casella! Ciclo terminato!\n");
	
	
	printf("Ho completato %d passaggi\n",i);
			
	
	return scacchiera [8] [8];
	
}

int chooser (int pos1, int pos2, int board [8] [8]){
	
		int last=90;
		npos1=pos1;
		npos2=pos2;
		
		
		if (pos1>=1 && pos2 <=5 && board [pos1-1] [pos2+2]!=1){ //-1 +2
			npos1=pos1-1;
			npos2=pos2+2;
			last=board[pos1-1][pos2+2];
		}
		
		if (pos1>=2 && pos2>=1 && board [pos1-2] [pos2-1]!=1 && board [pos1-2] [pos2-1]<last){ //-2 -1
			npos1=pos1-2;
			npos2=pos2-1;
			last=board[pos1-2][pos2-1];
		}
		
		if (pos1>=1 && pos2>=2 && board [pos1-1] [pos2-2]!=1 && board [pos1-1] [pos2-2]<last){ //-1 -2
			npos1=pos1-1;
			npos2=pos2-2;
			last=board[pos1-1][pos2-2];
		}
		
		if (pos1<=5 && pos2 <=6 && board [pos1+2] [pos2+1]!=1 && board [pos1+2] [pos2+1]<last){ //+2 +1
			npos1=pos1+2;
			npos2=pos2+1;
			last=board[pos1+2][pos2+1];
		}
		
		if (pos1>=2 && pos2 <=6 && board [pos1-2] [pos2+1]!=1 && board [pos1-2] [pos2+1]<last){ //-2 +1
			npos1=pos1-2;
			npos2=pos2+1;
			last=board[pos1-2][pos2+1];
		}
		
		if (pos1<=5 && pos2 >=1 && board [pos1+2] [pos2-1]!=1 && board [pos1+2][pos2-1]<last){ //+2 -1
			npos1=pos1+2;
			npos2=pos2-1;
			last=board[pos1+2][pos2-1];
		}
		
		if (pos1<=6 && pos2 <=5 && board [pos1+1] [pos2+2]!= 1 && board [pos1+1] [pos2+2]<last){ //+1 +2
			npos1=pos1+1;
			npos2=pos2+2;
			last=board[pos1+1][pos2+2]; 
		}
		
		if (pos1 <=6 && pos2 >=2 && board [pos1+1] [pos2-2]!=1 && board [pos1+1][pos2-2]<last){ //+1 -2
			npos1=pos1+1;
			npos2=pos2-2;
			last=board[pos1+1][pos2-2];
		}
		
		if (last==90) {
		npos1=90;
		}
		
		return 0;
		
	
	
}






