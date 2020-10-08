#include "List.h" 
int write(FILE* fp, LIST* List)
{
	
	char reade[101];
	/*if (fgets(reade, 100, fp) == NULL)
	{
		free(List);
		return 0;
	}*/
	//List->data[0] = '\n'; 
	//List = (LIST*)malloc(sizeof(LIST)); 
	List->next = NULL;
	int d = 0;
	LIST* current;
	LIST* prew;
	while (fgets(reade, 100, fp) != NULL)
		{
			int longl = strlen(reade);
			if (d == 0)
			{
				for (unsigned int i = 0; i < strlen(reade); i++)
				{
					List->data[i] = reade[i];
				}
				List->data[strlen(reade)] = '\0';
			}
			else {
				current = List;
				prew = current;
				LIST* NewBlock = (LIST*)malloc(sizeof(LIST));
				if (NewBlock == NULL)
				{
					return -1;
				}
				while (current != NULL && strcmp(current->data, reade) < 0)
				{
					prew = current;
					current = current->next;
				}
				for (unsigned int i = 0; i < strlen(reade); i++)
				{
					NewBlock->data[i] = reade[i];
				}
				/*if (NewBlock->data[strlen(reade)] != '\n')
				{
					NewBlock->data[strlen(reade)] = '\n';
				}*/
				NewBlock->data[strlen(reade)] = '\0';
				if (current == List)
				{
					for (unsigned int i = 0; i <= strlen(reade); i++)
					{
						reade[i] = List->data[i];
						List->data[i] = NewBlock->data[i];
						NewBlock->data[i] = reade[i];
					}
					NewBlock->next = List->next;
					List->next = NewBlock;
					List->data[longl - 1] = '\n';
					List->data[longl] = '\0';
					//NewBlock->data[strlen(reade)] = '\0';
				}
				else
				{
					NewBlock->next = current;
					prew->next = NewBlock;
				}
			}
			d++;
		}
	if (d == 0)
	{
		List->data[0]='\0';
	}
		//tmp = tmp->next; 
		/*while (List != NULL)
		{
		int i = 0;
		while (List->data[i] != '\n')
		{
		printf("%c", List->data[i]);
		i++;
		}
		printf("\n");
		List = List->next;
		}*/
	return 0;
}

int merger(LIST* List1, LIST* List2)
{
	LIST* current;
	LIST* prew;
	LIST* a;

	a = List1;
	//current = List2; 
	//prew->next = current; 
	while (a != NULL)
	{
		if (a->data[0] != '\0')
		{
			char b[100];
			LIST* NewBlock = (LIST*)malloc(sizeof(LIST));
			current = List2;
			prew = current;
			if (current->data[0] == '\0')
			{
				List2 = List1;
				break;
			}
			while (current != NULL && strcmp(current->data, a->data) < 0)
			{
				prew = current;
				current = current->next;
			}
			/*if (current != NULL) {
				if (strcmp(current->data, a->data) == 0)
				{
					a = a->next;
					continue;
				}
			}
			if (current == NULL && strcmp(prew->data, a->data) == 0)
			{
				a = a->next;
				continue;
			}*/
			for (unsigned int i = 0; i < strlen(a->data); i++)
			{
				NewBlock->data[i] = a->data[i];
			}
			NewBlock->data[strlen(a->data)] = '\0';
			if (current == List2)
			{

				for (unsigned int i = 0; i < strlen(a->data); i++)
				{
					b[i] = List2->data[i];
					List2->data[i] = NewBlock->data[i];
					NewBlock->data[i] = b[i];
					//NewBlock->data[strlen(a->data)] = '\n';
				}
				NewBlock->next = List2->next;
				List2->next = NewBlock;
			}
			else {
				NewBlock->next = current;
				prew->next = NewBlock;

			}
		}
			a = a->next;
		}

	return 0;
}

int free_list(LIST* List)
{
	LIST* prew;
	LIST* current;
	current = List->next;
	prew = List;
	while (current != NULL)
	{
		free(prew);
		prew = current;
		current = current->next;
	}
	return 0;
}