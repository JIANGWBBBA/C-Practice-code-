#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//链表
#include <stdlib.h>
#include <string.h>
struct Node
{
	char name[20];
	long num;
	struct Node* Next;
};
struct Node* creat(struct Node*);
struct Node* insert(struct Node*, struct Node*);
struct Node* delete(struct Node*, long num);
int main()
{
	struct Node* head = NULL, * p = NULL;
	head = creat(head);
	if (head == NULL)
	{
		printf("建立链表错误\n");
		return -1;
	}
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(node->name, "张san");
	node->num = 3;
	head = insert(head, node);
	long n = 4;
	head = insert(head, n);
	p = head;
	printf("输出\n");
	while (p->Next)
	{
		printf("%s %ld\n", p->name, p->num);
		p = p->Next;
	}
    free(head);
    head = NULL;
	return 0;
}
struct Node* creat(struct Node* head)
{
	struct Node* newnode = NULL;
	struct Node* q = NULL;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	scanf("%s %ld", newnode->name, &newnode->num);
	head = q = newnode;
	while (newnode->num > 0)
	{
		newnode = (struct Node*)malloc(sizeof(struct Node));
		scanf("%s %ld", newnode->name, &newnode->num);
		q->Next = newnode;
		q = q->Next;
	}
	q->Next = NULL;
	return head;
}
//插入链表
struct Node* insert(struct Node* head, struct Node* node)
{
	struct Node* p = head;
	struct Node* pre = p;
	while (p != NULL)
	{
		if (p->num < node->num)
		{
			pre = p;
			p = p->Next;
		}
		else if (p->num == node->num)
		{
			printf("已存在该信息\n");
			return head;
		}
		else
			break;
	}
	if (p == head)
	{
		node->Next = p;
		head = node;
	}
	else
	{
		pre->Next = node;
		node->Next = p;
	}
	return head;
}
//链表的删除
struct Node* delete(struct Node* head, long num)
{
	struct Node* p = head;
	struct Node* pre = p;
	if (head == NULL)
	{
		return head;
	}
	while (p != NULL)
	{
		if (p->num < num)
		{
			pre = p;
			p = p->Next;
		}
		else
			break;
	}
	if (p == head)
	{
		head = p->Next;
	}
	else if (p->Next != NULL)
	{
		pre->Next = p->Next;
	}
	else
		pre->Next = NULL;
	if (p == NULL);
	printf("Not exist\n");
	return head;
}