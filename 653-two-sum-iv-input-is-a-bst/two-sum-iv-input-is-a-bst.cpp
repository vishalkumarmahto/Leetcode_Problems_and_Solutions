/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    void postorder(TreeNode *root,vector<int> &v){
        if(!root) return ;
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->val);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        postorder(root,v);
        
        unordered_map<int,int> mp;
        
        for(auto &i:v){
            mp[i]++;
        }
        
        for(auto &i:v){
            if(k==2*i){
                if(mp.find(k-i)!=mp.end()){
                    if(mp[k-i]>1) return true;
                }
            }
            else if(mp.find(k-i)!=mp.end()) return true;
        }
        
        return false;
        
    }
};