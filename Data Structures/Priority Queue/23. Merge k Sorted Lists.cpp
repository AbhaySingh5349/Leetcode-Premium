Question Link: https://leetcode.com/problems/merge-k-sorted-lists/


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
    
    struct node{
        int val;
        ListNode* node;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.val > b.val; // min. heap
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        priority_queue<node,vector<node>,compare> pq;
        for(int i=0;i<lists.size();i++) if(lists[i] != NULL) pq.push({lists[i]->val,lists[i]});
        
        ListNode *head, *last;
        head=last = new ListNode(-1);
        
        while(pq.size()>0){
            struct node tp=pq.top();
            pq.pop();
            
            last->next=tp.node;
            last=last->next;
            
            if(tp.node->next) pq.push({tp.node->next->val,tp.node->next});
        }
        
        return head->next;
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
    
    ListNode* merge(ListNode* p, ListNode* q) {
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
    
    ListNode* mergeSort(vector<ListNode*> &lists, int s, int e){
        if(s==e) return lists[s];
        
        int m=s+(e-s)/2;
        ListNode* left = mergeSort(lists,s,m);
        ListNode* right = mergeSort(lists,m+1,e);
        
        return merge(left,right);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        int n=lists.size()-1;
        return mergeSort(lists,0,n);
    }
};
