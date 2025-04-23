#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
     cout << "Enter total number of vertices ";
     cin >> v;
     
     cout << "Enter total number of edges ";
      cin >> e;

      vector<vector<pair<int,int>>> adj(v);

      for(int i=0; i<e; i++)
      {
        int x,y,w;

        cin >> x >> y >> w;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
      }

      int source ;
      cout << "Enter source node :";
      cin >> source;

      vector<int> dis(v,INT_MAX);
      dis[source] = 0;

      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

      vector<bool> visi(v,0);

      pq.push({0,source});

      while(!pq.empty())
      {
         while(!pq.empty() && visi[pq.top().second])
         pq.pop();

         if(pq.empty())
         break;

         auto op = pq.top();
         pq.pop();

         visi[op.second] = 1;

         for(auto p : adj[op.second])
         {
            if(visi[p.first] == 0 && dis[p.first] > (op.first + p.second))
             {
                dis[p.first] = op.first + p.second;
                pq.push({dis[p.first],p.first});
             }
         }
         
        }
         cout << "Shortest distance of all nodes is : " << endl;

         for(int i=0; i<v; i++)
         {
            cout << source << " -> " << i <<  " = " << dis[i]<<endl;
         }
      return 0;
}