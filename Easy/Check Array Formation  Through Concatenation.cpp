class Solution {
public:
    class TrieNode
    {
        public:
            map<int, TrieNode*> children;
            bool isWord;
    };
        
    class Trie
    {
        public:
            TrieNode* root;
            Trie()
            {
                root = new TrieNode();
            }

            void insert(vector<int> word)
            {
                TrieNode* node = root;

                for(int i=0; i<word.size(); i++)
                {
                    int ch = word[i];
                    if(node->children.find(ch) == node->children.end())
                    {
                        node->children[ch] = new TrieNode();
                    }
                    node = node->children[ch];
                }
                node->isWord = true;
            }

            bool search(vector<int> word, int start)
            {
                if(start >= word.size())
                    return false;
                
                if(root->children.find(word[start]) == root->children.end())
                    return false;
                
                TrieNode* node = root;

                for(int i=start; i<word.size(); i++)
                {
                    int ch = word[i];
                    if(node->children.find(ch) != node->children.end())
                    {
                        node = node->children[ch];
                    }
                    else 
                    {
                        return search(word, i);
                    }
                }
                return node->isWord;
            }
        };

    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) 
    {    
        Trie* trie = new Trie();

        for(int i = 0; i<pieces.size(); i++)
        {
            trie->insert(pieces[i]);
        }
        
        return trie->search(arr, 0);
    }
};