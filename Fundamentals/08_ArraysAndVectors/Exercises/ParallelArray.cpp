// ## Exercise 3: Parallel Arrays for Student Records

// Design a program using parallel arrays to manage student information:

// **Requirements:**
// - Create three parallel arrays:
//   - `studentNames` (string array) - holds student names
//   - `testScores` (int array) - holds test scores
//   - `letterGrades` (char array) - holds letter grades
// - Store data for at least 6 students
// - Implement functions that accept all three arrays:
//   - `calculateGrades()` - assigns letter grades based on scores (90-100: A, 80-89: B, etc.)
//   - `displayStudentInfo()` - displays name, score, and grade for all students
//   - `findHighestScore()` - returns the name of the student with the highest score
//   - `calculateClassAverage()` - returns the average test score

// **Test your program by:**
// - Populating arrays with sample data
// - Displaying all student information in a formatted table
// - Showing the highest scoring student and class average

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 6;
void calculateGrades(int scores[], char grades [], int size) {
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 90) grades[i] = 'A';
        else if (scores[i] >= 80) grades[i] = 'B';
        else if (scores[i] >= 70) grades[i] = 'C';
        else if (scores[i] >= 60) grades[i] = 'D';
        else grades[i] = 'F';
    }
}

void displayStudentsInfo(string names[], int scores[], char grades[], int size) {
    cout << "Name\tScore\tGrade" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << "\t" << scores[i] << "\t" << grades[i] << endl;
    }
}

string findHighestScore(string names[], int scores[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (scores[i] > scores[highestIndex]) {
            highestIndex = i;
        }
    }
    return names[highestIndex];
}

double calculateClassAverage(int scores[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return static_cast<double>(total) / size;
}


int main(){
    string studentNames[SIZE] = {"Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona"};
    int testScores[SIZE] = {85, 92, 78, 90, 88, 95};
    char letterGrades[SIZE];

    calculateGrades(testScores, letterGrades, SIZE);
    displayStudentsInfo(studentNames, testScores, letterGrades, SIZE);
    cout << "Highest Scoring Student: " << findHighestScore(studentNames, testScores, SIZE) << endl;
    cout << "Class Average: " << calculateClassAverage(testScores, SIZE) << endl;

    return 0;
}