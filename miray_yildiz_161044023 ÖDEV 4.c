/*       CSE 102 HW4
**		MIRAY YILDIZ
**		 161044023
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_NUMBER 100
#define POLY_NUM 1000

int main()
{
	FILE *values;
	FILE *polynomial;

	values = fopen("values.txt",  "r");
	polynomial = fopen("polynomial.txt", "r");

	double numbers[MAX_NUMBER];
	char poly[POLY_NUM], polynom[POLY_NUM][POLY_NUM];
	int m, n, i = 0, s, x = 0, y = 0, j = 0;
	double pow_num, power, coefficient, sum;
	char chrctr, ch, operator, chrctr2;

	while(fscanf(values, "%lf", &numbers[i]) != EOF){ /*values reads from file*/
		//printf("%lf = %d. eleman \n", numbers[i], i);
		i++;
	}
	while(fscanf(polynomial, "%c", &ch) != EOF){ /* polynomial reads from file*/
		if(chrctr != ' '){
			poly[j] = ch;
			//printf("%c = %d. eleman\n", poly[j], j );
			j++;
		}

	}
	poly[j] = '\0';
	
	for(s = 0; s < j; s++){ /*Creating a two dimensional array. Assigns polynomials to this array.*/ 
		if(poly[s] == '+' || poly[s] == '-'){
			x++;
			y = 0;
			//printf("\n");
		}
		polynom[x][y] = poly[s];
		//printf("%c", polynom[x][y]);
		y++;
	}
	polynom[x][y] = '\0';
	fclose(values); /*closing files*/
	fclose(polynomial);

	FILE *output;
	output = fopen("evaluations.txt", "w"); /*opening evaluations file*/

	int start; /* if polnomials starting "-", start is 1. else, start is 0.*/
	if(poly[0] == '-')
		start = 1;
	else
		start = 0;
	//printf("%d\n", start );
	/* nested loops for evaluations*/
	for(m = 0; m < i; m++){ /* if evaluations first number, pass other numbers*/ 
			for(n = start; n <=x; n++){ /* increasing second dimension in polynom[][] */
				if(polynom[n][0] != '+' && polynom[n][0] != '-' && polynom[n][0] != 'x' && polynom[n][0] != '^'){ /* if x is coefficient*/ 
					sscanf(polynom[n], "%lf%c%c%lf", &coefficient, &chrctr, &chrctr, &pow_num);
					sscanf(polynom[n], "%c%c%lf", &chrctr, &chrctr, &pow_num);
					if(pow_num == 0.0) /* if pow_num is zero, new pow_num value is 1*/ 
						pow_num = 1.0;
					if(coefficient == 0.0) /* if coefficient is zero, new coefficient is 1*/
						coefficient = 1.0;
					power = pow(numbers[m], pow_num);
					sum = sum + (power * coefficient);
					pow_num = 0.0; /* pow_num always be zero at the and*/
				}
				if((polynom[n][0] == '+' || polynom[n][0] == '-') && polynom[n][1] == 'x'){ 
					sscanf(polynom[n], "%c%c%c%lf", &operator, &chrctr, &chrctr, &pow_num);
					if(pow_num == 0.0) /* if pow_num is zero, new pow_num value is 1*/ 
						pow_num = 1.0;
					power = pow(numbers[m], pow_num);
					if(operator == '+')
						sum = sum + power;
					if(operator == '-')
						sum = sum - power;
					pow_num = 0.0; /* pow_num always be zero at the and*/
				}
				if((polynom[n][0] == '+' || polynom[n][0] == '-') && polynom[n][1] != 'x'){
					sscanf(polynom[n], "%c%lf%c%c%lf", &operator, &coefficient, &chrctr, &chrctr, &pow_num);
					if(pow_num == 0.0)
						pow_num = 1.0;
					power = pow(numbers[m], pow_num);
					if(operator == '+')
						sum = sum + (power * coefficient);
					if(operator == '-')
						sum = sum - (power * coefficient);
					pow_num = 0.0; /* pow_num always be zero at the and*/
				}			
			}	
			//printf("sum : %.2lf\n", sum);
			fprintf(output, "%.2f\n",sum);
			sum = 0.0;	
		}
	fclose(output);	
	return 0;

	}