class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        bool isVowel = false;
        bool isCons = false;
        for (char c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    isVowel = true;
                else
                    isCons = true;
            } else if (!isdigit(c))
                return false;
        }
        return isVowel && isCons;
    }
};