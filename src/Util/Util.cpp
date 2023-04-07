#include "Util.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>

using std::ifstream;



auto Pow(const int x, const int y) -> int {
    // x^0 = 1
    if (y == 0) {
        return 1;
    }

    // Loop through y-1 times and multiply the current value by x
    int result = x;
    for (int i = 0; i < y-1; i++) {
        result *= x;
    }

    return result;
}

auto DenaryToBinary(int x, const int bits) -> vector<bool> {
    vector<bool> binary;

    // If x is greater than the maximum value for the given number of bits, that's an overflow
    // For the algorithm to work with this we'll need x >= 0 and x < max value
    int max_value = Pow(2, bits);
    if (x >= max_value) {
        x -= max_value;
    }

    // We'll start at the MSB, so find the value of said MSB
    int bit_value = max_value / 2;

    binary.reserve(bits);

    // Loop through every bit
    for (int bit = 0; bit < bits; bit++) {

        // Find if the current bit should be 1 or 0, add either 0 or 1 to the result string based on this
        // If the bit should be 1, subtract the bit value - this will allow us to use the same
        // technique on the next iteration
        if ((x - bit_value) >= 0) {
            binary.push_back(1);
            x -= bit_value;
        } else {
            binary.push_back(0);
        }

        // Next bit value will be half the previous one
        bit_value /= 2;
    }

    return binary;
}

auto DenaryToBinaryString(int x, const int bits) -> string {
    vector<bool> binary = DenaryToBinary(x, bits);
    string binary_string;
    for (const bool b : binary) {
        if (b) {
            binary_string.push_back('1');
        } else {
            binary_string.push_back('0');
        }
    }
    return binary_string;
}

auto Contains(const vector<int> &container, const int target) -> bool {
    return std::count(container.begin(), container.end(), target) != 0;
}

auto FormatValue(int x) -> string {
    if (x <= 9) {
        return "0" + std::to_string(x);
    }
    return std::to_string(x);
}

auto FormatAddress(int x) -> string {
    if (x <= 9) {
        return "000" + std::to_string(x);
    }

    if (x <= 99) {
        return "00" + std::to_string(x);
    }

    if (x <= 999) {
        return "0" + std::to_string(x);
    }
    
    return std::to_string(x);
}