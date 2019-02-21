/*
** 			CSE 102
**		HOMEWORK ASSIGNMENT 7
**		  MIRAY YILDIZ
**		   161044023
**
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define SIZE 11
#define SIZE1 20

typedef struct  /*create gate structure*/
{
	int former_out;
	int inp1;
	int inp2;
	char inpp1[SIZE];
	char inpp2[SIZE];
	int out;
	char outt[SIZE];
} gate;

char** create_char_array(FILE *circ, char **arr, int count){ /* read circuit.txt in 2D string */ 
	circ = fopen("circuit.txt", "r");
	int i, j; 
	char word1;
	arr = malloc(SIZE*SIZE1*sizeof(char*));
	for(i = 0; i<SIZE*SIZE1; i++){
		arr[i] = malloc(count*sizeof(char));
	}
	i=0;
	circ = fopen("circuit.txt", "r");
	while(fscanf(circ, "%c", &word1)!=EOF){ 
		if(word1 == '\n'){
			i++;
			j = 0;
		}
		else{
			arr[i][j] = word1;
			j++;

		}
	}
	
	fclose(circ);
	return arr;
}

int ** create_int_array(FILE *input, int **arr2, int count1){ /*read input.txt in 2D array */
	input = fopen("input.txt", "r");
	int i, j = 0; 
	int number;
	char space;
	arr2 = malloc(SIZE*SIZE1*sizeof(int*));
	for(i = 0; i<SIZE*SIZE1; i++){
		arr2[i] = malloc(count1*sizeof(int));
	}
	i=0;
	input = fopen("input.txt", "r");
	while(fscanf(input, "%d%c", &number, &space)!=EOF){ 
		if(space == '\n'){ 
			arr2[i][j] = number;
			//printf("%d", arr2[i][j] );
			//printf("\n");
			i++;
			j = 0;
		}
		else{
			arr2[i][j] = number;
			//printf("%d", arr2[i][j] );
			j++;

		}
	}
	
	fclose(input);
	return arr2;
}


