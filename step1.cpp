class Solution {
    public:
        bool isValid(string s) {
            string open;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    open += s[i];
                }
    
                if (!open.empty()) {
                  if (s[i] == ')' &&  open.back() == '(') {
                    open.pop_back();
                    continue;
                  }
                  if (s[i] == ']' &&  open.back() == '[') {
                    open.pop_back();
                    continue;
                  }
                  if (s[i] == '}' &&  open.back() == '{') {
                    open.pop_back();
                    continue;
                  }
                } 
                
                if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    return false;
                }
            }
            if (open.empty()) {
                return true;
            } else {
                return false;
            }
            
        }
    };