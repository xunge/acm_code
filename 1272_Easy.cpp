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
bool circle;         //判断是否存在环
bool visit[MAXN];    //用来记录顶点数
int endgenum, vnum;  //边数 顶点数

void initial()
{
	for (int i = 0; i < MAXN; ++i)
	{
		father[i] = i;
		visit[i] = false;
	}
	circle = false;
	endgenum = vnum = 0;
}

int find(int x)
{
	return x == father[x] ? x : father[x] = find(father[x]);   //找祖先节点 + 路径压缩
}

void merge(int a, int b)
{
	if (a == b)
	{
		circle = true;
	}
	int x;
	int y;
	x = find(a);
	y = find(b);
	if (x != y)
	{
		father[x] = y;
		endgenum++;      //引出一条边
	}
	else
	{
		circle = true;   //x == y 说明他们是同一个祖先，一旦连通便与祖先3者成环   
	}
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	while(true)
	{
		initial();
		scanf("%d%d", &a, &b);
		if (a == 0 && b == 0)
		{
			printf("Yes\n");
			continue;
		}
		if (a == -1 && b == -1)
		{
			break;
		}
		visit[a] = true;
		visit[b] = true;
		merge(a, b);
		while(true)
		{
			scanf("%d%d", &a, &b);
			if (a == 0 && b == 0)
			{
				break;
			}
			visit[a] = true;
			visit[b] = true;
			merge(a, b);
		}
		for (int i = 0; i < MAXN; ++i)
		{
			if (visit[i])
			{
				vnum++;
			}
		}
		if (!circle && endgenum + 1 == vnum)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}