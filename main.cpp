#include <iostream>
#include <vector>

using namespace std;

// Function to calculate GPA for a semester
float calculateGPA(vector<int> grades, vector<int> credits) {
    int totalPoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalPoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    if (totalCredits == 0) return 0; // To avoid division by zero
    return static_cast<float>(totalPoints) / totalCredits;
}

// Function to calculate CGPA from multiple semesters
float calculateCGPA(vector<float> gpaList, vector<int> creditsList) {
    float totalPoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < gpaList.size(); ++i) {
        totalPoints += gpaList[i] * creditsList[i];
        totalCredits += creditsList[i];
    }

    if (totalCredits == 0) return 0; // To avoid division by zero
    return totalPoints / totalCredits;
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<float> gpaList;
    vector<int> creditsList;

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "Enter the number of courses for semester " << (i + 1) << ": ";
        cin >> numCourses;

        vector<int> grades(numCourses);
        vector<int> credits(numCourses);

        cout << "Enter grades and credits for each course:\n";
        for (int j = 0; j < numCourses; ++j) {
            cout << "Course " << (j + 1) << " grade: ";
            cin >> grades[j];
            cout << "Course " << (j + 1) << " credits: ";
            cin >> credits[j];
        }

        float gpa = calculateGPA(grades, credits);
        cout << "GPA for semester " << (i + 1) << ": " << gpa << endl;

        gpaList.push_back(gpa);

        int totalCreditsForSemester = 0;
        for (int credit : credits) {
            totalCreditsForSemester += credit;
        }
        creditsList.push_back(totalCreditsForSemester);
    }

    float cgpa = calculateCGPA(gpaList, creditsList);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
