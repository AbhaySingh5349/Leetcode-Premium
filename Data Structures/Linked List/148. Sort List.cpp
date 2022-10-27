Question Link: https://leetcode.com/problems/sort-list/


// Approach :    
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
    
    ListNode* getMid(ListNode* head){
        ListNode *slow, *fast;
        slow=fast=head;
        fast=fast->next;
        
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* p, ListNode* q){
        ListNode *head, *last;
        head=last=new ListNode(-1);
        
        while(p!=NULL || q!=NULL){
            int x=(p!=NULL ? p->val:INT_MAX);
            int y=(q!=NULL ? q->val:INT_MAX);
            
            if(x>y){
                last->next = new ListNode(y);
                q=q->next;
            }else{
                last->next = new ListNode(x);
                p=p->next;
            }
            last=last->next;
        }
        return head->next;
    }
    
    ListNode* mergeSort(ListNode* head){
        if(head->next==NULL) return head;
        
        ListNode* mid=getMid(head);
        
        ListNode* head1=head;
        ListNode* head2=mid->next;
        mid->next=NULL;
        return merge(mergeSort(head1),mergeSort(head2));
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        return mergeSort(head);
    }
};
