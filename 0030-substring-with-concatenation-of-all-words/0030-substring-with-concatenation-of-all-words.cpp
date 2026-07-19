class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> target;

        for (string &w : words)
            target[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};