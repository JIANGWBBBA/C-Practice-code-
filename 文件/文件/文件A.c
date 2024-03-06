#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()//写文件  FILE* fputc("char*","FILE*")
{
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	char i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		fputc(i ,pf);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()//追加 FILE* fputs("char*","FILE*") 
{
	FILE* pf = fopen("text.txt", "a");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	fputs("\nhello A", pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()//读文件  char fputc(FILE*)
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	char ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c\n", ch);

	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()//读字符串 fgets(char*str,int num,FILE*) 只读一行
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	char arr[100] = { 0 };
	fgets(arr, 100, pf);
	printf("%s", arr);
	fclose(pf);
	pf = NULL;
	return 0;
//}
struct stu
{
	char name[20];
	int num;
	float score;
};
int main()//格式化输出
{
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	struct stu s = { "zhangsan",1,99.99f };
	fprintf(pf, "\n%s %d %.2f", s.name, s.num, s.score);
	fclose(pf);
	pf = NULL;
	return 0;
}
struct stu
{
	char name[20];
	int num;
	float score;
};
int main()//格式化输入
{
	struct stu s = { 0 };
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	fscanf(pf, "%s %d %f", s.name,& s.num,& s.score);
	printf("%s %d %.2f", s.name, s.num, s.score);
	return 0;
}
struct stu
{
	char name[20];
	int num;
	float score;
};
int main()//二进制书写
{
	struct stu s = { "zhangsan",1,99.99 };
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	fwrite(&s, sizeof(struct stu), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
struct stu
{
	char name[20];
	int num;
	float score;
};
int main()//二进制读
{
	struct stu s = { 0 };
	FILE* pf = fopen("text.txt", "rb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	fread(&s, sizeof(struct stu), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
struct stu
{
	char name[20];
	int num;
	float score;
};
int main()//转化字符串
{
	struct stu s = { "zhangsan",1,99.99 };
	char buf[100] = { 0 };
	struct stu tmp = { 0 };
	sprintf(buf, "%s %d %.2f", s.name, s.num, s.score);
	printf("%s\n", buf);
	sscanf(buf, "%s %d %f", tmp.name, &tmp.num,&tmp.score);
	printf("%s %d %.2f", tmp.name, tmp.num, tmp.score);
	return 0;
}