#include <bits/stdc++.h>
using namespace std;
 
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        vector<int>d=adj[i];
	        for(auto j:d){
	            indegree[j]++;
	        }
	    }
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	   while(!q.empty()){
	       int top1=q.front();
	       q.pop();
	       ans.push_back(top1);
	       for(auto j:adj[top1]){
	           indegree[j]--;
	           if(indegree[j]==0) q.push(j);
	       }
	   }
	    return ans;
	}
};