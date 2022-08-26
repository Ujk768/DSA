#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * @brief bipartite graph is a graph that can be coloured such that no two adjascent nodes have the same colour
 * 
 * any graph with odd cycle length 
 * cant be a bipartite graph
 * 
 * 1. use  a bfs traversal 
 * 2. take a colour array 
 * 3. when visited colour that node with the opposite of the adjascent node
 * 4. when you visit an already coloured node and the adj node also has the same colour
 * return false as the graph is not bi-partite
 * 
 * 
 * if you can colour the entire graph in a bfs traversal then ita a bipartite graph
 * 
 * t.c: O(n+e)
 * s.c: adj list + queue+ colour array: O(n+e) + O(n) +O(n)
 * 
 * 
 * any graph that has odd length cycle cant be bipartite 
 * 
 * a graph which doesnt have odd length cycle not necessary it has an even length cycle an can be bipartite graph
 * 
 * 
 * 
 * 
 * 
 * 
bipartite graph using dfs


1. take a clour arr only no visited array
2. colour the src node
3. traverse the adj nodes and colour them with the opposite colour
4. for each adj node conduct a dfs call
 once we reach last node we return true or false to all the nodes above

 * t.c: O(n+e)
 * s.c: adj list + queue+ colour array: O(n+e) + O(n) +O(n)
 * 

 */

bool bipartitebfs(int src,vector<int> adj[],int colour[]){
    queue<int>q;
    q.push(src);
    //color src node
    colour[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(colour[it]==-1){
                //colour with opposite colour
                colour[it]=1-colour[node];
                q.push(it);
                //if its alreay coloured
            }else if(colour[it]==colour[node]){
                //if adj nocde colour is same as curent node not bipartite
                return false;
            }
        }
    }
    return true;
}


bool bipartiteDfs(int node, vector<int>adj[],int colour[]){
    if(colour[node]==-1) colour[node]=1;

    for(auto it: adj[node]){
        if(colour[it]==-1){
            //colour iwth opposite colour
            colour[it]=1-colour[node];
            if(!bipartiteDfs(it,adj,colour)){
                return false;
            }else if(colour[it]==colour[node]) return false;
        }
        return true;
    }
}









bool checkBipartite(vector<int>adj[], int n){
    int colour[n];
    memset(colour,-1,sizeof(colour));
    //check fro multiple components
    for(int i=0;i<n;i++){
        //node not coloured hence call dfs/bfs
        if(colour[i]==-1){
            // change to bipartite dfs if you want to check using dfs
            if(!bipartitebfs(i,adj,colour)){
            return false;
            }
        }
    }
    return true;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkBipartite(adj,n)){
        cout<<"yes";
    }else{
        cout<<"NO";
    }
    return 0;
}

