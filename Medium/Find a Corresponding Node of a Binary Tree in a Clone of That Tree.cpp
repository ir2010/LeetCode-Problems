class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* ans;
        
        return dfs(cloned, target);
    }
    
    TreeNode* dfs(TreeNode* cloned, TreeNode* target)
    {
        TreeNode* ans;
        if(cloned->val == target->val)
            return cloned;
        
        if(cloned->left)
            if(ans = dfs(cloned->left, target))
                return ans;
            
        
        if(cloned->right)
            if(ans = dfs(cloned->right, target))
                return ans;
        
        return NULL;
    }
};