#include <iostream>
#include <string>
#include <cassert>

void testRelationalOperators() {
    std::cout << "Test 1: Relational Operators" << std::endl;
    
    int a = 5, b = 10;
    
    assert(a < b);
    assert(b > a);
    assert(a <= 5);
    assert(b >= 10);
    assert(a == 5);
    assert(a != b);
    
    std::cout << "5 < 10: " << (a < b ? "true" : "false") << std::endl;
    std::cout << "10 > 5: " << (b > a ? "true" : "false") << std::endl;
    std::cout << "5 <= 5: " << (a <= 5 ? "true" : "false") << std::endl;
    std::cout << "10 >= 10: " << (b >= 10 ? "true" : "false") << std::endl;
    std::cout << "5 == 5: " << (a == 5 ? "true" : "false") << std::endl;
    std::cout << "5 != 10: " << (a != b ? "true" : "false") << std::endl;
    
    std::cout << "✓ Test passed: Relational operators work correctly\n" << std::endl;
}

void testIfStatement() {
    std::cout << "Test 2: if Statement" << std::endl;
    
    int score = 85;
    std::string result = "";
    
    if (score >= 60) {
        result = "Pass";
    }
    
    assert(result == "Pass");
    std::cout << "Score: " << score << ", Result: " << result << std::endl;
    
    int age = 15;
    std::string category = "";
    
    if (age < 18) {
        category = "Minor";
    }
    
    assert(category == "Minor");
    std::cout << "Age: " << age << ", Category: " << category << std::endl;
    
    std::cout << "✓ Test passed: if statement works correctly\n" << std::endl;
}

void testIfElseStatement() {
    std::cout << "Test 3: if-else Statement" << std::endl;
    
    int temperature = 75;
    std::string weather;
    
    if (temperature > 80) {
        weather = "Hot";
    } else {
        weather = "Comfortable";
    }
    
    assert(weather == "Comfortable");
    std::cout << "Temperature: " << temperature << "°F, Weather: " << weather << std::endl;
    
    bool isRaining = false;
    std::string advice;
    
    if (isRaining) {
        advice = "Take an umbrella";
    } else {
        advice = "Enjoy the weather";
    }
    
    assert(advice == "Enjoy the weather");
    std::cout << "Is raining: " << (isRaining ? "Yes" : "No") << ", Advice: " << advice << std::endl;
    
    std::cout << "✓ Test passed: if-else statement works correctly\n" << std::endl;
}

void testNestedIf() {
    std::cout << "Test 4: Nested if Statements" << std::endl;
    
    int score = 85;
    std::string grade;
    
    if (score >= 90) {
        grade = "A";
    } else if (score >= 80) {
        grade = "B";
    } else if (score >= 70) {
        grade = "C";
    } else if (score >= 60) {
        grade = "D";
    } else {
        grade = "F";
    }
    
    assert(grade == "B");
    std::cout << "Score: " << score << ", Grade: " << grade << std::endl;
    
    std::cout << "✓ Test passed: Nested if statements work correctly\n" << std::endl;
}

void testLogicalOperators() {
    std::cout << "Test 5: Logical Operators" << std::endl;
    
    int age = 25;
    bool hasLicense = true;
    bool canDrive;
    
    canDrive = (age >= 16) && hasLicense;
    assert(canDrive == true);
    std::cout << "Age >= 16 AND has license: " << (canDrive ? "Can drive" : "Cannot drive") << std::endl;
    
    bool isWeekend = false;
    bool isHoliday = true;
    bool isDayOff;
    
    isDayOff = isWeekend || isHoliday;
    assert(isDayOff == true);
    std::cout << "Weekend OR holiday: " << (isDayOff ? "Day off" : "Work day") << std::endl;
    
    bool isSunny = false;
    bool needsUmbrella = !isSunny;
    assert(needsUmbrella == true);
    std::cout << "NOT sunny: " << (needsUmbrella ? "Need umbrella" : "No umbrella needed") << std::endl;
    
    std::cout << "✓ Test passed: Logical operators work correctly\n" << std::endl;
}

