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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        for(auto it: descriptions) {

            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];

            if(mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);
            
            if(mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);
            
            if(isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childs.insert(child);
        }

        for(auto it: descriptions) {
            int parent = it[0];

            if(childs.count(parent) == 0)
                return mp[parent];
        }

        return NULL;
    }
};