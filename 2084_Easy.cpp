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

int ss[1001][1001];
int dp[1001][1001];

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while(t--) 
	{
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(ss, 0, sizeof(ss));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				scanf("%d", &ss[i][j]);
			}
		}
		for (int i = n; i > 0; --i)
		{
			for (int j = 1; j <= i; ++j)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + ss[i][j];
			}
		}
		printf("%d\n", dp[1][1]);
	}
	return 0;
}