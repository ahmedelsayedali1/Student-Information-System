#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


class student
{
private:
    // Private variables data
    string Name;
    double GPA;
    string ID;
    int numSubject;
    vector<string> nameSubject;
    vector<int> CreditHours;

public:
    // Public functions
    void setData();
    void showRow();
    void saveRow(ofstream& file);

    //get ID for searching
    string getID() {
        return ID;
    }
};

// Function write a single student
void student::saveRow(ofstream& file)
{
    file << Name << "," << ID << "," << GPA << ",";
    for (int i = 0; i < numSubject; i++)
    {
        file << nameSubject[i] << " : " << CreditHours[i] << " | ";
    }
    file << "\n";
}

// Function inputs user (Name, ID, Subjects, etc.)
void student::setData()
{
    cout << "\n=== Enter Student Data ===\n";
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, Name);

    cout << "Enter Student ID: ";
    cin >> ID;

    cout << "Enter Student GPA: ";
    cin >> GPA;

    cout << "Enter Student number of Subjects: ";
    cin >> numSubject;

    // Clear vectors
    nameSubject.clear();
    CreditHours.clear();

    for (int i = 0; i < numSubject; i++)
    {
        cin.ignore();
        cout << " - Enter name of subject " << i + 1 << ": ";
        string name;
        getline(cin, name);
        nameSubject.push_back(name);

        cout << " - CreditHours for subject " << i + 1 << ": ";
        int hours;
        cin >> hours;
        CreditHours.push_back(hours);
    }
}

// Function to display
void student::showRow()
{
    cout << left << setw(15) << Name
         << setw(10) << ID
         << setw(8) << GPA
         << setw(2) << "| ";

    for (int i = 0; i < numSubject; i++)
    {
        cout << nameSubject[i] << "(" << CreditHours[i] << ") ";
    }
    cout << endl;
}

//function to save a CSV file
void saveAllToCSV(vector<student>& allStudents)
{
    ofstream file;
    file.open("students.csv", ios::out);

    file << "Name,ID,GPA,Subjects\n";

    for (size_t i = 0; i < allStudents.size(); i++)
    {
        allStudents[i].saveRow(file);
    }

    file.close();
    cout << "\n[Success] All data has been saved to students.csv\n";
}


int main()
{
    vector<student> studentsList; // Database to store students in memory

    // Main Menu Loop
    while (true)
    {
        int chois;

        cout << "\n<<<<<<< =========================== >>>>>>>\n";
        cout << "        STUDENT GRADES MANAGEMENT SYSTEM         \n";
        cout << "<<<<<<< =========================== >>>>>>>\n";
        cout << "1. Add Student\n2. View All Students\n3. Save to File\n4. Edit Student\n5. Delete Student\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> chois;

        // 6. Exit Program
        if (chois == 6)
        {
            cout << "Exit program...";
            break;
        }

        // 1. Add a new student
        else if (chois == 1)
        {
            student s;
            s.setData();
            studentsList.push_back(s);
            cout << "\n[+] Student added successfully.\n";
        }

        // 2. Display all students
        else if (chois == 2)
        {
            if (studentsList.empty())
            {
                cout << "\n[!] No students to display.\n";
            }
            else
            {
                cout << "\n---------------------------------------------------------------\n";
                cout << left << setw(15) << "Name" << setw(10) << "ID" << setw(8) << "GPA" << "Subjects\n";
                cout << "---------------------------------------------------------------\n";
                for (size_t i = 0; i < studentsList.size(); i++)
                {
                    studentsList[i].showRow();
                }
                cout << "---------------------------------------------------------------\n";
            }
        }

        // 3. Save data to file
        else if (chois == 3)
        {
            if (studentsList.empty())
            {
                cout << "\n[!] No data to save!\n";
            }
            else
            {
                saveAllToCSV(studentsList);
            }
        }

        // 4. Edit an existing student by ID
        else if (chois == 4)
        {
            if (studentsList.empty())
            {
                cout << "\n[!] No students to edit.\n";
            }
            else
            {
                string targetID;
                cout << "Enter ID of the student to EDIT: ";
                cin >> targetID;

                bool found = false;
                for (int i = 0; i < studentsList.size(); i++)
                {
                    if (studentsList[i].getID() == targetID)
                    {
                        cout << "\n[Found] Edit data for student ID: " << targetID << endl;
                        studentsList[i].setData(); // Re-enter data
                        cout << "\n[Updated] Student data updated successfully.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n[!] Student with ID " << targetID << " not found!\n";
            }
        }

        // 5. Delete a student by ID
        else if (chois == 5)
        {
            if (studentsList.empty())
            {
                cout << "\n[!] No students to delete.\n";
            }
            else
            {
                string targetID;
                cout << "Enter ID of the student to DELETE: ";
                cin >> targetID;

                bool found = false;
                for (int i = 0; i < studentsList.size(); i++)
                {
                    if (studentsList[i].getID() == targetID)
                    {
                        studentsList.erase(studentsList.begin() + i);
                        cout << "\n[Deleted] Student with ID " << targetID << " has been removed.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n[!] Student with ID " << targetID << " not found!\n";
            }
        }

        // Invalid input handler
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
