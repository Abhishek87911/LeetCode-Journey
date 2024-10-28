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
    int dfs(TreeNode* root,map<int,multiset<int>> &ml,int lev,vector<int> &mp,vector<int> &height)
    {
        if(root==NULL) return 0;
        int lh = dfs(root->left,ml,lev+1,mp,height);
        int rh = dfs(root->right,ml,lev+1,mp,height);
        ml[lev].insert(max(lh,rh)-1);
        mp[root->val]=lev;
        height[root->val]=max(lh,rh)-1;
        return 1+max(lh,rh);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int,multiset<int>> ml;
        vector<int> mp(1e5+1,0);
        vector<int> height(1e5+1,0);
        dfs(root,ml,0,mp,height);
        vector<int> ans;
        for(auto q: queries) {
            int lev = mp[q];
            int h = height[q];
            ml[lev].erase(ml[lev].find(h));
            if(ml[lev].size()==0) ans.push_back(lev-1);
            else ans.push_back(lev+*ml[lev].rbegin()+1);
            ml[lev].insert(h);

        }
        return ans;

    }
};