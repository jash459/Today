// Link : https://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<char, char> employers = {
        {'A', 'C'},
        {'B', 'C'},
        {'C', 'F'},
        {'D', 'E'},
        {'E', 'F'},
        {'F', 'F'}
    };
    // manager , employeer
    std::unordered_map<char, int> result;
    for (const auto& pair : employers) {
        result[pair.first] = 0;
    }

    for (const auto& pair : employers) {
        if (pair.second != pair.first) {
            result[pair.second]++;
            char manager = pair.second;
            while (employers[manager] != manager) {
                result[employers[manager]]++;
                manager = employers[manager];
            }
        }
    }

    for (const auto& pair : employers) {
        std::cout << pair.first << ':' << (result.count(pair.first) ? result[pair.first] : 0) << std::endl;
    }

    return 0;
}


