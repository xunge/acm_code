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

int a, b;
int father[MAXN];    //记录父节点
int num[MAXN];

void initial()
{
	for (int i = 1; i <= MAXN; ++i)
	{
		father[i] = i;
		num[i] = 1;
	}
}

int find(int x)
{
	return x == father[x] ? x : father[x] = find(father[x]);   //找祖先节点 + 路径压缩
}

void merge(int a, int b)
{
	int x;
	int y;
	x = find(a);
	y = find(b);
	if (x != y)
	{
		father[x] = y;
		num[x] += num[y];
		num[y] = num[x];
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int n, max;
	while(~scanf("%d", &n))
	{
		if (n == 0)
		{
			printf("1\n");
			continue;
		}
		max = 0;
		initial();
		while(n--)
		{
			scanf("%d%d", &a, &b);
			if (a > max)
			{
				max = a;
			}
			if (b > max)
			{
				max = b;
			}
			merge(a, b);
		}
		int MAX = 0;
		for (int i = 1; i <= max; ++i)
		{
			if (num[i] > MAX)
			{
				MAX = num[i];
			}
			//printf("%d\n", num[i]);
		}
		printf("%d\n", MAX);
	}
	return 0;
}