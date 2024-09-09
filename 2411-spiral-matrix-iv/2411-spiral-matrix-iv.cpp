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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int left=0,right=n-1,bottom=m-1,up=0;
        while(left<=right and up<=bottom and head!=NULL){
            for(int i=left;i<=right and head!=NULL;i++){
                ans[up][i] = head->val;
                head=head->next;
            }
            up++;
            for(int i=up;i<=bottom and head!=NULL;i++){
                ans[i][right] = head->val;
                head=head->next;
            }
            right--;
            if(left<=right and up<=bottom){
                for(int i=right;i>=left and head!=NULL;i--){
                ans[bottom][i] = head->val;
                head=head->next;
            }
            bottom--;
            }
             if(left<=right and up<=bottom){
                for(int i=bottom;i>=up and head!=NULL;i--){
                ans[i][left] = head->val;
                head=head->next;
            }
            left++;
            }
            

        }
        return ans;
    }
};