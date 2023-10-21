// Betel Gurara
// A program that write a class that represents a manager at a company.

#include <iostream>
#include <string>
#include "employee.h"
#include "employee.cpp"
#include <iomanip>

using namespace std;

class Manager: public Employee
{
    double bonus;

    public:
    double calcPay() const;

    Manager(string theName, double theWage, double theHours, double manager_bonus):Employee(theName,  theWage,  theHours)
    {bonus = manager_bonus;};
};

double Manager:: calcPay() const
{
    return ((wage * hours) + bonus);
}

int main()
{
    int num;
    cout << "Enter number of managers: ";
    cin >> num;
    Manager* managers[num];

    for(int i = 0; i < num; i++)
    {
        cout << endl;
        string manager_name;
        double manager_wage;
        double manager_bonus;
        double manager_hours;
        cout << "Enter manager " << i << " name: ";
        cin.ignore(1, '\n');
        getline(cin, manager_name);

        // Get manager's information

        cout << "Enter manager " << i << " hourly wage: ";
        cin >> manager_wage;


        cout << "Enter manager " << i << " hours worked: ";
        cin >> manager_hours;

        cout << "Enter manager " << i << " bonus: ";
        cin >> manager_bonus;

        //create manager object

        managers[i] = new Manager(manager_name, manager_wage, manager_hours, manager_bonus);

    }

    double combined_pay = 0;
    int i = 0;

    //get total pay
    while (i < num)
    {
        combined_pay += managers[i]->calcPay();
        i++;
    }

    int most_pay = 0;

    //find highest paid
    for (int i = 1; i < num; i++)
    {
        double current_manager = managers[i]->calcPay();
        double highest_paid = managers[most_pay]->calcPay();
        if (current_manager > highest_paid)
        {
            most_pay = i;
        }
    }

    cout << endl;

    //display output
    double average_manager_pay = combined_pay / static_cast<double>(num);
    cout << "Highest paid manager is " << managers[most_pay]->getName() << " who is paid $" <<  fixed << setprecision(2) << managers[most_pay]->calcPay() << endl;
    cout << "Average pay is $" << fixed << setprecision(2) << average_manager_pay;


    return 0;
}
