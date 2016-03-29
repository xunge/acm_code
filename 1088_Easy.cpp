#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000000+10

using namespace std;

typedef long long ll;

char str[1001];

int main() 
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n = 0;
	while(~scanf("%s", str)) 
	{
		int len = strlen(str);
		if (strcmp(str, "<br>") == 0)
		{
			printf("\n");
			n = 0;
		}
		else if (strcmp(str, "<hr>") == 0)
		{
			if (n != 0)
			{
				printf("\n");
			}
			for (int i = 0; i < 80; ++i)
			{
				printf("-");
			}
			printf("\n");
			n = 0;
		}
		else
		{
			if (n + len + 1 <= 80)
			{
				if (n != 0)
				{
					printf(" ");
					n++;
				}
				printf("%s", str);
				n += len;
			}
			else
			{
				printf("\n%s", str);
				n = len;
			}
		}
	}
	printf("\n");
	return 0;
}