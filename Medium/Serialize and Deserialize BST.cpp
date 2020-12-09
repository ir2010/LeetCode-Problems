/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {    
        //converting into preorder traversal
        if(root == NULL)
            return "";
        
        return to_string(root->val) + '.' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {    
        int i=0;
        TreeNode* root = NULL;
        while(i < data.length())
        {
            string s="";
            while(i < data.length() && data[i] != '.')
            {   
                s+=data[i];
                i++;
            }
            i++;
            
            root = insertInBST(root, stoi(s));
        }
        return root;
    }
    
    TreeNode* insertInBST(TreeNode* root, int s)
    {
        if(root == NULL)
        {
            root = new TreeNode(s);
            return root;
        }    
        
        if(root->val < s)
            root->right = insertInBST(root->right, s);
        else
            root->left = insertInBST(root->left, s);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;