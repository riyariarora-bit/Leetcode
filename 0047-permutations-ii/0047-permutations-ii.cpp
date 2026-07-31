class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int, int> counter;
    int n;

    void backtrack(vector<int>& temp) {
        if ((int)temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (auto& [num, cnt] : counter) {
            if (cnt >= 1) {
                cnt--;
                temp.push_back(num);

                backtrack(temp);

                temp.pop_back();
                cnt++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int num : nums) {
            counter[num]++;
        }

        n = nums.size();
        vector<int> temp;
        backtrack(temp);
        return result;
    }
};