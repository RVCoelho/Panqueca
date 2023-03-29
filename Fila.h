/*                */
/* Arquivo: 
   Autores: GABRIEL CAVALCANTI FRANCISCO	
   			GABRIEL SALES COSTA
   			RICARDO VEIGA COELHO
   Date: 06/05/22 09:29
   Descrição: implementação das operações de uma fila
   
*/

#include <stdio.h>
#include "Booleano.h"
#define Max 10
#define sinal -1 //identifica a pilha vazia
#define fantasma 99 //não tem relação com o array

typedef struct {
	int inicio;
	int fim;
	int Vetor[Max];
} Fila;


Fila criarFila();
bool filaVazia(Fila);
int acessarPrimeiro(Fila);
Fila pushFila(Fila, int);
Fila popFila(Fila);
void mostrarFila(Fila);



//implementação
Fila criarFila(){
	Fila A;
	A.fim = sinal;
	A.inicio = sinal;
	
	return A;
}

bool filaVazia(Fila A){
	bool vazia = FALSE;
	
	if(A.fim == sinal)
		vazia = TRUE;
		
	return vazia;
}

int acessarPrimeiro(Fila A){
	int p = A.inicio;
	int ch;
	
	if(p != sinal)
		ch = A.Vetor[p];
		
	return ch;
}

Fila pushFila(Fila A, int ch){
	int p = (A.fim+1) % Max;
	
	if(p != A.inicio){
		A.Vetor[p] = ch;
		
		if(A.inicio == sinal) 
			A.inicio = p;  
		A.fim = p;
	}
	
	return A;
}

Fila popFila(Fila A){
	int p = A.inicio;
	int seg;
	
	if(p != sinal){
		if(p == A.fim){ //reseta a fila
			A.inicio = sinal;
			A.fim = sinal;
		}
		else{
			seg = (A.inicio + 1) % Max;
			A.inicio = seg;
		}
	}
	return A;
}

void mostrarFila(Fila A){
	if(A.inicio == sinal)
		printf("Fila vazia");
		
	else{
		int k = A.inicio;
		int j = A.fim;
		
		if(k == A.fim)
			printf(" %d ", A.Vetor[k]);
		
		else{
			//printf("%d %d", k, j);
			int x = 0;
			int y = -1;
			while(y != j){
				y = (k+x) % Max;
				printf(" %d ", A.Vetor[y]);
				x++;
			}
		}
	}
}
