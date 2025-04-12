class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            
            int n = nums.size();
            vector<vector<int>> buckets(n + 1);
            for (auto& pair : freq) {
                int element = pair.first;
                int count = pair.second;
                buckets[count].push_back(element);
            }

            vector<int> result;
            for (int i = n; i >= 0 && result.size() < k; --i) {
                for (int element : buckets[i]) {
                    result.push_back(element);
                    if (result.size() == k) break;
                }
            }
            
            return result;
    }
};
