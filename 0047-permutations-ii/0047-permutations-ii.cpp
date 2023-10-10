class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& nums) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used; // To keep track of used elements
        for (int i = ind; i < nums.size(); i++) {
            if (used.count(nums[i])) {
                continue; // Skip duplicates
            }
            used.insert(nums[i]);
            
            swap(nums[ind], nums[i]);
            solve(ind + 1, ans, nums);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int ind = 0;
        solve(ind, ans, nums);
        return ans;
    }
};