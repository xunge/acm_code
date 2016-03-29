#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long

using namespace std;

const double eps = 1e-8;
const int MAXN = (int)1e7 + 5;
const LL MOD = 1000000007;

int dp[MAXN];
int val[1000], wei[1000];

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int e, f, w;
		scanf("%d%d", &e, &f);
		w = f - e;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &val[i], &wei[i]);
		}
		for (int i = 0; i <= w; ++i)
		{
			dp[i] = MAXN;
		}
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = wei[i]; j <= w; ++j)
			{
				dp[j] = min(dp[j], dp[j - wei[i]] + val[i]);
			}
		}
		if (dp[w] == MAXN)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
		}
	}
	return 0;
}