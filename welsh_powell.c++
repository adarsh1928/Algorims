#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    
    
    bool isSafeColor(bool graph[101][101], int i, int j,vector<int>&color,int m,int n){
        
        
        for(int k=0;k<n;k++){
            if(graph[i][k]==1 && color[k]==j) return false; 
        }
        
        return true;
    }
    
    bool fun(bool graph[101][101], int m, int n,int i,vector<int>&color){
        if(i==n) return true;
        
        for(int j=1;j<=m;j++){
            
            if(isSafeColor(graph,i,j,color,m,n)) {
                color[i]=j;
                
                if(fun(graph,m,n,i+1,color)) return true;
                
                color[i]=-1;
            }
            
        }
        return false;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n);
        
       return fun(graph,m,n,0,color);
    }

};