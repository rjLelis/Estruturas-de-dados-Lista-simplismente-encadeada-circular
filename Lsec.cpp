#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//Estrutura da lista
struct lsec {
	int numero;
	struct lsec *prox;
}*prim,*ult,*aux;

// Assinaturas das funções
void inclusao(int numero);
void listagem();
void exclusao(int numero);

// Programa principal
main(){
	int op,x;
	do{
		puts("1 - inclusao");
		puts("2 - listagem");
		puts("3 - exclusao");
		cout << ">>> ";
		cin >> op;
		switch(op){
			case 1:
				cout << "Digite um numero: ";
				cin >> x;
				inclusao(x);
				break;
			case 2:
				listagem();
				break;
			case 3:
				cout << "Digite um numero: ";
				cin >> x;
				exclusao(x);
				break;
		}
	}while(op != 4);
}

// Inclusao
void inclusao(int numero){
	aux = (struct lsec *) malloc(sizeof(struct lsec));
	if(prim == NULL){
		prim = aux;
	}else{
		ult->prox = aux;
	}
	ult = aux;
	ult->numero = numero;
	ult->prox = prim;
	puts("Inclusao realizada!");
}

// Listagem
void listagem(){
	if(prim != NULL){
		puts("Valores:");
		cout << prim->numero << "\n";
		aux = prim->prox;
		while(aux != prim){
			cout << aux->numero << "\n";
			aux = aux->prox;
		}
	} else{
		puts("Lista vazia!");
	}
}

// Exclusao
void exclusao(int numero){
	struct lsec *aux2;
	int achei = 0;
	aux = prim;
	if(prim != NULL){
		if(prim->numero == numero){
			if(prim == ult){
				prim = ult = NULL;
			} else{
				prim = prim->prox;
				ult->prox = prim;
			}
			achei = 1;
			free(aux);
		} else {
			aux = prim->prox;
			aux2 = prim;
			while(aux != prim && achei == 0){
				if(aux->numero == numero){
					if(aux == ult){
						ult = aux2;
						ult->prox = prim;
					} else {
						aux2->prox = aux->prox;
					}
				achei = 1;
				free(aux);
				} else {
					aux2 = aux;
					aux = aux->prox;
				}
			}
		}
 	} else {
 		puts("Lista vazia!");
	}
	if(achei == 0){
		puts("Numero nao encontrado!");
	}else{
		puts("Exclusao realizada!");
	}
}
