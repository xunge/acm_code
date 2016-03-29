#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long

using namespace std;

const double eps = 1e-8;
const int MAXN = (int)1001;
const LL MOD = 1000000007;

int n, m;

struct Rice
{
	int price;
	int weight;
	int number;
} rice[MAXN];

int dp[MAXN];

//完全背包
void CompletePack(int cost, int weight)
{
	for (int i = cost; i <= n; ++i)
	{
		dp[i] = max(dp[i], dp[i - cost] + weight);
	}
}

//01背包
void ZeroOnePack(int cost, int weight)
{
	for (int i = n; i >=cost; --i)
	{
		dp[i] = max(dp[i], dp[i - cost] + weight);
	}
}

//多重背包
void MultiplePack(int cost, int weight, int number)
{
	//如果大于等于金额，就按完全背包处理（此时相当于不限定袋数）
	if (cost * number >= n)
	{
		CompletePack(cost, weight);
		return ;
	}
	int k = 1;
	while(k  < number)
	{
		ZeroOnePack(k * cost, k * weight);
		number -= k;
		k *= 2;
	}
	ZeroOnePack(number * cost, number * weight);
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d",&n, &m);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &rice[i].price, &rice[i].weight, &rice[i].number);
		}
		for (int i = 0; i < m; ++i)
		{
			MultiplePack(rice[i].price, rice[i].weight, rice[i].number);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}