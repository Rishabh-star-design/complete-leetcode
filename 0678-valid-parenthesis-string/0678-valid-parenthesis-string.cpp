class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--; // Fixed: max_open must decrease for ')'
            } else { // c == '*'
                min_open--; // If '*' acts as ')'
                max_open++; // If '*' acts as '('
            }
            
            // If at any point the maximum possible open brackets is negative,
            // it means we have too many closing brackets.
            if (max_open < 0) return false;
            
            // min_open cannot drop below 0 because we can't match 
            // closing brackets that appeared before open brackets.
            min_open = std::max(min_open, 0); 
        }
        
        // If min_open is 0, it means all open brackets could be validly closed.
        return min_open == 0;
    }
};
