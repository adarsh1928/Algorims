#include <bits/stdc++.h>
using namespace std;

 vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int>dist(V,1e8);
        vector<int>visited(V,0);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto i:adj){
                int u=i[0];
                int v=i[1];
                int w=i[2];
                
                if(dist[v]>(dist[u]+w)){
                    dist[v]=dist[u]+w;
                }
            }
        }
        return dist;
    }

int main()
{

   
}