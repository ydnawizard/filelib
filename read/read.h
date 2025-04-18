#ifndef READ_H
#define READ_H

//Andy Weglewski's file reading C utils

  ///////////////////////////////////////////////////////////////
 //MAKE SURE TO INCLUDE DIRENT & STRING LIBRARIES IN MAIN FILE//
///////////////////////////////////////////////////////////////

//IMPORT COMPONENT HEADERS//
#include "filetypes/readOBJ.h"
#include "filetypes/readTXT.h"

/////////////////////////////////////////////////////////////////////////
//USE:                                                                  /
//FUNCTIONS IN THIS FILE ARE GENERAL UTILITIES. THEY ARE TO BE USED     /
//TO GAIN KNOWLEDGE ABOUT A FILE'S NATURE (EX:DISCERN FILE TYPE).       /
//USING THE OUTPUTS OF THESE GENERAL UTILITIES, FILE-TYPE-SPECIFIC      /
//UTILITIES CAN THEN BE CALLED. USUALLY THESE ARE STRAIGHTFORWARD       /
//LIKE USING readOBJ(struct OBJ,file) TO READ AN OBJ FILE.              /
//SUPPORTED FILE TYPES HAVE THEIR OWN HEADERS LOCATED IN /filetypes.    /
//MORE IN-DEPTH UNDERSTANDING CAIN BE GAINED FROM EXAMINING THESE FILES /
/////////////////////////////////////////////////////////////////////////

  /////////////////////
 //GENERAL FUNCTIONS//
/////////////////////

//readDirectory(directory name/path)->array of file names
//takes in a directory path and returns an array of
//file names as strings. Returns empty array if directory is empty
char** readDirectory(char* directory){
	int i=0;
	//Initialize raw (dirty) directory steam structure
	DIR* directoryDirty;
	//Set path
	directoryDirty=opendir(directory);
	//Initialize dirent struct called that stores
	//usable (clean) version of the raw directory data
	struct dirent* directoryClean;
	//Initialize char double pointer for array of file names
	char** files;
	//Allocate space for a string
	files=malloc(sizeof(char*));
	//While directory exists:
	if(directoryDirty){
		//Run this loop:
		//Reads all files in directory to directoryClean
		//one at a time
		while((directoryClean=readdir(directoryDirty))!=NULL){
			//Check for duplicates
			if(strcmp(directoryClean->d_name,".")!=0&&strcmp(directoryClean->d_name,"..")){
				//Count characters in file name and allocate necessary memory space
				files[i]=realloc(files[i],strlen(directoryClean->d_name)*sizeof(char));
				//add file name to files array
				strcpy(files[i],directoryClean->d_name);
				//increment i
				i+=1;
				files=realloc(files,(i+1)*sizeof(char*));
			}
		}
	}
	return files;
}

//readFileType(file name/path)->file type
//Takes in a file and outputs its file type
//as a string.
char* readFileType(char* file){
	int i=0;
	//initialize fileType string to store file type
	char* fileType;
	//allocate memory for fileType string
	fileType=malloc(sizeof(char*)); //while current file name char is not null terminator
	while(file[i]!='\0'){
		//if char is period (.) char then the file type
		//must follow so we grab it and store it in fileType
		if(file[i]=='.'){
			//initialize j to index/grab fileType chars
			int j=i+1;
			//initialize k to index fileType
			int k=0;
			while(file[j]!='\0'){
				//grab char and put it in fileType
				fileType[k]=file[j];
				//Increment j (next index in file)
				j+=1;
				//Increment k (next index in fileType)
				k+=1;
			}
			//Add null terminator to filetype string
			break;
		}else{
			i+=1;
		}
	}
	return fileType;
}

//readFilePrefix(file name/path)->file chars before '.'
char* readFilePrefix(char* file){
	int i=0;
	char* prefix;
	prefix=malloc(sizeof(char*));
	while(file[i]!='.'){
		prefix[i]=file[i];
		i+=1;
	}
	return prefix;
}




#endif //READ_H
