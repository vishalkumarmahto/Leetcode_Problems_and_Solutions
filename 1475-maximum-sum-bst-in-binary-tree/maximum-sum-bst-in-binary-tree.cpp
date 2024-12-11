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
class node {
public:
    int sum;        // Sum of values in the subtree
    int minVal;     // Minimum value in the subtree
    int maxVal;     // Maximum value in the subtree
    bool isBST;     // Whether the subtree is a BST
    node* left;     // Pointer to the left child
    node* right;    // Pointer to the right child
    
    node() {
        sum = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        left = NULL;
        right = NULL;
        isBST = true;
    }
};

class Solution {
public:  
    int ans; // Variable to store the maximum sum of a BST

    // Function to create a node object representing a subtree
    node* createNode(TreeNode* root) {
        if (!root) return NULL;

        node* temp = new node();
        temp->sum = root->val;
        bool isBST = true;
        
        // Process the left subtree
        if (root->left) {
            temp->left = createNode(root->left);
            if (!temp->left->isBST || temp->left->maxVal >= root->val) isBST = false;
            temp->sum += temp->left->sum;
            temp->minVal = min(temp->minVal, temp->left->minVal);
            temp->maxVal = max(temp->maxVal, temp->left->maxVal);
        }
        
        // Process the right subtree
        if (root->right) {
            temp->right = createNode(root->right);
            if (!temp->right->isBST || temp->right->minVal <= root->val) isBST = false;
            temp->sum += temp->right->sum;
            temp->minVal = min(temp->minVal, temp->right->minVal);
            temp->maxVal = max(temp->maxVal, temp->right->maxVal);
        }
        
        // Update min and max values for the current node
        temp->minVal = min(temp->minVal, root->val);
        temp->maxVal = max(temp->maxVal, root->val);
        temp->isBST = isBST;
        
        return temp;
    }

    // Function to update the maximum sum if the current subtree is a BST
    void MaxSum(node* root) {
        if (!root) return;
        if (root->isBST) ans = max(ans, root->sum);
        MaxSum(root->left);
        MaxSum(root->right);
    }
    
    int maxSumBST(TreeNode* root) {
        node* rote = createNode(root); // Create node object for the entire tree
        ans = 0; // Initialize the maximum sum
        MaxSum(rote); // Find the maximum sum of BSTs
        return ans;
    }
};