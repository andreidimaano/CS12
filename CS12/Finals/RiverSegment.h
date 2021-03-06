#include "TransportationLink.h"
#include <string>
#include <vector>

#ifndef __RIVERSEGMENT_H__
#define __RIVERSEGMENT_H__

class RiverSegment : public TransportationLink
{
 protected:
	double defaultspeed;
	vector<double> scheduledDepartureTimes;
 public:
    RiverSegment(const string &, double, double);
    void setSpeed(double speed);
    void addDepartureTime(double hour);
    // Passes in the departure time (as minute) and returns arrival time (as minute)
    // For example: 
    //     8 am will be passed in as 480 (8 * 60)
    //     2:30 pm will be passed in as 870 (14.5 * 60) 
    unsigned computeArrivalTime(unsigned minute) const;
};

#endif
