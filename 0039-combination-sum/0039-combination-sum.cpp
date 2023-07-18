class Solution {
public:
    void solve(int i, set<vector<int>> &s, vector<int> &v, vector<int> &candidates, int target){
        if(i==candidates.size()) return;
        if(candidates[i]>target) return;
        if(candidates[i]==target){
            v.push_back(candidates[i]);
            s.insert(v);
            v.pop_back();
            
        }
        v.push_back(candidates[i]);
        solve(i, s, v, candidates, target-candidates[i]);
        v.pop_back();
        solve(i+1, s, v, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> s;
        vector<int> v;
        vector<vector<int>> ans;
        solve(0, s, v, candidates, target);
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};