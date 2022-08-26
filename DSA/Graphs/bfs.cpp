#include<iostream>
#include<queue>
#include<vector>
using namespace std;


/**
 * @brief 
 * 
 * in bfs when we take a queue and when we visit a node 
 * we put it in the queue
 * 
 * iterate on that vector and place all the nodes in queue till not empty
 * when placing an element in a queue we first update the visited array
 * 
 * delete the top most element
 * 
 * 
 * t.c:O(n+e) s.c: O(n+e)
 * 
 */
// v is the number of nodes in the graph
vector<int>bfsOnGraph(int V, vector<int>adj[]){
    vector<int> bfs;
    vector<int>vis(V+1,0);

    for(int i=1;i<=V;i++){
        if(!vis[i]){
            queue<int>q;
            //insert starting point of the component in the queue
            q.push(i);
            //mark as visited
            vis[i]=1;
            //iterate queue when not empty
            while(!q.empty()){
                //take out first elemnt from the queue and make sure its  deleted
                int node=q.front();
                q.pop();
                //for that element we have traversed the node hence we add it to the bfs vector
                bfs.push_back(node);
                //put all the adj node in the queue
                for(auto it: adj[node]){
                    //if node is not visited take the node and push it i the queue 
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }

        }
    }
    return bfs;
}