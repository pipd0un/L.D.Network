#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct {
	int size;
	int id;
	int tip;
	
	float x1;
	float x2;
	float y1;
	float y2;
}blocks;
int credit();
void linelen(blocks *block3);

int main() {  
	
	blocks *block1 , *block2 , *block3;
	char line[60];
	
	int index=0;
	int blcNum=1;
	int endCount=1;
	int temp;
	
	int sizer=0;
	int sizes[3];
	
	
	block1 = malloc( sizeof(blocks) );
	block2 = malloc( sizeof(blocks) );
	block3 = malloc( sizeof(blocks) );
	
	FILE *fp;
	fp = fopen("IEEE_test_system_12.txt","r");
	
	// block's size calculator and memory allocater ;
	
	while(fgets(line,60,fp))
	{
		
            if ( strstr(line,"ID") == NULL && strstr(line,"END") == NULL ) 
			{
            	sizer++;
            }
            else if( strstr(line,"END") != NULL )
            {
            	
            	if(endCount == 1)
            	{
            		sizes[0] = sizer;
            		sizer=0;
            		endCount++;
				}
				else if(endCount == 2)
				{
					sizes[1] = sizer;
					sizer=0;
					endCount++;
				}
				else if (endCount == 3)
				{
					sizes[2] = sizer;
					sizer=0;
				}
				
			}
	};
	printf("\nsizes[0] : %d",sizes[0]);
	printf("\nsizes[1] : %d",sizes[1]);
	printf("\nsizes[2] : %d\n",sizes[2]);
	block1->size = sizes[0];
	block2->size = sizes[1];
	block3->size = sizes[2];
	
	block1 = realloc(block1 , block1->size * sizeof(blocks));
	block2 = realloc(block2 , block2->size * sizeof(blocks));
	block3 = realloc(block3 , block3->size * sizeof(blocks));
    fclose(fp);
    line == NULL;
    fp = fopen("IEEE_test_system_12.txt","r");
    char *szTempString;
    while(fgets(line,60,fp))
	{
    	
        if (  strstr(line,"ID") == NULL && strstr(line,"END") == NULL && strstr(line,"\0") != NULL)
        {
        	
    		
            szTempString = line;
            if ( blcNum == 1){
            	printf("%s",line);
                sscanf(szTempString,"%d %f %f",&(block1 + index)->id,&(block1 + index)->x1,&(block1 + index)->y1);
                index++;
            }
            else if ( blcNum == 2){
            	printf("%s",line);
                sscanf(szTempString,"%d %d %f %f %f %f",&(block2 + index)->id,&(block2 + index)->tip, &(block2 + index)->x1,&(block2 + index)->y1,&(block2 + index)->x2,&(block2 + index)->y2);
                index++;
            }
            else if ( blcNum == 3){
            	printf("%s",line);
                sscanf(szTempString,"%d %f %f %f %f",&(block3 + index)->id,&(block3 + index)->x1, &(block3 + index)->y1,&(block3 + index)->x2, &(block3 + index)->y2);
                index++;
            }
        }
        else if ( strstr(line,"END") != NULL ){
                blcNum++;
                index = 0;
        }
    
    }   
    fclose(fp);
    printf("\nUploader's information : \n");
   for (temp =0; temp < block1->size ; temp++)
   {
   	printf(" id : %d , X1 : %.2f , Y1 : %.2f  \n",(block1+temp)->id,(block1+temp)->x1,(block1+temp)->y1);
   } 

    printf("\nCustomer's information : \n");
   for (temp =0; temp < block2->size ; temp++)
   {
   	printf(" id : %d , tip : %d , X1 : %.2f , Y1 : %.2f , X2 : %.2f , Y2 : %.2f \n",(block2+temp)->id,(block2+temp)->tip,(block2+temp)->x1,
	                                                                        (block2+temp)->y1,(block2+temp)->x2,(block2+temp)->y2);
   } 

    printf("\nLine's information : \n");
   for (temp =0; temp < block3->size ; temp++)
   {
   	printf(" id : %d , X1 : %.2f , Y1 : %.2f , X2 : %.2f , Y2 : %.2f \n",(block2+temp)->id,(block2+temp)->x1,
	                                                            		 (block2+temp)->y1,(block2+temp)->x2,
																 		 (block2+temp)->y2);
   }
   
	printf("\nblock1's size : %d ",block1->size);
	printf("\nblock2's size : %d ",block2->size);
	printf("\nblock3's size : %d ",block3->size);	
	printf("\na random number block3.size * block2.size + block1.size : %d",(block3->size*block2->size + block1->size));
	free(block1);
	free(block2);
	free(block3);
	//credit();
	//linelen(block3);
	return 0;
}
void linelen(blocks *a)
{
	float totallen =0.00;
	int i;
	int lenGrab[a->size];
	for(i=0;i < a->size;i++)
	{
		lenGrab[i] = sqrt( pow( (a+i)->x2 - (a+i)->x1 , 2) + pow( (a+i)->y2 - (a+i)->y1 , 2));
		totallen += lenGrab[i];
	}
	printf("\nTotal line number : %d",a->size);
	printf("\nTotal length of Lines : %.2f",totallen);
}
int credit()
{
	int choice;
	printf("\nPlease enter choice (1/2) : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\nselected choice 1");
			break;
		case 2: printf("\nselected choice 2");
			break;
	}
	return 0;
}
