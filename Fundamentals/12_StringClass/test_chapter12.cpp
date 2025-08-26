#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <cctype>

void testStringBasics() {
    std::cout << "Test 1: String Basics" << std::endl;
    
    std::string str1;
    std::string str2("Hello");
    std::string str3 = "World";
    std::string str4(str2);
    
    assert(str1.empty());
    assert(str2 == "Hello");
    assert(str3 == "World");
    assert(str4 == str2);
    
    std::cout << "str1 (empty): '" << str1 << "'" << std::endl;
    std::cout << "str2: '" << str2 << "'" << std::endl;
    std::cout << "str3: '" << str3 << "'" << std::endl;
    std::cout << "str4 (copy of str2): '" << str4 << "'" << std::endl;
    
    std::cout << "✓ Test passed: String basics work correctly\n" << std::endl;
}

void testStringOperators() {
    std::cout << "Test 2: String Operators" << std::endl;
    
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string str3 = str1 + " " + str2;
    
    assert(str3 == "Hello World");
    
    str1 += " C++";
    assert(str1 == "Hello C++");
    
    assert(str1[0] == 'H');
    assert(str1[6] == 'C');
    
    str1[6] = 'J';
    assert(str1 == "Hello J++");
    
    std::cout << "Concatenated string: '" << str3 << "'" << std::endl;
    std::cout << "Modified string: '" << str1 << "'" << std::endl;
    
    std::cout << "✓ Test passed: String operators work correctly\n" << std::endl;
}

void testStringComparison() {
    std::cout << "Test 3: String Comparison" << std::endl;
    
    std::string str1 = "Apple";
    std::string str2 = "Banana";
    std::string str3 = "Apple";
    
    assert(str1 == str3);
    assert(str1 != str2);
    assert(str1 < str2);
    assert(str2 > str1);
    assert(str1 <= str3);
    assert(str3 >= str1);
    
    int comparison = str1.compare(str2);
    assert(comparison < 0);
    
    comparison = str1.compare(str3);
    assert(comparison == 0);
    
    std::cout << "str1 == str3: " << (str1 == str3 ? "true" : "false") << std::endl;
    std::cout << "str1 < str2: " << (str1 < str2 ? "true" : "false") << std::endl;
    std::cout << "str1.compare(str2): " << str1.compare(str2) << std::endl;
    
    std::cout << "✓ Test passed: String comparison works correctly\n" << std::endl;
}

void testStringMethods() {
    std::cout << "Test 4: String Methods" << std::endl;
    
    std::string str = "Hello World";
    
    assert(str.length() == 11);
    assert(str.size() == 11);
    assert(!str.empty());
    
    char ch = str.at(6);
    assert(ch == 'W');
    
    std::string substr = str.substr(0, 5);
    assert(substr == "Hello");
    
    substr = str.substr(6);
    assert(substr == "World");
    
    size_t pos = str.find("World");
    assert(pos == 6);
    
    pos = str.find("xyz");
    assert(pos == std::string::npos);
    
    std::cout << "String length: " << str.length() << std::endl;
    std::cout << "Substring (0, 5): '" << str.substr(0, 5) << "'" << std::endl;
    std::cout << "Position of 'World': " << str.find("World") << std::endl;
    
    std::cout << "✓ Test passed: String methods work correctly\n" << std::endl;
}

void testStringModification() {
    std::cout << "Test 5: String Modification" << std::endl;
    
    std::string str = "Hello";
    
    str.append(" World");
    assert(str == "Hello World");
    
    str.insert(5, " Beautiful");
    assert(str == "Hello Beautiful World");
    
    str.erase(5, 10);
    assert(str == "Hello World");
    
    str.replace(6, 5, "C++");
    assert(str == "Hello C++");
    
    str.push_back('!');
    assert(str == "Hello C++!");
    
    str.pop_back();
    assert(str == "Hello C++");
    
    std::cout << "Final string after modifications: '" << str << "'" << std::endl;
    
    std::cout << "✓ Test passed: String modification works correctly\n" << std::endl;
}

void testStringIterators() {
    std::cout << "Test 6: String Iterators" << std::endl;
    
    std::string str = "Hello";
    
    std::string reversed;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        reversed += *it;
    }
    assert(reversed == "olleH");
    
    int vowelCount = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowelCount++;
        }
    }
    assert(vowelCount == 2);
    
    std::cout << "Original: '" << str << "'" << std::endl;
    std::cout << "Reversed: '" << reversed << "'" << std::endl;
    std::cout << "Vowel count: " << vowelCount << std::endl;
    
    std::cout << "✓ Test passed: String iterators work correctly\n" << std::endl;
}

