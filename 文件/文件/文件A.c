#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()//д�ļ�  FILE* fputc("char*","FILE*")
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
int main()//׷�� FILE* fputs("char*","FILE*") 
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
int main()//���ļ�  char fputc(FILE*)
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
int main()//���ַ��� fgets(char*str,int num,FILE*) ֻ��һ��
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
int main()//��ʽ�����
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
int main()//��ʽ������
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
int main()//��������д
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
int main()//�����ƶ�
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
int main()//ת���ַ���
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