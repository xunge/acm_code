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

char map[101][101];
int h, w, cnt;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y)
{
	int fx, fy;
	for (int i = 0; i < 4; ++i)
	{
		fx = x + dir[i][0];
		fy = y + dir[i][1];
		if (fx >= 0 && fx < w && fy >= 0 && fy < h && map[fx][fy] == '#')
		{
			map[fx][fy] = '.';
			dfs(fx, fy);
		}
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		cnt = 0;
		scanf("%d%d", &w, &h);
		for (int i = 0; i < w; ++i)
		{
			scanf("%s", map[i]);
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				if (map[i][j] == '#')
				{
					map[i][j] = '.';
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}