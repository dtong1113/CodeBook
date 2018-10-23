#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int from, to, cost;
};
int main()
{
    int n;
    scanf("%d", &n);
    Edge edges[n];

    for(int i=0; i<n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        edges[i].from=a;
        edges[i].to=b;
        edges[i].cost=c;
    }

    for(int i=0; i<n; i++)
    {
        printf("From: %d To: %d Cost: %d\n", edges[i].from, edges[i].to, edges[i]. cost);
    }
    return 0;
}
