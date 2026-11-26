#include "Time.h"


Time::Time(int h,int m,int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int hr) {
	if (hr >= 0 && hr <= 23)
		hours = hr;
	else {
		hours = 0;
		cout << "Wrong Hour" << endl;
	}
}
void Time::setMinute(int min) {
	if (min >= 0 && min <= 59)
		minutes = min;
	else {
		minutes = 0;
		cout << "Wrong Minutes" << endl;
	}
}
void Time::setSecond(int sec) {
	if (sec >= 0 && sec <= 59)
		seconds = sec;
	else {
		seconds = 0;
		cout << "Wrong Seconds" << endl;
	}
}

void Time::setTime(int hr, int min, int sec) {
	setHour(hr);
	setMinute(min);
	setSecond(sec);
}

int Time::getHour() {

	return hours;

}
int Time::getMinute() {

	return minutes;

}
int Time::getSecond() {

	return seconds;

}

void Time::incSec(int inc) {
	if (inc >= 0) {
		seconds += inc;
		if (seconds >= 60) {
			incMin(seconds / 60);
			seconds %= 60;
		}
	}
}
void Time::incMin(int inc) {
	if (inc >= 0)
	{
		minutes += inc;
		if (minutes >= 60) {
			incHour(minutes / 60);
			minutes %= 60;
		}
	}
}
void Time::incHour(int inc) {
	if (inc >= 0)
	{
		hours += inc;
		if (hours >= 24)
			hours = hours % 24;
	}
}

void Time::printTwelveHourFormat() {
	int hr = 12;
	if (hours > 0 && hours < 12)
	{
		hr = hours;
	}
	if (hours > 12 && hours < 24)
	{
		hr = hours - 12;
	}

	cout << setfill('0') << setw(2) << hr << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " " << (hours < 12 ? "AM" : "PM") << endl;

}
void Time::printTwentyFourHourFormat() {

	cout << hours << ":" << minutes << ":" << seconds << endl;

}
bool Time::operator<(const Time& t) const
{
	if (hours < t.hours)
		return true;

	if (hours == t.hours && minutes < t.minutes)
		return true;

	if (hours == t.hours && minutes == t.minutes && seconds < t.seconds)
		return true;

	return false;
}

bool Time::operator>(const Time& t) const
{
	return t < *this;
}

bool Time::operator<=(const Time& t) const
{
	return !(*this > t);
}

bool Time::operator>=(const Time& t) const
{
	return !(*this < t);
}

bool Time::operator==(const Time& t) const
{
	return hours == t.hours &&
		minutes == t.minutes &&
		seconds == t.seconds;
}

bool Time::operator!=(const Time& t) const
{
	return !(*this == t);
}
