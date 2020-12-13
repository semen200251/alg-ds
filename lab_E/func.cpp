#include "Header.h"
LIST* list;
LIST* add_block(LIST* parent, int data)
{
    LIST* NEW = (LIST*)malloc(sizeof(LIST));
    NEW->left = NEW->right = NULL;
    NEW->data = data;
    NEW->parent = parent;
    return NEW;
}

void insert_in_tree(int data)
{
    if (list == NULL)
    {
        list = add_block(NULL, data);
        return;
    }
    LIST* current;
    current = list;
    while (current != NULL)
    {
        if (current->data > data)
        {
            if (current->left != NULL)
            {
                current = current->left;
                continue;
            }
            else if (current->left == NULL)
            {
                current->left = add_block(current, data);
                return;
            }
        }
        if (current->data < data)
        {
            if (current->right != NULL)
            {
                current = current->right;
                continue;
            }
            else if (current->right == NULL)
            {
                current->right = add_block(current, data);
                return;
            }
        }
        return;
    }
}

LIST* find_min(LIST* current)
{
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

LIST* find_max(LIST* current)
{
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}


LIST* find_data(int data, LIST* current)
{
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        else if (current->data > data)
        {
            current = current->left;
            continue;
        }
        else if (current->data < data)
        {
            current = current->right;
            continue;
        }
    }
    return NULL;
}


void delete_block(LIST* current)
{
    if (current == NULL)
    {
        return;
    }
    if (current->right == NULL && current->left == NULL)
    {
        if (current->parent == NULL)
        {
            list = NULL;
            return;
        }
        if (current->parent->left == current)
        {
            current->parent->left = NULL;
        }
        else if (current->parent->right == current)
        {
            current->parent->right = NULL;
        }
    }
    else if (current->left != NULL && current->right == NULL)
    {
        if (current->parent == NULL)
        {
            LIST* tmp = current->left;
            current->data = tmp->data;
            current->left = tmp->left;
            current->right = tmp->right;
            current = tmp;
        }
        else if (current->parent->left == current)
        {
            current->parent->left = current->left;
            current->left->parent = current->parent;
        }
        else if (current->parent->right == current)
        {
            current->parent->right = current->left;
            current->left->parent = current->parent;
        }
    }
    else if (current->left == NULL && current->right != NULL)
    {
        if (current->parent == NULL)
        {
            LIST* tmp = current->right;
            current->data = tmp->data;
            current->left = tmp->left;
            current->right = tmp->right;
            current = tmp;
        }
        else if (current->parent->left == current)
        {
            current->parent->left = current->right;
            current->right->parent = current->parent;
        }
        else if (current->parent->right == current)
        {
            current->parent->right = current->right;
            current->right->parent = current->parent;
        }
    }
    else if (current->left != NULL && current->right != NULL)
    {
        LIST* localMax = find_max(current->left);
        current->data = localMax->data;
        delete_block(localMax);
        return;
    }
    free(current);
}

void deleteValue(LIST* root, int value)
{
    LIST* target = find_data(value, root);
    delete_block(target);
}

void printTree(LIST* root, const char* dir, int level)
{
    if (root)
    {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        printTree(root->left, "left", level + 1);
        printTree(root->right, "right", level + 1);
    }
}

void file_read(FILE* fp)
{
    char res;
    char prev;
    res = getc(fp);
    prev = res;
    while (res != '=')
    {
        res = getc(fp);
    }
    res = getc(fp);
    if (res == ' ')
    {
        return;
    }
    list = add_block(NULL, 0);
    while (res != EOF)
    {
        while (res != '(' && res != ')' && res != EOF)
        {
            prev = res;
            res = getc(fp);
        }
        if (res == '(')
        {
            if (prev != ')')
            {
                list->left = add_block(list, 0);
                list = list->left;
            }
            if (prev == ')')
            {
                list->right = add_block(list, 0);
                list = list->right;
            }
        }
        if (res == ')')
        {
            list = list->parent;
        }
        prev = res;
        res = getc(fp);
    }
}
