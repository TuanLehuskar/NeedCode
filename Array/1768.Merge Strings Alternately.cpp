class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        res.reserve(word1.size() + word2.size());

        int i = 0;
        while (i < word1.size() || i < word2.size()) {
            if (i < word1.size()) res += word1[i];
            if (i < word2.size()) res += word2[i];
            i++;
        }

        return res;
    }
};

// Interleave characters one by one; append the remaining tail of the longer string.
// O(n) time, O(n) space.