#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>

void testBasicFileIO() {
    std::cout << "Test 1: Basic File I/O" << std::endl;
    
    std::ofstream outFile("test_basic.txt");
    assert(outFile.is_open());
    
    outFile << "Hello, File I/O!" << std::endl;
    outFile << "Line 2" << std::endl;
    outFile << "Line 3" << std::endl;
    outFile.close();
    
    std::ifstream inFile("test_basic.txt");
    assert(inFile.is_open());
    
    std::string line1, line2, line3;
    std::getline(inFile, line1);
    std::getline(inFile, line2);
    std::getline(inFile, line3);
    
    assert(line1 == "Hello, File I/O!");
    assert(line2 == "Line 2");
    assert(line3 == "Line 3");
    
    inFile.close();
    
    std::cout << "Written and read: '" << line1 << "'" << std::endl;
    
    std::remove("test_basic.txt");
    
    std::cout << "✓ Test passed: Basic file I/O works correctly\n" << std::endl;
}

void testTextFileReading() {
    std::cout << "Test 2: Text File Reading" << std::endl;
    
    std::ofstream outFile("test_reading.txt");
    outFile << "apple 5" << std::endl;
    outFile << "banana 3" << std::endl;
    outFile << "cherry 8" << std::endl;
    outFile.close();
    
    std::ifstream inFile("test_reading.txt");
    std::string word;
    int number;
    std::vector<std::pair<std::string, int>> data;
    
    while (inFile >> word >> number) {
        data.push_back({word, number});
    }
    inFile.close();
    
    assert(data.size() == 3);
    assert(data[0].first == "apple" && data[0].second == 5);
    assert(data[1].first == "banana" && data[1].second == 3);
    assert(data[2].first == "cherry" && data[2].second == 8);
    
    std::cout << "Read " << data.size() << " items from file" << std::endl;
    for (const auto& item : data) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
    
    std::remove("test_reading.txt");
    
    std::cout << "✓ Test passed: Text file reading works correctly\n" << std::endl;
}

void testFileAppending() {
    std::cout << "Test 3: File Appending" << std::endl;
    
    std::ofstream outFile("test_append.txt");
    outFile << "Initial line" << std::endl;
    outFile.close();
    
    std::ofstream appendFile("test_append.txt", std::ios::app);
    appendFile << "Appended line 1" << std::endl;
    appendFile << "Appended line 2" << std::endl;
    appendFile.close();
    
    std::ifstream inFile("test_append.txt");
    std::string line;
    std::vector<std::string> lines;
    
    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();
    
    assert(lines.size() == 3);
    assert(lines[0] == "Initial line");
    assert(lines[1] == "Appended line 1");
    assert(lines[2] == "Appended line 2");
    
    std::cout << "Total lines after append: " << lines.size() << std::endl;
    
    std::remove("test_append.txt");
    
    std::cout << "✓ Test passed: File appending works correctly\n" << std::endl;
}

void testBinaryFiles() {
    std::cout << "Test 4: Binary Files" << std::endl;
    
    struct Student {
        char name[20];
        int id;
        double gpa;
    };
    
    Student students[] = {
        {"Alice", 101, 3.8},
        {"Bob", 102, 3.2},
        {"Charlie", 103, 3.9}
    };
    
    std::ofstream binOut("test_binary.dat", std::ios::binary);
    binOut.write(reinterpret_cast<const char*>(students), sizeof(students));
    binOut.close();
    
    Student readStudents[3];
    std::ifstream binIn("test_binary.dat", std::ios::binary);
    binIn.read(reinterpret_cast<char*>(readStudents), sizeof(readStudents));
    binIn.close();
    
    assert(std::string(readStudents[0].name) == "Alice");
    assert(readStudents[0].id == 101);
    assert(std::abs(readStudents[0].gpa - 3.8) < 0.001);
    
    assert(std::string(readStudents[2].name) == "Charlie");
    assert(readStudents[2].id == 103);
    assert(std::abs(readStudents[2].gpa - 3.9) < 0.001);
    
    std::cout << "Binary file student: " << readStudents[0].name 
              << ", ID: " << readStudents[0].id 
              << ", GPA: " << readStudents[0].gpa << std::endl;
    
    std::remove("test_binary.dat");
    
    std::cout << "✓ Test passed: Binary files work correctly\n" << std::endl;
}

