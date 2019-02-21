#include<stdio.h>
#include <string.h>

#define MAX_COLUMN 250
#define MAX_ROW 100
#define WORDS_NUM 100000000
#define LENGTH 10

int num[WORDS_NUM];
int size[WORDS_NUM];
char words[LENGTH][WORDS_NUM];
char text[MAX_ROW][MAX_COLUMN];

int main() {
    char f, l;
    int counter, x = 0, y = 0, x1 = 0, y1 = 0, k = 0, maxx = 0, maxy = 0, maxx1 = 0, maxy1 = 0 ;
    
    FILE *input1; /* I identified the files. */
    FILE *input2;
   
    input1 = fopen("input1.txt", "r"); /* I opened file */ 
     
    while((f = fgetc(input1)) != EOF){ /* I took the letters in order. */
        if(f == '\n' || f == ' '){
            x++; /* If it moves to the bottom line, increase x. */
            num[k] = y; /* I kept the size of the words in the array*/
            k++; /* Increasing k. */
            if( y > maxy){  
                maxy = y;
            }
            y = 0;
        }       
        else {
            words[x][y] = f; /* Send letter to array. */
			words[x+1][y] = '\0'; 
            y++;
        }

    }
    maxx = x+1; 
    input2 = fopen("input2.txt", "r"); /* I opened file */
   
    while(( l = fgetc(input2)) != EOF){ /* I took the letters in order. */
        if(l == '\n'){
            x1++; /* If it moves to the bottom line, increase x1. */
            if( y1 > maxy1){
                maxy1 = y1;
                
            }
            y1 = 0;
           
        }
        else {
            text[x1][y1] = l; /* Send letter to array. */
			text[x1+1][y] = '\0';
            y1++;
        }
    }
    
    maxx1 = x1+1;  
                                                                                                                             
    fclose(input1); /* I closed files. */
    fclose(input2);
    
    FILE *out; /*  I identified output file . */
    out = fopen("output.txt", "wt"); /* Opened file */
    
    int i, j, m, t = 0;
    char temp, temp1;
    for(m = 0; m<maxx; m++){ /* Loops for finding words. */
        for(i = 0; i <= MAX_ROW; i++){ 
            for(j = 0; j <= MAX_COLUMN; j++){ 
                if(text[i][j] == words[m][0]){ 
                    while(t<=num[m]){ /* printing file condition. */
                        temp = words[m][0+t] ;
                            if(temp == text[i+t][j]){ 
                                t++;
                            }
                            else{ 
                                t = 0;
                                break;
                            }
                            if(t == num[m]){
                                for(int c = 0; c<=num[m]-1; c++){ /* I printed the words to the file */
                                    //printf("%c", words[m][c]);
                                    fprintf(out, "%c", words[m][c]);
                                }
                                //printf(" (%d,%d) Vertical \n", i+1,j+1); 
                                fprintf(out, " (%d,%d) Vertical \n", i+1, j+1); /* I printed coordinates to the file */
                              
                                t = 0; 
                                break;
                            }
                     }
                     while(t<=num[m]){ /* printing file condition */
                        temp1 = words[m][0+t];
                            if(text[i][j+t] ==temp1){ 
                                t++;
                            }
                            else{ 
                                t = 0;
                                break;
                            }
                            if(t == num[m]){
                                for(int c = 0; c<=num[m]-1; c++){ /* I printed the words to the file */
                                    //printf("%c", words[m][c]);
                                    fprintf(out, "%c", words[m][c]);
                                }
                                //printf(" (%d,%d) Horizontal \n", i+1, j+1);
                                fprintf(out, " (%d,%d) Horizontal \n", i+1, j+1); /* I printed coordinates to the file */
                                t = 0; 
                                break;
                            }
                     }
                }
            }                     
        }
    }                  
    
fclose(out); /* Closed the file */
return 0;
}
