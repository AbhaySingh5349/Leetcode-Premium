Question Link: https://leetcode.com/problems/plus-one-linked-list/


// Approach 1:    
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
    
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *q;
        p=head, q=NULL;
        
        while(p!=NULL){
            ListNode* on = p->next;
            p->next=q;
            q=p;
            p=on;
        }
        return q;
    }
    
    ListNode* plusOne(ListNode* head) {
        head=reverseList(head);
        ListNode *preHead, *last;
        preHead=last=new ListNode(-1);
        
        int carry=1;
        while(head!=NULL){
            int val=head->val + carry;
            head->val = val%10;
            carry = val/10;
            
            last->next=head;
            last=last->next;
            
            head=head->next;
        }
        
        if(carry!=0){
            last->next = new ListNode(carry);
            last=last->next;
        }
        
        preHead=reverseList(preHead->next);
        
        return preHead;
    }
};


// Approach 2:
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
    ListNode* plusOne(ListNode* head) {
        ListNode *right_not_nine, *new_head;
        right_not_nine = new_head = new ListNode(0);
        right_not_nine->next = new_head->next = head;
        
        while(head != NULL){
            if(head->val!=9) right_not_nine=head;
            head=head->next;
        }
        
        right_not_nine->val++;
        right_not_nine=right_not_nine->next;
            
        while(right_not_nine != NULL){
            right_not_nine->val=0;
            right_not_nine=right_not_nine->next;
        }
        
        return (new_head->val != 0 ? new_head:new_head->next);
    }
};
