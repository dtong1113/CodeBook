#include <bits/stdc++.h>

using namespace std;

/*
Edmondsk-Karp Algorithm for Max Flow has an algorithm of O(E^2 * V)
*/
struct Edge{
    int from, to, cost, next;
};
const int MAX_EDGE=10000;
const int MAX_VERTEX=1000;

int sink;
int src;
int last[MAX_VERTEX];

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
int bfs()
{
    bool visited[MAX_VERTEX];
    memset(visited, false, MAX_VERTEX);
    int prev[MAX_VERTEX];       //previous vertex you were after to get to the current vertex
    memset(prev, 0, MAX_VERTEX);
    int index[MAX_VERTEX];      //index of the edge you used to get to a vertex
    memset(index, 0, MAX_VERTEX);
    visited[src]=true;
    prev[src]=-1;
    index[src]=-1;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i=last[curr]; i!=-1; i=edges[i].next)
        {
            if(edges[i].cost>0 && !visited[edges[i].to])
            {
                q.push(edges[i].to);
                visited[edges[i].to]=true;
                prev[edges[i].to]=curr;
                index[edges[i].to]=i;
            }
        }
    }
    if(!visited[sink])
    {
        return 0;
    }
    int curVertex=sink;
    int flow=INT_MAX;
    while(prev[curVertex]!=-1)
    {
        flow=min(flow, edges[index[curVertex]].cost);
        curVertex=prev[curVertex];
    }
    curVertex=sink;
    while(prev[curVertex]!=-1)
    {
        edges[index[curVertex]].cost-=flow;
        edges[index[curVertex]^1].cost+=flow;
        curVertex=prev[curVertex];
    }
    return flow;
}
int maxFlow()
{
    int flow=0;
    int curr=0;
    curr=0;
    while((curr=bfs())>0)
    {
        flow+=curr;
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
