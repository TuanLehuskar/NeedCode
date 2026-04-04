class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int len = s.size();

        int l = 0;
        int r = len - 1;

        while(l < r) {
            if (vowels.count(tolower(s[l])) && vowels.count(tolower(s[r]))) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
            } else if (vowels.count(tolower(s[l])) && !vowels.count(tolower(s[r]))) {
                r--;
            } else {
                l++;
            }
        }
        return s;
    }
};

// Two pointers from both ends; swap when both point to vowels, otherwise advance the non-vowel pointer.
// O(n) time, O(1) space.