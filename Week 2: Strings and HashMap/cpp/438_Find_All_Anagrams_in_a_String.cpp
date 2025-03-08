class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            if (s.length() < p.length()) return result;
    
            vector<int> count_p(26, 0);
            vector<int> count_window(26, 0);
    
            for (int i = 0; i < p.length(); i++) {
                count_p[p[i] - 'a']++;
                count_window[s[i] - 'a']++;
            }
            if (count_window == count_p) {
                result.push_back(0);
                }
            for (int i = p.length(); i <s.length(); i++) {
                count_window[s[i - p.length()] - 'a']--;
    
                count_window[s[i] - 'a']++;
                
                if (count_window == count_p) {
                    result.push_back(i - p.length() + 1);
                }
            }   
            return result;
        }
    };
