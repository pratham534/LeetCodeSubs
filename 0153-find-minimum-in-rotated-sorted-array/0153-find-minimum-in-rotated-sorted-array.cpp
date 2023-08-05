class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]<nums[n-1]) return nums[0];
        int l=0,r=n-1;
        int ans=1e4;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }else{
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};