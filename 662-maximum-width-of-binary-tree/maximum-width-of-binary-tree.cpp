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
    int widthOfBinaryTree(TreeNode* root) {
            if (!root) return 0;

        // Use long long for indices to prevent overflow
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second; // Min index at this level
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long curid = q.front().second - mmin; // Normalize index
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curid;  // First node index at this level
                if (i == size - 1) last = curid;  // Last node index at this level

                if (node->left) q.push({node->left, curid * 2 + 1});
                if (node->right) q.push({node->right, curid * 2 + 2});
            }

            ans = max(ans, static_cast<int>(last - first + 1)); // Update the max width
        }

        return ans;
    }
};