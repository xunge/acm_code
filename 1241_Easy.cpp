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
int m, n;
int dir[8][2] = {{1, 0}, {1, -1}, {1, 1}, {0, -1}, {0, 1}, {-1, 0}, {-1, -1}, {-1, 1}};

void dfs(int x, int y)
{
	int fx, fy;
	for (int i = 0; i < 8; ++i)
	{
		fx = x + dir[i][0];
		fy = y + dir[i][1];
		if (fx >= 0 && fx < n && fy >= 0 && fy < m && map[fx][fy] == '@')
		{
			map[fx][fy] = '*';
			dfs(fx, fy);
		}
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	while(~scanf("%d%d", &n, &m) && n && m)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", map[i]);
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (map[i][j] == '@')
				{
					map[i][j] = '*';
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}