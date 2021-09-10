//The driver program that uses the class clockType
//Sherine Antoun
#include <iostream> 
#include "clockType.h"
 
using namespace std;

int main()
{
    clockType myClock(9, 30, 45);
    clockType yourClock(12, 45, 18);  
    clockType tempClock(6, 10, 59);

    cout << "myClock:---" << endl;
    cout << "  Time: ";
    myClock.printTime();
    cout << endl;
    cout << "  The elapsed time of the day in seconds:  "
         << myClock.timeElapsed() << endl;
    cout << "  The remaining time of the day in seconds:  "
         << myClock.timeRemaining() << endl;
    cout << endl;

    cout << "yourClock:---" << endl;
    cout << "  Time: ";
    yourClock.printTime();
    cout << endl;
    cout << "  The elapsed time of the day in seconds:  "
         << yourClock.timeElapsed() << endl;
    cout << "  The remaining time of the day in seconds:  "
         << yourClock.timeRemaining() << endl;
    cout << endl;

    cout << "tempClock:---" << endl;
    cout << "  Time: ";
    tempClock.printTime();
    cout << endl;
    cout << "  The elapsed time of the day in seconds:  "
         << tempClock.timeElapsed() << endl;
    cout << "  The remaining time of the day in seconds:  "
         << tempClock.timeRemaining() << endl;
    cout << endl << endl;

    cout << "The time difference between myClock and yourClock:  ";
    myClock.timeDifference(yourClock);
    cout << endl;

    cout << "The time difference between myClock and tempClock:  ";
    myClock.timeDifference(tempClock);
    cout << endl;

    cout << "The time difference between yourClock and tempClock:  ";
    yourClock.timeDifference(tempClock);
    cout << endl;

    return 0;
}//end main


