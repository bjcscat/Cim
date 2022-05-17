#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "parser.h"

int main(void) {

	char* input = malloc(100);

	strcpy(input,"ok  \"  \\\"  \"  ok /* sentimentalminimal \n test */ end");

	strip_nonsemantic_whitespace(&input);
	strip_comments(&input);
	
	printf("%s",input);

	return 0;
}