class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(),nums.end(),target);
        if(it==nums.begin() || (*(--it))!=target) return -1;
        else return (it-nums.begin());
    }
};