int main(){
	FILE *circ;
	FILE *input;
	FILE *outputt;
	gate *gate1; 
	char word, word2;
	int i = 0, j = 0, count = 0, count1 = 0, m = 0;
	circ = fopen("circuit.txt", "r");
	input = fopen("input.txt", "r");
	outputt = fopen("output.txt", "w");
	char **arr;
	int **arr2, **arrr;

	while(fscanf(circ, "%c", &word)!=EOF){ /* how many lines have circuit.txt*/
		if(word == '\n'){
			count++;
		}
	}

	fclose(circ);
	while(fscanf(input, "%c", &word2) != EOF){ /* how many lines have input.txt*/

		if(word2 == '\n')
			count1++;
		
	}
	
	char **str1 = malloc(SIZE*SIZE1*sizeof(char*)); /* using malloc */
	for(i = 0; i<SIZE*SIZE1; i++){
		str1[i] = malloc(count*sizeof(char));
	}

	str1 = create_char_array(circ,arr,count); /* called function */
	circ = fopen("circuit.txt","r");
	j = 0;
	int count3 = 0;
	char word3;
	char *str6 = malloc(sizeof(char)*SIZE); /* using malloc */
	gate1 = malloc(count*sizeof(gate));

	for(i = 0; i<=count; i++){  /*how many gate*/
		sscanf(str1[i], "%s", str6);
		int res = strcmp(str6,"INPUT");
		if(res == 0){ 
			while(fscanf(circ, "%c", &word3) != '\n'){
				if(word3 == ' '){
				sscanf(str1[i], "%s", str6); 
				j++;
					count3++;
				}
				if(word3 == '\n'){
					break;
				}
			}
		}
	}

	circ = fopen("circuit.txt", "r");
	i = 0;
	j = 0;
	int k = 0;

	for(i = 0; i<=count; i++){ /* I read ınputs and put structure */
		fscanf(circ, "%s", str6);
		if(strcmp(str6 ,"INPUT") == 0 ){ 
			while( k <= count3-1 ){ 
			fscanf(circ,"%s",str6);
			//printf("%s\n",str6);
			strcpy(gate1[k].outt,str6);
		
			k++;

			}
			break;
		}
	}	
	fclose(circ);
	arrr = malloc(SIZE*SIZE1*sizeof(int*)); /*using malloc*/
	for(i = 0; i<SIZE*SIZE1; i++){
		arrr[i] = malloc(count1*sizeof(int));
	}
	
	arrr = create_int_array(input,arr2,count1); /* called function */
	gate1[0].former_out = 0;
	int x = 0 ,a = 0;
	int n, d;


	while(x <= count1-1){
	n = 0;
		while(n<=count3-1){ /* put numbers in structure */
			gate1[n].out = arrr[x][n];
			n++;
		}
		d = 0;
		
		char gatee[SIZE], result[SIZE], inpp11[SIZE], inpp22[SIZE];
		while(m+1 <= count){ 
			sscanf(str1[m+1], "%s %s %s %s", gatee, result, inpp11, inpp22);
			strcpy(gate1[m].inpp1,inpp11); /*put inputs in structure*/
			strcpy(gate1[m].inpp2 ,inpp22);
			
			while(d <= n){ 
				if(strcmp(gate1[m].inpp1, gate1[d].outt) == 0){ 
					gate1[m].inp1 = gate1[d].out;
					
				}
				if(strcmp(gate1[m].inpp2, gate1[d].outt) == 0){
					gate1[m].inp2 = gate1[d].out;
					
				}
			d++;		
			}

			if(strcmp(gatee,"AND") == 0){ /* if gate is AND */
				strcpy(gate1[n].outt,result);
				if(gate1[m].inp1 == 1 && gate1[m].inp2 == 1){
					gate1[n].out = 1;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 1 && gate1[m].inp2 == 0){
					gate1[n].out = 0;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
				if(gate1[m].inp1 == 0 && gate1[m].inp2 == 1){
					gate1[n].out = 0;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
				if(gate1[m].inp1 == 0 && gate1[m].inp2 == 0){
					gate1[n].out = 0;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
			}
			if(strcmp(gatee,"OR") == 0){ /* if gate is OR */
				strcpy(gate1[n].outt,result);
				if(gate1[m].inp1 == 1 && gate1[m].inp2 == 1){
					gate1[n].out = 1;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 1 && gate1[m].inp2 == 0){
					gate1[n].out = 1;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
				if(gate1[m].inp1 == 0 && gate1[m].inp2 == 1){
					gate1[n].out = 1;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
				if(gate1[m].inp1 == 0 && gate1[m].inp2 == 0){
					gate1[n].out = 0;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
			}
			if(strcmp(gatee,"NOT") == 0){ /* if gate is NOT */
				strcpy(gate1[n].outt,result);
				if(gate1[m].inp1 == 1 ){
					gate1[n].out = 0;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 0){
					gate1[n].out = 1;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}
				
			}
			if(strcmp(gatee,"FLIPFLOP") == 0){ /* if gate is FLIPFLOP */
				strcpy(gate1[n].outt,result);
				if(gate1[m].inp1 == 1 && gate1[m].former_out == 1){
					gate1[n].out = 0;
					gate1[m].former_out = gate1[n].out;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 1 && gate1[m].former_out == 0){
					gate1[n].out = 1;
					gate1[m].former_out = gate1[n].out;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 0 && gate1[m].former_out == 1){
					gate1[n].out = 1;
					gate1[m].former_out = gate1[n].out;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
				if(gate1[m].inp1 == 0 && gate1[m].former_out == 0){
					gate1[n].out = 0;
					gate1[m].former_out = gate1[n].out;
					strcpy(gate1[n].outt,result);
					n++;
					//m++;
				}	
			
			}
			
			m++;

		}

		//printf("%d\n", gate1[n].out );
		fprintf(outputt, "%d\n", gate1[n].out ); /* writing file*/
		x++;
	}
	for(i = 0; i<SIZE*SIZE1; i++)
		free(str1[i]);
	free(str1);
	free(str6);
	for(i = 0; i<SIZE*SIZE1; i++)
		free(arrr[i]);
	free(arrr);
	
}
