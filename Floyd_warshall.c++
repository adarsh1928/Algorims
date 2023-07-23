#include <bits/stdc++.h>
using namespace std;

//The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.

//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    
	    int n=mat.size();
	    int m=mat[0].size();
	    
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                if(mat[j][k]<0) mat[j][k]=1e9;
	            }
	        }
	   
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                mat[j][k]=min(mat[j][k] , mat[j][i]+mat[i][k]);
	            }
	        }
	    }
	     for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                if(mat[j][k]==1e9) mat[j][k]=-1;
	            }
	        }
	}
};
