#ifndef READOBJ_H
#define READOBJ_H

//ANDY's FILE READING C UTILS

//OBJ-TYPE-SPECIFIC UTILITIES//

//I know this is written kind of clunky but its fast enough and works
//USE:
//	1.)Define an OBJ struct
//	2.)Make sure .obj file is in shapes directory
//	3.)Call readOBJ on the struct and the filename

  ///////////////////////////////////////////////////////////////
 //MAKE SURE TO INCLUDE DIRENT & STRING LIBRARIES IN MAIN FILE//
///////////////////////////////////////////////////////////////

//DEFINE THE OBJ STRUCT FOR .obj FILE TYPE
struct OBJ{
	double** VERTICES;
	double** NORMS;
	float** TEXTURES;
	int*** FACES;
};

//SINGLE-LINE PARSE FUNCTIONS//

//readVertice(obj vertice line)->vertice (float array)
//Takes in a vertice line from obj file (as string) and
//returns the relevant values in a float array
double* readVertice(char* toParse){
	//Inits for indexing vertice
	//Init Space Counter
	int spaceCount=0;
	//Init Number Counter
	int number=0;
	//Init Digit Counter
	int digit=0;
	//Init character for indexing toParse
	int character=0;
	//Init verticeString for easy reading
	//of toParse stream
	char* verticeString;
	//Allocate memory for verticeString
	verticeString=malloc(sizeof(char));
	//Init vertice. verticeString is converted
	//to float and dumped into vertice once
	//the float has been completely read from toParse
	double* vertice;
	//Allocate for vertice
	vertice=malloc(3*sizeof(double));
	//While character counter is less than the length of toParse string, do:
	while(character<=strlen(toParse)){
		if(toParse[character]=='\0'){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//If first space in line, then skip
		}else if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		//If not first space in line, convert verticeString
		//Dump verticeString into vertice and increment/reset
		//relevant counters
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//Skip v
		}else if(toParse[character]=='v'){
			character+=1;
		//If character is not v and not space(because of prev ifs)
		//Add the char to verticeString, increment relevant counters
		//and realloc space for next char.
		}else{
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}
	}
	//Return vertice double array
	return vertice;
}

//readVerticeNorm(obj vertice norm line)->vertice (float array)
//Takes in a vertice norm line from obj file (as string) and
//returns the relevant values in a float array
double* readVerticeNorm(char* toParse){
	//Inits for indexing vertice
	//Init Space Counter
	int spaceCount=0;
	//Init Number Counter
	int number=0;
	//Init Digit Counter
	int digit=0;
	//Init character for indexing toParse
	int character=0;
	//Init verticeString for easy reading
	//of toParse stream
	char* verticeString;
	//Allocate memory for verticeString
	verticeString=malloc(sizeof(char));
	//Init vertice. verticeString is converted
	//to float and dumped into vertice once
	//the float has been completely read from toParse
	double* vertice;
	//Allocate for vertice
	vertice=malloc(3*sizeof(double));
	//While character counter is less than the length of toParse string, do:
	while(character<=strlen(toParse)){
		if(toParse[character]=='\0'){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//If first space in line, then skip
		}else if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		//If not first space in line, convert verticeString
		//Dump verticeString into vertice and increment/reset
		//relevant counters
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//Skip v & n
		}else if(toParse[character]=='v'||toParse[character]=='n'){
			character+=1;
		//If character is not v or n and not space(because of prev ifs)
		//Add the char to verticeString, increment relevant counters
		//and realloc space for next char.
		}else{
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}
	}
	//Return vertice double array
	return vertice;
}
//readVerticeTexture(obj vertice texture line)->vertice (float array)
//Takes in a vertice texture line from obj file (as string) and
//returns the relevant values in a float array
float* readVerticeTexture(char* toParse){
	//Inits for indexing vertice
	//Init Space Counter
	int spaceCount=0;
	//Init Number Counter
	int number=0;
	//Init Digit Counter
	int digit=0;
	//Init character for indexing toParse
	int character=0;
	//Init verticeString for easy reading
	//of toParse stream
	char* verticeString;
	//Allocate memory for verticeString
	verticeString=malloc(sizeof(char));
	//Init vertice. verticeString is converted
	//to float and dumped into vertice once
	//the float has been completely read from toParse
	float* vertice;
	//Allocate for vertice
	vertice=malloc(3*sizeof(float));
	//While character counter is less than the length of toParse string, do:
	while(character<=strlen(toParse)){
		if(toParse[character]=='\0'){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//If first space in line, then skip
		}else if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		//If not first space in line, convert verticeString
		//Dump verticeString into vertice and increment/reset
		//relevant counters
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice[number]=atof(verticeString);
			number+=1;
			digit=0;
			character+=1;
		//Skip v & t
		}else if(toParse[character]=='v'||toParse[character]=='t'){
			character+=1;
		//If character is not v or n and not space(because of prev ifs)
		//Add the char to verticeString, increment relevant counters
		//and realloc space for next char.
		}else{
			verticeString[digit]=toParse[character];
			digit+=1;
			verticeString=realloc(verticeString,(digit+1)*sizeof(char));
			character+=1;
		}
	}
	//Return vertice double array
	return vertice;
}

//readFace(string,int)->list of face definitions
int** readFace(char* toParse,int pointCount){
	int spaceCount=0;
	int character=0;
	int vertice=0;
	int digit=0;
	int** face;
	face=malloc(pointCount*sizeof(int*));
	for(int i=0;i<pointCount;i++){
		face[i]=malloc(3*sizeof(int));
	}
	while(character<=strlen(toParse)){
		if(toParse[character]=='\0'){
			return face;
		}else if(toParse[character]==' '&&spaceCount==0){
			spaceCount+=1;
			character+=1;
		}else if(toParse[character]==' '&&spaceCount>0){
			vertice+=1;
			digit=0;
			character+=1;
		}else if(toParse[character]!='f'&&toParse[character]!='/'){
			face[vertice][digit]=toParse[character]-'0';
			digit+=1;
			character+=1;
		}else{
			character+=1;
		}
	}
}
			

