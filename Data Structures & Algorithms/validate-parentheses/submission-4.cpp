class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;
        
        for (char c : s) {
            // 1. If it's an opening bracket, push it
            if (c == '(' || c == '[' || c == '{') {
                tracker.push(c);
            } 
            // 2. If it's a closing bracket, verify the stack is safe and matches
            else {
                if (tracker.empty()) return false; // Closing bracket with no opening one
                
                char topElement = tracker.top();
                if ((c == ')' && topElement == '(') ||
                    (c == ']' && topElement == '[') ||
                    (c == '}' && topElement == '{')) {
                    tracker.pop(); // Valid match found
                } else {
                    return false; // Mismatched brackets (e.g., "( ]")
                }
            }
        }
        
        // If the stack is empty, all brackets were matched perfectly
        return tracker.empty();
    }
};