#include "TransportationLink.h"
#include <string>
#include <vector>

#ifndef __ROADSEGMENT_H__
#define __ROADSEGMENT_H__

class RoadSegment : public TransportationLink
{
 protected:
	double defaultspeed;
	vector<double> hourlySpeeds;
 public:
    RoadSegment(const string &, double, double);
    void setHourSpeed(unsigned hour, double speed);
    void setAllHourSpeeds(const vector<double> &);
    // Passes in the departure time (as minute) and returns arrival time (as minute)
    // For example: 
    //     8 am will be passed in as 480 (8 * 60)
    //     2:30 pm will be passed in as 870 (14.5 * 60) 
    unsigned computeArrivalTime(unsigned minute) const;
};

#endif