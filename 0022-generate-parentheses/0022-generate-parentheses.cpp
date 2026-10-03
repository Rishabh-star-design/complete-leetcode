//Problem of bactracking or recursion.
class Solution{
    public:

void backtrack(vector<string>& result, string current, int open, int close, int n) {
    // Base Case: Jab string complete ho jaye
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    // Choice 1: Agar opening brackets bache hain toh open lagao
    if (open < n) {
        backtrack(result, current + "(", open + 1, close, n);
    }
    
    // Choice 2: Closing tabhi lagega jab matching open available ho
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}
};