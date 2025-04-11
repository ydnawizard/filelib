
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "main.h"

int main(){
	char** objs;
	objs=malloc(sizeof(char**));
	objs=readDirectory("./shapes");
	char** txts;
	txts=malloc(sizeof(char**));
	txts=readDirectory("./texts");
	int i=0;
	while(objs[i]!=NULL){
		printf("%s \n",objs[i]);
		i+=1;
	}
	i=0;
	while(txts[i]!=NULL){
		printf("%s \n",txts[i]);
		i+=1;
	}
	struct OBJ obj;
	readOBJ(&obj,objs[0]);
	struct TXT txt;
	readTXT(&txt,"./texts/subCipher.txt");
	i=0;
	return 0;
}

