#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool>mset(V,false);
        vector<int>dist(V,INT_MAX);
        
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(pq.size()){
            int curr=pq.top().second;
            pq.pop();
            
            if(mset[curr]==true) continue;
            mset[curr]=true;
            for(auto i:adj[curr]){
                int v=i[0];
                int w=i[1];
                
                if(mset[v]==false && dist[v]>w){
                    dist[v]=w;
                    pq.push({w,v});
                }
            }
        }
        int sum1=accumulate(dist.begin(),dist.end(),0);
        return sum1;
    }
};

