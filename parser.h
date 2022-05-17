#ifndef PARSER
#define PARSER

#include <string.h>

#define MEM_MANUAL manual
#define MEM_BORROW borrow
#define MEM_GCED gc

#define MACRO_INTRODUCTION #
#define DEFINE #define
#define IMPLY #imply

//keywords
#define IF_STATE if
#define WHILE_STATE while
#define FOR_STATE for
#define FUNCTION_STATE func
#define FREE_STATE free
#define ALLOC_STATE allocate
#define AS_STATE as
#define CLASS_STATE class
#define CONSTRUCT_STATE construct

#define OPEN_PAREN (
#define CLOSE_PAREN )
#define OPEN_TYPE <
#define CLOSE_TYPE >
#define OPEN_BLOCK {
#define CLOSE_BLOCK }

struct class {
	long unsigned int class_size;
	//void* 
};

struct value {
	struct class type;
	
};

struct operation {
	int opcode;
	struct value* operand_f_memory_address;
	struct value* operand_s_memory_address;
};

struct block {
	unsigned short mem_type; // 1 - GC 2 - BORROW 3 - MANUAL
	void* contents;
};

void strip_nonsemantic_whitespace(char** string);
void strip_comments(char** string);

#endif // PARSER