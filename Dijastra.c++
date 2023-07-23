#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         vector<int>d(V,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,S});
        d[S]=0;
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            int a=p.second;
            pq.pop();
            for(int i=0;i<adj[a].size();i++)
            {
                int res=adj[a][i][0];
                int w=adj[a][i][1];
                if(w+d[a]<d[res])
                {
                    d[res]=d[a]+w;
                    pq.push({d[res],res});
                }
            }
        }
        return d;
    
    }
};

