#include "boykisser_converter.h"

std::string boykisser_converter::convert(const std::string& input){
    std::string binaryString = "";
    for (char c : input) {
        binaryString += std::bitset<8>(c).to_string() + " ";
    }
    return binaryString;
}

