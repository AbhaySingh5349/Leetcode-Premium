Question Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/


// Approach :    
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* root) {
        if(root==NULL) return NULL;
        
        Node* head=root;
        while(head!=NULL){
            if(head->child!=NULL){
                Node* on=head->next;
                
                Node* newNext=flatten(head->child);
                
                head->child=NULL;
                head->next=newNext;
                if(newNext) newNext->prev=head;
                
                Node* last=newNext;
                while(last!=NULL && last->next!=NULL) last=last->next;
                if(last) last->next=on;
                if(on) on->prev=last;
            }
            head=head->next;
        }
        return root;
    }
};
