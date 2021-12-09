#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Driver Code
class DigClock{
int Hour, Min, Sec;
public:
    void getTime()
    {
         cout << setw(70)
         << "*Enter Current time*\n";

          cout << "HH- ";
    cin >> Hour;
    cout << "MM- ";
    cin >> Min;
    cout << "SS- ";
    cin >> Sec;
    }
    void setTime()
    {
        if (Hour > 23) {
        cout << "Wrong Time input";
    }
    else if (Min > 60) {
        cout << "Wrong Time Input";
    }
    else if (Sec > 60) {
        cout << "Wrong Time Input";
    }

    // Otherwise
    else {
        while (1)

        // Run Block infinitely
        {
            system("cls");

            // Clear the console

            // Code for Showing Time
            for (Hour; Hour < 24; Hour++) {

                for (Min; Min < 60; Min++) {

                    for (Sec; Sec < 60; Sec++) {
                        system("cls");

                       /* cout << "\n\n\n\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                                    "Current Time = "
                             << hour << ":" << min << ":"
                             << sec
                             << "Hrs~~~~~~~~~~~~~~~~~~"
                                "~~~~~~~~~~~~~~~~~~~~~"
                                "~~~~~~~~~";*/
                                cout<<setw(50)
                                <<"*************"<<"Current Time= "<<Hour << ":" << Min << ":"<< Sec <<"Hrs*************";

                        // HH:MM:SS columns in output

                        Sleep(1000);//Sleep(number of milli seconds)

                        // Pause for 1 sec
                    }
                    Sec = 0;
                }
                Min = 0;
            }
        }
    }

    }

};
int main()
{
    DigClock c;
    system("color 3E");
    c.getTime();
    system("color 3E");
    c.setTime();

    // Background color and Foreground
   /* int hour, min, sec;
    cout << setw(70)
         << "*Enter Current time*\n";

    // Use of manipulator for taking
    // input from the user
    cout << "HH- ";
    cin >> hour;
    cout << "MM- ";
    cin >> min;
    cout << "SS- ";
    cin >> sec;

    // Background color and the
    // Foreground for 2nd screen
    system("color 3E");

    // Cases for the Wrong Time Input
    if (hour > 23) {
        cout << "Wrong Time input";
    }
    else if (min > 60) {
        cout << "Wrong Time Input";
    }
    else if (sec > 60) {
        cout << "Wrong Time Input";
    }

    // Otherwise
    else {
        while (1)

        // Run Block infinitely
        {
            system("cls");

            // Clear the console

            // Code for Showing Time
            for (hour; hour < 24; hour++) {

                for (min; min < 60; min++) {

                    for (sec; sec < 60; sec++) {
                        system("cls");

                       /* cout << "\n\n\n\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                                    "Current Time = "
                             << hour << ":" << min << ":"
                             << sec
                             << "Hrs~~~~~~~~~~~~~~~~~~"
                                "~~~~~~~~~~~~~~~~~~~~~"
                                "~~~~~~~~~";
                                cout<<setw(50)
                                <<"*************"<<"Current Time= "<<hour << ":" << min << ":"<< sec <<"Hrs*************";

                        // HH:MM:SS columns in output

                        Sleep(1000);//Sleep(number of milli seconds)

                        // Pause for 1 sec
                    }
                    sec = 0;
                }
                min = 0;
            }
        }
    }*/
    return 0;
}
