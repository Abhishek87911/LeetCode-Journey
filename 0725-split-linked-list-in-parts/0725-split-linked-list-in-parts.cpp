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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int  m =k;
        int len=0;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;


        }

        int e = len/k;
        int rem = len%k;

        curr=head;
        for(int i=0;i<k;i++)
        {
            int x = e;
            if(rem!=0){
                x++;
                rem--;
            }
            if(curr==NULL){
                res.push_back(NULL);
                continue;
            }
            ListNode* temp;
            temp=curr;
            
            while(x!=0 and curr!=NULL){
                 if(x==1)  {
                     ListNode* t = curr;
                     curr=curr->next;
                     t->next=NULL;
                     
                     x--;
                     continue;
                 }
                 x--;
               curr=curr->next;
              
            }
            
            res.push_back(temp);
            

        }
        return res;
    }
};