/* ==========================================
    Project: Scholarship Management System
  ========================================== */

#include <iostream>
#include <string>
using namespace std;

// Class defining the Scholarship criteria
class Scholarship {
public:
    string name;
    double minGPA;
    double maxIncome;
    double fundAmount;

    // Default Constructor 
    Scholarship() {
        name       = "";
        minGPA     = 0;
        maxIncome  = 0;
        fundAmount = 0;
    }

    string checkEligibility(double gpa, double income) {
        if (gpa < minGPA && income > maxIncome)
            return "GPA too low & Family income exceeds limit";
        if (gpa < minGPA)
            return "GPA too low";
        if (income > maxIncome)
            return "Family income exceeds limit";
        return "ELIGIBLE";
    }
};

// Class defining the Student
class Student {
public:
    int    studentID;
    string name;
    double gpa;
    double familyIncome;
    string scholarshipStatus;
    double allocatedFunds;

    // Default Constructor
    Student() {
        studentID         = 0;
        name              = "";
        gpa               = 0;
        familyIncome      = 0;
        scholarshipStatus = "Pending";
        allocatedFunds    = 0.0;
    }

    void displayStatus() {
        cout << "  +-----------------------------------------------+\n";
        cout << "  | ID       : " << studentID                        << "\n";
        cout << "  | Name     : " << name                             << "\n";
        cout << "  | GPA      : " << gpa                              << "\n";
        cout << "  | Status   : " << scholarshipStatus                << "\n";
        cout << "  | Funds    : Rs. " << allocatedFunds               << "\n";
        cout << "  +-----------------------------------------------+\n";
    }
};

// System class to manage all operations
class ScholarshipSystem {
public:
    Student students[100];       // An array to hold up to 100 students
    Scholarship scholarships[10]; // An array to hold up to 10 scholarships
    int studentCount;
    int scholarshipCount;

    ScholarshipSystem() {
        studentCount     = 0; // Initialize student count to 0
        scholarshipCount = 0; // Initialize scholarship count to 0
    }

    // Helper function to check for duplicate student IDs
    bool isDuplicateID(int id) {
        for (int i = 0; i < studentCount; i++)
            if (students[i].studentID == id) return true; // ID already exists
        return false; // ID is unique
    }

    void addScholarship(Scholarship sch) {
        if (scholarshipCount >= 10) {
            cout << "Scholarship limit reached!\n";
            return;
        }
        scholarships[scholarshipCount] = sch;
        scholarshipCount++;
    }

    void addStudent(Student s) {
        if (studentCount >= 100) {
            cout << "\nError: Student limit reached!\n";
            return;
        }
        if (isDuplicateID(s.studentID)) {
            cout << "\nError: Student with ID " << s.studentID << " already exists!\n";
            return;
        }
        students[studentCount] = s;
        studentCount++;
        cout << "\n--- Student '" << s.name << "' added successfully! ---\n";
    }

    void processScholarships() {
        if (studentCount == 0) {
            cout << "\nNo students in the system to process.\n";
            return;
        }
        for (int i = 0; i < studentCount; i++) {
            bool allocated = false;
            for (int j = 0; j < scholarshipCount; j++) {
                if (students[i].gpa >= scholarships[j].minGPA &&
                    students[i].familyIncome <= scholarships[j].maxIncome)
                    {
                        students[i].scholarshipStatus = "Approved - " + scholarships[j].name;
                        students[i].allocatedFunds    = scholarships[j].fundAmount;
                        allocated = true;
                        break;
                    }
            }
            if (!allocated) {
                students[i].scholarshipStatus = "Rejected - Does not meet any scholarship criteria";
            }
        }
        cout << "\n  ===============================================\n";
        cout << "       Scholarship Processing Complete!        \n";
        cout << "  ===============================================\n";
    }

    void displayReport() {
        if (studentCount == 0) {
            cout << "\nNo students to display.\n";
            return;
        }
        cout << "\n  ===============================================\n";
        cout << "       ITM SKILLS UNIVERSITY                    \n";
        cout << "       Scholarship Status Report                \n";
        cout << "  ===============================================\n";
        cout << "  Total Students: " << studentCount << "\n\n";
        for (int i = 0; i < studentCount; i++)
            students[i].displayStatus();
        cout << "  ===============================================\n";
    }

    void trackStudentByID(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == id) {
                cout << "\n  [ Tracking Student ID: " << id << " ]\n";
                students[i].displayStatus();
                return;
            }
        }
        cout << "\n  [ ERROR ] No student found with ID: " << id << "\n";
    }
};

// Input Validation Helpers
int getValidID() {
    int id;
    string line;
    while (true) {
        getline(cin, line);
        bool valid = true;
        if (line.empty()) valid = false;
        for (char c : line) if (!isdigit(c)) { valid = false; break; }
        if (valid) {
            id = stoi(line);
            if (id > 0) return id;
        }
        cout << "\nInvalid ID. Enter a positive integer: " << endl;
    }
}

double getValidGPA() {
    double gpa;
    string line;
    while (true) {
        getline(cin, line);
        try {
            size_t pos;
            gpa = stod(line, &pos);
            if (pos == line.size() && gpa >= 0.0 && gpa <= 10.0) return gpa;
        } catch (...) {}
        cout << "\nInvalid GPA. Enter a value between 0.0 and 10.0: " << endl;
    }
}

double getValidIncome() {
    double income;
    string line;
    while (true) {
        getline(cin, line);
        try {
            size_t pos;
            income = stod(line, &pos);
            if (pos == line.size() && income >= 0) return income;
        } catch (...) {}
        cout << "\nInvalid income. Enter a positive value: Rs. " << endl;
    }
}


// Main Menu Loop
int main() {
    ScholarshipSystem sys;

    Scholarship merit;
    merit.name      = "Merit Base";
    merit.minGPA    = 8.5;
    merit.maxIncome = 800000;
    merit.fundAmount = 50000;
    sys.addScholarship(merit);

    Scholarship need;
    need.name       = "Need Base";
    need.minGPA     = 7.0;
    need.maxIncome  = 400000;
    need.fundAmount = 30000;
    sys.addScholarship(need);

    int choice;
    bool running = true;

    while (running) {
        cout << "\n=======================================";
        cout << "\n  SCHOLARSHIP MANAGEMENT SYSTEM MENU  ";
        cout << "\n=======================================\n";
        cout << "1. Add New Student\n";
        cout << "2. Process Scholarships (Verify Eligibility)\n";
        cout << "3. View Full Status Report (Console)\n";
        cout << "4. Track a Specific Student by ID\n";
        cout << "5. Exit System\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "\n--- Enter Student Details ---\n";
                cout << "Student ID: ";
                int id = getValidID();

                string name;
                cout << "Full Name: ";
                getline(cin, name);

                cout << "GPA (0.0 - 10.0): ";
                double gpa = getValidGPA();

                cout << "Family Income: Rs. ";
                double income = getValidIncome();

                Student newStudent;
                newStudent.studentID    = id;
                newStudent.name         = name;
                newStudent.gpa          = gpa;
                newStudent.familyIncome = income;

                sys.addStudent(newStudent);
                break;
            }
            case 2: sys.processScholarships(); break;
            case 3: sys.displayReport();       break;
            case 4: {
                cout << "\nEnter Student ID to track: ";
                int id = getValidID();
                sys.trackStudentByID(id);
                break;
            }
            case 5:
                cout << "\nExiting Scholarship Management System. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}