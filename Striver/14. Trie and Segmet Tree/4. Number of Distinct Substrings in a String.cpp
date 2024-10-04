// Link: https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/

// video: https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=5

/*
1. Brute
                                
#include <iostream>
#include <set>
#include <string>
using namespace std;

// Function to count all distinct
// substrings of a given string
set<string> countDistinctSubstrings(const string& s) {
    // Set to store
    // distinct substrings
    set<string> st;

    // Length of the
    // input string
    int n = s.length();

    // Iterate over each
    // character in the string
    for (int i = 0; i < n; i++) {
        // Initialize an empty string
        // to store the current substring
        string str = "";

        // Iterate over the remaining characters 
        // in the string starting from index i
        for (int j = i; j < n; j++) {
            // Append the current
            // character to the substring
            str += s[j];

            // Insert the current
            // substring into the set
            st.insert(str);
        }
    }

    // Return the set containing
    // all distinct substrings
    return st;
}

int main() {
    string s = "striver";
    cout << "Given String: " << s << endl;

    // Call the function to
    // count distinct substrings
    set<string> substrings = countDistinctSubstrings(s);
    int count = 0;
    // Print the distinct substrings
    cout << "Distinct Substrings:" << endl;
    for (const auto& substr : substrings) {
        cout << substr << endl;
        count ++;
    }
    // Count + 1 as we have to count
    // the empty string as well
    cout << "Number of distinct substrings: "<< count + 1<< endl;

    return 0;
}
                                
                            
Time Complexity: O(N*N) where N is the number of characters in the given word. The implementation has two nested loops:

The outer loop iterates over each character of the string, leading to O(N) iterations.
The inner loop iterates over the remaining characters in the string for each character, also leading to O(N) iterations in the worst case.
Space Complexity : O(N*N)where N is the number of characters in the given word. The size of the set to store distinct substrings can grow up to O(N*N) in the worst case where all substrings are distinct. Each substring stored in the set occupies space proportional to its length, but the total space occupied by all substrings will limit to O(N*N).
*/

// 2. 

                                
#include <iostream>  
#include <string>    

using namespace std;  


// Node structure representing
// each node in the trie
struct Node {
    Node* links[26];  
    // Array of pointers to child nodes,
    // each corresponding to a letter
    // of the alphabet
    bool flag = false;  
    // Flag indicating if the current
    // node represents the end of a substring

    // Method to check if a specific character key
    // exists in the children of the current node
    bool containsKey(char ch) {  
        // Check if the current node has a child node
        // corresponding to character 'ch'
        return (links[ch - 'a'] != NULL);
    }

    // Method to get the child node corresponding
    // to a specific character key
    Node* get(char ch) {  
        // Get the child node
        // corresponding to character 'ch'
        return links[ch - 'a'];
    }

    // Method to insert a new child
    // node with a specific character key
    void put(char ch, Node* node) {  
        // Insert a new child
        // node for character 'ch'
        links[ch - 'a'] = node;
    }

    // Method to mark the current
    // node as the end of a substring
    void setEnd() {  
        // Mark the current node
        // as the end of a substring
        flag = true;
    }

    // Method to check if the current
    // node marks the end of a substring
    bool isEnd() {  
        // Check if the current node
        // marks the end of a substring
        return flag;
    }
};

// Function to count the number of
// distinct substrings in the given string
int countDistinctSubstrings(string &s) {  
    // Function to count distinct
    // substrings in the input string 's'
    Node* root = new Node();  
    // Creating the root
    // node of the trie
    int cnt = 0;  
    // Counter to keep track
    // of distinct substrings
    int n = s.size();  
    // Length of the input string

    // Nested loops to iterate through all
    // possible substrings of the input string
    for (int i = 0; i < n; i++) {  
        // Iterate through each
        // starting position of the substring
        Node* node = root;  
        // Start from the root for each substring
        for (int j = i; j < n; j++) {  
            // Iterate through each character of the substring
            // If the current character is not a child
            // of the current node, insert it as a new child node
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());  
                // Insert a new child
                // node for character s[j]
                cnt++;  
                // Increment the counter
                // since a new substring is found
            }
            node = node->get(s[j]);  
            // Move to the child node
            // corresponding to character s[j]
        }
    }
     // Return the total count of distinct substrings
     // (+1 to account for the input string itself)
    return cnt + 1;  
  
}

int main() {  
    // Main function to test the
    // countDistinctSubstrings function
    string s = "striver";  
    cout << "Current String: " << s << endl;
    // Input string
    cout << "Number of distinct substrings: " << countDistinctSubstrings(s) << endl;  
    return 0;  

}
                                
// Time Complexity: O(N*N)where N is the length of the input string. This is because for each starting position of the substring, we traverse the entire substring once. However, due to the Trie structure, the actual number of comparisons is reduced as we progress.

// Space Complexity : O(N*N) where N is the length of the input string. In the worst-case scenario, where there are no common prefixes among substrings the number of nodes could be as high as the total number of substrings which is bounded by O(N*N).