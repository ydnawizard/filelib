#ifndef READTXT_H
#define READTXT_H

//ANDY's FILE READING C UTILS

//TXT-TYPE-SPECIFIC UTILITIES//


  ///////////////////////////////////////////////////////////////
 //MAKE SURE TO INCLUDE DIRENT & STRING LIBRARIES IN MAIN FILE//
///////////////////////////////////////////////////////////////

//DEFINE THE TXT STRUCT FOR .txt FILE TYPE
struct TXT{
	char* CHARACTERS;
	char** STRINGS;
};

void readCharToTXT(struct TXT* txt,char character,int charCount){
	txt->CHARACTERS=realloc(txt->CHARACTERS,(charCount+1)*sizeof(char));
	txt->CHARACTERS[charCount]=character;
	printf("%c ",txt->CHARACTERS[charCount]);
}

void readCharToString(char character,char* string,int stringCharCount){
	string[stringCharCount]=character;
	string=realloc(string,(stringCharCount+1)*sizeof(char));
}

void readStringToTXT(struct TXT* txt,char* string,int stringCount){
	txt->STRINGS=(char**)realloc(txt->STRINGS,(stringCount+1)*sizeof(char*));
	txt->STRINGS[stringCount]=malloc((strlen(string))*sizeof(char));
	strcpy(txt->STRINGS[stringCount],string);
	printf("%s %s %d \n",txt->STRINGS[stringCount],"string",stringCount);
}

void readTXT(struct TXT* txt,char* filePath){
	txt=(struct TXT*)malloc(sizeof(struct TXT));
	txt->CHARACTERS=malloc(sizeof(char*));
	txt->STRINGS=malloc(sizeof(char*));
	FILE* toParse=fopen(filePath,"read");
	char* string=malloc(sizeof(char*));
	int charCount=0;
	int stringCount=0;
	int stringCharCount=0;
	char character;
	while((character=fgetc(toParse))!=EOF){
		if(character==' '){
			readStringToTXT(txt,string,stringCount);
			memset(string,'\0',strlen(string));
			stringCount+=1;
			stringCharCount=0;
		}else if(character=='\n'){
			readStringToTXT(txt,string,stringCount);
			memset(string,'\0',strlen(string));
			stringCount+=1;
			stringCharCount=0;
		}else{
			readCharToTXT(txt,character,charCount);
			readCharToString(character,string,stringCharCount);
			stringCharCount+=1;
			charCount+=1;
		}
	}
}

#endif
		
