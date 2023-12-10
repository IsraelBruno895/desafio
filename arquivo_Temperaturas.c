# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

int main(){
	
	FILE *arq;
	FILE *novoArq;
   
	char temperaturas[] = "temperaturas.txt";
	int tamanho;
	int i=0,j;
	float tempMinima=0.0,tempMaxima=0.0,tempMedia=0.0,soma=0.0;
	double somaQuadrado=0.0,desvioPadrao=0.0,cont=0;
	
	arq = fopen("temperaturas.txt","r");
	
	fscanf(arq, "%d",&tamanho);
	
	float vetor[tamanho];
	if(arq == NULL){
		printf("erro");
		exit(1);
	}else{
		while(i < tamanho && fscanf(arq,"%f",&vetor[i]) == 1){
	   	i++;
		   	
		}
		fclose(arq);	
	}
   
   novoArq = fopen("novoSaida.txt","w");
   
   if(novoArq == NULL){
   	printf("ERRO\n");
   	exit(1);
   }
   
   tempMinima = vetor[0];
   for(j=0;j<tamanho;j++){
   	if(vetor[j] < tempMinima){
   		tempMinima = vetor[j];
	   }
   }
   
   
    tempMaxima = vetor[0];
   	for(j=0;j<tamanho;j++){
   		if(vetor[j] > tempMaxima){
   			tempMaxima = vetor[j];
		   }
	   }
	   
	   for(j=0;j<tamanho;j++){
	   	soma = soma + vetor[j];
	   	cont++;
	   }
	   
	   tempMedia = soma / cont;
	   
	   for(j=0;j<tamanho;j++){
	   	somaQuadrado += pow(vetor[j] - tempMedia,2);
	   }
	   
	   desvioPadrao = sqrt(somaQuadrado / tamanho);
   	
   	fprintf(novoArq,"Temperatura minima: %0.3f\n",tempMinima);
    fprintf(novoArq,"Temperatura maxima: %0.3f\n",tempMaxima);
   	fprintf(novoArq,"Temperatura media: %0.3f\n",tempMedia);
   	fprintf(novoArq,"Desvio padrao: %0.3lf\n\n",desvioPadrao);
   	
   	printf("resultado escrito no arquivo novoSaida.txt\n");

	fclose(novoArq);
	return 0;
}
