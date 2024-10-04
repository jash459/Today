// Link: https://leetcode.com/problems/remove-k-digits/description/
//     : https://leetcode.com/problems/remove-k-digits/solutions/5005706/faster-lesser-detailed-explaination-stack-greedy-step-by-step-explaination-python-java-c/


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end()); // Reverse to get the correct order
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};

/*
Step: size_t pos = result.find_first_not_of('0');

This finds the first position in the string result where the character is not '0'. If all characters are '0', it returns std::string::npos, indicating no such position is found.
Step: result = (pos == std::string::npos) ? "0" : result.substr(pos);

If pos is std::string::npos, it means the string result consists entirely of '0's or is empty, so the smallest number we can return is "0".
Otherwise, it returns the substring of result starting from the first non-'0' character, effectively removing all leading '0's.
*/

/*
The complexity of the given code can be analyzed in terms of both time and space.

### Time Complexity

1. First Loop (Processing Digits):
   - This loop iterates through each digit in the input string `num`. For each digit, there can be at most one pop operation from the stack.
   - Since each digit is pushed and popped from the stack at most once, the overall time complexity for this loop is O(n), where n is the length of the string `num`.

2. Second Loop (Removing Extra Digits):
   - This loop runs up to `k` times. In the worst case, it runs O(n) times if all `k` digits need to be removed from the stack.
   - However, since `k <= n`, this step does not exceed O(n).

3. Third Loop (Constructing Result):
   - This loop pops all elements from the stack and appends them to the result string.
   - The stack can hold at most `n` elements, so this loop runs O(n) times.

4. Reversing the Result String:
   - Reversing a string of length `n` takes O(n) time.

5. Removing Leading Zeros:
   - The operation `find_first_not_of('0')` scans through the result string once, taking O(n) time.
   - Creating a substring from a given position takes O(n) in the worst case.

Therefore, the overall time complexity is dominated by the O(n) operations mentioned above, and it remains O(n).

### Space Complexity

1. Stack:
   - The stack can hold up to `n` characters in the worst case.
   - Hence, the space complexity for the stack is O(n).

2. Result String:
   - The result string can also hold up to `n` characters.
   - The space complexity for the result string is O(n).

Overall, the space complexity is O(n) due to the stack and the result string.

### Summary

- Time Complexity: O(n)
- Space Complexity: O(n)

This makes the algorithm efficient in terms of both time and space for handling the problem of removing `k` digits to form the smallest possible integer.*/