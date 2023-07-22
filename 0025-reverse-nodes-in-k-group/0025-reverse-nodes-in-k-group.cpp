class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* ptr = head;
        if(ptr == NULL) return ptr;
        ListNode* ans = NULL;
        ans = ptr;
        ListNode* newNode = NULL;
        vector<int> v;
        while(ptr)
        {
            if(v.size()==0)
            {
                newNode = ptr;
            }
            if(newNode == NULL) break;
            v.push_back(newNode->val);
            if(v.size()<k)
            {
                newNode = newNode->next;
            }
            else
            {
                while(v.size()>=1)
                {
                    ptr->val = v.back();
                    v.pop_back();
                    ptr = ptr->next;
                }
            }
        }
        return ans;
    }
};