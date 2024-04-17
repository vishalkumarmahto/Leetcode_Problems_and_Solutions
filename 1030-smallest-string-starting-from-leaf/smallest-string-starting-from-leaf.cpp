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
    vector<string> store;
    void func(TreeNode* node, string s) {
        if(!node) return;
        s += (node->val + 'a');
        if(!node->left && !node->right) {
            reverse(s.begin(), s.end());
            store.push_back(s);
            return;
        }
        func(node->left, s);
        func(node->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        func(root, s);
        sort(store.begin(), store.end());
        return store[0];
    }
};