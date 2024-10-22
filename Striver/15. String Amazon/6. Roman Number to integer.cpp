// Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

/*
1. Brute 

public int romanToDecimal(String str)
{
    int ans = 0;

    for (int i = 0; i < str.length() - 1; i++)
    {
        int n1 = convert(str.charAt(i));
        int n2 = convert(str.charAt(i + 1));

        if (n1 >= n2)
            ans += n1;

        else
            ans -= n1;
    }

    ans += convert(str.charAt(str.length() - 1));

    return ans;
}
public int convert(char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;
}


*/

// 2. Optimal :

int romanToDecimal(string &str)
{
    // code here
    int n = str.length();
    map<char, int> map;
    map.insert({'I', 1});
    map.insert({'V', 5});
    map.insert({'X', 10});
    map.insert({'L', 50});
    map.insert({'C', 100});
    map.insert({'D', 500});
    map.insert({'M', 1000});

    int sum = map[str[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        if (map[str[i]] >= map[str[i + 1]])
        {
            sum += map[str[i]];
        }
        else
        {
            sum -= map[str[i]];
        }
    }
    return sum;
}

/*
Rules of Roman Numerals:
Addition Rule: If a Roman numeral is followed by another numeral of equal or lesser value, their values are added. For example:

"VI" = V (5) + I (1) = 6
"XV" = X (10) + V (5) = 15
Subtraction Rule: If a Roman numeral is followed by another numeral of greater value, the first numeral is subtracted from the second. This is used to avoid four identical symbols in succession. For example:

"IV" = V (5) - I (1) = 4
"IX" = X (10) - I (1) = 9
"XL" = L (50) - X (10) = 40
*/