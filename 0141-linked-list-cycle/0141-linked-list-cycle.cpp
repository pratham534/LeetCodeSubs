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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mp;
        ListNode* ptr=head;
        while(ptr){
            if(mp[ptr]==1){
                return true;
            }
            mp[ptr]=1;
            ptr = ptr->next;
        }
        return false;
    }
};