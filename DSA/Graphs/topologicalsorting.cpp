#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/**
 * @brief 
 * topological sort=> linear ordering of vertices such that if 
 * ther is an edge u-> v , u appears before v in that ordering
 * 
 *  topological sort cant be in a cyclic graph because if we have a cycle
 * of 2-> 3-> 4->2 then if we write 2 3 4 then 2 will appear before 3 
 *  3 will appear before 4 but 4 cant appear before 2
 * 
 * hence topological sort can only work in dag
 * 
 * directed acyclic graph 
 * 
 * use dfs algo
 * 
 * 1. run a loop from 0-> number of nodes and if unvisited we call dfs
 * 2. we carry stack and visited array
 * 3. once dfs is over(visited all its adj nodes) i.e all adj nodes have been traversed we put it 
 * in the stack
 * 
 * dfs call for the called one will finish first and then the
 * actual dfs call will happen 
 * 
 * 
 * there can be  multiple topo sorts
 * 
 * t.c: O(n+e)  s.c: O(n)+O(n)-> stack +O(n)-> recursive stack
 * 
 * 
 */




void findTopoSort(int node, vector<int>& vis,stack<int>& st, vector<int> adj[]){
    vis[node]=1;

    for(auto it: adj[node]){
        //loop throughunvisited adj nodes
        if(!vis[it]){
            findTopoSort(it,vis,st,adj);
        }
    }
    //push in stack when its dfs calls are over
    st.push(node);
    
}

vector<int> topoSort(int N,vector<int> adj[]){
    stack<int>st;
    vector<int>vis(N,0);
    for(int i=0;i<N;i++){
        if(!vis[i]==0){
            findTopoSort(i,vis,st,adj);
        }
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}