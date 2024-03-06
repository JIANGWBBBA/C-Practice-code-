#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//ͨѶ¼
#include <string.h>
#define MAX 100
#include <assert.h>
#define Default 3
#define enlarge 2
enum Option
{
	exit,
	add,
	delete,
	search,
	modify,
	show,
	sort
};//���ӿɶ���
void menu()
{
	printf("*****************************\n");
	printf("*****1.add     2.delete  ****\n");
	printf("*****3.search  4.modify  ****\n");
	printf("*****5.show    6.sort    ****\n");
	printf("*****0.exit       ***********\n");
	printf("*****************************\n");

}
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;
void InitContact(Contact* pc)
{
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(Default, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	pc->capacity = Default;
}
void Add(Contact* pc)
{
	assert(pc);

	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + enlarge) * sizeof(PeoInfo));
		if (ptr != NULL)
			pc->data = ptr;
		pc->capacity += enlarge;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->count].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
}
int Find(const Contact* pc, char* name)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;

	}
	return -1;
}
void Del(Contact* pc)
{
	assert(pc);
	printf("������Ҫɾ���˵�����\n");
	char name[20] = { 0 };
	scanf("%s", name);
	//������
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("������\n");
		return;
	}
	//ɾ��fv12a3Q	1
	int i = 0;
	for (i = ret; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
}
void Show(const Contact* pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%s %d %s %s %s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}
void Search(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("����������˵�����\n");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("�����ڸ���ϵ��\n");
		return;
	}
	printf("%s %d %s %s %s\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}
void Modify(Contact* pc)
{
	printf("������Ҫ�޸��˵�����\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = Find(pc, name);
	scanf("%d %s %s %s", pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void Sort(Contact* pc)
{
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_name);
}
int main()
{
	int input = 0;
	Contact Con;
	InitContact(&Con);
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add(&Con);
			break;
		case delete:
			Del(&Con);
			break;
		case search:
			Search(&Con);
			break;
		case modify:
			Modify(&Con);
			break;
		case show:
			Show(&Con);
			break;
		case sort:
			Sort(&Con);
			break;
		case exit:
			free(Con.data);
			Con.data = NULL;
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}