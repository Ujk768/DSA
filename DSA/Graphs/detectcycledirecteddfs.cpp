#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * in undirected whoever dfs is aclled we used
 * to mark there as visited in the visited array
 * 
 * in undirected graph if we visited any other node that
 * was not the parent node then we declared it a cycle
 * 
 * hence this algo for undirected graph will not work here
 * 
 * 1. graph can have multiple components so we write a loop 
 * for all the nodes in the graph 
 * 2. call cycle check for the node i
 * 3. we need to create two visited arrays
 * visited, n dfs visited.
 * 
 * when we start initialy we mark visited and dfs visited 
 * with 1 to show the node we have visited.
 * 
 * call dfs for the adjascent nodes
 * and mark both visited and dfs visited  as 1
 * 
 * when we dint find any adjascent nodes there will be 
 * further recursion calls so we remove that value from dfs visit
 * 
 * visited array will remain the same
 * dfs visited is used so that we can know if 5 was visited in the 
 * same dfs call or not
 * 
 * if dfs call is made to a node that has been marked as 1 in 
 * both the visited and unvisited array then its a cycle 
 * 
 * 
 * t.c O(n+e)
 * s.c: O(2n)=> visited and dfs visited
 *      O(n)=> aux stack space
 * 
 * 
 * 
 */

bool checkCycle(int node, vector<int> adj[],int vis[],int dfsVis[]){
    vis[node]=1;
    dfsVis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            //node is visited
            if(checkCycle(it,adj,vis,dfsVis)) return true;
        }else if(dfsVis[it]){ // node also visited in dfs array hence return true 
            return true;
        }
    }
    dfsVis[node]=0;
    return false;
}



bool isCyclic(int N, vector<int>adj[]){
    int vis[N],dfsVis[N];
    memset(vis,0,sizeof(vis));
    memset(dfsVis,0,sizeof(dfsVis));

    for(int i=0;i<N;i++){
        if(!vis[i]){
            if(checkCycle(i,adj,vis,dfsVis)){
                return true;
            }
        }
    }
    return false;
}