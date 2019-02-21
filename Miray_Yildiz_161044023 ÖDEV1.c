/*
*     CSE 102 FALL 2018
*       ASSIGNMENT 1
*       MIRAY YILDIZ
*        161044023
*/

#include<stdio.h>
#define class1 10
#define class2 10 

int main(){
int i, j;
double numx1, numy1, sumx1, sumy1, averagex1, averagey1; /* I have defined the x and y values and x y averages ​​for class1 */
double numx2, numy2, sumx2, sumy2, averagex2, averagey2; /* I have defined the x and y values and x y averages ​​for class2 */
double numx_user, numy_user; /* I have defined points that taken from user */
double averagey, averagex; /* I have defined midpoint of (averagex1, averagey1) and (averagex2, averagey2) */ 

        for(i = 1; i <= class1; i++){ /* Get class1 points from user */
                scanf("%lf %lf", &numx1, &numy1);
                sumx1 = numx1 + sumx1; /* All x values ​​added for class1 */
                sumy1 = numy1 + sumy1; /* All y values ​​added for class1 */
        } 
         
        averagex1 = sumx1 / class1; /* The average of x values ​​for class1 was found */
        averagey1 = sumy1 / class1; /* The average of y values ​​for class2 was found*/
      
        for(j = 1; j <= class2; j++){ /* Get class2 points from user */
               scanf("%lf %lf", &numx2, &numy2);
               sumx2 = numx2 + sumx2; /* All x values ​​added for class2 */
               sumy2 = numy2 + sumy2; /* All y values ​​added for class2 */              
        } 
        
        averagex2 = sumx2 / class2; /* The average of x values ​​for class2 was found*/
        averagey2 = sumy2 / class2;  /* The average of y values ​​for class2 was found */
      
        /* The equation of the line => y - averagey1 = ((averagey1 - averagey2) / (averagex1 - averagex2)) * (x - averagex1) */
        
        averagex = (averagex1 + averagex2) / 2; /* I found the midpoint of mid-points of class1 and class2 for x */
        averagey = (averagey1 + averagey2) / 2; /* I found the midpoint of mid-points of class1 and class2 for y */
        
        if( averagex == 0 ) 
                averagex = 0.000000000000000000000001;
        if( averagey == 0 ) 
                averagey = 0.000000000000000000000001;      
        /* 
        *  The product of the slopes of two lines perpendicular to each other is -1.
        *  Perpendicular line slope: (-(averagex1 - averagex2) / (averagey1 - averagey2))
        */
             
        while(scanf("%lf %lf", &numx_user, &numy_user)){ /* If user enter character, the loop is end */

                if(averagex1 > averagex2){ /* I used if because I dont know which class have bigger x */
                /*  Perpendicular line equation:(numy_user - averagey) = (-(averagex1 - averagex2) / (averagey1 - averagey2) * (numx_user - averagex) */
                        if((-(averagex1 - averagex2) / (averagey1 - averagey2) * (numx_user - averagex) + averagey - numy_user) < 0){ 
                                        printf("Class1\n"); /* If y is not greater than others, solution is class1 */
                        }
                        else{ 
                                        printf("Class2\n"); /* If y is greater than others, solution is class2 */
                        }
                }        
                if(averagex1 < averagex2){ /* I used if because I dont know which class have bigger x */
                        if((-(averagex1 - averagex2) / (averagey1 - averagey2) * (numx_user - averagex) + averagey - numy_user) > 0){
                                        printf("Class1\n"); /* If y is greater than others, solution is class1 */
                        }
                        else{    
                                        printf("Class2\n"); /* If y is not greater than others, solution is class2 */
                        }
                }                                                                   
         }                  

return 0;

}
