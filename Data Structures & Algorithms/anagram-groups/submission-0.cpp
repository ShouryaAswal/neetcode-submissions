class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<int>> arr(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            for (char c : strs[i]) {
                arr[i][c - 'a']++;
            }
        }

        vector<vector<string>> ans;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<string> anagrams;

                anagrams.push_back(strs[i]);
                vis[i] = 1;

                for (int j = i + 1; j < n; j++) {
                    if (!vis[j] && arr[i] == arr[j]) {
                        anagrams.push_back(strs[j]);
                        vis[j] = 1;
                    }
                }

                ans.push_back(anagrams);
            }
        }

        return ans;
    }
};