#include "pch.h"
#include "C:/Users/semen/source/repos/Project1/Project1/func.c"

TEST(write, normal) {
	FILE* fp = fopen("test1.txt", "r");
	LIST* Test = (LIST*)malloc(sizeof(LIST));
	write(fp, Test);
	ASSERT_EQ(strcmp(Test->data, "arbuz\n"), 0);
	ASSERT_EQ(strcmp(Test->next->data, "banan\n"), 0);
    ASSERT_EQ(strcmp(Test->next->next->data, "coc\n"), 0);
	ASSERT_EQ(strcmp(Test->next->next->next->data, "prikol\n"), 0);
	free_list(Test);
}

TEST(write, EmptyFile) {
	FILE* fp2 = fopen("test6.txt", "r");
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp2, Test2);
	ASSERT_EQ(Test2->data[0], '\0');
	free_list(Test2);
}

TEST(write, SameStr) {
	FILE* fp = fopen("test5.txt", "r");
	LIST* Test = (LIST*)malloc(sizeof(LIST));
	write(fp, Test);
	ASSERT_EQ(strcmp(Test->data, "arbuz\n"), 0);
	ASSERT_EQ(strcmp(Test->next->data, "banan\n"), 0);
	ASSERT_EQ(strcmp(Test->next->next->data, "banan\n"), 0);
	ASSERT_EQ(strcmp(Test->next->next->next->data, "coc\n"), 0);
	ASSERT_EQ(strcmp(Test->next->next->next->next->data, "prikol\n"), 0);
	ASSERT_EQ(strcmp(Test->next->next->next->next->next->data, "prikol\n"), 0);
	free_list(Test);
}

TEST(merge, normal) {
	FILE* fp1 = fopen("test31.txt", "r");
	FILE* fp2 = fopen("test32.txt", "r");
	LIST* Test1 = (LIST*)malloc(sizeof(LIST));
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp1, Test1);
	write(fp2, Test2);
	merger(Test1, Test2);
	ASSERT_EQ(strcmp(Test2->data,"abc\n"),0);
	ASSERT_EQ(strcmp(Test2->next->data, "acd\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->data, "bad\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->data, "dog\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->next->data, "kis\n"), 0);
	free_list(Test1);
	free_list(Test2);
}

TEST(merge, EmptyList1) {
	FILE* fp1 = fopen("test6.txt", "r");
	FILE* fp2 = fopen("test32.txt", "r");
	LIST* Test1 = (LIST*)malloc(sizeof(LIST));
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp1, Test1);
	write(fp2, Test2);
	merger(Test1, Test2);
	ASSERT_EQ(strcmp(Test2->data, "abc\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->data, "kis\n"), 0);
	free_list(Test1);
	free_list(Test2);
}

TEST(merge, EmptyList2) {
	FILE* fp1 = fopen("test6.txt", "r");
	FILE* fp2 = fopen("test32.txt", "r");
	LIST* Test1 = (LIST*)malloc(sizeof(LIST));
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp1, Test1);
	write(fp2, Test2);
	merger(Test1, Test2);
	ASSERT_EQ(strcmp(Test2->data, "abc\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->data, "kis\n"), 0);
	free_list(Test1);
	free_list(Test2);
}

TEST(merge, EmptyList1AndList2) {
	FILE* fp1 = fopen("test6.txt", "r");
	FILE* fp2 = fopen("test7.txt", "r");
	LIST* Test1 = (LIST*)malloc(sizeof(LIST));
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp1, Test1);
	write(fp2, Test2);
	merger(Test1, Test2);
	ASSERT_EQ(Test2->data[0], '\0');
	free_list(Test1);
	free_list(Test2);
}

TEST(merge, SameStr) {
	FILE* fp1 = fopen("test3.txt", "r");
	FILE* fp2 = fopen("test4.txt", "r");
	LIST* Test1 = (LIST*)malloc(sizeof(LIST));
	LIST* Test2 = (LIST*)malloc(sizeof(LIST));
	write(fp1, Test1);
	write(fp2, Test2);
	merger(Test1, Test2);
	ASSERT_EQ(strcmp(Test2->data, "afas\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->data, "afas\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->data, "gdsg\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->data, "gdsh\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->next->data, "gdsh\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->next->next->data, "tew\n"), 0);
	ASSERT_EQ(strcmp(Test2->next->next->next->next->next->next->data, "tew\n"), 0);
	free_list(Test1);
	free_list(Test2);
}