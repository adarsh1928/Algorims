// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void dfs(int V, vector<int> adj[], vector<bool> &visited)
    {
        visited[V] = true;
        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
            }
        }
    }
    void dfsord(int V, vector<int> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[V] = true;
        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                dfsord(i, adj, visited, st);
            }
        }
        st.push(V);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> v;
        stack<int> st;

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsord(i, adj, visited, st);
            }
        }
        vector<int> n1[V];
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                n1[j].push_back(i);
            }
        }

        int cnt = 0;
        vector<bool> nv(V, false);
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            if (!nv[t])
            {
                cnt++;
                dfs(t, n1, nv);
            }
        }

        return cnt;
    }
};

