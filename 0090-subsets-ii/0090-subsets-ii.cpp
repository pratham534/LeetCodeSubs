class Solution {
public:
    void uniquesubsets(int start, vector<int> &nums, set<vector<int>> &s, vector<int> &v){
        if(start==nums.size()) return;
        v.push_back(nums[start]);
        s.insert(v);
        uniquesubsets(start+1, nums, s, v);
        v.pop_back();
        s.insert(v);
        uniquesubsets(start+1, nums, s, v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int start;
        start = 0;
        vector<int> v;
        sort(nums.begin(),nums.end());
        uniquesubsets(0, nums, s, v);
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};