#include <iostream>
#include <conio.h>
#include <string>
#include <array>
#include <vector>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

int GetNumberEmployees();
void FillEmployeeInfo(Employee *Employees, int size);
void PrintReport(Employee* Employees, int size);
int GetInt();
float GetFloat();
string GetString();
void Space();
void PrintEmployee(Employee Employee);
int GetTotalPay(Employee* Employees, int size);

int main() {
    int arraysize = GetNumberEmployees();
    Employee* Employees = new Employee[arraysize];
    Space();
    FillEmployeeInfo(Employees, arraysize);
    PrintReport(Employees, arraysize);
    (void)_getch();
    return 0;
}

int GetNumberEmployees() {
    cout << "Enter the number of employees: ";
    return GetInt();
}

void FillEmployeeInfo(Employee *Employees, int size) {
    
    for (int i = 0; i < size; i++)
    {
        int EmployeeNumber = i + 1;
        cout << "Enter the ID for Employee " + to_string(EmployeeNumber) + ": ";
        Employees[i].ID = GetInt();
        cout << "Enter the First Name for Employee " + to_string(EmployeeNumber) + ": ";
        Employees[i].FirstName = GetString();
        cout << "Enter the Last Name for Employee " + to_string(EmployeeNumber) + ": ";
        Employees[i].LastName = GetString();
        cout << "Enter the Hours Worked for Employee " + to_string(EmployeeNumber) + ": ";
        Employees[i].HoursWorked = GetFloat();
        cout << "Enter the Hourly Rate for Employee " + to_string(EmployeeNumber) + ": ";
        Employees[i].HourlyRate = GetFloat();
        Space();
    }
}

void PrintReport(Employee* Employees, int size) {
    cout << "Pay Report\n----------";
    for (int i = 0; i < size; i++)
    {
        Space();
        PrintEmployee(Employees[i]);
       
    }
    Space(); Space();
    cout << "Total Pay: $" + to_string(GetTotalPay(Employees, size));
}

void PrintEmployee(Employee Employee) {

    cout << to_string(Employee.ID) + ". " + Employee.FirstName + " " + Employee.LastName + ": $" + to_string((int)(Employee.HoursWorked * Employee.HourlyRate));
}


int GetTotalPay(Employee *Employees, int size) {
    float totalpay = 0;
    for (int i = 0; i < size; i++)
    {
        totalpay += Employees[i].HoursWorked * Employees[i].HourlyRate;
    }
    return (int)totalpay;
}

void Space() {
    cout << "\n";
}

int GetInt() {
    int input;
    cin >> input;
    return input;
}

float GetFloat() {
    float input;
    cin >> input;
    return input;
}

string GetString() {
    string input;
    cin >> input;
    return input;
}