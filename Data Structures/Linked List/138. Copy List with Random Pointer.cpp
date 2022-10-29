Question Link: https://leetcode.com/problems/copy-list-with-random-pointer/


// Approach :    
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        
        Node *new_head, *new_last;
        new_head=new_last = new Node(-1);
        
        Node *cur=head;
        while(cur != NULL){
            new_last->next = new Node(cur->val);
            new_last = new_last->next;
            
            mp[cur]=new_last;
            
            cur = cur->next;
        }
        
        Node *c1=head, *c2=new_head->next;
        while(c1 != NULL && c2 != NULL){
            c2->random = mp[c1->random];
            
            c1=c1->next, c2=c2->next;
        }
        
        return new_head->next;
    }
};
