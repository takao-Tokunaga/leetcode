class Solution {
    public:
        bool isValid(string s) {
            stack <char> open_brackets;
            unordered_map<char, char> bracket_pair {
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
            };
            for (char c : s) {
                if (bracket_pair.contains(c)) {
                    open_brackets.push(c);
                    continue;
                }
                if (open_brackets.empty()) {
                    return false;
                }
                char excepted_closing = bracket_pair.at(open_brackets.top());
                if (c != excepted_closing) {
                    return false;
                }
                open_brackets.pop();
            }
            return open_brackets.empty();
        }
    };