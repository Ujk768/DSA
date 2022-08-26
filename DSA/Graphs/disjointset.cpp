#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/**
 * @brief 
 * helps us to tell if two random nodes belong to the same component or not
 * 
 * it has teo operations find parent() and  union()
 * 
 * every node has himself as the parent when we start off in the parent array
 * 
 * we use anothe rank array inital values of all is 0
 * 
 * union(1,2) 
 * both have rank 0 initially 
 * 
 * parent of 1 is 1 and parent of 2 is 2 
 * 
 * we can attach 2 to 1 
 * 
 * parent of 2 is 1 now
 * 
 *  and the node to which we are attaching is increased by 1
 * 
 * 
 * union(2,3)
 * 
 * first we find parent of 2 which is 1
 * parent of 1 is 1 
 * 
 * parent of 3 is 3 himself so now we connect 1 and 3
 * 
 * node with smaller rank is connected to node with larger rank hence 3 connects to 1
 * 
 * whenever ranks are different dont increase the rank keep them as it is
 * 
 * lower rank guy is attached to higher rank and if rank is same we increase rank by 1
 * 
 * 
 * parent of 7 is 6 and parent of 6 is 4  in sucah a case we do path compression and connect 7 directly to 4
 * 
 * O(4) or O(1)
 * 
 * s.c:O(n)
 * 
 * 
 */

int parent[100];
int Rank[100];

void makeset(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        Rank[i]=0;
    }
}

int findParent(int node){
    if(node==parent[node]) return node;

    return parent[node]=findParent(parent[node]);
}

void Union(int u, int v){
    u=findParent(u);
    v=findParent(v);
    if(Rank[u]<Rank[v]){
        parent[u]=v;
    }else if(Rank[v]<Rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        //level of u will increase only if its similar
        Rank[u]++;
    }


}

int main(){
    int m;
    cin>>m;
    makeset(m);
    while(m--){
        int u,v;
        Union(u,v);
    }

    //2 or 3 belong ot same component or not
    if(findParent(2)!=findParent(3)){
        cout<<"diff component"<<endl;
    }else cout<<"same component"<<endl;

}