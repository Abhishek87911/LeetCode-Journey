/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root,int start=0) {
        if(head==NULL) return true;
        if(root==NULL or (start==1 and root->val!=head->val)) return false;
        return (root->val==head->val and isSubPath(head->next,root->left,1)) or (root->val==head->val and isSubPath(head->next,root->right,1)) or (start==0 and isSubPath(head,root->left,0)) or (start==0 and isSubPath(head,root->right,0));
    }
};