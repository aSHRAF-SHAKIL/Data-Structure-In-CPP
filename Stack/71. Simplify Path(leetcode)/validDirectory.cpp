
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string dir;

        // Split the path by '/'
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                // Ignore empty strings and "."
                continue;
            } else if (dir == "..") {
                // Go up one directory, if possible
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Add the directory to the stack
                stack.push_back(dir);
            }
        }

        // Construct the simplified path
        std::string result = "/";
        for (const std::string& s : stack) {
            result += s + "/";
        }
        if (result.length() > 1) {
            result.pop_back(); // Remove the trailing '/'
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::string path = "/home//foo/../bar/";
    std::string simplified_path = solution.simplifyPath(path);
    std::cout << "Simplified Path: " << simplified_path << std::endl;
    return 0;
}
