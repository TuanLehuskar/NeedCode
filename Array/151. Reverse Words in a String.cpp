class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int len = s.size();
        
        while (i < len) {
            
            while (i < len && s[i] == ' ') {
                i++;
            }

            if (i < len) {
                int j = i;
                while (j < len && s[j] != ' ') {
                    j++;
                }
                string temp = s.substr(i, j - i);
                words.push_back(temp);
                i = j;
            }
        }
        string res;
        for (int k = words.size() - 1; k >= 0; k--) {
            res += words[k];
            if (k > 0) {
                res += ' ';
            }
        }
        return res;
    }
};

// Extract words by skipping spaces, push into vector, then join in reverse order.
// O(n) time, O(n) space.