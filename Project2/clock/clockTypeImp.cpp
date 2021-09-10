//Implementation File for the class clockType
 
#include <iostream>
#include <cmath>
#include "clockType.h"

using namespace std;  

int clockType::timeElapsed() const
{
    return hr * 3600 + min * 60 + sec;
}

int clockType::timeRemaining() const
{ 
    return 24 * 3600 - timeElapsed();
}

void clockType::timeDifference(const clockType& otherClock) const
{
    int timeDiffInSec;

    timeDiffInSec = abs(timeElapsed() - otherClock.timeElapsed());

    cout << timeDiffInSec / 3600 << ":";

    timeDiffInSec = timeDiffInSec % 3600;

    cout << timeDiffInSec / 60 << ":"
         << timeDiffInSec % 60 << endl;
}

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
	    hr = hours;
	else 
	    hr = 0;

	if (0 <= minutes && minutes < 60)
	    min = minutes;
	else 
	    min = 0;

	if (0 <= seconds && seconds < 60)
	    sec = seconds;
	else 
	    sec = 0;
}

void clockType::setHours(int hours)
{
	if (0 <= hours && hours < 24)
	    hr = hours;
	else 
	    hr = 0;
}

void clockType::setMinutes(int minutes)
{
	if (0 <= minutes && minutes < 60)
	    min = minutes;
	else 
	    min = 0;
}

void clockType::setSeconds(int seconds)
{
	if (0 <= seconds && seconds < 60)
	    sec = seconds;
	else 
	    sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

int clockType::getHours() const
{
    return hr;
}

int clockType::getMinutes() const
{
    return min;
}

int clockType::getSeconds() const
{
    return sec;
}

void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	   hr = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
	    min = 0;
	    incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
	    sec = 0;
	    incrementMinutes();
	}
}

void clockType::printTime() const
{
	if (hr < 10)
	    cout << "0";
	cout << hr << ":";

	if (min < 10)
	    cout << "0";
	cout << min << ":";

	if (sec < 10)
	   cout << "0";
	cout << sec;
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr 
		    && min == otherClock.min 
		    && sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

clockType::clockType()  //default constructor
{
    hr = 0;
    min = 0;
    sec = 0;
}