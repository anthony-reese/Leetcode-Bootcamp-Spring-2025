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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; 
        if (!root) return result; 
            
        queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* rightmost = nullptr;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                rightmost = currentNode;

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);                    
            }

            result.push_back(rightmost->val);                
        }
        
        return result;
    }
};
