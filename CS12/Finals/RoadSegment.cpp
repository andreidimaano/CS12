#include "RoadSegment.h"
#include <iostream>

using namespace std;

RoadSegment::RoadSegment(const string & n, double s, double d) :TransportationLink(n , d)
{
	defaultspeed = s;
	hourlySpeeds.reserve(24);
	for(unsigned i = 0; i < 24; i++)
	{
		hourlySpeeds.push_back(defaultspeed);
	}
}

void RoadSegment::setHourSpeed(unsigned hour, double speed)
{
	hourlySpeeds.at(hour) = speed;
}
    
void RoadSegment::setAllHourSpeeds(const vector<double> &)
{
	return;
}
    
// Passes in the departure time (as minute) and returns arrival time (as minute)
    // For example: 
    //     8 am will be passed in as 480 (8 * 60)
    //     2:30 pm will be passed in as 870 (14.5 * 60) 

unsigned RoadSegment::computeArrivalTime(unsigned minute) const
{
	int hour = minute / 60;
	
	double traveltime = _distance / hourlySpeeds.at(hour);
	
	return minute + traveltime;
// 	return 1;
}