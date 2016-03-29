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

int sum;
double dp[300010];
int mm[10000];
double pp[10000];
double x, y;

double max(double a, double b)
{
	return a > b ? a : b;
}

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

	int n, t;
	scanf("%d", &t);
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%lf%d", &x, &n);
		sum = 0;
		//sum = (int)(x * 100);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%lf", &mm[i], &pp[i]);
			sum += mm[i];
			//v[i] = (int)(y * 100);
		}
		dp[0] = 1;
		for(int i = 0; i < n; ++i)
        {
            for(int j = sum; j >= mm[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - mm[i]] * (1 - pp[i])); 
            }
        }
        for (int i = sum; i >= 0; --i)
        {
        	if (dp[i] >= (1 - x))
        	{
        		printf("%d\n", i);
        		break;
        	}
        }
	}
	return 0;
}