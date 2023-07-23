
#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int>&parent, vector<int>&rank)
{
    int n=rank.size();
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node, vector<int>&parent)
{
    if(node == parent[node])
        return node;
    return parent[node] = findPar(parent[node], parent);
}

void unionn(int u, int v, vector<int>&parent, vector<int>&rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    
    if(u == v)
        return; // Same parents means belong to the same components
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
// struct unionFind{
//     vector<int> roots;
//     vector<int> heights;
    
//     unionFind(int sz):roots(sz),heights(sz){
//         for(int i=0;i<sz;i++){//initializes all subtrees with their own node and height 1
//             roots[i]=i;
//             heights[i]=1;
//         }
            
//     }
    
//     int find(int x){
//         return (x==roots[x])?x:roots[x]=find(roots[x]); //DSU with path compression
//     }
    
//     void connect(int a,int b){
//         int root1=find(a),root2=find(b);
//         if(root1!=root2){
//             if(heights[root1]>heights[root2])
//                 roots[root2]=root1;
//             else if(heights[root1]<heights[root2]) //Union by rank
//                 roots[root1]=root2;
//             else{
//                 roots[root2]=root1;
//                 heights[root1]++;
//             }
//         }
//     }
    
//     bool isConnected(int a,int b){
//         return find(a)==find(b); //Function to know if two nodes are connected
//     }
    
// }; 
int main()
{
    int n=7; // 7 nodes
    // These pairs needs to be combined
    vector<vector<int>>pairs = {{1,2}, {2,3}, {4,5}, {6,7}, {5,6}};
    vector<int>parent(n);
    vector<int>rank(n);
    
    makeSet(parent, rank);
    for(int i=0;i<pairs.size();i++){
        
        int u = pairs[i][0], v = pairs[i][1];
        unionn(u, v, parent, rank);
    }

    // if 3 and 7 belong to the same component or not
    if(findPar(3, parent)!=findPar(7, parent))
        cout<<"Different components";
    else 
        cout<<"Same components";
    return 0;
}

