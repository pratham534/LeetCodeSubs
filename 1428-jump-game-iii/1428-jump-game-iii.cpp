class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> visited(n,0);
        q.push(start);
        while(!q.empty()){
            int ind = q.front();
            cout<<ind<<"->";
            visited[ind]=1;
            q.pop();
            int diff = arr[ind];
            if(diff==0) return true;
            if(ind-diff>=0 && visited[(ind-diff)]!=1){
                q.push((ind-diff));
            }
            if(ind+diff<n && visited[(ind+diff)]!=1){
                q.push((ind+diff));
            }
        }
        return false;
    }
};