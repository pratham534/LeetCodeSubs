class Solution {
public:
    void solve(int i, int target, vector<int> &candidates, vector<int> &v, set<vector<int>> &s, map<int,int> &mp){
        if(target==0){
            s.insert(v);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            v.push_back(candidates[j]);
            solve(j+1, target-candidates[j], candidates, v, s, mp);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        set<vector<int>> s;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        map<int, int> mp;
        for(auto x : candidates){
            mp[x]=1;
        }
        solve(0, target, candidates, v, s, mp);
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};
