#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

class Patient {
protected:
    string name;
    int age;
    int patientID;

public:
    void getPatientDetails() {
        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Patient ID: ";
        cin >> patientID;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string getName() { return name; }
    int getAge() { return age; }
    int getPatientID() { return patientID; }
};

class LabTest : public Patient {
public:
    string testName;
    float cost;
    string result;

    LabTest() {
        cost = 0;
    }

    void getTestDetails() {
        cout << "\nEnter Test Name: ";
        getline(cin, testName);

        cout << "Enter Test Result: ";
        getline(cin, result);

        cout << "Enter Test Cost (Rs.): ";
        cin >> cost;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    LabTest operator+(LabTest t) {
        LabTest temp;
        temp.cost = this->cost + t.cost;
        return temp;
    }
};

int main() {
    LabTest patient;
    patient.getPatientDetails();

    int n;
    cout << "\nEnter Number of Tests: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<LabTest> tests(n);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter Details for Test " << i + 1 << " ---";
        tests[i].getTestDetails();
    }

    LabTest total;
    for (int i = 0; i < n; i++) {
        total = total + tests[i];
    }

    ofstream file("report.txt");
    file << "--- Medical Lab Report ---\n";
    file << "Patient Name: " << patient.getName() << endl;
    file << "Age: " << patient.getAge() << endl;
    file << "Patient ID: " << patient.getPatientID() << endl;

    file << "\nTests Conducted:\n";
    for (int i = 0; i < n; i++) {
        file << "- " << tests[i].testName
             << " | Result: " << tests[i].result
             << " | Cost: Rs." << tests[i].cost << endl;
    }

    file << "\nTotal Bill: Rs." << total.cost << endl;
    file.close();

    cout << "\n? Report Generated Successfully!";
    cout << "\n? Total Bill: Rs." << total.cost;
    cout << "\n? Report saved in 'report.txt'\n";

    return 0;
}

