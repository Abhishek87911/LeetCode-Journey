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
    long long  kthLargest(vector < long long > & arr, int K) {
  sort(arr.begin(), arr.end(), greater < long long > ());
  return arr[K - 1];
}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        vector<long long> t;
        q.push(root);
       
        while(!q.empty())
        {
            long long siz = q.size();
            long long sum=0;
            while(siz--)
            {
                
                TreeNode *x = q.front();
                q.pop();
                sum+=x->val;
                if(x->left!=NULL) q.push(x->left);
                if(x->right!=NULL) q.push(x->right);
                
                
                
            }
            t.push_back(sum);
        }
        
       sort(t.begin(),t.end(),greater<long long>());
        // for(auto x: t) cout<<x<<" ";
        // cout<<endl;
      if(t.size()<k) return -1;
        else return kthLargest(t,k);
            
        }
        
        
    
};