void testStringConversion() {
    std::cout << "Test 7: String Conversion" << std::endl;
    
    int intValue = 123;
    double doubleValue = 45.67;
    
    std::string intStr = std::to_string(intValue);
    std::string doubleStr = std::to_string(doubleValue);
    
    assert(intStr == "123");
    assert(doubleStr.substr(0, 5) == "45.67");
    
    std::string numStr = "456";
    int convertedInt = std::stoi(numStr);
    assert(convertedInt == 456);
    
    std::string floatStr = "78.9";
    double convertedDouble = std::stod(floatStr);
    assert(std::abs(convertedDouble - 78.9) < 0.001);
    
    std::cout << "Int to string: " << intStr << std::endl;
    std::cout << "Double to string: " << doubleStr << std::endl;
    std::cout << "String to int: " << convertedInt << std::endl;
    std::cout << "String to double: " << convertedDouble << std::endl;
    
    std::cout << "✓ Test passed: String conversion works correctly\n" << std::endl;
}

void testStringStreams() {
    std::cout << "Test 8: String Streams" << std::endl;
    
    std::ostringstream oss;
    oss << "Value: " << 42 << ", Pi: " << 3.14159;
    std::string result = oss.str();
    
    assert(result == "Value: 42, Pi: 3.14159");
    
    std::istringstream iss("10 20 30");
    int a, b, c;
    iss >> a >> b >> c;
    
    assert(a == 10);
    assert(b == 20);
    assert(c == 30);
    
    std::stringstream ss;
    ss << "Hello " << 123 << " World";
    std::string word1, word3;
    int number;
    ss >> word1 >> number >> word3;
    
    assert(word1 == "Hello");
    assert(number == 123);
    assert(word3 == "World");
    
    std::cout << "Output stream result: '" << result << "'" << std::endl;
    std::cout << "Input stream values: " << a << ", " << b << ", " << c << std::endl;
    
    std::cout << "✓ Test passed: String streams work correctly\n" << std::endl;
}

void testStringAlgorithms() {
    std::cout << "Test 9: String Algorithms" << std::endl;
    
    std::string str = "hello world";
    
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    assert(str == "HELLO WORLD");
    
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    assert(str == "hello world");
    
    std::string sentence = "the quick brown fox";
    std::replace(sentence.begin(), sentence.end(), ' ', '_');
    assert(sentence == "the_quick_brown_fox");
    
    std::string data = "abcdef";
    std::reverse(data.begin(), data.end());
    assert(data == "fedcba");
    
    std::string sorted = "dcba";
    std::sort(sorted.begin(), sorted.end());
    assert(sorted == "abcd");
    
    std::cout << "Uppercase: '" << str << "'" << std::endl;
    std::cout << "Underscored: '" << sentence << "'" << std::endl;
    std::cout << "Reversed: '" << data << "'" << std::endl;
    std::cout << "Sorted: '" << sorted << "'" << std::endl;
    
    std::cout << "✓ Test passed: String algorithms work correctly\n" << std::endl;
}

void testStringUtilities() {
    std::cout << "Test 10: String Utilities" << std::endl;
    
    auto trim = [](std::string str) {
        str.erase(0, str.find_first_not_of(" \t\n\r"));
        str.erase(str.find_last_not_of(" \t\n\r") + 1);
        return str;
    };
    
    auto split = [](const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    };
    
    auto join = [](const std::vector<std::string>& tokens, const std::string& delimiter) {
        if (tokens.empty()) return std::string();
        std::string result = tokens[0];
        for (size_t i = 1; i < tokens.size(); i++) {
            result += delimiter + tokens[i];
        }
        return result;
    };
    
    std::string whitespaceStr = "  Hello World  ";
    std::string trimmed = trim(whitespaceStr);
    assert(trimmed == "Hello World");
    
    std::string csvData = "apple,banana,cherry";
    auto tokens = split(csvData, ',');
    assert(tokens.size() == 3);
    assert(tokens[0] == "apple");
    assert(tokens[1] == "banana");
    assert(tokens[2] == "cherry");
    
    std::string rejoined = join(tokens, " | ");
    assert(rejoined == "apple | banana | cherry");
    
    std::cout << "Trimmed: '" << trimmed << "'" << std::endl;
    std::cout << "Split tokens: ";
    for (const auto& token : tokens) {
        std::cout << "'" << token << "' ";
    }
    std::cout << std::endl;
    std::cout << "Rejoined: '" << rejoined << "'" << std::endl;
    
    std::cout << "✓ Test passed: String utilities work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 12: String Class" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testStringBasics();
    testStringOperators();
    testStringComparison();
    testStringMethods();
    testStringModification();
    testStringIterators();
    testStringConversion();
    testStringStreams();
    testStringAlgorithms();
    testStringUtilities();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 12 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}