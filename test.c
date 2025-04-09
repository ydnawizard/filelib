
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "read/read.h"

int main(){
	char** files;
	files=malloc(sizeof(char**));
	files=readDirectory("./shapes");
	int i=0;
	while(files[i]!=NULL){
		printf("%s \n",files[i]);
		i+=1;
	}
	readFile(files[0]);
	readOBJ(files[0]);
	return 0;
}

