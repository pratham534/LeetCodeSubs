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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        if(n == 1) return true;
        for(int i=0;i<n/2;i++){
            if(v[i]!=v[n-i-1]) return false;
        }
        return true;
    }
};