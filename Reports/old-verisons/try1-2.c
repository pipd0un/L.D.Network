#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct  {
	int size;
	int id;
	float x1;
	float y1;
	float x2;
	float y2;
}block1;
typedef struct  {
	int size;
	int tip;
	int id;
	float x1;
	float y1;
	float x2;
	float y2;
}block2;
typedef struct  {
	int size;
	int id;
	float x1;
	float y1;
	float x2;
	float y2;
}block3;

typedef struct {
	block1 *flag_up;
	block2 *flag_cust;
	block3 *flag_line;
	int size;
	} blocks ;
	
int main(){
	int blcNum=0,*elements,item=0;
	elements = &item;
	char line[60];
	int getter;
	
	blocks *block;
	block = malloc(sizeof(blocks));
	block->flag_up = malloc(sizeof(block->flag_up));
	block->flag_cust = malloc(sizeof(block->flag_cust));
	block->flag_line = malloc(sizeof(block->flag_line));
	
	int temp;
	// ///////////////////////////////////////////
	FILE *fp;
	
	fp = fopen("IEEE_test_system_12.txt","r");
	while(!feof(fp)){
		fgets(line,60,fp);
		if(strstr(line,"ID") != NULL ){
		
		blcNum++;
		}
		
		if ( strstr(line,"\0") != NULL && strstr(line,"X1") == NULL && strstr(line,"END") == NULL ){
			item ++  ;
			// printf("%s",line);
			// size calculator

			if(item > 0)
			{
				block = realloc(block, item*sizeof(blocks));
				if(blcNum == 1){

					block->flag_up->size = item;
					// block->flag_up = realloc(block->flag_up , block->flag_up->size * sizeof(block->flag_up));
					fscanf(fp,"%d %.2f %.2f",&block->flag_up->id,&block->flag_up->x1,&block->flag_up->y1); 

				} 
				else if (blcNum == 2) {
					block->flag_cust->size = item - (block->flag_up->size) ;
					// block->flag_cust = realloc(block->flag_cust, block->flag_cust->size * sizeof(block->flag_cust));
					fscanf(fp,"%d %d %.2f %.2f %.2f %.2f",&block->flag_cust->id,&block->flag_cust->tip,
					                                      &block->flag_cust->x1,&block->flag_cust->y1,
														  &block->flag_cust->x2,&block->flag_cust->y2);

				}
				else if (blcNum == 3) {
					block->flag_line->size = item - (block->flag_up->size + block->flag_cust->size);
					// block->flag_line = realloc(block->flag_line, block->flag_line->size * sizeof(block->flag_line));
					fscanf(fp,"%d %.2f %.2f %.2f %.2f",&(block->flag_line + (block->flag_line->size * sizeof(block->flag_line)))->id,
					&(block->flag_line + (block->flag_line->size * sizeof(block->flag_line)))->x1,
					&(block->flag_line + (block->flag_line->size * sizeof(block->flag_line)))->y1,
					&(block->flag_line + (block->flag_line->size * sizeof(block->flag_line)))->x2, 
					&(block->flag_line + (block->flag_line->size * sizeof(block->flag_line)))->y2);
				}
			}
	}	
			
		
	};
	
	fclose(fp);
	/*
	printf("\nuploader     size : %d",block->flag_up->size);
	printf("\ncustomer     size : %d ",block->flag_cust->size);
   	printf("\nline         size : %d",block->flag_line->size);
	printf("\nblock      number : %d",blcNum);
	printf("\n3. line        id : %d",(block->flag_line + 2*sizeof(block->flag_line))->id);
	printf("\nelement number is : %d ",*elements);

	*/
	free(block->flag_up);
	free(block->flag_cust);
	free(block->flag_line);
	// &(      block -> flag_line + (  block->flag_line->size * sizeof(block->flag_line)  )      )->y1
	return 0;
}
