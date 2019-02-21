/*
** 				CSE 102
**			      HW8
**           MIRAY YILDIZ
**  		   161044023
*/



#include <stdio.h>
#include <stdlib.h>
#define SIZE1 512
#define SIZE2 512
/* My code works in all sizes. But when;
for instance L = 3 and my terrain is
111111111111161111111111
111111111111141111111111
111111114444441111111111
111151114111111111111111
111141114111111111111111
111144444111111111111111 
it is one island but my code evaluate two islands. Just this example similar to cases code is 
calculating one extra. Everything else is right. I tried so hard but I couldn't solve the problem.
11111111111666661111111
11111111111611161111111
11111111111611161111111
1111111111166666111111
1111111111111111111111
1111111111111111111111
for instance it works, it is one island.
*/


int main(){ 
	int m[SIZE1][SIZE2], l, g, i, j, count = 0;
	int k = 0, z = 0;
	FILE *input, *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	fscanf(input, "%3d", &l); /*Reading water level*/
	//printf("%d\n", l);

	for(i = 0; i<SIZE1; i++){ /*Reading input file and throw array.*/
		for(j = 0; j<SIZE2; j++){
			fscanf(input, "%3d", &g);
			if(g <= l ){
				m[i][j] = 0;
				//printf("%d ", m[i][j]);
			}
			if(g > l ){
				m[i][j] = 1;
				//printf("%d ", m[i][j]);
			}

		}
	//printf("\n");

	}

	i = 0;
	j = 0; 
	int d = 0;;
	int q = 0, p = 0, f = 0, x = 0, c = 0;
	g = 0;
	while(i < SIZE1){ /*Condition for array */ 
			while( j < SIZE2){
				if(i == 0 && j == 0 && m[i][j] == 1 ){ /* If first element is hihgher than water*/
					m[i][j] = m[i][j] * 8; /*Multiply with 8 to find it later*/
					count ++; /* Increase count*/
				}

				if( i == 0 && j != 0 && m[i][j] == 1 && m[i][j-1] < 1 ){  /*if there is a place higher than water in the first line*/
					if(m[i+1][j] > 0 && m[i][j-1]==0 ){ 
						if(m[i+1][j-1] > 0){
							z = j-1;
							if(z == 0){
									m[i][j] = m[i][j] * 8;
									count ++;
							}
							while( z >= 0){ 
								if(m[i+1][z-1]>0){ 
									if(m[i][z-1]==0){
										if(z == 0){
											break;
									}
									z--;
									}
									if(m[i][z-1]>0){
										break;
									}
								}
								else{
									m[i][j] = m[i][j] * 8;
									count ++;
									break;
								}
								if(z==0){
									break;
								}

							}
						}

						else{
									m[i][j] = m[i][j] * 8;
									count ++;
									
						}

						
					}
				}
	
				if( i != 0 && j == 0 && m[i][j] == 1 && m[i-1][j]==0 && i< SIZE1){ /* if there is a place higher than water in the another line */
					if(j == SIZE2-1){ /* If j == SIZE-1 its definitely island.*/
						m[i][j] = m[i][j] * 8; /* Multiply 8*/
						count ++; /* İncrease count*/
					} 
					k = j + 1;
					if(j != SIZE2-1){ /* But it is not equal to SIZE-1 check other elements*/
						while(k<SIZE2){ 
							if(m[i][k] > 0){
		 						if(m[i-1][k] > 0){ 
								break;
								}

								if(m[i-1][k]<1){
									if( k == SIZE2-1){
										m[i][j] = m[i][j] * 8;
										count ++;
										break;
									}
									else{
									k++;
									}
								}
							}
							else{ 
								m[i][j] = m[i][j] * 8;
								count ++;
								break;
							}
						}
					}
					
				}
				if( i != 0 && j != 0 && m[i][j]==1 && m[i][j-1]==0  && m[i-1][j]==0  && i< SIZE1){ /* if there is a place higher than water in the another line */
					if(j == SIZE2-1){ /* If j == SIZE-1 its definitely island.*/
						m[i][j] = m[i][j] * 8;
						count ++;
					} 
					d = j + 1;
					if( j!= SIZE2-1){ /* But it is not equal to SIZE-1 check other elements*/
						while(d<SIZE2){ 
							if(m[i][d] > 0){
		 						if(m[i-1][d] > 0){ 
								break;

								}

								if(m[i-1][d]<1){ 
									if( d == SIZE2-1){
										m[i][j] = m[i][j] * 8;
										count ++;
										break;
									}
									else{
									d++;
									}
								}
							}
							
							if(m[i][d] < 1){ 
								if(m[i+1][d-1]>0){
									z = d-1;
									while( z >= 0){
										if(m[i+1][z-1]>0){ 
											if(m[i][z-1]==0){
												if(z == 0){
													break;
												}

											z--;
											}
											if(m[i][z-1]>0){
												if(m[i-1][z-1]==0 && m[i][z-2]==0){
													m[i][j] = m[i][j] * 8;
													count ++;
													break;
												}
												else{
													break;
												}
											}
										}
										else{
											m[i][j] = m[i][j] * 8;
											count ++;
											break;
										}
										if(z==0){
											break;
										}

									}
									break;
								}
								else{
									
											m[i][j] = m[i][j] * 8;
											count ++;
											break;

								}		

							}

						}
					}
					
				}
				if(j == SIZE2-1){ /*If j = SIZE-1 increase i */
					i++;
					j = 0;
					break;
				}
				if(j != SIZE2-1){ /* If j is not equal to SIZE-1 increase j */ 
					j++;
				}
			
				if(i == SIZE1-1){ /* If i equal to SIZE-1, break*/
					break;
				}
	}
}		

		/*for(i = 0; i<SIZE1; i++){
			for(j = 0; j<SIZE2; j++){
			
				printf("%d ", m[i][j]);
		
			}
		printf("\n");
		}*/
	fprintf(output, "%d\n", count ); /* Writing output file count*/
	for(i = 0; i<SIZE1; i++){
			for(j = 0; j<SIZE2; j++){
				if(m[i][j]>1){
					fprintf(output, "%d %d\n",i,j ); /*Writing coordinates*/
				}
		
			}
	}
	fclose(input);
	fclose(output);
		
}

