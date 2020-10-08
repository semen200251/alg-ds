#include "List.h" 
int write(FILE* fp, LIST* List)
{
	
	char reade[101];
	List->next = NULL;
	int count_runs = 0;
	LIST* current;
	LIST* prew;
	while (fgets(reade, 100, fp) != NULL)
		{
			int longl = strlen(reade);
			if (count_runs == 0)
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
				}
				else
				{
					NewBlock->next = current;
					prew->next = NewBlock;
				}
			}
			count_runs++;
		}
	if (count_runs == 0)
	{
		List->data[0]='\0';
	}
	return 0;
}

int merger(LIST* List1, LIST* List2)
{
	LIST* current_List2;
	LIST* prev_List2;
	LIST* current_List1;
	current_List1 = List1;
	while (current_List1 != NULL)
	{
		if (current_List1->data[0] != '\0')
		{
			char auxiliary_array[100];
			LIST* NewBlock = (LIST*)malloc(sizeof(LIST));
			current_List2 = List2;
			prev_List2 = current_List2;
			if (current_List2->data[0] == '\0')
			{
				List2 = List1;
				break;
			}
			while (current_List2 != NULL && strcmp(current_List2->data, current_List1->data) < 0)
			{
				prev_List2 = current_List2;
				current_List2 = current_List2->next;
			}
			for (unsigned int i = 0; i < strlen(current_List1->data); i++)
			{
				NewBlock->data[i] = current_List1->data[i];
			}
			NewBlock->data[strlen(current_List1->data)] = '\0';
			if (current_List2 == List2)
			{

				for (unsigned int i = 0; i < strlen(current_List1->data); i++)
				{
					auxiliary_array[i] = List2->data[i];
					List2->data[i] = NewBlock->data[i];
					NewBlock->data[i] = auxiliary_array[i];
					
				}
				NewBlock->next = List2->next;
				List2->next = NewBlock;
			}
			else {
				NewBlock->next = current_List2;
				prev_List2->next = NewBlock;

			}
		}
			current_List1 = current_List1->next;
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