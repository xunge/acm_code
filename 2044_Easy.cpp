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

int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif

    LL ss[1000];
    memset(ss, 0, sizeof(ss));
    ss[0] = 1;
    ss[1] = 1;
    for (int i = 2; i < 51; ++i)
    {
    	ss[i] = ss[i - 1] + ss[i - 2];
    }
	int n;
	scanf("%d", &n);
	while(n--) 
	{
		LL a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", ss[b - a]);

	}
	return 0;
}