#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	if (n > 30) printf("%d\n", m);
	else printf("%d\n", m % (1 << n));
	return 0;
}