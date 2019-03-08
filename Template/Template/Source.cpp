#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <string>

using namespace::std;

char word[20];

char tab[105][105];
int down[105][105];
int rt[105][105];
int rd[105][105];
struct _THUNDER {
	int iVersion;
	char cTag;
	char cAdv;
	int iUser;
	char cEnd;
}Thunder;

int main()
{
	
	int a[5] = { 1,2,3,4,5 };
	int *ptr = (int *)(&a + 1);
	cout <<a<< &a << endl;
	system("pause");
}