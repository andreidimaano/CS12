#include "RiverSegment.h"
#include <iostream>

using namespace std;

RiverSegment::RiverSegment(const string & n, double s, double d) :TransportationLink(n , d)
{
	defaultspeed = s;
}

void RiverSegment::setSpeed(double speed)
{
	defaultspeed = speed;
}

void RiverSegment::addDepartureTime(double hour)
{
	if(scheduledDepartureTimes.size() == 0 || scheduledDepartureTimes.at(scheduledDepartureTimes.size() - 1) < hour)
	{
		scheduledDepartureTimes.push_back(hour);
	}
	else
	{
		for(unsigned int i = 0; i < scheduledDepartureTimes.size(); ++i)
		{
			if(scheduledDepartureTimes.at(i) > hour)
			{
				scheduledDepartureTimes.insert(scheduledDepartureTimes.begin() + i, hour);
				i = scheduledDepartureTimes.size();
			}
		}
	}
}
    
// Passes in the departure time (as minute) and returns arrival time (as minute)
    // For example: 
    //     8 am will be passed in as 480 (8 * 60)
    //     2:30 pm will be passed in as 870 (14.5 * 60) 

unsigned RiverSegment::computeArrivalTime(unsigned minute) const
{
	double nextFerry = 0.0;
// 	cout << "minute: " << minute << endl;
	for(unsigned int i = 0; i < scheduledDepartureTimes.size(); ++i)
		{
// 			cout << "Time: " << scheduledDepartureTimes.at(i) * 60 << endl;
			if(scheduledDepartureTimes.at(i) * 60 > minute)
			{
// 				cout << "Used Time: " << scheduledDepartureTimes.at(i) << endl;
				nextFerry = scheduledDepartureTimes.at(i) * 60 - minute;
				i = scheduledDepartureTimes.size() - 1;
			}
		}
	double hour = minute / 60;
// 	cout << "hour: " << hour << endl;
// 	cout << "nextFerry: " << nextFerry << endl;
	
	double traveltime = _distance / defaultspeed;
// 	cout << "traveltime: " << traveltime << endl;
// 	cout << "total : " << (nextFerry + minute + traveltime) << endl;
	
	return nextFerry + minute + traveltime;
}