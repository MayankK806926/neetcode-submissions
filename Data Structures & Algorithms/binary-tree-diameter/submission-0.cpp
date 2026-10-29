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
    int maxDepth(TreeNode* root,int& ans) {
        if(root==NULL) return 0;
        int l = 0,r = 0;
        if(root->left) l = maxDepth(root->left,ans);
        if(root->right) r = maxDepth(root->right,ans);
        ans = max(ans,l+r);
        return max(l,r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        maxDepth(root,ans);
        return ans;
    }
};
