#include <bits/stdc++.h>

using namespace std;

/*
Ford-Fulkerson Algorithm for Max Flow has an algorithm of O(maxFlow * E)
*/
struct Edge{
    int from, to, cost, next;
};
const int MAX_EDGE=10000;
const int MAX_VERTEX=1000;

int sink;
int src;
int last[MAX_VERTEX];
bool visited[MAX_VERTEX];
Edge edges[2*MAX_EDGE];
int edgeIndex=0;
void addEdge(int from, int to, int cost)
{
    edges[edgeIndex].from=from;
    edges[edgeIndex].to=to;
    edges[edgeIndex].cost=cost;
    edges[edgeIndex].next=last[from];
    last[from]=edgeIndex;
    edgeIndex++;

    edges[edgeIndex].from=to;
    edges[edgeIndex].to=from;
    edges[edgeIndex].cost=0;
    edges[edgeIndex].next=last[to];
    last[to]=edgeIndex;
    edgeIndex++;
}
void addBiEdge(int from, int to, int cost)
{
    edges[edgeIndex].from=from;
    edges[edgeIndex].to=to;
    edges[edgeIndex].cost=cost;
    edges[edgeIndex].next=last[from];
    last[from]=edgeIndex;
    edgeIndex++;

    edges[edgeIndex].from=to;
    edges[edgeIndex].to=from;
    edges[edgeIndex].cost=cost;
    edges[edgeIndex].next=last[to];
    last[to]=edgeIndex;
    edgeIndex++;
}
int dfs(int pos, int flow)
{
    visited[pos]=true;
    if(pos==sink)
    {
        return flow;
    }
    for(int i=last[pos]; i!=-1; i=edges[i].next)
    {
        if(edges[i].cost>0 && !visited[edges[i].to])
        {
            int res=dfs(edges[i].to, min(flow, edges[i].cost));
            if(res>0)
            {
                edges[i].cost-=res;
                edges[i^1].cost+=res;
                return res;
            }
        }
    }
    return 0;
}
int maxFlow()
{
    int flow=0;
    int curr=0;
    curr=0;
    memset(visited, false, MAX_VERTEX);
    while((curr=dfs(src, INT_MAX))>0)
    {
        flow+=curr;
        memset(visited, false, MAX_VERTEX);
    }
    return flow;
}
int main()
{
    int n;  //vertices
    int m;  //edges


    memset(last, -1, MAX_VERTEX);
    scanf("%d%d%d%d", &n, &m, &src, &sink);


    for(int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        addEdge(a, b, c);
    }

    printf("%d", maxFlow());

}
