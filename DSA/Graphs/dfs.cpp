#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * 
 * 1. create a visited array of size nodes+1 and init to 0
 * 2. write a for loop
 * 
 * for(i=1->7){
 *  if(!vis[i]) dfs()
 * }
 * 
 * 
 * 3. once you reach a node mark in visited then call recursive dfs calls for all adj nodes
 * 
 * t.c: o(n+n)
 * s.c: O(n+e+n)
 *  
 */

void dfs(int node,vector<int>& vis,vector<int> adj[],vector<int>&storeDfs){
    storeDfs.push_back(node);
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,storeDfs);
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[]){
    //store dfs traversal of graph
    vector<int>storeDfs;
    //create visited array
    vector<int>vis(V+1,0);
    //run dfs for all nodes
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            //call dfs if node is unvisited
            dfs(i,vis,adj,storeDfs);
        }
    }
    return storeDfs;
}