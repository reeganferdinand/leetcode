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
    int maxi=INT_MIN;

    int func(TreeNode *root)
    {
        if(root==nullptr) return 0;

        int ls=max(0,func(root->left));
        int rs=max(0,func(root->right));

        maxi=max(maxi,ls+rs+root->val);

        return root->val+max(rs,ls);
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        func(root);
        return maxi;
    }
};