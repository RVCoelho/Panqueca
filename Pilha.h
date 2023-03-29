/*  Produção da biblioteca do tipo Pilha  */
/* Arquivo: Pilha.h
   Autores: GABRIEL CAVALCANTI FRANCISCO	
   			GABRIEL SALES COSTA
   			RICARDO VEIGA COELHO
   Date: 29/04/22 09:18
   Descrição: implementação das operações principais de uma pilha
   
*/

/*Pilha.h
	- Os elementos da pilha são guardados a partir da posição 0
	- O campo topo indica o local onde está o último item colocado na pilha
	- Os elementos da pilha não são números inteiros não negativos	{1, 2, 3, 4, ...}
*/

#include <stdio.h>
#include "Booleano.h"
#define Max 10
#define sinal -1 //identifica a pilha vazia
#define geist 0

typedef struct{
	int topo; //local do último item
	int Vetor[Max];
} Pilha;	
	
//Interfaces
Pilha criarPilha();
bool pilhaVazia(Pilha);
void mostrarPilha(Pilha);
Pilha pushPilha(Pilha, int);
Pilha popPilha(Pilha);
int acessarTopo(Pilha);

//Implementação
Pilha criarPilha(){
	Pilha A;
	A.topo = sinal;
	
	return A;
}

bool pilhaVazia(Pilha A){
	bool vazia = FALSE;
	
	if(A.topo == sinal)
		vazia = TRUE;
		
	return vazia;
}

void mostrarPilha(Pilha A){
	int tam = A.topo;
	int i = tam;
	if(tam == sinal) //verifica se está vazia 
		printf("\nPilha vazia");
		
	else{
		for(i; i >= 0; i--){
			int ch = A.Vetor[i];
			printf("\n %d", ch);
		}
	}
}

Pilha pushPilha(Pilha A, int ch){
	int p = A.topo+1;
	
	if(p != Max){
		A.Vetor[p] = ch;
		A.topo = p;
	}
		
	return A;
}

Pilha popPilha(Pilha A){
	int tam = A.topo;
	int p;
	
	if(tam != sinal) { //verifica se não está vazio
		p = tam-1;
		A.topo = p;
	}
	
	return A;
}

int acessarTopo(Pilha A){
	
	int p = A.topo;
	int ch;
	
	if(p == sinal)
		ch = geist;
	else
		ch = A.Vetor[p];
	
	return ch;
}
