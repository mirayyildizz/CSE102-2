/*
**     CSE 102 Homework Assignment 5
**			MIRAY YILDIZ
**           161044023
*/
#include <stdio.h>
#define MAX_LENGTH 251 /* Define string's maximum lengths*/ 

int recursion(char string2[], int count, int count2, FILE *output, int i, int j, int k, int max, char t, char b){ /*Recurison function.*/ 

	if(i >= max){ /* If i equal to strings last element, quit function. */
		return 1;
	}

	if(string2[i] == '('){ /* If element equal to '(', increase count and i */
		count ++;
		i++;
		return recursion(string2, count, count2, output, i,j,k, max,t,b); 
	}
	if(string2[i] == ' '){ /* If element equal to space, increase count2 and i */
		count2++;
		i++;
		return recursion(string2, count, count2, output, i,j,k, max,t,b);
	}
	if(string2[i] == ','){ /* If element equal to ',', increase i */
		i++;
		return recursion(string2, count, count2, output, i,j,k, max,t,b);	
	}
	if(string2[i] == ')'){ /* If element equl to ')', decrease count and increase  */ 
		count--;
		i++;
		return recursion(string2, count, count2, output, i,j,k, max,t,b);
	}
	if(string2[i] != ',' && string2[i] != ')' && string2[i] != ' ' && string2[i] != '('){ /* If element equal to another chars; */
		if(count != 0){
			for(j = 0; j < count; j++){  /* If count is different from zero, write a file '-' up to the count */ 
				//printf("-");
				fprintf(output, "%c", t );
			}
		}
		if(count2 != 0){
			for (k = 0; k < count2; k++){ /* If count2 is different from zero, write a file ' ' up to the count2 */
				//printf(" ");
				fprintf(output, "%c",b);
			}
		}
		while(string2[i] != ',' && string2[i] != '(' && string2[i] != ')'){
			if(i < max){
				//printf("%c", string2[i]);
				fprintf(output, "%c", string2[i] ); /* Write a file another chars */ 
				i++;
			}
			if(i>= max){
				break;
			}
			
		}
		//printf("\n");
		fprintf(output,"\n"); /* Go to bottom line */
		count2 = 0; /* Reset values */
		j = 0;
		k = 0;
		return recursion(string2, count, count2, output, i,j,k, max,t,b);
	}
}

int main(){
	char string[MAX_LENGTH], t = '-', b = ' ', string1[MAX_LENGTH], string2[MAX_LENGTH]; 
	int count = 0, count2 = 0, i = 0, j = 0, k = 0, max = 0, s = 0, d = 0, countx = 0, m = 0, n = 0;
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");  /* Opening files. */
	output = fopen("output.txt", "w");

	while(fscanf(input, "%c", &string[i]) != EOF){ /* Put the input file to into the string */
		//printf("%d. eleman = %c\n", i,string[i] );
		i++;
	}
	string[i] = '\0'; /* Last element */
	
	while(string[s] == ' '){ /* If the string start with a space or spaces, I delete space or spaces */
		s++;
	}	

	while(string[s] != '\0'){
		string1[d] = string[s];
		//printf("%d. eleman = %c\n", d,string1[d]);
		s++;
		d++;
	}
	string1[d] = '\0';
	int temp = d;
 
	while(string1[d-1] = ' '){ /* If string finish with a space or spaces, I delete space or spaces */ 
		countx++;
		d--;
		if( string1[d-1] != ' '){
			break;
		}
	}
	
	if(countx != 0){
		while( m <= (temp-1-countx)){
			string2[m] = string1[n];
			//printf("%d. eleman = %c\n", m,string2[m]);
			n++;
			m++;
		}
	max = m;
	}

	m = 0;
	n = 0;

	if(count == 0){
		while(string1[n] != '\0'){
			string2[m] = string1[n];
			m++;
			n++;
		}
	max = m;
	}

	string2[m] = '\0'; /* Last element */
	max = m;
	i = 0;
	recursion(string2, count, count2, output, i,j,k, max,t,b); /* Call function */
}
