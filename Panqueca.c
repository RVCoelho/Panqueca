/*                */
/* Arquivo: Panqueca.c
   Autores: GABRIEL CAVALANTI FRANCISCO
   			GABRIEL SALES COSTA
   			RICARDO VEIGA COELHO
   Date: 06/05/22 10:41
   Descrição: Interface e corpo de 3 funções que implementam o funcionamento da ordenação das panquecas,
   			  além do corpo principal do algoritmo das panquecas.
   
*/

#include "Pilha.h"
#include "Fila.h"
#include <stdlib.h>
#include <time.h>

int contarPilha(Pilha, int);
Pilha construirPilha(int);
Pilha inverter(Pilha, int);


int contarPilha(Pilha A, int ch){
	int qtd = A.topo;
	
	Pilha B; B=criarPilha(B);
	
	while(A.Vetor[qtd] != ch){
		pushPilha(B, A.Vetor[qtd]);
		qtd--;
	}
		
	int pos = Max-qtd;
	return pos;
}

Pilha construirPilha(int k){
	
	Pilha A;
	A=criarPilha();
	int i = 1;
	
	//montar
	for(i; i <= k; i++){
		A = pushPilha(A, i);
	}
	
	//embaralhar
	int x = k-1;
	while(x > 1){
		int pos = rand() % x;
				
		int aux = A.Vetor[pos];
		A.Vetor[pos] = A.Vetor[x];
		A.Vetor[x] = aux;
		x--;
	}
	
	return A;
}

Pilha inverter(Pilha A, int pos){
	
	int topo = A.topo;

	for(topo; topo >= pos; topo--){
		
		int aux = A.Vetor[topo];
		A.Vetor[topo] = A.Vetor[pos];
		A.Vetor[pos] = aux;
		
		pos++;
	}
	
	return A;
}


int main(){
	
	srand((int) time(NULL));
	
	int n = Max;
	Pilha P = construirPilha(n);
	
	mostrarPilha(P);
	
	do{
		
		int qtd = contarPilha(P, n);
		int p = P.topo;
		
		if(qtd != n){
			if(qtd != 1){
				P = inverter(P, Max-qtd);
			}
			P = inverter(P, Max-n);
		}
		
		n--;
		
	}while(n != 1);
	
	printf("\n");
	mostrarPilha(P);
	
	return 0;
}

