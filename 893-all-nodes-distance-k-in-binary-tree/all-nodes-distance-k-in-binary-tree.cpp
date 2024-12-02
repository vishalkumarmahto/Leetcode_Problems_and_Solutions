/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* node, unordered_map<int, vector<int>>& graph) {
        if (!node) return;

        // Connect current node with its left child.
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            buildGraph(node->left, graph);
        }

        // Connect current node with its right child.
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            buildGraph(node->right, graph);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Convert the tree into a graph.
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph);

        // Step 2: Perform BFS to find nodes at distance K.
        vector<int> result;
        unordered_set<int> visited; // To avoid revisiting nodes.
        queue<pair<int, int>> q;    // Pair of (current node value, current distance).

        q.push({target->val, 0});  // Start BFS from the target node.
        visited.insert(target->val);

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                // If the current distance equals k, add the node to the result.
                result.push_back(node);
            } else if (dist < k) {
                // Continue exploring neighbors if distance < k.
                for (int neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push({neighbor, dist + 1});
                    }
                }
            }
        }

        return result;
    }
};