//MULTI-LINE PARSE FUNCTIONS//

//countPoints(string)->int
//This function counts backslashes in a string
//and divides that number by two. This is useful
//for discerning how many points an obj files uses
//to define its faces
int countPoints(char* toParse){
	int pointCount=0;
	int slashCount=0;
	int character=0;
	while(character<=strlen(toParse)){
		if(toParse[character]=='/'){
			slashCount+=1;
			character+=1;
		}else{
			character+=1;
		}
	}
	pointCount=slashCount/2;
	return pointCount;
}

//Takes in a file name and converts each file line into a string.
//The line strings are dumped into an array and that array is returned
void readOBJ(struct OBJ* obj,char* file){
	//Allocate memory for obj
	obj=(struct OBJ*)malloc(sizeof(struct OBJ));
	//Initialize counter for obj components
	int verticeCount=0;
	int normCount=0;
	int textureCount=0;
	int faceCount=0;
	//Iinitalize file path destination string with correct
	//directory name prefix
	char filePath[50]="./shapes/";
	//Concatenate prefix and file name together to form
	//proper filPath string
	strcat(filePath,file);
	//Initialize file struct and open filePath into it
	FILE* toParse=fopen(filePath,"read");
	//Initialize toParseString to pass lines into read functions
	char* toParseString=(char*)malloc(sizeof(char));
	//Init component to specify what part of
	//OBJ struct is being parsed: 0-none,1-VERTICES,2-NORMS,3-TEXTURES,4-FACES
	int component=0;
	//Init line index
	int index=0;
	//Iinit character placeholder for file stream
	char character;
	//While the character being parsed is not end of file, do:
	while((character=fgetc(toParse))!=EOF){
		//If vertice is being parsed and its the end of the line, do:
		if(character=='\n'&&component==1){
			//add space to end of string (so readVertice functions right)
			//readVertice has a space counter that is crucial to its functionality
			//Cophuge c functionsy the output of readVertice(toParseString) into the current verticeCount index
			//of the OBJ(obj) struct's VERTICES component
			toParseString[index]='\0';
			//Allocate space in OBJ for next VERTICES entry
			obj->VERTICES=(double**)realloc(obj->VERTICES,(verticeCount+1)*sizeof(double*));
			obj->VERTICES[verticeCount]=(double*)malloc(3*sizeof(double));
			//readVertice returns a pointer to an array of doubles so memcpy must
			//be used to move contents from the array into the OBJ structure
			memcpy(obj->VERTICES[verticeCount],readVertice(toParseString),3*sizeof(double));
			//Increment releveant counters
			verticeCount+=1;
			component=0;
			index=0;
			//Clear the contents of toParseString, resetting it
			memset(toParseString,0,strlen(toParseString));
		}else if(character=='\n'&&component==2){
			toParseString[index]=='\0';
			obj->NORMS=(double**)realloc(obj->NORMS,(normCount+1)*sizeof(double*));
			obj->NORMS[normCount]=(double*)malloc(3*sizeof(double));
			memcpy(obj->NORMS[normCount],readVerticeNorm(toParseString),3*sizeof(double));
			normCount+=1;
			component=0;
			index=0;
			memset(toParseString,0,strlen(toParseString));
		}else if(character=='\n'&&component==3){
			toParseString[index]='\0';
			obj->TEXTURES=(float**)realloc(obj->TEXTURES,(textureCount+1)*sizeof(float*));
			obj->TEXTURES[textureCount]=(float*)malloc(2*sizeof(float));
			memcpy(obj->TEXTURES[textureCount],readVerticeTexture(toParseString),2*sizeof(float));
			textureCount+=1;
			component=0;
			index=0;
			memset(toParseString,0,strlen(toParseString));
		}else if(character=='\n'&&component==4){
			toParseString[index]='\0';
			obj->FACES=(int***)realloc(obj->FACES,(faceCount+1)*sizeof(int**));
			int pointCount=countPoints(toParseString);
			obj->FACES[faceCount]=(int**)malloc(pointCount*sizeof(int*));
			for(int i=0;i<pointCount;i++){
				obj->FACES[faceCount][i]=(int*)malloc(3*sizeof(int));
			}
			memcpy(obj->FACES[faceCount],readFace(toParseString,pointCount),pointCount*sizeof(int*));
			faceCount+=1;
			component=0;
			index=0;
			memset(toParseString,0,strlen(toParseString));
		}else if(character=='v'){
			component=1;
			toParseString[index]=character;
			index+=1;
			toParseString=realloc(toParseString,(index+1)*sizeof(char));
		}else if(character=='n'){
			component=2;
			toParseString[index]=character;
			index+=1;
			toParseString=realloc(toParseString,(index+1)*sizeof(char));
		}else if(character=='t'){
			component=3;
			toParseString[index]=character;
			index+=1;
			toParseString=realloc(toParseString,(index+1)*sizeof(char));
		}else if(character=='f'){
			component=4;
			toParseString[index]=character;
			index+=1;
			toParseString=realloc(toParseString,(index+1)*sizeof(char));
		}else if(component>0){
			toParseString[index]=character;
			index+=1;
			toParseString=realloc(toParseString,(index+1)*sizeof(char));
		}
	}
}


#endif //READOBJ_H
