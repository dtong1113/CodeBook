#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iP;
typedef vector<int> intV;

vector<vector< iP> >graph;  //adjacency List

intV dist;  //stores all lists
void reset()
{
    dist.clear();
    graph.clear();
}
void dijkstra(int s)
{
    dist.assign(graph.size(), INT_MAX);
    dist[s]=0;

    priority_queue<iP, vector<iP>, greater<iP> > pq;    //greater sends lowest values first
    pq.push({0,s});

    while(!pq.empty())
    {
        iP curr=pq.top();   //cost, destination
        pq.pop();
        for(int i=0; i<graph[curr.second].size(); i++)  //iterate through edges connecting curr to other nodes
        {
         //   cout<<i<<endl;
          //  cout<<graph[curr.second].size()<<endl;
            iP temp= graph[curr.second][i];    //current edge you are looking at (cost, destination)
            if(dist[curr.second]+ temp.first<dist[temp.second])
            {
                dist[temp.second]=dist[curr.second]+temp.first;
                pq.push({dist[temp.second], temp.second});
            }
        }
    }
}
int main()
{
    reset();
    int N, M, source, dest; //N=nodes, M=edges
    cin>>N>>M;
    graph.resize(N+1);
//    dist.resize(N+1);
    for(int i=0; i<M; i++)
    {
        int from, to, cost;
        cin>>from>>to>>cost;
        graph[from].push_back({cost, to});
       // graph[to].push_back({cost, from});
    }

    cin>>source;
    cin>>dest;
    dijkstra(source);


    if(dist[dest]!=INT_MAX)
        cout<<dist[dest]<<endl;
    else
        cout<<-1<<endl;
}