void testFilePositioning() {
    std::cout << "Test 5: File Positioning" << std::endl;
    
    std::ofstream outFile("test_position.txt");
    outFile << "0123456789ABCDEF" << std::endl;
    outFile.close();
    
    std::fstream file("test_position.txt", std::ios::in | std::ios::out);
    
    file.seekg(5);
    char ch;
    file.get(ch);
    assert(ch == '5');
    
    file.seekg(10);
    file.get(ch);
    assert(ch == 'A');
    
    file.seekp(5);
    file.put('X');
    
    file.seekg(0);
    std::string line;
    std::getline(file, line);
    assert(line == "01234X6789ABCDEF");
    
    std::streampos pos = file.tellg();
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();
    
    std::cout << "File size: " << size << " bytes" << std::endl;
    std::cout << "Modified line: '" << line << "'" << std::endl;
    
    file.close();
    std::remove("test_position.txt");
    
    std::cout << "✓ Test passed: File positioning works correctly\n" << std::endl;
}

void testErrorHandling() {
    std::cout << "Test 6: Error Handling" << std::endl;
    
    std::ifstream nonexistentFile("nonexistent.txt");
    assert(!nonexistentFile.is_open());
    assert(nonexistentFile.fail());
    
    std::cout << "Correctly detected nonexistent file" << std::endl;
    
    std::ofstream testFile("test_error.txt");
    testFile << "test data" << std::endl;
    testFile.close();
    
    std::ifstream inFile("test_error.txt");
    assert(inFile.is_open());
    assert(inFile.good());
    assert(!inFile.fail());
    assert(!inFile.bad());
    assert(!inFile.eof());
    
    std::string data;
    inFile >> data;
    assert(data == "test");
    
    inFile >> data;
    assert(inFile.eof());
    
    inFile.close();
    std::remove("test_error.txt");
    
    std::cout << "File state checking works correctly" << std::endl;
    
    std::cout << "✓ Test passed: Error handling works correctly\n" << std::endl;
}

void testFormattedOutput() {
    std::cout << "Test 7: Formatted Output" << std::endl;
    
    std::ofstream outFile("test_formatted.txt");
    
    outFile << std::fixed << std::setprecision(2);
    outFile << "Price: $" << 19.999 << std::endl;
    
    outFile << std::setw(10) << std::right << "Right" << std::endl;
    outFile << std::setw(10) << std::left << "Left" << std::endl;
    
    outFile << std::setfill('*') << std::setw(15) << "Centered" << std::endl;
    
    outFile.close();
    
    std::ifstream inFile("test_formatted.txt");
    std::string line1, line2, line3, line4;
    std::getline(inFile, line1);
    std::getline(inFile, line2);
    std::getline(inFile, line3);
    std::getline(inFile, line4);
    inFile.close();
    
    assert(line1 == "Price: $20.00");
    
    std::cout << "Formatted line 1: '" << line1 << "'" << std::endl;
    std::cout << "Formatted line 2: '" << line2 << "'" << std::endl;
    std::cout << "Formatted line 4: '" << line4 << "'" << std::endl;
    
    std::remove("test_formatted.txt");
    
    std::cout << "✓ Test passed: Formatted output works correctly\n" << std::endl;
}

