#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * @brief 
 * run a bfs for every component and check if a cycle exists or not
 * 
 * if any of the adj node has been visited previosly then there is a cycle
 * 
 * this time we pt the node and the parent node in the queue when placing bfs
 * 
 * starting node will not have a prev node / parent node hence we
 * we put it as -1 
 * 
 * 
 * from the position we came if the prev value is visited then its not a cycle hence ignored
 *
 * 
 * if the adj node from that node is already visited but its not prev then its a cycle
 * 
 * t.c: O(n+e)  s.c: O(n+e) adj list +queue
 * 
 * 
  
 */


bool checkForCycle(int s, int V, vector<int>adj[],vector<int>& visited){
    //create a queue for bfs
    queue<pair<int,int>> q;
    //starting node
    visited[s]=true;
    //initial starting node with prev as -1
    q.push({s,-1});

    while(!q.empty()){
        //traverse in top most elemnt in the queue
        int node=q.front().first;
        //prev of the first elemnt/ parent elemnt
        int por=q.front().second;
        q.pop();
        //traverse all its adjacseent nodes
        for(auto it: adj[node]){
            if(!visited[it]){
                //when not visited mark it as visited and put in the queue
                visited[it]=true;
                q.push({it,node});
            }else if /** adj node has been visited and it not prev hence a cycle*/(por != it) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adj[]){
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(checkForCycle(i,V,adj,vis)) return true;
    }
    return false;
}