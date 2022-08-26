#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * node/vertex => point in a graph 
 * 
 * edge=> connects two nodes / vertex
 * 
 *  types of graphs  two ways directed and directed
 * 
 *  edges in directed and undirected
 * 
 * directed=> edge btw u and v
 * undirected=> edge btw u and v and then also edge btw v and u
 * 
 * degree number of edges incoming or outgoing from a graph
 * 
 * undirected graph=> has only degree as there is no direction
 * 
 * in undirected graph the
 *  total degree of all the nodes is twice of all the edges
 * total degree= 2*E
 * 
 * indegree=> number of edges 
 * 
 * directed graph
 * 
 * indegree=> number of edges incoming to a node
 * 
 * outdegree> number of edges going outside a given node
 * 
 * 
 * path=> seuence of nodes/vertex such that no nodes are repeated or visited twice
 * 
 * cycle=> if you start from onr node and reach that node again wothout visiting any other node twice
 * 
 * 
 * weighted graphs=> edges have been given a partcular weight
 * 
 * 
 * 
 * Graph representaiton
 * 
 * input  
 *      n => number of nodes in the graph
 * 
 *      m lines follow each containing a u and a v
 *      m represents the number of edges in the graph
 * 
 *      in an undirected graph the value 3 5 represents both the 
 *      5 3 and 3 5  in the graph
 * 
 * n=5 m=7
 * 
 *  1) adjacency matrix:
 *      if the number of nodes are 5 and we use a 1 based indexnig we create a 6*6 2d array
 *      iterate over all the edges and mark 1 in that position
 *      
 *      adj[u][v]=1  adj[v][u]=1
 * 
 *  dis adv
 * -can only use for smaller values of n as we cant create very huge 2d arrays
 * -
 * 2) adjacency list
 *  vectpor<int>adj[6]
 * 
 * creates an vector of size 6
 * (1-2) 
 * 1 is an adjascent node of 1 
 * 2 is an adjacent node of 1
 * 
 * at every index we store all the nodes adjacenent nodes 
 *  
 * 
 * adj[u].push_back(v)
 * adj[v].push_back(u)
 * 
 * incase they have given weigths then tou will create a vector of pairs 
 * 
 * 
 */ 


//adjacency matrix code

int adjMatrix(){
    int n,m;
    cin>>n>>m;
    //declare the adj matrix
    int adj[n+1][n+1];
    // m edges in the graph
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;

}
int adjList(){
    int n,m;
    cin>>n>>m;
    //declare the adj matrix
    vector<int>adj[n+1];
    // m edges in the graph
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

}
int adjListWeighted(){
    int n,m;
    cin>>n>>m;
    //declare the adj matrix
    vector<pair<int,int>>adj[n+1];
    // m edges in the graph
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    return 0;

}