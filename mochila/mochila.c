#include <stdio.h>
#include <stdlib.h>

struct presentes{
	int id, peso, sentimental;
};

int peso(struct presentes* aux[], int n){
	int peso = 0;
	for (int i = 0; i < n; i++){
		if (aux[i] != NULL)
			peso += aux[i]->peso;
	}

	return peso;
}

int sentimental(struct presentes* aux[], int n){
	int valor_sentimental = 0;
	for (int i = 0; i < n; i++){
		if (aux[i] != NULL)
			valor_sentimental += aux[i]->sentimental;
	}

	return valor_sentimental;
}

void subconjuntos(struct presentes* saco[], struct presentes* aux[], struct presentes* itens[], int i, int n, int p_max, int* maior_sentimental){

	if (i == n){
		int valor_sentimental = sentimental(aux, n);

		if ((peso(aux, n) <= p_max) && (valor_sentimental > (*maior_sentimental))){
			*maior_sentimental = valor_sentimental;

			int k = 0;
			for (int j = 0; j < n; j++){ //copia para o vetor saco
				if (aux[j] == NULL)
					k++;
				else {
					saco[k] = aux[j];
					k++;
				}
			}
		}

	}

	aux[i] = NULL;
	subconjuntos(saco, aux, itens, i + 1, n, p_max, maior_sentimental);

	aux[i] = itens[i];
	subconjuntos(saco, aux, itens, i + 1, n, p_max, maior_sentimental);
}

int main(){
	int n, p_max, maior_sentimental = 0;
	struct presentes **itens, **aux, **saco;

	scanf("%d\n %d", &n, &p_max);
	saco = malloc(sizeof(int) * n);
	itens = malloc(sizeof(int) * n);
	aux = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++){	//le o vetor
		scanf("%d %d\n", &itens[i]->sentimental, &itens[i]->peso);
		itens[i]->id = i;
	}

	subconjuntos(saco, aux, itens, 0, n, p_max, &maior_sentimental);

	for (int i = 0; i < n; i++){	//imprime indice
		printf("%d ", saco[i]->id);
	}

	printf("\n");
	printf("%d\n", maior_sentimental);

	free(itens);
	free(saco);
	free(aux);

	return 0;
}