#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct LIST {
    int data;
    struct LIST* left;
    struct LIST* right;
    struct LIST* parent;
} LIST;


LIST* add_block(LIST* parent, int data);

void insert_in_tree(int data);

LIST* find_min(LIST* current);

LIST* find_max(LIST* current);

LIST* find_data(int data, LIST* current);

void delete_block(LIST* current);

void deleteValue(LIST* root, int value);

void printTree(LIST* root, const char* dir, int level);

void file_read(FILE* fp);

