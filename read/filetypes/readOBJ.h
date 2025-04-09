#ifndef READOBJ_H
#define READOBJ_H

//Andy Weglewski's file reading C utils

//OBJ File-Type Read Definitions

  ///////////////////////////////////////////////////////////////
 //MAKE SURE TO INCLUDE DIRENT & STRING LIBRARIES IN MAIN FILE//
///////////////////////////////////////////////////////////////

//.obj
struct OBJ{
	float** vertices;
	float** verticeNorms;
	float** verticeTextures;
	char** faces;
};

//OBJ-SPECIFIC FUNCTIONS//

//readVertice(obj vertice line)->vertice (float array)
//Takes in a vertice line from obj file (as string) and
//returns the relevant values in a float array
float* readVertice(char* toParse){
	int spaceCount=0;
	int number=0;
	int digit=0;
	int character=0;
	char* verticeString;
	verticeString=malloc(sizeof(char));
	float* vertice;
	vertice=malloc(3*sizeof(float));
	while(toParse[character]!='\n'){
		if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		}else if(toParse[character]!='v'){
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}else{
			character+=1;
		}
	}
	return vertice;
}

//readVerticeNorm(obj vertice norm line)->vertice (float array)
//Takes in a vertice norm line from obj file (as string) and
//returns the relevant values in a float array
float* readVerticeNorm(char* toParse){
	int spaceCount=0;
	int number=0;
	int digit=0;
	int character=0;
	char* verticeString;
	verticeString=malloc(sizeof(char));
	float* vertice;
	vertice=malloc(3*sizeof(float));
	while(toParse[character]!='\n'){
		if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		}else if(toParse[character]!='v'&&toParse[character]!='n'){
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}else{
			character+=1;
		}
	}
	for(int i=0;i<3;i++){
		printf("%f ",vertice[i]);
	}
	return vertice;
}

//readVerticeTexture(obj vertice texture line)->vertice (float array)
//Takes in a vertice texture line from obj file (as string) and
//returns the relevant values in a float array
float* readVerticeTexture(char* toParse){
	int spaceCount=0;
	int number=0;
	int digit=0;
	int character=0;
	char* verticeString;
	verticeString=malloc(sizeof(char));
	float* vertice;
	vertice=malloc(3*sizeof(float));
	while(toParse[character]!='\n'){
		if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		}else if(toParse[character]!='v'&&toParse[character]!='t'){
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}else{
			character+=1;
		}
	}
	for(int i=0;i<3;i++){
		printf("%f ",vertice[i]);
	}
	return vertice;
}


void readOBJ(char* file){
	char* toParse="vt 5.000 -1.0000 100.000";
	readVerticeTexture(toParse);
}

#endif //READOBJ_H
