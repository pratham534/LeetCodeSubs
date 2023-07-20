class Solution {
public:
    void allpermute(vector<int> &p, set<vector<int>> &s, vector<int> &nums){
        if(nums.size()==0){
            for(auto x : p) cout<<x<<" ";
            cout<<endl;
            s.insert(p);
            return;
        }
        for(int i=0;i<nums.size();i++){
            p.push_back(nums[i]);
            int x = nums[i];
            nums.erase(nums.begin()+i);
            allpermute(p, s, nums);
            nums.push_back(x);
            sort(nums.begin(),nums.end());
            p.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        vector<int> p;
        for(int i=0;i<n;i++){
            p.push_back(nums[i]);
            int x = nums[i];
            nums.erase(nums.begin()+i);
            allpermute(p, s, nums);
            nums.push_back(x);
            sort(nums.begin(),nums.end());
            p.pop_back();
        }
        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};