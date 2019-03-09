#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace::std;




class State
{
public:
	int p_x;
	int p_y;
	int b_x;
	int b_y;
	int step;
	State(int a, int b, int c, int d,int e)
		:p_x(a), p_y(b), b_x(c), b_y(d),step(e)
	{

	}
};

int main()
{
	char map[15][15];
	int n, m;
	queue<State*> que;
	int start_p_x, start_p_y, start_b_x, start_b_y,dest_x,dest_y;
	bool isVis[15][15][15][15];
	while (cin >> n >> m)
	{
		//initial
		bool hasAns = false;
		while (!que.empty())
		{
			delete que.front();
			que.pop();
		}
		memset(isVis, 0, sizeof(isVis));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char c;
				cin >> c;
				if (c == 'X')
				{
					start_p_x = i;
					start_p_y = j;
					map[i][j] = '.';
				}
				else if (c == '*')
				{
					start_b_x = i;
					start_b_y = j;
					map[i][j] = '.';
				}
				else if (c == '@')
				{
					dest_x = i;
					dest_y = j;
					map[i][j] = '.';
				}
				else if(c == '#') {
					map[i][j] = '#';
				}
				else{
					map[i][j] = '.';
				}
			}
		}
		State *s1 = new State(start_p_x, start_p_y, start_b_x, start_b_y, 0);
		que.push(s1);
		isVis[start_p_x][start_p_y][start_b_x][start_b_y] = true;
		
		while (!que.empty())
		{
			State *nowp=que.front();
			que.pop();
			if (nowp->b_x == dest_x && nowp->b_y == dest_y)
			{
				cout<< nowp->step<<endl;
				hasAns = true;
				break;
			}
			int ptox, ptoy, btox, btoy;
			//left one
			ptox = nowp->p_x;
			ptoy = nowp->p_y - 1;
			btox = nowp->b_x;
			btoy = nowp->b_y - 1;
			if (ptoy >= 0)
			{
				//走后与箱子重叠
				if (ptox == nowp->b_x&&ptoy == nowp->b_y)
				{
					//推动箱子
					if (btoy >= 0 && map[btox][btoy] == '.')
					{
						if (!isVis[ptox][ptoy][btox][btoy])
						{
							que.push(new State(ptox, ptoy, btox, btoy, nowp->step + 1));
							isVis[ptox][ptoy][btox][btoy] = true;
						}
					}
				}
				//走后不与箱子重叠
				else
				{
					//可以到达
					if (map[ptox][ptoy] == '.')
					{
						if (!isVis[ptox][ptoy][nowp->b_x][nowp->b_y])
						{
							que.push(new State(ptox, ptoy, nowp->b_x, nowp->b_y, nowp->step + 1));
							isVis[ptox][ptoy][nowp->b_x][nowp->b_y] = true;
						}
					}
				}
			}
			//right one
			ptox = nowp->p_x;
			ptoy = nowp->p_y + 1;
			btox = nowp->b_x;
			btoy = nowp->b_y + 1;
			if (ptoy < m)
			{
				//走后与箱子重叠
				if (ptox == nowp->b_x&&ptoy == nowp->b_y)
				{
					//推动箱子
					if (btoy < m && map[btox][btoy] == '.')
					{
						if (!isVis[ptox][ptoy][btox][btoy])
						{
							que.push(new State(ptox, ptoy, btox, btoy, nowp->step + 1));
							isVis[ptox][ptoy][btox][btoy] = true;
						}
					}
				}
				//走后不与箱子重叠
				else
				{
					//可以到达
					if (map[ptox][ptoy] == '.')
					{
						if (!isVis[ptox][ptoy][nowp->b_x][nowp->b_y])
						{
							que.push(new State(ptox, ptoy, nowp->b_x, nowp->b_y, nowp->step + 1));
							isVis[ptox][ptoy][nowp->b_x][nowp->b_y] = true;
						}
					}
				}
			}
			//up one
			ptox = nowp->p_x - 1;
			ptoy = nowp->p_y;
			btox = nowp->b_x - 1;
			btoy = nowp->b_y;
			if (ptox >= 0)
			{
				//走后与箱子重叠
				if (ptox == nowp->b_x&&ptoy == nowp->b_y)
				{
					//推动箱子
					if (btox >= 0 && map[btox][btoy] == '.')
					{
						if (!isVis[ptox][ptoy][btox][btoy])
						{
							que.push(new State(ptox, ptoy, btox, btoy, nowp->step+1));
							isVis[ptox][ptoy][btox][btoy] = true;
						}
					}
				}
				//走后不与箱子重叠
				else
				{
					//可以到达
					if (map[ptox][ptoy] == '.')
					{
						if (!isVis[ptox][ptoy][nowp->b_x][nowp->b_y])
						{
							que.push(new State(ptox, ptoy, nowp->b_x, nowp->b_y, nowp->step + 1));
							isVis[ptox][ptoy][nowp->b_x][nowp->b_y] = true;
						}
					}
				}
			}

			//down one
			ptox = nowp->p_x + 1;
			ptoy = nowp->p_y;
			btox = nowp->b_x + 1;
			btoy = nowp->b_y;
			if (ptox < n)
			{
				//走后与箱子重叠
				if (ptox == nowp->b_x&&ptoy == nowp->b_y)
				{
					//推动箱子
					if (btox <n && map[btox][btoy] == '.')
					{
						if (!isVis[ptox][ptoy][btox][btoy])
						{
							que.push(new State(ptox, ptoy, btox, btoy, nowp->step + 1));
							isVis[ptox][ptoy][btox][btoy] = true;
						}
					}
				}
				//走后不与箱子重叠
				else
				{
					//可以到达
					if (map[ptox][ptoy] == '.')
					{
						if (!isVis[ptox][ptoy][nowp->b_x][nowp->b_y])
						{
							que.push(new State(ptox, ptoy, nowp->b_x, nowp->b_y, nowp->step + 1));
							isVis[ptox][ptoy][nowp->b_x][nowp->b_y] = true;
						}
					}
				}
			}
			


			delete nowp;
		}
		while(!hasAns)
			cout << -1 << endl;		
	}

}