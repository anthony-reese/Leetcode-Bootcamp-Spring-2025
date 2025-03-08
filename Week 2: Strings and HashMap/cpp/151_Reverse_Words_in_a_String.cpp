class Solution {
    public:
        string reverseWords(string s) {
            // Step 1: Trim leading and trailing spaces
            int left = 0, right = s.size() - 1;
            while (left <= right && s[left] == ' ') left++;
            while (right >= left && s[right] == ' ') right--;
            s = s.substr(left, right - left + 1);

            // Step 2: Split the string into words
            stringstream ss(s);
            string word;
            vector<string> words;
            while (ss >> word) {
                words.push_back(word);
            }
            
            // Step 3: Reverse the order of words
            reverse(words.begin(), words.end());

            // Step 4: Join the words with a single space
            string result;
            for (int i = 0; i < words.size(); ++i) {
                result += words[i];
                if (i < words.size() - 1) {
                    result += " ";
                }
            }
            return result;
        }
    };
