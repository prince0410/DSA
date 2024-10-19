#include <iostream>
#include <string>
#include <algorithm>  // For std::max

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    size_t maxLength = 0;
    size_t currentLength = 0;

    for (char c : input) {
        if (std::isspace(c)) {
            // If we encounter a space, we compare currentLength with maxLength
            maxLength = std::max(maxLength, currentLength);
            currentLength = 0;  // Reset currentLength for the next word
        } else {
            // If it's not a space, we increase the currentLength
            ++currentLength;
        }
    }

    // We need to check the last word's length as well
    maxLength = std::max(maxLength, currentLength);

    std::cout << "The maximum length of a word in the given string is: " << maxLength << std::endl;
    return 0;
}
