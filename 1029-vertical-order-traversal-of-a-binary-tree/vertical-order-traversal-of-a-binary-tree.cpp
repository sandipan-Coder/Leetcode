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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> nodeQ; // This store {node, {row, col}}
        nodeQ.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp;

        while(!nodeQ.empty()){
            auto it = nodeQ.front();
            nodeQ.pop();

            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mp[col][row].insert(node->val);

            if(node->left)
                nodeQ.push({node->left, {row + 1, col - 1}});
            if(node->right)
                nodeQ.push({node->right, {row + 1, col + 1}});
        }

        for(auto secondMap: mp){
            vector<int> col;
            for(auto colVal: secondMap.second)
                col.insert(col.end(), colVal.second.begin(), colVal.second.end());
            ans.push_back(col);
        }

        return ans;
    }
};