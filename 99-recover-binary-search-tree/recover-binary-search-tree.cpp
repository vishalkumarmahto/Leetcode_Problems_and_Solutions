class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) return;
        inorder(root->left, nodes);
        nodes.push_back(root); // Collect node references
        inorder(root->right, nodes);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Find the two swapped nodes
        for (int i = 0; i < nodes.size() - 1; ++i) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                if (first == nullptr) {
                    first = nodes[i];
                }
                second = nodes[i + 1];
            }
        }

        // Swap their values
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};