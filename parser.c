#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "parser.h"

void strip_nonsemantic_whitespace(char** string) {
	char* buffer = malloc(strlen(*string)+1);
	
	bool instr = false;
	int strc = 0;
	
	for (int i=0;i<strlen(*string);i++) {
		if ((*string)[i]=='"'&&(*string)[i-1]!='\\') {
			instr = !instr;
		}
		if ((*string)[i]==' '&&(*string)[i+1]==' '&&!instr){
			continue;
		}
		buffer[strc] = (*string)[i];
		strc++;
	}
	free(*string);
	if (realloc(*string,strlen(buffer)+1) == NULL) {
		puts("Memory allocation error in preprocessing.");
		exit(1);
	}
	*string = buffer;
}

void strip_comments(char** string) {
	char* buffer = malloc(strlen(*string)+1);

	short incomment = 0;
	int strc = 0;

	for (int i=0;i<strlen(*string);i++) {
		if (incomment==1&&(*string)[i]=='\n') {
			incomment = 0;
		}
		if (incomment==2&&(*string)[i]=='*'&&(*string)[i+1]=='/') {
			incomment = 0;
			i+=2;
			continue;
		}
		if (incomment!=0){
			continue;
		}
		if ((*string)[i]=='/'&&(*string)[i+1]=='/') {
			incomment = 1;
			continue;
		}
		if ((*string)[i]=='/'&&(*string)[i+1]=='*') {
			incomment = 2;
			continue;
		}
		buffer[strc] = (*string)[i];
		strc++;
	}
	free(*string);
	if (realloc(*string,strlen(buffer)+1) == NULL) {
		puts("Memory allocation error in preprocessing.");
		exit(1);
	}
	*string = buffer;
}

// preprocessing over