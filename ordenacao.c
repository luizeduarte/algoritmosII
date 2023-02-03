#include "ordenacao.h"
#include <string.h>

void getNome(char nome[]){
        //substitua por seu nome
        strncpy(nome, "Luize Cunha Duarte", MAX_CHAR_NOME);
        nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
        return 1232;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (tam <= 0)
		return -1;

	(*numComparacoes)++;
	if (vetor[tam - 1] == valor)
		return (tam - 1);

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes);
}

int buscaBinaria_rec(int vetor[], int a, int b, int valor, int* numComparacoes){
	if (a > b)
		return -1;
	
	int m = (a + b)/2;

	(*numComparacoes)++;
	if (vetor[m] == valor)
		return m;

	(*numComparacoes)++;
	if (vetor[m] < valor)
		return buscaBinaria_rec(vetor, a, m - 1, valor, numComparacoes);
	
	return buscaBinaria_rec(vetor, m + 1, b, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
        int a = 0;
        int b = tam - 1;

	return buscaBinaria_rec(vetor, a, b, valor, numComparacoes);
}

void swap(int vetor[], int a, int b){
        int x = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = x;
}

int insert(int vetor[], int tam){
	int numComparacoes = 0;
	int i = tam - 1;

	numComparacoes++; //eh necessario contar a comparacao do while que nao entra no laco.
	while ((vetor[i] < vetor[i - 1]) && (i - 1 >= 0)){
		numComparacoes++;
		swap(vetor, i, i - 1);
		i--;
	}
	return numComparacoes;
}

int insertionSort(int vetor[], int tam){

        if (tam <= 1)
                return 0;

        int numComparacoes = insertionSort(vetor, tam - 1);
        numComparacoes += insert(vetor, tam);
        return numComparacoes;
}

int minimum(int vetor[], int a, int b){
        int min = a;

        for (int i = a + 1; i <= b; i++){
                if (vetor[i] < vetor[min])
                        min = i;
        }
        return min;
}

void selectionSort_rec(int vetor[], int a, int b, int *numComparacoes){
        if (a >= b)
                return;

        swap(vetor, a, minimum(vetor, a, b));
        (*numComparacoes) += b - a; //a funcao de achar o minimo compara todos os elementos com seu proximo.

        selectionSort_rec(vetor, a + 1, b, numComparacoes);
}

int selectionSort(int vetor[], int tam){
        int a = 0;
        int b = tam - 1;
        int numComparacoes = 0;

        selectionSort_rec(vetor, a, b, &numComparacoes);
        return numComparacoes;
}

void merge(int vetor[], int a, int b, int m, int *numComparacoes){
        int u[b - a + 1];

        if (a >= b)
                return;

        int i = a;
        int j = m + 1;

        for (int k = 0; k < b - a + 1; k++){
		(*numComparacoes)++;
                if ((j > b) || ((i <= m) && (vetor[i] <= vetor[j]))){
                        u[k] = vetor[i];
                        i++;
                } else {
                        u[k] = vetor[j];
                        j++;
		}
	}

        for (int k = 0; k < b - a + 1; k++){
		vetor[a + k] = u[k];
	}
}

void mergeSort_rec(int vetor[], int a, int b, int *numComparacoes){
	if (a >= b)
		return;
	
	int m = (a + b)/2;

	mergeSort_rec(vetor, a, m, numComparacoes);
	mergeSort_rec(vetor, m + 1, b, numComparacoes);
	merge(vetor, a, b, m, numComparacoes);
}

int mergeSort(int vetor[], int tam){
        int a = 0;
        int b = tam - 1;
	int numComparacoes = 0;

	mergeSort_rec(vetor, a, b, &numComparacoes);
	return numComparacoes;
}

int partition(int vetor[], int a, int b, int x, int *numComparacoes){
        int m = a - 1;
        int i = a;

        for (i = a; i <= b; i++){
                (*numComparacoes)++;
                if (vetor[i] <= x){
                        m++;
                        swap(vetor, m, i);
                }
        }
        return m;
}

void quickSort_rec(int vetor[], int a, int b, int *numComparacoes){
        if (a >= b)
                return;

        int m = partition(vetor, a, b, vetor[b], numComparacoes);

        quickSort_rec(vetor, a, m - 1, numComparacoes);
        quickSort_rec(vetor, m + 1, b, numComparacoes);
}

int quickSort(int vetor[], int tam){
        int numComparacoes = 0;
        int a = 0;
        int b = tam - 1;

	quickSort_rec(vetor, a, b, &numComparacoes);
	return numComparacoes;
}

void max_heapify(int vetor[], int i, int tam, int *numComparacoes){
	int largest, left = 2*i + 1, right = 2*i + 2;

	(*numComparacoes)++;
	if ((left < tam) && (vetor[left] > vetor[i]))
		largest = left;
	else 
		largest = i;

	(*numComparacoes)++;
	if ((right < tam) && (vetor[right] > vetor[largest]))
		largest = right;

	if (largest != i){
		swap(vetor, i, largest);
		max_heapify(vetor, largest, tam, numComparacoes);
	}
}

void build_max_heap(int vetor[], int tam, int *numComparacoes){
	for (int i =  tam/2 - 1; i >= 0; i--)
		max_heapify(vetor, i, tam, numComparacoes);
}

int heapSort(int vetor[], int tam){
	int numComparacoes = 0;
	build_max_heap(vetor, tam, &numComparacoes);

	for (int i = tam - 1; i >= 0; i--){
		swap(vetor, 0, i);
		max_heapify(vetor, 0, i, &numComparacoes);
	}
	return numComparacoes;
}