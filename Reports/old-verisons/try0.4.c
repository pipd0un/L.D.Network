#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct{
	float x1;
	float y1;
	float x2;
	float y2;
}loader;

typedef struct Cust {
	int tip;
	int id ;
	int size;
	float x1;
	float y1;
	float x2;
	float y2;
}customer;

typedef struct{
	int id ;
	float x1;
	float y1;
	float x2;
	float y2;
}liner;

int main() {
	char satir[60];
	loader *load;
	liner *line;
	customer *cust;
	int ret ;
	
	int size=0 ;
	int currChar ;
	FILE *fp;
	fp = fopen("IEEE_test_system_12.txt","r");
	while((currChar=fgetc(fp))!=EOF){
		 if(currChar=='\n'){
            size++;
    }
    // SIZE HESAPLANDI AMK ..
}

	printf("%d",size);
	return 0;
}
