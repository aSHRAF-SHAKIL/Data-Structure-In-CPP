
#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool validParenthesis(const std::string& s) {
        std::stack<char> stack;
        std::unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If the character is an opening bracket, push it onto the stack.
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                // If the stack is not empty, check for matching opening bracket.
                if (!stack.empty()) {
                    if (mapping[c] == stack.top()) {
                        stack.pop(); // Pop the matching opening bracket.
                    } else {
                        return false; // Mismatched closing bracket.
                    }
                } else {
                    return false; // Closing bracket with no corresponding opening bracket.
                }
            }
        }
        // The string is valid if the stack is empty at the end.
        return stack.empty();
    }
};

int main() {
    Solution solution;
    std::string input;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> input;

    if (solution.validParenthesis(input)) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }

    return 0;
}
