#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)1e4+5
#define pi pair<int,int>

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

void shortestPath(vector<int> &path, int u, vector<int> const& parent)
{
  //base case : if u is the Source
  if (parent[u] == -1)
  {
    path.push_back(u);
    return;
  }

  shortestPath(path, parent[u], parent);

  path.push_back(u);

}

//Returns shortest path from src to dest

vector<int> dijkstra(int V, int src, int dest, vector<pi> graph[])
{
    // Create a priority queue to store vertices that
    // are being preprocessed.

    priority_queue< pi, vector <pi> , greater<pi> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (MAXN)
    vector<int> dist(V+1, MAXN);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    vector<int> parent(V+1,-1);

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        // list< pair<int, int> >::iterator i;
        for (auto x : graph[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = x.first;
            int weight = x.second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                //making u as parent of v
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    vector<int> path;

    shortestPath(path, dest, parent);
    return path;

}


vector<vector<int>> find_TNDP(int V,vector<pair<int,int>>*res, demand d)
{
  vector<vector<int>> output;
  int s=d.s;
  int t=d.t;
  for(int i=0;i<2;i++)
  {
    vector<int>path;
    path=dijkstra(V, s, t, res);
    output.push_back(path);
    vector<pair<int,int>>::iterator it;
    for(int j=1;j<=V;j++)
    {
      for(it = res[j].begin(); it != res[j].end(); it++)
      {
        for(auto k:path)
        {
          if(k==(*it).first && (k!=s || k!=t))
          res[j].erase(it);
        }
      }
    }
  }
  return output;
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

  vector<vector<int>> final_paths;
  for (auto d:demands) {
    int h=d.h;
    vector<pair<int,int>>res[MAXN] = residual_graph;
    for(int i=1;i<=V;i++)
    {
      vector<pair<int,int> >::iterator it;
      for(it = res[i].begin(); it != res[i].end(); it++)
      {
        if((*it).second <= h)
        res[i].erase(it);
      }
    }
    vector<vector<int>> paths = find_TNDP(V,res,d);
    if(paths.size()==2)
    {
      int path_1_sz = paths[0].size(), path_2_sz = paths[1].size();
      for (int i = 0 ; i < path_1_sz-1; ++i)
      {
        auto u = residual_graph[paths[0][i]];
        auto v = paths[0][i+1];
        for (auto k : u)
        {
          if (k.first == v)
            k.second-=h;
        }
      }
    }
    else
      break;
  }


  return 0;
}

	
	
	

