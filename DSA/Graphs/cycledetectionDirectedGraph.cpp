#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * @brief 
 * 
 * steps
 * 1. create a visited array of size 8 
 * 2. create an adjacency list
 * 3. iterate from first node to the last node if node was not visited then we do dfs
 * 4. we keep doing recursive calls for dfs on its adjascent elements and if we reach a node that has 
 * already been visited then we know we have found a cycle
 * 
 *  
 * in queue we also need to put the parent element also with the node int the queue and if we find a visited node
 * and its not parent its a cycle
 * 
 * t.c: O(n+e) sc: O(n+e)+O(n)+O(n)
 */



bool checkForCycle(int node,int parent, vector<int> & vis, vector<int>  adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]==0){
            if(checkForCycle(it,node,vis,adj)){
                return true;
            }else if(it!=parent) return true;
        } 
    }
    return false;
}




bool isCycle(int V,vector<int>adj[]){
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(checkForCycle(i,-1,vis,adj)) return true;
        }
    }
    return false;
}



