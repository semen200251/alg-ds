#pragma once 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct LIST
{
	char data[100];
	struct LIST* next;
}LIST;
int write(FILE* fp, LIST* List);
int merger(LIST* List1, LIST* List2);
int free_list(LIST* List);