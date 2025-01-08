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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1; // To store the previous node value in in-order traversal
        
        // In-order traversal using a helper function
        inOrderTraversal(root, prev, minDiff);
        return minDiff;
    }
    
private:
    void inOrderTraversal(TreeNode* node, int& prev, int& minDiff) {
        if (!node) return;
        
        // Traverse the left subtree
        inOrderTraversal(node->left, prev, minDiff);
        
        // Process the current node
        if (prev != -1) { // If there's a previous value
            minDiff = min(minDiff, abs(node->val - prev));
        }
        prev = node->val; // Update the previous node value
        
        // Traverse the right subtree
        inOrderTraversal(node->right, prev, minDiff);
    }
};