void testCSVProcessing() {
    std::cout << "Test 8: CSV Processing" << std::endl;
    
    std::ofstream csvFile("test_data.csv");
    csvFile << "Name,Age,Score" << std::endl;
    csvFile << "Alice,25,85.5" << std::endl;
    csvFile << "Bob,30,92.0" << std::endl;
    csvFile << "Charlie,28,78.5" << std::endl;
    csvFile.close();
    
    auto parseCSVLine = [](const std::string& line) {
        std::vector<std::string> fields;
        std::stringstream ss(line);
        std::string field;
        
        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }
        return fields;
    };
    
    std::ifstream inFile("test_data.csv");
    std::string line;
    std::vector<std::vector<std::string>> csvData;
    
    while (std::getline(inFile, line)) {
        csvData.push_back(parseCSVLine(line));
    }
    inFile.close();
    
    assert(csvData.size() == 4);
    assert(csvData[0][0] == "Name");
    assert(csvData[1][0] == "Alice");
    assert(csvData[1][1] == "25");
    assert(csvData[2][2] == "92.0");
    
    double totalScore = 0;
    for (size_t i = 1; i < csvData.size(); i++) {
        totalScore += std::stod(csvData[i][2]);
    }
    double avgScore = totalScore / (csvData.size() - 1);
    
    std::cout << "CSV rows: " << csvData.size() << std::endl;
    std::cout << "Average score: " << avgScore << std::endl;
    
    std::remove("test_data.csv");
    
    std::cout << "✓ Test passed: CSV processing works correctly\n" << std::endl;
}

void testFileUtilities() {
    std::cout << "Test 9: File Utilities" << std::endl;
    
    auto fileExists = [](const std::string& filename) {
        std::ifstream file(filename);
        return file.good();
    };
    
    auto getFileSize = [](const std::string& filename) {
        std::ifstream file(filename, std::ios::ate | std::ios::binary);
        return file.tellg();
    };
    
    auto copyFile = [](const std::string& source, const std::string& dest) {
        std::ifstream src(source, std::ios::binary);
        std::ofstream dst(dest, std::ios::binary);
        dst << src.rdbuf();
        src.close();
        dst.close();
    };
    
    std::ofstream testFile("source.txt");
    testFile << "This is a test file for utilities." << std::endl;
    testFile.close();
    
    assert(fileExists("source.txt"));
    assert(!fileExists("nonexistent.txt"));
    
    auto size = getFileSize("source.txt");
    assert(size > 0);
    
    copyFile("source.txt", "copy.txt");
    assert(fileExists("copy.txt"));
    
    auto copySize = getFileSize("copy.txt");
    assert(size == copySize);
    
    std::cout << "Original file size: " << size << " bytes" << std::endl;
    std::cout << "Copy file size: " << copySize << " bytes" << std::endl;
    
    std::remove("source.txt");
    std::remove("copy.txt");
    
    std::cout << "✓ Test passed: File utilities work correctly\n" << std::endl;
}

void testStringStreams() {
    std::cout << "Test 10: String Streams as File Alternatives" << std::endl;
    
    std::ostringstream oss;
    oss << "Student Data:" << std::endl;
    oss << "John " << 123 << " " << 3.75 << std::endl;
    oss << "Jane " << 124 << " " << 3.90 << std::endl;
    
    std::string data = oss.str();
    
    std::istringstream iss(data);
    std::string header, name1, name2;
    int id1, id2;
    double gpa1, gpa2;
    
    std::getline(iss, header);
    iss >> name1 >> id1 >> gpa1;
    iss >> name2 >> id2 >> gpa2;
    
    assert(header == "Student Data:");
    assert(name1 == "John");
    assert(id1 == 123);
    assert(std::abs(gpa1 - 3.75) < 0.001);
    assert(name2 == "Jane");
    assert(id2 == 124);
    assert(std::abs(gpa2 - 3.90) < 0.001);
    
    std::cout << "String stream data:" << std::endl;
    std::cout << header << std::endl;
    std::cout << name1 << " " << id1 << " " << gpa1 << std::endl;
    std::cout << name2 << " " << id2 << " " << gpa2 << std::endl;
    
    std::cout << "✓ Test passed: String streams work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 13: Advanced File I/O" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testBasicFileIO();
    testTextFileReading();
    testFileAppending();
    testBinaryFiles();
    testFilePositioning();
    testErrorHandling();
    testFormattedOutput();
    testCSVProcessing();
    testFileUtilities();
    testStringStreams();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 13 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}