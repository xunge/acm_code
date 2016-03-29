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
int n = 1;
int father[MAXN];    //记录父节点
bool circle;         //判断是否存在环
int visit1[MAXN];    //用来记录顶点数
bool visit[MAXN];
int endgenum, vnum;  //边数 顶点数

void initial()
{
	for (int i = 0; i < MAXN; ++i)
	{
		father[i] = i;
		visit[i] = false;
		visit1[i] = 0;
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

	//memset(visit1, 0, sizeof(visit1))
	while(true)
	{
		initial();
		scanf("%d%d", &a, &b);
		if (a == 0 && b == 0)
		{
			printf("Case %d is a tree.\n", n);
			n++;
			continue;
		}
		if (a < 0 && b < 0)
		{
			break;
		}
		visit[a] = true;
		visit[b] = true;
		visit1[b]++;
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
			visit1[b]++;
			merge(a, b);
		}
		for (int i = 0; i < MAXN; ++i)
		{
			if (visit[i])
			{
				vnum++;
			}
			if (visit1[i] == 2)
			{
				circle = true;
			}
		}
		if (!circle && endgenum + 1 == vnum)
		{
			printf("Case %d is a tree.\n", n);
		}
		else
		{
			printf("Case %d is not a tree.\n", n);
		}
		n++;
	}
	return 0;
}