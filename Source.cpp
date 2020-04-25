#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <malloc.h>
#include <conio.h>

void inverStr(char* string)
{
	setlocale(LC_ALL, "Rus");
	printf("¬ведите строку с инвертируемыми парными фрагментами: ");
	fgets(string, 1000, stdin);
}

int StrLen(const char* Str)
{
	int i;
	for (i = 0; *Str++; i++);
	return i;
}

void Putsn(const char* Str, int Len1)
{
	while (Len1--)
		putchar(*Str++);
}

int SearchInvar(char* Str, char** strFore, char** strBack)
{
	char* fore = Str, * back = Str + StrLen(Str) - 1;
	*strFore = *strBack = NULL;
	int len = 0;
	bool find = false;
	while (fore < back)
	{
		int i = 0;
		while ((*fore == *back) && (fore <= back))
		{
			fore++;
			back--;
			i++;
		}
		if (len < i - 1)
		{
			*strFore = Str;
			*strBack = back + 1;
			len = i;
			find = true;
		}
		else
			back--;
		fore = Str;
	}
	return len;
}

int main(int argc, char** argv)
{
	char* s = (char*)malloc(1000 * sizeof(char));
	inverStr(s);
	char* inverStr(s);
	char* tempStr = inverStr;
	char* fore, * back;
	puts(tempStr);
	while (*tempStr)
	{
		int len = SearchInvar(tempStr, &fore, &back);
		if (len)
		{
			Putsn(fore, len);
			putchar(' ');
			Putsn(back, len);
			putchar('\n');
			tempStr += len;
		}
		else
			tempStr++;
	}
	_getch();
	return 0;
}