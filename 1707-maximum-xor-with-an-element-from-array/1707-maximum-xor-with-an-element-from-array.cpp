class TrieNode {
    public:
    vector<TrieNode*> next;
    int value;
    TrieNode() {
        value = -1;
        next.resize(2);
        for (auto& x : next)
            x = NULL;
    }
};
class Solution {
public:
    TrieNode* root;

    void insert(int num) {
        TrieNode* head = root;
        for (int i = 31; i >= 0; i--) {
            int ind = (num >> i) & 1;
            if (head->next[ind] == NULL) {
                head->next[ind] = new TrieNode();
            }
            head = head->next[ind];
        }
        head->value = num;
    }

    int findMaxXOR(int val) {
        TrieNode* head = root;
        for (int i = 31; i >= 0; i--) {
            int ind = (val >> i) & 1;
            int revind = (ind ^ 1);
            if (head->next[revind] != NULL) {
                head = head->next[revind];
            } else {
                head = head->next[ind];
            }
        }
        int res = val ^ (head->value);
        return res;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root = new TrieNode();
        int q = queries.size();
        int n = nums.size();
        vector<int> ans(q);
        /*
        / OFFLINE QUERIES
        */
        sort(nums.begin(),nums.end());
        for (int i = 0; i < q; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int j = 0;
        for (int i = 0; i < q; i++) {
            auto query = queries[i];
            cout<<query[0]<<":"<<query[1]<<":"<<query[2]<<endl;
            while(j<n && nums[j]<=query[1]){
                insert(nums[j]);
                j++;
            }
            if (j == 0) {
                ans[query[2]] = -1;
                continue;
            }
            int res = findMaxXOR(query[0]);
            ans[query[2]]=res;
        }
        return ans;
    }
};