#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//通讯录
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
};//增加可读性
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
	printf("请输入名字\n");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址\n");
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
	printf("请输入要删除人的名字\n");
	char name[20] = { 0 };
	scanf("%s", name);
	//查找人
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("不存在\n");
		return;
	}
	//删除fv12a3Q	1
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
	printf("请输入查找人的姓名\n");
	scanf("%s", name);
	int ret = Find(pc, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
		return;
	}
	printf("%s %d %s %s %s\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}
void Modify(Contact* pc)
{
	printf("请输入要修改人的名字\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int ret = Find(pc, name);
	scanf("%d %s %s %s", pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
	printf("修改成功\n");
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
		printf("请选择>\n");
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
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}