void testSwitchStatement() {
    std::cout << "Test 6: switch Statement" << std::endl;
    
    int dayNumber = 3;
    std::string dayName;
    
    switch (dayNumber) {
        case 1:
            dayName = "Monday";
            break;
        case 2:
            dayName = "Tuesday";
            break;
        case 3:
            dayName = "Wednesday";
            break;
        case 4:
            dayName = "Thursday";
            break;
        case 5:
            dayName = "Friday";
            break;
        case 6:
            dayName = "Saturday";
            break;
        case 7:
            dayName = "Sunday";
            break;
        default:
            dayName = "Invalid day";
    }
    
    assert(dayName == "Wednesday");
    std::cout << "Day number: " << dayNumber << ", Day name: " << dayName << std::endl;
    
    char grade = 'B';
    std::string performance;
    
    switch (grade) {
        case 'A':
            performance = "Excellent";
            break;
        case 'B':
            performance = "Good";
            break;
        case 'C':
            performance = "Average";
            break;
        default:
            performance = "Needs improvement";
    }
    
    assert(performance == "Good");
    std::cout << "Grade: " << grade << ", Performance: " << performance << std::endl;
    
    std::cout << "✓ Test passed: switch statement works correctly\n" << std::endl;
}

void testConditionalOperator() {
    std::cout << "Test 7: Conditional (Ternary) Operator" << std::endl;
    
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    assert(max == 20);
    std::cout << "Max of " << a << " and " << b << ": " << max << std::endl;
    
    int score = 75;
    std::string result = (score >= 60) ? "Pass" : "Fail";
    assert(result == "Pass");
    std::cout << "Score: " << score << ", Result: " << result << std::endl;
    
    bool isMember = true;
    double discount = isMember ? 0.10 : 0.0;
    assert(discount == 0.10);
    std::cout << "Member discount: " << (discount * 100) << "%" << std::endl;
    
    std::cout << "✓ Test passed: Conditional operator works correctly\n" << std::endl;
}

void testInputValidation() {
    std::cout << "Test 8: Input Validation Logic" << std::endl;
    
    int userInput = 5;
    bool isValid = false;
    
    if (userInput >= 1 && userInput <= 10) {
        isValid = true;
    }
    
    assert(isValid == true);
    std::cout << "Input " << userInput << " in range [1-10]: " << (isValid ? "Valid" : "Invalid") << std::endl;
    
    int age = 150;
    std::string ageStatus;
    
    if (age < 0 || age > 120) {
        ageStatus = "Invalid age";
    } else if (age < 18) {
        ageStatus = "Minor";
    } else {
        ageStatus = "Adult";
    }
    
    assert(ageStatus == "Invalid age");
    std::cout << "Age " << age << ": " << ageStatus << std::endl;
    
    std::cout << "✓ Test passed: Input validation logic works correctly\n" << std::endl;
}

void testCompoundConditions() {
    std::cout << "Test 9: Compound Conditions" << std::endl;
    
    int temperature = 72;
    int humidity = 45;
    std::string comfort;
    
    if (temperature >= 68 && temperature <= 78 && humidity >= 30 && humidity <= 60) {
        comfort = "Comfortable";
    } else {
        comfort = "Uncomfortable";
    }
    
    assert(comfort == "Comfortable");
    std::cout << "Temp: " << temperature << "°F, Humidity: " << humidity << "%, Comfort: " << comfort << std::endl;
    
    std::cout << "✓ Test passed: Compound conditions work correctly\n" << std::endl;
}

void testFlagVariables() {
    std::cout << "Test 10: Flag Variables" << std::endl;
    
    bool foundError = false;
    int data[] = {10, 20, -5, 30};
    
    for (int i = 0; i < 4; i++) {
        if (data[i] < 0) {
            foundError = true;
            break;
        }
    }
    
    assert(foundError == true);
    std::cout << "Error found in data: " << (foundError ? "Yes" : "No") << std::endl;
    
    std::cout << "✓ Test passed: Flag variables work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 4: Making Decisions" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testRelationalOperators();
    testIfStatement();
    testIfElseStatement();
    testNestedIf();
    testLogicalOperators();
    testSwitchStatement();
    testConditionalOperator();
    testInputValidation();
    testCompoundConditions();
    testFlagVariables();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 4 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}