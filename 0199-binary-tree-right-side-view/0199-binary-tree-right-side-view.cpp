class Solution {
public:
    
    void func(TreeNode *node,int level,vector<int>& ans)
    {
        if(node==nullptr) return;

        if(level==ans.size())
        {
            ans.push_back(node->val);
        }

        func(node->right,level+1,ans);
        func(node->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;

       func(root,0,ans);

       return ans;
    }
};