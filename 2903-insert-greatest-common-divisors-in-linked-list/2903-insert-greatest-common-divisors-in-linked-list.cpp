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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* curr = head;
        while(curr->next!=NULL){
            ListNode* newnode = new ListNode(__gcd(curr->val,curr->next->val));
            newnode->next=curr->next;
            curr->next=newnode;
            curr=curr->next->next;
            
            
        }
        return head;
    }
};