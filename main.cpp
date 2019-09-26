#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)1e4+5

//graph G(original graph) and G'(residual graph)
//first element of pair represents destination
//second element of pair represents weight of edge from u to v

vector<pair<int,int> > original_graph[MAXN], residual_graph[MAXN];

//struct for demand

struct demand {

  //demand id, source of demand, destination of demand and demand of traffic flow
  //from s to t

  demand(int a, int b, int c, int d) : d(a), s(b), t(c), h(d)
  {
    //cout << "constructor called" << endl;
  }

  int d, s, t, h;

};

// vector<int> bfs(int src,int dest)
// {
//   vector<int>shortest_path;
//   bool visited[MAXN];
//   memset(visited,false,sizeof(visited));
//   queue<int>q;
//   q.push(src);
//   visited[src]=true;
//   shortest_path.push_back(src);
//   while(!q.empty())
//   {
//     int u=q.front();
//     q.pop();
//     for(auto v:original_graph[src])
//     {
//       if(!visited[v])
//       {
//         shortest_path.push_back(v);
//         visited[v]=true;
//         q.push(v);
//         if(v==dest)
//         return shortest_path;
//       }
//     }
//   }
// }

vector<vector<int>> find_TNDP(demand d)
{
  vector<vector<int>> output;
  int s=d.s;
  int t=d.t;
  for(int i=0;i<2;i++)
  {
    vector<int>path;

  }
}

int main()
{
  //INPUT the ORIGINAL graph. Also, the Residual graph is the same as the
  //original graph

  int u, v, h, temp, w;    //temporary variables to aid in input

  int V, A;         //no of nodes and edges in the graph
  cin >> V >> A;

  for(int i = 1; i <= A; ++i)
  {
    cin >> u >> v >> w;      //u = source node, v = destination node

    original_graph[u].emplace_back(v,w);

    residual_graph[u].emplace_back(v,w);
  }

  int D;  //no of demands
  cin >> D;

  vector<demand> demands;

  //INPUT the respective demands

  for(int i = 1; i <= D; ++i)
  {
    cin >> u >> v >> h;

    demands.emplace_back(i,u,v,h);
  }

  sort(demands.begin(), demands.end(), [](const demand& a, const demand& b) -> bool
  {
    return a.h > b.h;
  });



  return 0;
}
