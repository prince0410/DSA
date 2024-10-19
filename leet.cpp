#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator function to sort the numbers
bool compare(string &a, string &b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    // Convert the integers to strings
    vector<string> strNums;
    for (int num : nums) {
        strNums.push_back(to_string(num));
    }

    // Sort the string numbers using the custom comparator
    sort(strNums.begin(), strNums.end(), compare);

    // Handle the case where the largest number is "0"
    if (strNums[0] == "0") {
        return "0";
    }

    // Concatenate the sorted strings to form the result
    string result = "";
    for (string &numStr : strNums) {
        result += numStr;
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> nums1 = {10, 2};
    cout << "Largest number: " << largestNumber(nums1) << endl;  // Output: "210"

    // Test case 2
    vector<int> nums2 = {3, 30, 34, 5, 9,78};
    cout << "Largest number: " << largestNumber(nums2) << endl;  // Output: "9534330"

    return 0;
}
