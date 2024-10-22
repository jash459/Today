// Link: https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

int isValid(string s) {
    // Step 1: Check if the string contains any alphabetic characters
    for (char c : s) {
        if (isalpha(c)) return 0;  // If any character is a letter, return 0
    }

    // Step 2: Split the string into parts based on dots
    vector<string> v;
    string str = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') {
            if(str != "") {
                v.push_back(str); // Add the part to the vector
            }
            str = ""; // Reset the string for the next part
        } else {
            str += s[i]; // Build the current part
        }
    }
    v.push_back(str); // Add the last part

    // Step 3: Check if we have exactly 4 parts
    if(v.size() != 4) return 0;

    // Step 4: Validate each part
    for(int i = 0; i < v.size(); i++) {
        // Convert the current part to an integer
        int num = stoi(v[i]);
        
        // Check if the part is a valid number without leading zeros
        if((num == 0 && v[i].size() != 1) || (num != 0 && v[i][0] == '0')) return 0;

        // Check if the number is within the valid range
        if(num < 0 || num > 255) return 0;
    }

    // If all checks passed, return true
    return 1;
}


// Expected Time Complexity: O(N), N = length of the string.
// Expected Auxiliary Space: O(1)

/*
You need to validate whether a given string is a valid IPv4 address. An IPv4 address is valid if:

It consists of four decimal numbers separated by dots.
Each decimal number should be in the range 0 to 255.
Leading zeros are not allowed unless the number is exactly zero.
Each part is converted to an integer using stoi.
If the part is zero (num == 0) but its length is not 1 (meaning it's not exactly "0"), it's invalid.
If the part is not zero but starts with '0' (leading zero), it's invalid.
If the integer is not within the range 0 to 255, it's invalid.
*/
