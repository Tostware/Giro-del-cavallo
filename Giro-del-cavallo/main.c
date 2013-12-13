/*FUNZIONAMENTO DEL PROGRAMMA
 * Il seguente codice rappresenta la soluzione al problema proposto da Eulero del cavallo e della scacchiera:
 * riesce un cavallo a percorrere tutta la scacchiera senza tornare mai sui suoi passi facendo la classica mossa a "L"?
 * 
 * Il problema viene così risolto: viene dichiarato un array 8x8 rappresentante la scacchiera. 
 * Vengono assegnati valori alle caselle in base al grado di accessibilità. Il grado di accessibilità è la quantità di caselle
 * dalle quali si può accedere a una determinata casella. Il programma valuterà quale delle caselle a cui può accedere è quella 
 * con il grado più basso, e andrà lì. Così facendo il programma ha più possibilità di terminare le 64 mosse.
 * 
 * Nicolò Rossi, 13/12/2013
 * 
 * V. 2.1 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int npos1, npos2;

int mossa_cavallo (int scacchiera [8] [8]);

int board_wr (int scacchiera [8] [8]);

int chooser (int pos1, int pos2, int board [8] [8]);

int main (void){

	int board [8] [8];  //matrice rappresentante la scacchiera
	
	board_wr (board); //chiamata alla funzione che azzera la scacchiera

	mossa_cavallo(board); //chiamata alla funzione che fa muovere il cavallo

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
	
	for ( j=2 ; j<=5; j++){ /*scrittura degli 8*/
		for ( i=2 ; i<=5; i++){
			scacchiera [i] [j]=8;
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

	return scacchiera [8] [8];
}

int mossa_cavallo (int scacchiera [8] [8]){ //funzione addetta a far muovere il cavallo
	
	int i;
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

	printf("Ho completato %d passaggi",i);
			
	
	return scacchiera [8] [8];
	
}

int chooser (int pos1, int pos2, int board [8] [8]){
	
		int last=90;
		npos1=pos1;
		npos2=pos2;
		
		//parte MONELLA!!!
		
		if (pos1>=1 && pos2 <=5 && board [pos1-1] [pos2+2]!=1){
			npos1=pos1-1;
			npos2=pos2+2;
			last=board[pos1-1][pos2+2];
		}
		
		if (pos1>=2 && pos2>=1 && board [pos1-2] [pos2-1]!=1 && board [pos1-2] [pos2-1]<last){
			npos1=pos1-2;
			npos2=pos2-1;
			last=board[pos1-2][pos2-1];
		}
		
		if (pos1<=5 && pos2 <=6 && board [pos1+2] [pos2+1]!=1 && board [pos1+2] [pos2+1]<last){
			npos1=pos1+2;
			npos2=pos2+1;
			last=board[pos1+2][pos2+1];
		}
		
		if (pos1>=2 && pos2 <=6 && board [pos1-2] [pos2+1]!=1 && board [pos1-2] [pos2+1]<last){
			npos1=pos1-2;
			npos2=pos2+1;
			last=board[pos1-2][pos2+1];
		}
		
		if (pos1<=5 && pos2 >=1 && board [pos1+2] [pos2-1]!=1 && board [pos1+2][pos2-1]<last){
			npos1=pos1+2;
			npos2=pos2-1;
			last=board[pos1+2][pos2-1];
		}
		
		if (pos1>=2 && pos2 >=1 && board [pos1-2] [pos2-1]!=1 && board [pos1-2][pos2-1]<last){
			npos1=pos1-2;
			npos2=pos2-1;
			last=board[pos1-2][pos2-1];
		}
		
		if (pos1<=6 && pos2 <=5 && board [pos1+1] [pos2+2]!= 1 && board [pos1+1] [pos2+2]<last){
			npos1=pos1+1;
			npos2=pos2+2;
			last=board[pos1+1][pos2+2]; 
		}
		
		if (pos1 <=6 && pos2 >=2 && board [pos1+1] [pos2-2]!=1 && board [pos1+1][pos2-2]<last){
			npos1=pos1+1;
			npos2=pos2-2;
			last=board[pos1+1][pos2-2];
		}
		
		if (last==90) {
		printf("Non posso accedere a nessuna casella! Ciclo terminato!\n");
		npos1=90;
		}
		
		return 0;
		
	
	
}



