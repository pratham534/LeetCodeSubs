class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<pair<int, int>> q;
        int n = arr.size();
        map<int, vector<int>> similar;
        for (int i = 0; i < n; i++) {
            similar[arr[i]].push_back(i);
        }
        vector<int> visited(n, 0);
        int ct = 0;
        q.push({0, 0});
        visited[0]=1;
        while (!q.empty()) {
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            // visited[curr] = 1;
            if (curr == n - 1)
                return steps;
            if (curr + 1 < n && visited[curr + 1] == 0){
                visited[curr+1]=1;
                q.push({curr + 1, steps + 1});
            }
            if (curr - 1 >= 0 && visited[curr - 1] == 0){
                visited[curr-1]=1;
                q.push({curr - 1, steps + 1});
            }
            for (auto& i : similar[arr[curr]]) {
                if (i != curr && visited[i] == 0) {
                    visited[i]=1;
                    q.push({i, steps + 1});
                }
            }
            similar.erase(arr[curr]);
        }
        return n;
    }
};