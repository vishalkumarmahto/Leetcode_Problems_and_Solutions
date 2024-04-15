/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void calcSum(TreeNode* root, int& sum, int ds) {
        if (!root)
            return;
        ds = ds * 10 + root->val;
        if (!root->left && !root->right) {
            sum += ds; // appending to sum if we have reached a leaf node
            return;
        }
        calcSum(root->left, sum, ds);
        calcSum(root->right, sum, ds);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        calcSum(root, sum, 0);
        return sum;
    }
};