class Solution {
public:
    void solve(int i, int n, vector<string> &ans, string s){
        
    }
    string getPermutation(int n, int k) {
        string s="";
        int prd=1;
        vector<char> nums;
        for(int i=1;i<n;i++){
            prd*=i;
            nums.push_back(i+'0');
        }
        k=k-1;
        nums.push_back(n+'0');
        for(int i=0;i<n;i++){
            s += nums[k/prd];
            nums.erase(nums.begin()+(k/prd));
            if(nums.size()==0) break;
            k = k%prd;
            prd = prd/nums.size();
        }
        cout<<s<<endl;
        return s;
    }
};