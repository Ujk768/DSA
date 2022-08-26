/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> que;
    que.push(A);
    que.push(NULL);
    vector<vector<int>>ans;
     vector<int>levels;
   
    while(que.size()>1){
        
        TreeNode*tmp=que.front();
        //pop the first node in queue
        que.pop();
        //if tmp==NULL it means level is over so push vector of level into ans and clear level
        if(tmp==NULL){
            ans.push_back(levels);
            levels.clear();
            que.push(NULL);
         
            continue;
        }
        //if not null push that node into level vector
        levels.push_back(tmp->val);
        //push left and rigth child into the queue
        if(tmp->left!=NULL){
            que.push(tmp->left);
        }
        if(tmp->right!=NULL){
            que.push(tmp->right);
        }

    }
    //last level not inserted in ans vector
    ans.push_back(levels);
    return ans;

}
**/