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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(0);
        ListNode * temp=ans;
        int carry=0;
        while(l1 != NULL && l2 != NULL){
            int k=l1->val+l2->val+carry;
            ListNode *t=new ListNode(k%10);
            carry=k/10;
            temp->next=t;
            temp=t;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int k=l1->val+carry;
            ListNode *t=new ListNode(k%10);
            temp->next=t;
            temp=t;
            carry=k/10;
            l1=l1->next;
        }
        while(l2!=NULL){
            int k=l2->val+carry;
            ListNode *t=new ListNode(k%10);
            carry=k/10;
            temp->next=t;
            temp=t;
            l2=l2->next;
        }
        if(carry>0){
            ListNode *t=new ListNode(carry%10);
            temp->next=t;
            temp=t;
            carry/=10;
        }
        return ans->next;
    }
};