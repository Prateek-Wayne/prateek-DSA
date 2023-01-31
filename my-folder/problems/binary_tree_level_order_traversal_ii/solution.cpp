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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
      queue<TreeNode *> q;
      if(root==NULL)
        return ans;
      q.push(root);
      while(1)
      {
          
          int size=q.size();
          if(size==0)
             break;
          
          vector<int> d;
          
          while(size>0)
          {
              TreeNode *temp=q.front();
              q.pop();
              d.push_back(temp->val);
              if(temp->left)
                q.push(temp->left);
              if(temp->right)
                q.push(temp->right);
              size--;
          }
          ans.push_back(d);
      }
    reverse(ans.begin(),ans.end());
    return ans;
        
    }
};