#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dpArray[1020][2];
vector<int> degout[1020];
vector<int> degin[1020];
int n, m;

void top_down(int from)
{
	for (int i = 0; i < degout[from].size(); i++)
	{
		int to = degout[from].at(i);
		top_down(to);
		if (i == 0)
		{
			dpArray[from][1]++;
		}
		dpArray[from][1] += dpArray[to][0];
		dpArray[from][0] += max(dpArray[to][0],dpArray[to][1]);
	}
}

int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dpArray, 0, sizeof(dpArray));
		for (int i = 1; i <= n; i++)
		{
			degout[i].clear();
			degin[i].clear();
		}
		for (int i = 1; i <= m; i++)
		{
			int up, down;
			scanf("%d%d", &up, &down);
			degin[down].push_back(up);
			degout[up].push_back(down);
		}
		for (int i = 1; i <= n; i++)
		{
			if (degout[i].size() == 0)
			{
				dpArray[i][1] = 1;
			}
		}
		int king;
		for (int i = 1; i <= n; i++)
		{
			if (degin[i].size() == 0)
			{
				king = i;
			}
		}
		top_down(king);
		printf("%d\n", dpArray[king][1]);
	}
}