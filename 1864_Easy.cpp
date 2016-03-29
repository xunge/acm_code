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

char ch;

int dp[3000010];

int a, b, c, flag;
int money[35], v, sum;

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int n;
	double x, y;
	while(~scanf("%lf%d", &x, &n))
	{
		if (n == 0)
		{
			break;
		}
		sum = (int)(100 * x);
		int l = 0;
		memset(dp, 0, sizeof(dp));
		memset(money, 0, sizeof(money));
		while(n--)
		{
			flag = 1;
			a = b = c = 0;
			int t;
			scanf("%d", &t);
			for (int i = 0; i < t; ++i)
			{
				scanf(" %c:%lf", &ch, &y);
				v = (int)(100 * y);
				if (ch == 'A' && a + v <= 60000)
				{
					a += v;
				}
				else if (ch == 'B' && b + v <= 60000)
				{
					b += v;
				}
				else if (ch == 'C' && c + v <= 60000)
				{
					c += v;
				}
				else
				{
					flag = 0;
				}
			}
			if (a + b + c <= 100000 && a <= 60000 && b <= 60000 && c <= 60000 && flag)
			{
				money[l++] = a + b + c;
			}
		}
		for (int i = 0; i <= l; ++i)
		{
			for (int j = sum; j >= money[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - money[i]] + money[i]);
			}
		}
		printf("%.2lf\n", dp[sum] / 100.0);
	}
	return 0;
}