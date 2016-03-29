#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000000+10

using namespace std;

typedef long long ll;

int main() 
{
	int n, m;
	while(~scanf("%d%d", &n, &m)) 
	{
		int a, b;
		int ans = MAXN;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
			if (n % a == 0)
			{
				ans = min((n / a) * b, ans);
			}
			else
			{
				ans = min (((n / a) + 1) * b, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}