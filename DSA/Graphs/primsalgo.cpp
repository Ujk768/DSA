#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * @brief 
 * 
 *  1. start at the src node and find the min node
 * attached to node 0.
 * 2. check out all the adj edges to both the nodes and 
 * pick the min adj node
 * 3. keep finding the minimal edge and add it
 * 4. once all the nodes are connected then its done
 * 
 * we also have to make sure we dont form a cycle
 * 
 * 3 arrays  key=init to infinity except 
 * the first element, 
 * mst intit to false
 * and parent init to -1
 * 
 * node with ind 0 wil have min possible key value and its not part of mst
 * take it and mark it true in mst.
 * 
 * iterate through its adj nodes and check if its part of mst
 *
 *take the adj edges weight and mark it with the weight in key array

 * go to ind of adj node and put the prev node as parent 

 next check the min node among all the alues in jey array whose mst 
 is marked as false
 *  
 */
//brute force approach 

int main(){
    //graph input in adj list
    int N,m;
    cin>>N,m;
    vector<pair<int,int>>adj[10];

    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));

    }
    int parent[10];
    int key[10];
    bool mstSet[10];
    //init key,parent and mast array
    for(int i=0;i<N;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    // we have n-1 edges in the min spanning tree hence iterate for n-1
    //edges
    for(int count=0;count<N-1;count++){
        int mini=INT_MAX,u;
//figure out minimum key value
        for(int v=0;v<N;v++){
            //if its not part of mst and value is less than mini then this is the mini and we store this index
            if(mstSet[v]==false && key[v]<mini){
                mini=key[v];
                u=v;

            }
            //mark that particular index as true in the mst
            mstSet[u]=true;
            //iterate for its adj nodes
            for(auto it: adj[u]){
                int v=it.first;
                int weight=it.second;
//if it wasnt part of mst we compare that weigth with key value
                if(mstSet[v]==false && weight<key[v]){
                    //find minimal and keep updating key and parent
                    parent[v]=u;
                    key[v]=weight;
                }
            }

        }


    }

    for(int i=0;i<N;i++){
        cout<<parent[i]<<" ";
    }

}

/**
 * @brief t.c O(n^2) s.c : adj list+3 vectors
 * 
 */

/**
 * @brief 
 * priority queue implemetation
 * 
 *  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>pq;
 *  to optimizr this we need to use priority queue to get minn value in 
 *  log n time
 * 
 * traversing adj nodes for every node its O(n+e)
 * 
 * 
 */

