#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long

using namespace std;

const double eps = 1e-8;
const int MAXN = (int)1e5 + 5;
const LL MOD = 1000000007;

int m, n, t;
char map[8][8];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int ex, ey, sx, sy, ok;

void dfs(int x, int y, int cnt)
{
	if (cnt == t)
	{
		if (ex == x && ey == y)
		{
			ok = 1;
		}
		return ;
	}
	if (ok)
	{
		return;
	}
	int temp = abs(x-ex) + abs(y-ey) - abs(cnt - t);//剪枝2：（（（（要点））））
    //奇偶性剪枝 ，起点和终点确定以后就可以确定走的步数是奇数还是偶数，通过这个特点来剪枝
    if(temp > 0|| temp & 1)
    {
    	return;//temp&1相当于temp%2，运算位。
    }
	for (int i = 0; i < 4; ++i)
	{
		int fx = x + dir[i][0];
		int fy = y + dir[i][1];
		if (fx >= 0 && fx < n && fy >=0 && fy < m && map[fx][fy] != 'X')
		{
			map[fx][fy] = 'X';
			dfs(fx, fy, cnt + 1);
			map[fx][fy] = '.';
		}
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	while(~scanf("%d%d%d", &n, &m, &t) && (m || n || t))
	{
		int wall = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", map[i]);
			for (int j = 0; map[i][j] != '\0'; ++j)
			{
				if (map[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if (map[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
				else if (map[i][j] == 'X')
				{
					wall++;
				}
			}
		}
		//if(m*n-wall<=t) printf("NO\n");
		// if (abs(sx - ex) + abs(sy - ey) > t || (sx + sy + ex + ey + t) % 2 == 1)
		// {
		// 	printf("No\n"); //奇偶剪枝；
		// }
		//else
		//{
			ok = 0;
			map[sx][sy] = 'X';
			dfs(sx, sy, 0);
			if (ok)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		//}
	}
	return 0;
}