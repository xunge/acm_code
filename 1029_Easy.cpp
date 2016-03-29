#include <stdio.h>
#include <string.h>

int A[1000000];

int main()
{
	int n, m, i, ok;
	while (scanf("%d", &n) != EOF)
	{
		memset(A, 0, sizeof(A));
		for (i=0; i<n; i++)
		{
			scanf("%d", &m);
			A[m]++;
			if (A[m] == (n+1)/2)
				ok = m;
		}
		printf("%d\n", ok);
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
using namespace std;
int num[100007];
int main()
{
    int n, ans, aa;
    while(~scanf("%d",&n))
    {
        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&aa);
            num[aa]++;
            if(num[aa]>=((n+1)/2))
            {
                ans=aa;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}