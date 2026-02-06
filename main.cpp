#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void addGrade(vector<double>& grades);
void displayGrades(const vector<double>& grades);
void calculateAverage(const vector<double>& grades);
void findMinMax(const vector<double>& grades);
void countAboveThreshold(const vector<double>& grades);

int main()
{
    vector<double> grades;
    int choice;

    do
    {
        cout << "\n1. Add a Grade\n";
        cout << "2. Display All Grades\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Find Highest and Lowest Grade\n";
        cout << "5. Count Grades Above Threshold\n";
        cout << "6. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addGrade(grades);
            break;

        case 2:
            displayGrades(grades);
            break;

        case 3:
            calculateAverage(grades);
            break;

        case 4:
            findMinMax(grades);
            break;

        case 5:
            countAboveThreshold(grades);
            break;

        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}

// Add a grade
void addGrade(vector<double>& grades)
{
    double grade;
    cout << "Enter grade: ";
    cin >> grade;
    grades.push_back(grade);
}

// Display all grades
void displayGrades(const vector<double>& grades)
{
    if (grades.empty())
    {
        cout << "No grades entered.\n";
        return;
    }

    for (double grade : grades)
        cout << grade << " ";

    cout << endl;
}

// Calculate average
void calculateAverage(const vector<double>& grades)
{
    if (grades.empty())
    {
        cout << "No grades to average.\n";
        return;
    }

    double sum = 0;
    for (double grade : grades)
        sum += grade;

    cout << "Average: " << sum / grades.size() << endl;
}

// Find highest and lowest grade
void findMinMax(const vector<double>& grades)
{
    if (grades.empty())
    {
        cout << "No grades available.\n";
        return;
    }

    double min = grades[0];
    double max = grades[0];

    for (double grade : grades)
    {
        if (grade < min) min = grade;
        if (grade > max) max = grade;
    }

    cout << "Lowest: " << min << endl;
    cout << "Highest: " << max << endl;
}

// Count grades above threshold
void countAboveThreshold(const vector<double>& grades)
{
    if (grades.empty())
    {
        cout << "No grades available.\n";
        return;
    }

    double threshold;
    cout << "Enter threshold: ";
    cin >> threshold;

    int count = 0;
    for (double grade : grades)
    {
        if (grade > threshold)
            count++;
    }

    cout << count << " grade(s) above " << threshold << endl;
}