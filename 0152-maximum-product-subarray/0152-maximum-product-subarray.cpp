class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0],prod2 = nums[0],maxp=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i],nums[i]*prod1,nums[i]*prod2});
            prod2 = min({nums[i],nums[i]*prod1,nums[i]*prod2});
            prod1 = temp;
            maxp = max(maxp,prod1);
        }
        return maxp;
    }
};