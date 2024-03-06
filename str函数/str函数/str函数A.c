#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char* My_strcpy(char* target, char* start)
{
	char* p = target; //¼ÇÂ¼ÆğÊ¼µØÖ·
	while (*target++ = *start++);
	return p;
}
int main()
{
	char arr[20] = { 0 };
	char str[] = "abcdef";
	My_strcpy(arr, str);
	printf("%s", arr);
	return 0;
}
#include <string.h>
int main()
{
	char arr[20] = "Hello ";
	strcat(arr, "A");//×·¼Ó×Ö·û´®
	printf("%s", arr);
	return 0;
}
#include <assert.h>
char* My_strcat(char* target, char* start)

{
	assert(target && start);
	char* tmp = start;
	while (*target != '\0')
	{
		target++;
	}
	while (*target++ = *start++);
	return tmp;
}
int main()
{
	char arr[20] = "Hello ";
	char str[20] = "A!";
	My_strcat(arr, str);
	printf("%s", arr);
	return 0;
}
#include <stdio.h>
int My_strcmp(char* parr, char* pstr)
{
	while (*parr++ && *pstr++)
	{
		if (*parr > *pstr)
		{
			return 1;
			break;
		}
		else if (*parr < *pstr)
		{
			return -1;
			break;
		}
	}
	return 0;
}
int main()
{
	char arr[20] = "abcdef";
	char str[20] = "abq";
	int ret = My_strcmp(arr, str);
	printf("%d", ret);

	return 0;

}
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[20] = "AAAAA AAA";
	char str[20] = "Hello hh";
	strncpy(arr, str, 5);
	printf("%s", arr);
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char emil[20] = "zpw.bitejiuyeke";
	char str[20] = "bitejiuyeke";
	char* ret = strstr(emil, str);
	if (ret == NULL)
	{
		printf("×Ö·û´®²»´æÔÚ\n");
	}
	else
	{
		printf("%s", ret);
	}
	return 0;
}
#include <stdio.h>//Ñ°ÕÒ
#include <assert.h>
char* My_strstr(const char* arr, const char* str)
{
	assert(arr && str);
	char* flag = arr;
	char* parr = arr;
	char* pstr = str;
	while (*flag)
	{
		parr = flag;
		pstr = str;
		while (*parr == *pstr && *parr != '\0' && *pstr != '\0')
		{
			parr++;
			pstr++;
		}
		if (*pstr == '\0')
			return str;
		flag++;
	}
	return NULL;
}
int main()
{
	char arr[20] = "aaabbc";
	char str[20] = "aab";
	char* p = My_strstr(arr, str);
	printf("%s", p);
	return 0;
}
#include <string.h>
int main()
{
	char email[20] = "1269938269@qq.com";
	char sep[10] = "@.";
	char cpy[20] = { 0 };
	strcpy(cpy, email);
	char* ret = strtok(cpy, sep);
	printf("%s\n", ret);
	ret = strtok(NULL, sep);
	printf("%s\n", ret);
	ret = strtok(NULL, sep);
	printf("%s", ret);
	return 0;
}
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int str[20] = { 0 };
	int sz = sizeof(arr);
	memcpy(str, arr, sz);
	return 0;
}
void My_memcpy(void* target, const void* giver, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		*(char*)target = *(char*)giver;
		target = (char*)target + 1;
		giver = (char*)giver + 1;

	}
}
int main()
{
	char arr[] = { 'a','b','c' };
	char str[10] = { 0 };
	int sz = sizeof(arr);
	My_memcpy(str, arr, sz);
	return 0;
}
#include <stdio.h>
void* My_memomove(void* dest, const void* giver, int sz)
{

	if (dest < giver)
	{
		while (sz--)
		{
			*(char*)dest = *(char*)giver;
			dest = (char*)dest + 1;
			giver = (char*)giver + 1;

		}
	}
	else
	{
		while (sz--)
		{
			*((char*)dest + sz) = *((char*)giver + sz);
		}
	}

}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	My_memomove(arr + 2, arr, 16);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	memset(arr, 'a', 5);
	printf("%s", arr);
	return 0;
}