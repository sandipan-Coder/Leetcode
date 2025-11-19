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
private:

    void createParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap, TreeNode* &startNode, int start){

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        
        for(int i = 0; i < size; i++){

            TreeNode* node = q.front();
            q.pop();
            if(node->val == start)
                startNode = node;
            
            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    return;
}

public:
    int amountOfTime(TreeNode* root, int start) {
        
        TreeNode* startNode = NULL;
        unordered_map<TreeNode*, TreeNode*> parentMap;


        createParentMap(root, parentMap, startNode, start);

        int time = -1;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;

        q.push(startNode);
        st.insert(startNode);

        while(!q.empty()){

            time++;
            int size = q.size();
            
            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !st.count(node->left)){
                    q.push(node->left);
                    st.insert(node->left);
                }

                if(node->right && !st.count(node->right)){
                    q.push(node->right);
                    st.insert(node->right);
                }

                if(parentMap.count(node) && !st.count(parentMap[node])){
                    q.push(parentMap[node]);
                    st.insert(parentMap[node]);
                }
            }
        }

        return time;
    }
};