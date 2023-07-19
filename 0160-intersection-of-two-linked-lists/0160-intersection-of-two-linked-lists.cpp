/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=NULL){
            l1++;
            p1 = p1->next;
        }
        while(p2!=NULL){
            l2++;
            p2 = p2->next;
        }
        int diff = abs(l1-l2);
        if(l1>=l2){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }else{
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        while(headA && headB){
            // whole linkedlist after the matching node has to be matched and not the value at that node
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};