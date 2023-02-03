#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#define TAM1 50000 //utilizado para o primeiro teste
#define TAM2 20 //utilizado no segundo e terceiro teste

void cria_vetor_ordenado(int v[], int tam){
	for (int i = 0; i < tam; i++)
		v[i] = i + 1;
}

void cria_vetor_decresente(int v[], int tam){
	for (int i = 0; i < tam; i++)
		v[i] = tam - i;
}

void cria_vetor_aleatorio(int v[], int tam){
	for (int i = 0; i < tam; i++)
		v[i] = rand()%10000;
}

void imprime_vetor(int v[], int tam){
	for (int i = 0; i < tam; i++)
		printf("%d ", v[i]);
	printf("\n\n");
}

int main(){
	int* v = malloc(TAM1 * sizeof(int));
	clock_t start, end;
    double total;
	int numComp, valor, indice, numComparacoes = 0;
	char nome[MAX_CHAR_NOME];

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	printf("	PRIMEIRO TESTE: analise de tempo de CPU e numero de comparacoes de cada algoritmo:\n\n");
	printf("	Utilizando um vetor de tamanho %d ordenado:\n\n", TAM1);

	cria_vetor_ordenado(v, TAM1);
	start = clock();
	numComp = insertionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o insertion sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_ordenado(v, TAM1);
	start = clock();
	numComp = selectionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o selection sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_ordenado(v, TAM1);
	start = clock();
	numComp = mergeSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o merge sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_ordenado(v, TAM1);
	start = clock();
	numComp = quickSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o quick sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_ordenado(v, TAM1);
	start = clock();
	numComp = heapSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o heap sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	printf("	Utilizando um vetor de tamanho %d ordenado ao contrario:\n\n", TAM1);

	cria_vetor_decresente(v, TAM1);
	start = clock();
	numComp = insertionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o insertion sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_decresente(v, TAM1);
	start = clock();
	numComp = selectionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o selection sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_decresente(v, TAM1);
	start = clock();
	numComp = mergeSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o merge sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_decresente(v, TAM1);
	start = clock();
	numComp = quickSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o quick sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);



	cria_vetor_decresente(v, TAM1);
	start = clock();
	numComp = heapSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o heap sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	printf("	Utilizando um vetor de tamanho %d aleatorizado:\n\n", TAM1);

	cria_vetor_aleatorio(v, TAM1);
	start = clock();
	numComp = insertionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o insertion sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_aleatorio(v, TAM1);
	start = clock();
	numComp = selectionSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o selection sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_aleatorio(v, TAM1);
	start = clock();
	numComp = mergeSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o merge sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_aleatorio(v, TAM1);
	start = clock();
	numComp = quickSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o quick sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);


	cria_vetor_aleatorio(v, TAM1);
	start = clock();
	numComp = heapSort(v, TAM1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Para o heap sort:\n tempo total: %f\n numero de comparacoes: %d\n\n", total, numComp);



	printf("	SEGUNDO TESTE: algoritmos de busca:\n\n Informe um numero ate %d que deseja buscar.\n", TAM2);

	v = realloc(v, TAM2 * sizeof(int));
	cria_vetor_decresente(v, TAM2);
	scanf("%d", &valor);
	indice = buscaSequencial(v, TAM2, valor, &numComparacoes);
	printf("O indice do elemento no vetor eh %d, o algoritmo de busca sequencial levou %d comparacoes.\n", indice, numComparacoes);

	numComparacoes = 0;
	indice = buscaBinaria(v, TAM2, valor, &numComparacoes);
	printf("O indice do elemento no vetor eh %d, o algoritmo de busca binaria levou %d comparacoes.\n\n", indice, numComparacoes);



	printf("	TERCEIRO TESTE: algoritmos de ordenacao:\n");
	printf("ANTES:\n");
	imprime_vetor(v, TAM2);

	printf("insertion sort:\n");
	insertionSort(v, TAM2);
	imprime_vetor(v, TAM2);

	cria_vetor_decresente(v, TAM2);
	printf("selection sort:\n");
	selectionSort(v, TAM2);
	imprime_vetor(v, TAM2);

	cria_vetor_decresente(v, TAM2);
	printf("merge sort:\n");
	mergeSort(v, TAM2);
	imprime_vetor(v, TAM2);

	cria_vetor_decresente(v, TAM2);
	printf("quick sort:\n");
	quickSort(v, TAM2);
	imprime_vetor(v, TAM2);

	cria_vetor_decresente(v, TAM2);
	printf("heap sort:\n");
	heapSort(v, TAM2);
	imprime_vetor(v, TAM2);

	free(v);
	return 0;
}