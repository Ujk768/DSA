/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {

    for each node we also need to know which level it will belong to hence we use a pair to store this

            //node       //level
    queue<pair<TreeNode*,int>>q;

    //push root node which is at level 0
    
    q.push({A,0});
    
    // use a hashmap to store the nodes which are at each level so we use level as key and store the values 
    //at each level in a vector
    
    unordered_map<int,vector<int>>hm;

    int minLevel=1,maxLevel=-1;
    while(q.size()>0){

        pair<TreeNode*,int>data=q.front();
        q.pop();
    
        //this gives us the node we are currently at
    
        TreeNode*tmp=data.first;
    
        //level of the node we are currently at
    
        int l=data.second;

    // when we get the elements we use min and max level to get range of level values which exist

        minLevel=min(minLevel,l);
        maxLevel=max(maxLevel,l);

    //insert the values at that particular level in the hash map

        hm[l].push_back(tmp->val);

    // the left child will be at level-1th level from current level hence we update l-1 at the level
    
        if(tmp->left!=NULL){
            q.push({tmp->left,l-1});
        }
    //the right child will be at level+1 from current level

        if(tmp->right!=NULL){
            q.push({tmp->right,l+1});
        }
        
    }

    // after doing this we will have a hashmap with all values at each of the levels

    
    vector<vector<int>>ans;

    //iterate through all the levels and print the data at each level

    for(int i=minLevel;i<=maxLevel;i++){
        vector<int>ele=hm[i];
        ans.push_back(ele);
    }

    return ans;
}


after doing this we can now solve majority of the problems 

topview => print first element at every level

bottom view=> print last element at every level

diagonal left=>left side belongs to same level as the current node

diagonal right=> right side belongs to same levvel as current node

****/