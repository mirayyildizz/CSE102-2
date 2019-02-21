/*        CSE 102
**       ASSIGNMENT 2
**      MIRAY YILDIZ
**       161044023
*/       

#include<stdio.h>
#define p1 0.5
#define p2 20
#define MAX_SIZE 1000
#define MAX_CHUNK 100

void minimum_average(double average[], int size[], int k){ /* The function that find minimum average and saves the array its sequence. */
int l, m, q = 0, count = 0;
for(l=0; l<=k; l++){
        m = 0;
        while(m <= k){
                if(average[l] > average[m]){
                        count ++; 
                        m++;
                }
                else{
                        m++;
                }
        }
        size[q] = count; /* Count saved size[] array. */
        q++;
        count = 0; /* Count reset. */
}
}

void print_file(int num_ar[], double chunk[][MAX_CHUNK], int y, int size[]){ /* Function that prints chunk to input file according to averages. */
FILE *output; /* Defined the file */
output = fopen("output.txt", "w"); /* Opening file. */
int p = 0, d = 0, c;

while(p<=y){ /* The requirement to print from small to large. */
        c = 0;
        while(c<=y){ 
                if(size[c] == p){  /* The requirement to print from small to large. */
                        d = 0;
                        while(d<num_ar[c]){ /* num_arc is an array that contains how many numbers chunk contains. */
                        //printf("%5.4lf ", chunk[d][c]);
                        fprintf(output, "%5.4lf ", chunk[d][c]); /* Printing file. */
                        d++;
                        }
                        //printf("\n");
                        fputs("\n", output);
                        }
                c++;      
        }
        p++;  
}

fclose(output);
} 
int main(){

double chunk[MAX_SIZE][MAX_CHUNK], average[MAX_CHUNK];
double a_sum, b_sum;
double a, b, n;
int size[MAX_CHUNK];
int x = 0, y = 0, k=0;
FILE *input;
input = fopen("input.txt", "r"); /* Open the file */
int num, g = 0;
int num_ar[MAX_CHUNK];

fscanf(input, "%lf", &n); /* Reading first input to input file. */
a_sum = n;
b_sum = 0;
a = n;
chunk[x][y] = n; 
num ++;

        while(fscanf(input, "%lf", &n) != EOF){ /* keep counting from the file unless it reaches the end of the file. */
                b_sum = a_sum + n;
                b = (b_sum) / (x+2) ;
                if(!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2)){ /* If provide the condition, get the same chunk. */
                        x++;
                        chunk[x][y] = n;
                        a_sum = b_sum;
                        a = b_sum / (x+1) ;
                        num++;
                }
                else{ /* If it does not provide the condition, get the another chunk */
                        num_ar[g] = num;
                        g++;
                        num = 1;             
                        y++;
                        x = 0;                 
                        chunk[x][y] = n;
                        average[k] = a; /* Save average. */  
                        k++;
                        a_sum = n;
                        a = n;
                        b_sum = 0;
               }
        }
        average[k] = a; /* Save last average. */ 
        num_ar[g] = num;
        
fclose(input); /* Close file. */

minimum_average(average, size,k); /* Call a minimum_average function. */              
print_file(num_ar,chunk,y,size); /* Call a print_file function. */
              
return 0;
}
