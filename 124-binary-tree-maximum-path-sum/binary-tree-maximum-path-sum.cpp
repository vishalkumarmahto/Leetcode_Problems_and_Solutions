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
    int findMaxPathSum(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
        int data = root->val;
        maxi = max(maxi, (leftMaxPath + rightMaxPath) + data);
        return max(leftMaxPath, rightMaxPath) + data;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};