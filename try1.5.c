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
void selections();
void custlen(blocks *b);
void randLine(blocks *a);
void randUp(blocks *c);
void randCust(blocks *b);
void linelen(blocks *a);
void analizer(blocks *a , blocks *b , blocks *c);
int line2line(int id,blocks *c);

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
	fp = fopen("data/IEEE_test_system_12.txt","r");
	
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
	block1->size = sizes[0];
	block2->size = sizes[1];
	block3->size = sizes[2];
	
	block1 = realloc(block1 , block1->size * sizeof(blocks));
	block2 = realloc(block2 , block2->size * sizeof(blocks));
	block3 = realloc(block3 , block3->size * sizeof(blocks));
    fclose(fp);
    line == NULL;
    fp = fopen("data/IEEE_test_system_12.txt","r");
    char *szTempString;
    while(fgets(line,60,fp))
	{
    	
        if (  strstr(line,"ID") == NULL && strstr(line,"END") == NULL && strstr(line,"\0") != NULL)
        {
            szTempString = line;
            if ( blcNum == 1){
                sscanf(szTempString,"%d %f %f",&(block1 + index)->id,&(block1 + index)->x1,&(block1 + index)->y1);
                index++;
            }
            else if ( blcNum == 2){
                sscanf(szTempString,"%d %d %f %f %f %f",&(block2 + index)->id,&(block2 + index)->tip, &(block2 + index)->x1,&(block2 + index)->y1,&(block2 + index)->x2,&(block2 + index)->y2);
                index++;
            }
            else if ( blcNum == 3){
                sscanf(szTempString,"%d %f %f %f %f",&(block3 + index)->id,&(block3 + index)->x1, &(block3 + index)->y1,&(block3 + index)->x2, &(block3 + index)->y2);
                index++;
            }
        }
        else if ( strstr(line,"END") != NULL ){
                blcNum++;
                index = 0;
        }
    }

	 //USER MENU 
	int broken = 0, selection;
	/*
	while(1)
	{
		
		printf("\n\n         Wanna continue ? (y/n) : ");
		char cont;
		scanf("%c",&cont);
		if(cont == 'y' || cont == 'Y')
		{
			system("cls");
			break;
		}
		else if(cont == 'n' || cont == 'N')
		{
			printf(" Can't escape lol !");
		} 
	}
	*/
	printf("\n****************************************");
	printf("\n*****Welcome To City Draft Center !*****");
	printf("\n****************************************");
	while (!broken) 
	{
		selections();
		
		scanf("%d",&selection);
		switch ( selection ) 
			{
				case 1 :  system("cls");linelen(block3);
					break;
				case 2 :  system("cls");custlen(block2);
					break;
				case 3 :  system("cls");randLine(block3);
					break;
				case 4 :  system("cls");randCust(block2);
					break;
				case 5 :  system("cls");randUp(block1);
					break;
				case 6 :  system("cls");credit();
					break;
				case 0 : system("cls");
						 broken = 1;
					break;		
			}
	}
	
	analizer(block1,block2,block3);
	printf("\n See ya later ! ");
	free(block1);
	free(block2);
	free(block3);
	return 0;
}
void analizer(blocks *a , blocks *b ,blocks *c)
{
	int id;
	int i;
	int j;
	int ret;
	int cont;
	printf("\nEnter customer's id to analyse its line route : ");
	scanf("%d",&id);
	system("cls");
	for(i =0; i < b->size ;i++)
	{
		if( (b+i)->id == id)
		{
			for(j=0;j< c->size;j++)
			{
				if((b+i)->x1 == (c+j)->x2 && (b+i)->y1 == (c+j)->y2)
				{
					// found the line that connected to customer.
					ret = j;
					printf("\n Line %d",(c+j)->id);
					cont = line2line(ret,c);
				}
			}
		}
	}
	while( !((c+cont)->x1 == a->x1 && (c+cont)->y1 == a->y1))
	{
		line2line(ret,c);
	}
	printf("\n Uploader Center %d",a->id);
}
int line2line(int id,blocks *c)
{
	int i;
	int j;
	int ret;
	for (i=0;i<c->size;i++)
	{
		if((c+id)->x1 == (c+i)->x2 && (c+id)->y1 == (c+j)->y2)
		{
			ret = j;
			printf("\n Line %d",(c+j)->id);
		}
	}
	line2line(ret,c);
	return ret;
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
	printf("\nTotal length of Lines : %.2f\n",totallen);
}
int credit()
{
	int choice;
	printf("\nPlease enter choice (1/2) : ");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1: printf("\nThanks a lot Hubert :)");
			break;
		case 2: printf("\nThanks for Hubert :)");
			break;
	}
	return 1;
}
void selections()
{
	printf("\n\n Please put a number what you want to select ...\n");
	printf("\n (1) To see total Line number and total Line length");
	printf("\n (2) To see total customer number and total customer numbers by their types");
	printf("\n (3) To see coordinate information and id number of a random line");
	printf("\n (4) To see coordinate information and id number of a customer");
	printf("\n (5) To see id number and coordinate information of uploader center");
	printf("\n (6) Credits");
	printf("\n (0) Exit\n\n");
	printf("\nput here -> ");
}
void randUp(blocks *c)
{
	int id;
	int i;
	puts("Please enter id .. ");
	printf("\nUploader ");
	scanf("%d",&id);
	for(i=0; i < c->size ;i++)
	{
		if((c+i)->id == id)
		{
			printf("Uploader %d,(%.2f,%.2f)",(c+i)->id,(c+i)->x1,(c+i)->y1);
		}
	}
}
void randCust(blocks *b)
{
	int id;
	int i;
	puts("Please enter id .. ");
	printf("\nCustomer ");
	scanf("%d",&id);
	for(i=0; i < b->size ;i++)
	{
		if((b+i)->id == id)
		{
			printf("Customer %d,(%.2f,%.2f,%.2f,%.2f)",(b+i)->id,(b+i)->x1,(b+i)->y1,(b+i)->x2,(b+i)->y2);
		}
	}
}
void custlen(blocks *b)
{
	int i;
	int dwell=0;
	int comm=0;
	int ind=0;
	
 	for(i=0;i < b->size ;i++)
	{
		
		if((b+i)->tip == 1)
		{
			dwell++;
		}
		else if((b+i)->tip == 2)
		{
			comm++;
		}
		else if((b+i)->tip == 3)
		{
			ind++;
		}
		
	} 
	printf("\nTotal customer number : %d ",b->size); 
	printf("\n%d customer %d dwelling , %d commercial , %d industrial",b->size,dwell,comm,ind);
}
void randLine(blocks *a)
{
	int id;
	int i;
	puts("Please enter id .. ");
	printf("\nLine ");
	scanf("%d",&id);
	for(i=0; i < a->size ;i++)
	{
		if((a+i)->id == id)
		{
			printf("Line %d,(%.2f,%.2f,%.2f,%.2f)",(a+i)->id,(a+i)->x1,(a+i)->y1,(a+i)->x2,(a+i)->y2);
		}
	}
}
