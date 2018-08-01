/**
 * Minimum Depth of Binary Tree
 * Myyura
 */

/**
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root 
 * node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its minimum depth = 2.
 *
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
    int minDepth(TreeNode* root, int depth) {
        int minimum = 0xFFFFFFF;
        if (root->left) { minimum = std::min(minDepth(root->left, depth + 1), minimum); }
        if (root->right) { minimum = std::min(minDepth(root->right, depth + 1), minimum); }
        if (root->left == NULL && root->right == NULL) { minimum = std::min(depth, minimum); }
        return minimum;
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL) { return 0; }
        return minDepth(root, 1);
    }
};