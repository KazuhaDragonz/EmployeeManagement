// EmployeeManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<iomanip>
//#include<unistd.h>
using namespace std;

class Employee_management {
private:
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc;
    char experience[20];

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    
};

void Employee_management::menu()
{


    {
        int password_user();
        password_user();
        while (true)
        {
            int choice;
            char x;
            std::system("cls");
            std::cout << "\n\t\t\t------------------------------------------------------------------------";
            std::cout << "\n\t\t\t >>                    EMPLOYEE MANAGEMENT SYSTEM                     <<" << endl;
            std::cout << "\n\t\t\t------------------------------------------------------------------------";
            std::cout << "\n\t\t\t 1. Enter New Record " << endl;
            std::cout << "\n\t\t\t 2. Display Record " << endl;
            std::cout << "\n\t\t\t 3. Modify Record " << endl;
            std::cout << "\n\t\t\t 4. Search Record " << endl;
            std::cout << "\n\t\t\t 5. Delete Record " << endl;
            std::cout << "\n\t\t\t 6. Exit " << endl;

            std::cout << "\n\t\t\t.................................................................";
            std::cout << "\n\t\t\t >>           Choose Option [1/2/3/4/5/6]                <<" << endl;
            std::cout << "\n\t\t\t..................................................................";

            std::cout << "\n Enter Your Choice : ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                do {
                    insert();
                    std::cout << "\n\n\t\t\t Add Another Employee Record Press (Y,N) :";
                    std::cin >> x;
                } while (x == 'y' || x == 'Y');
                waitForEnter();
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleted();
                break;
            case 6:
                std::system("cls");
                std::cout << "\n\n\n\n\t----------------------------------------------------------------" << endl;
                std::cout << "\n\t\t\t >> EMPLOYEE MANAGEMENT SYSTEM  - By Zain    <<";
                std::cout << "\n\n\t--------------------------------------------------------------------" << endl;
                for (int i = 10; i >= 1; i--) {
                    std::cout << i << "Second remaining...\r" << flush;
                    Sleep(1);
                }
                exit(0);
                break;
            default:
                std::cout << "\n\n\n\t\t\t\t Invalid Choice... Please Try Again..... \n";
            }
            _getch();
        }
    }

}

    void Employee_management::insert()
    {
        std::system("cls");
        fstream file;
        cout << "\n------------------------------------------------------------------" << endl;
        cout << "-------------------------Employee Insert Data-----------------------" << endl;
        cout << "\n Enter Name of Employee :";
        cin >> name;
        cout << "\n Enter Employee ID [max 4 digits]:";
        cin >> id;
        cout << "\n Enter Designation :";
        cin >> designation;
        cout << "\n Enter Employee Age :";
        cin >> age;
        cout << "\n Enter Employee CTC :";
        cin >> ctc;
        cout << "\n Enter Employee Experience :";
        cin >> experience;
        file.open("Employee_Record.txt", ios::app | ios::out);
        file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
    }

    void Employee_management::display()
    {
        system("cls");
        int total = 1;
        fstream file;
        cout << "\n\t\t\t\t--------------------------------------------------------------" << endl;
        cout << "\t\t\t\t----------------------Employee Record Data --------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t\t No Data is Present..";
            file.close();
        }
        else
        {
            file >> name >> id >> designation >> age >> ctc >> experience;
            cout << "\n-------------------------------------------------------" << endl;
            cout << "\n||  NAME  ||  ID  ||     DESIGNATION    || AGE  || CTC ||  EXPERIENCE  ||";
            cout << "\n--------------------------------------------------------" << endl;
            while (!file.eof())
            {
                cout << "\n";
                cout << total++ << " ." << name << "\t\t" << designation << "\t\t\t " << age << "\t\t" << ctc << "\t\t" << experience << "\n";
                file >> name >> id >> designation >> age >> ctc >> experience;
            }
        }

        cout << "\n\n\n" << endl;
        
       for (int i = 10; i >= 1; i--) 
        {
            cout << i << "Second remaining..\r" << flush;
            Sleep(1);
        }
        file.close();
        void waitForEnter();
    }

    void Employee_management::modify()
    {
        std::system("cls");
        char checkId[5];
        int found = 0;
        fstream file, file1;
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "\n---------------------Employee Modify Data-----------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t No Data is Present...";
            file.close();

        }
        else
        {
            cout << "\nEnter Employee id :";
            cin >> checkId;
            file1.open("record.txt", ios::app | ios::out);
            file >> name >> id >> designation >> age >> ctc >> experience;
            while (!file.eof())
            {
                if (strcmp(checkId, id) == 0)
                {
                    cout << "\n Enter Name of Employee :";
                    cin >> name;
                    cout << "\n Enter Employee ID [max 4 digits] :";
                    cin >> id;
                    cout << "\n Enter Designation :";
                    cin >> designation;
                    cout << "\n Enter Employee Age :";
                    cin >> age;
                    cout << "\n Enter Employee CTC :";
                    cin >> ctc;
                    cout << "\n Enter Employee Experience :";
                    cin >> experience;
                    cout << "\n\n Successfully Modify Details of Employee ";
                    file1 << "" << name << "" << id << "" << designation << "" << age << "" << ctc << "" << experience << "\n";
                    found++;
                }
                else
                {
                    file1 << "" << name << "" << id << "" << designation << "" << age << "" << ctc << "" << experience << "\n";
                }
                file >> name >> id >> designation >> age >> ctc >> experience;

            }
            if (found == 0)
            {
                cout << "\n\t\t Employee ID Not Found.. Pleaa Try Again ";
            }
            file1.close();
            file.close();
           remove("Employee_Record.txt");
            remove("record.txt");
        }
        void waitForEnter();
    }

    void Employee_management::search()
    {
        system("cls");
        fstream file;
        char checkId[5];
                cout << "\n-------------------------------------------------------" << endl;
                cout << "------------------------Employee serach Data --------------------" << endl;
                file.open("Employee_Record.txt ",ios::in);
                    cout << "\n\n Enter Employee ID :";
                    cin >> checkId;
                if (!file) {
                    std::cout << "\n\t\t\t No Data is Present....";
                     file.close();
                }

                else 
                {
                    file >> name >> id >> designation >> age >> ctc >> experience;
                    while (!file.eof())
                    {
                        if (strcmp(checkId, id) == 0)
                        {
                            std::cout << "\n------------------\n\n" << endl;
                            std::cout << "Employee Name: " << name << endl;
                            std::cout << "Employeee ID :" << id << endl;
                            std::cout << "Employee Designation :" << designation << endl;
                            std::cout << "Employee Age:" << age << endl;
                            cout << "Employee CTC:" << ctc << endl;
                            cout << "Employee Exprience : " << experience << endl;
                            cout << "\n------------------------------\n" << endl;

                        }
                        file >> name >> id >> designation >> age >> ctc >> experience;

                    }

                }

                for (int i = 10; i >= 1; i--)
                {
                    cout << i << "Second remaining... \r" << flush;
                    Sleep(1);
                }
                file.close();
                void waitForEnter();
    }

            void Employee_management::deleted()
            {
                system("cls");
                char checkId[5];
                fstream file, file1;
                int found = 0;
                cout << "\n----------------------------------------------------------------" << endl;
                cout << "\n-------------------------Employee Delete Data-------------------" << endl;
                file.open("Employee_Record.txt", ios::in);
                if (!file) {
                    cout << "\n\t\t\t No Data is Present.....";
                    for (int i = 5; i >= 1; i--) {
                        cout << i << " Second remaining....\r" << flush;
                        Sleep(1);

                    }
                    file.close();
                }
                else {
                    cout << "\nEnter Employee Id To Remove Data :";
                    cin >> checkId;
                    file1.open("record.txt", ios::app | ios::out);
                    file >> name >> id >> designation >> age >> ctc >> experience;
                    while (!file.eof())
                    {
                        if (strcmp(checkId, id) != 0)
                        {
                            file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
                        }
                        else 
                        {

                            found++;
                            cout << "\n\t\t\t Succesfully Delete Data";
                        }
                        file >> name >> id >> designation >> age >> ctc >> experience;
                    }
                    if (found == 0) 
                    {
                        cout << "\n\n\t Employee ID Not Found... Please Try again";
                    }
                    cout << "\n\n\n";

                    for (int i = 5; i >= 1; i--)
                    {
                        cout << i << "Second remaining...\r" << flush;
                        Sleep(1);
                    }
                    file1.close();
                    file.close();
                    remove("Employee_Record.txt");
                    remove("record.txt");
                void waitForEnter();
                }

            }

            void Employee_management::waitForEnter()
            {
                cout << "\n\n Press enter to go back :";
                cin.get();
            }

            int password_user()
            {
                string pass_reg = "";
                string name_reg = "";
                string pass = "";
                string name = "";
                fstream file;
                char ch;
                system("cls");

                cout << "\n\t\t\t----------------------------------------------------";
                cout << "\n\t\t\t||    WELCOME TO EMPLOYEE MANAGEMENT SYSTEM      ||";
                cout << "\n\t\t\t----------------------------------------------------";
                cout << "\n\t\t   -| Press:[1] Register & [2] Login |-";

                int selection;
                cout << "\n\n Please Enter Value :";
                cin >> selection;

                //if user press 1 then register
                if (selection == 1)
                {
                    system("cls");
                    cout << "\n\t\t\t\t--------------------------------------------------";
                    cout << "\n\t\t\t\t>>   REGISTRATION EMPLOYEE    <<<";
                    cout << "\n\t\t\t\t--------------------------------------------------";
                    cout << "\n\t\t\t\t Enter Your Name : ";
                    cin >> name_reg;
                    cout << "\n\t\t\t\t Enter Your Password : ";
                    ch = _getch();
                    while (ch != 13)
                    {
                        pass_reg.push_back(ch);
                        cout << '*';
                        ch = _getch();
                    }

                    file.open("Ep_data.txt", ios::app);
                    file << " " << name_reg << " " << pass_reg << "\n";
                    file.close();
                    std::cout << "\n Registration Successfully Save...";
                    _getch();
                    password_user();
                }
                else if (selection == 2)
                {
                    //if user press 2 then login
                    system("cls");
                    file.open("Ep_data.txt", ios::in);
                    cout << "\n\t\t\t\t-------------------------------";
                    cout << "\n\t\t\t\t>>     LOGIN EMPLOYEE  << ";
                    cout << "\n\t\t\t\t-------------------------------";
                    cout << "\n\n\t\t\t\t Enter Your Name : ";
                    cin >> name;
                    cout << "\n\t\t\t\t Enter Your Password : ";
                    ch = _getch();
                    while (ch != 13)
                    {
                        pass.push_back(ch);
                        cout << '*';
                        ch = _getch();
                    }
                    file >> name_reg >> pass_reg;
                    while (!file.eof())
                    {
                        if (pass == pass_reg && name == name_reg)
                        {
                            cout << "\n\n\n\t\t\t\t\t| Verfying EMPLOYEE |\n\t\t\t\t\t";
                            for (int a = 1; a < 8; a++)
                            {
                                Sleep(500);
                                cout << "...";
                            }
                            cout << "\n\n Accessed Granted.. \n\n";
                            system("PAUSE");
                            system("cls");
                            break;
                        }
                        else
                        {
                            cout << "\n\n\n\t\t\t\t| Verfying EMPLOYEE | \n\t\t\t\t";
                            for (int a = 1; a < 8; a++)
                            {
                                Sleep(500);
                                    cout << "...";
                            }
                            cout << "\n\n Accessed Granted.. \n\n";
                            system("PAUSE");
                            system("cls");
                            break;

                        }
                        file >> name_reg >> pass_reg;
                    }
                        file.close();
                    }
                else
                    {
                        cout << "\n Invalid Input , please try again....\n";
                        password_user();
                    }

                    return 0;
                }
            


int main()
{
    Employee_management system;
    system.menu();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
