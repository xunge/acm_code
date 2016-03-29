#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000000+10

using namespace std;

typedef long long ll;

struct node
{
	char name[100];
	int p_num;
	int p_time;
}str[100001];

bool cmp(node a, node b)
{
	if (a.p_num != b.p_num)
	{
		return a.p_num > b.p_num;
	}
	else if (a.p_time != b.p_time)
	{
		return a.p_time < b.p_time;
	}
}

int main() 
{
	int n, time1, score, count, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		count = 0, sum = 0;
		scanf("%s", str[i].name);
		for (int j = 0; j < 4; ++j)
		{
			scanf("%d%d", &time1, &score);
			if (score != 0)
			{
				count++;
				sum += (score + (time1 - 1) * 20);
			}
			
		}
		str[i].p_num = count;
		str[i].p_time = sum;
		//printf("%d %d\n", count, sum);
	}
	sort(str, str + n, cmp);
	printf("%s %d %d\n", str[0].name, str[0].p_num, str[0].p_time);
	return 0;
}