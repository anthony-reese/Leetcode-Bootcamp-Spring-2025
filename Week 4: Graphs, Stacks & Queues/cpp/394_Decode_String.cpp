class Solution {
    public:
        string decodeString(string s) {
            stack<int> countStack;
            stack<string> resultStack;
            string currentResult = "";
            int k = 0;

            for (char c : s) {
                if (isdigit(c)) {
                    k = k * 10 + (c - '0');
                  
                } else if (c == '[') {
                    countStack.push(k);
                    resultStack.push(currentResult);
                    k = 0;
                    currentResult = "";
                  
                } else if (c == ']') {
                    int repeatCount = countStack.top();
                    countStack.pop();
                    string decodedSegment = resultStack.top();
                    resultStack.pop();
                    
                    for (int i = 0; i < repeatCount; i++) {
                        decodedSegment += currentResult;
                    }
                    currentResult = decodedSegment;
                } else {
                    currentResult += c;
                }
            }
            return currentResult;
        }
    };
