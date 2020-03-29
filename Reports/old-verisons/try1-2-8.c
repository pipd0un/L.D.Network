#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

int main() {  
	
	blocks *block1 , *block2 , *block3;
	char line[60];
	
	int index=1;
	int blcNum=1;
	int endCount=1;
	int temp;
	
	int sizer=0;
	int* sizep;
	sizep = malloc( (int*)(sizep + 3*sizeof(int)));
	
	
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
            		*(sizep + endCount*sizeof(int)) = sizer;
            		sizer=0;
            		endCount++;
				}
				else if(endCount == 2)
				{
					*(sizep + endCount*sizeof(int)) = sizer;
					sizer=0;
					endCount++;
				}
				else if (endCount == 3)
				{
					*(sizep + endCount*sizeof(int)) = sizer;
					sizer=0;
				}
				
			}
	};
	
	block1->size = *(sizep + sizeof(int));
	block2->size = *(sizep+2*sizeof(int));
	block3->size = *(sizep+3*sizeof(int));
	
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
                sscanf(szTempString,"%d %f %f",&(block1 + (index*sizeof(blocks)))->id,&(block1 + (index*sizeof(blocks)))->x1,&(block1 + (index*sizeof(blocks)))->y1);
                index++;
            }
            else if ( blcNum == 2){
            	printf("%s",line);
                sscanf(szTempString,"%d %d %f %f %f %f",&(block2 + (index*sizeof(blocks)))->id,&(block2 + (index*sizeof(blocks)))->tip, &(block2 + (index*sizeof(blocks)))->x1,&(block2 + (index*sizeof(blocks)))->y1,&(block2 + (index*sizeof(blocks)))->x2,&(block2 + (index*sizeof(blocks)))->y2);
                index++;
            }
            else if ( blcNum == 3){
            	printf("%s",line);
                sscanf(szTempString,"%d %f %f %f %f",&(block3 + (index*sizeof(blocks)))->id,&(block3 + (index*sizeof(blocks)))->x1, &(block3 + (index*sizeof(blocks)))->y1,&(block3 + (index*sizeof(blocks)))->x2, &(block3 + (index*sizeof(blocks)))->y2);
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
   for (temp =1; temp <= block1->size ; temp++)
   {
   	printf(" id : %d , X1 : %.2f , Y1 : %.2f  \n",(block1+(temp*sizeof(blocks)))->id,(block1+(temp*sizeof(blocks)))->x1,(block1+(temp*sizeof(blocks)))->y1);
   } 

   printf("\nCustomer's information : \n");
   for (temp =1; temp <= block2->size ; temp++)
   {
   	printf(" id : %d , tip : %d , X1 : %.2f , Y1 : %.2f , X2 : %.2f , Y2 : %.2f \n",(block2+(temp*sizeof(blocks)))->id,(block2+(temp*sizeof(blocks)))->tip,(block2+(temp*sizeof(blocks)))->x1,
	                                                                        (block2+(temp*sizeof(blocks)))->y1,(block2+(temp*sizeof(blocks)))->x2,(block2+(temp*sizeof(blocks)))->y2);
   } 

   printf("\nLine's information : \n");
   for (temp =1; temp <= block3->size ; temp++)
   {
   	printf(" id : %d , X1 : %.2f , Y1 : %.2f , X2 : %.2f , Y2 : %.2f \n",(block2+(temp*sizeof(blocks)))->id,(block2+(temp*sizeof(blocks)))->x1,
	                                                            		 (block2+(temp*sizeof(blocks)))->y1,(block2+(temp*sizeof(blocks)))->x2,
																 		 (block2+(temp*sizeof(blocks)))->y2);
   }
   
	printf("\nblock1's size : %d ",block1->size);
	printf("\nblock2's size : %d ",block2->size);
	printf("\nblock3's size : %d ",block3->size);	
	printf("\na random number : %d",(block3->size*block2->size + block1->size));
	free(block1);
	free(block2);
	free(block3);
	credit();
	return 0;
}
int credit()
{
	int choice;
	//system("cls");
	printf("Please enter choice (1/2) : ");
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
