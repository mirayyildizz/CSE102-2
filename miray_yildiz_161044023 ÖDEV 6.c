#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 101

int countspaces(const char *str, int len);
int is_this_cost(char *str);
char* delete_space(char str[SIZE]);
double cost(char *str1, char *str,  char str5[SIZE], double *cost1, int number, char*temp, char *temp2);

int main()
{
 	char *str, *str1, str5[SIZE], space, *temp, *temp2;
 	double *cost1=0, sum = 0, i = 0, l = 0,total;
 	int number, f = 0, m = 0, n = 0;
 	printf("Name the object?:\n"); /* Asking object*/
 	str1 = malloc(SIZE * sizeof(char));
 	fgets(str1, SIZE, stdin);
 	int length1 = strlen(str1);
 	str1[length1-1] = '\0';
	temp2 = malloc(SIZE*sizeof(char));
 	strcpy(temp2,str1);
	printf("Define %s?:\n", str1); /* Asking pieces*/
	total= cost(str1, str, str5, cost1, number, temp, temp2); 
	printf("total : %lf\n",total);
}

double cost(char *str1, char *str,  char str5[SIZE], double *cost1, int number, char*temp, char *temp2) /*recursive function*/
{
 	double sum = 0;
 	int flag = 0, x = 0,c;
 	char space; 
	int count = 0;
	str = malloc(SIZE * sizeof(char));
 	fgets(str, SIZE, stdin);
 	int lngth = strlen(str);
 	str[lngth-1] = '\0';
 	strcpy(str, delete_space(str));
 	int x1 = is_this_cost(str);
 
 	if(x1 == 0)
 	{
  		return atof(str);
 	}
 
 	if(x1 == 1) /* If input is not price, ask again another pieces */
 	{
  	while(count<10){ /* I GOT THE ERROR BECAUSE I DONT KNOW CONDİTİON İN THERE, I TRIED HARD BUT DOES NOT FIX */
   	temp = malloc(strlen(str) * sizeof(char));
   	strcpy(temp, str);
   	sscanf(temp, "%d%c%s%c", &number, &space, str5, &space);
  	printf("Define %s in %s?:\n", str5, temp2);
   	strcpy(temp2,str5);
   	strcpy(str5,str1);
	count ++;
   	sum = sum + cost(str1, temp, str5, cost1,number,temp,temp2);
	}
  	}
 return sum;
}

int countspaces(const char *str, int len) /* If I see space, it is not price. If I do not see space, it is another piece. */
{
 	int i, count = 0;
 	for( i = 0; i < len; i++ )
 	{
  		if( str[i] == ' ' )
  			count++;
 		}
 
 	return count;
}

int is_this_cost(char *str) /* Control string it is price or another things*/
{ 
	int temp3;
	int temp2;
 	double temp1;

 	if( countspaces(str, strlen(str)) > 0 ){ /* If string has space, it is not price.*/
  		return 1;
 }
 
 else /* Else, return 0. */
 {
  if( sscanf(str, "%lf", &temp1) == 1 ){
	   return 0;
  }
 
  else if( sscanf(str, "%d", &temp2) == 1 ){
   return 0;
  }
 }

 return 1;
}


char* delete_space(char str[SIZE]) /*deleting space*/
{
 	int i = 0, j = 0, last;
 	for(i = 0; str[i]!='\0'; i++)
 	{
  		if(str[i]!=' ')
  		{
   			str[j] = str[i];
   			last = i;
   			j++;
  		}
  		else
  		{
   			if(i == last+1)
   			{
    			str[j] = str[i];
    //printf("%c\n",str[j] );
    			j++;
  			}
  		}
 	}

 str[j] = '\0';
 return str;
}
