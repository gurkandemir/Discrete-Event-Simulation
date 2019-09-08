//
// Created by user on 10.11.2017.
//

#ifndef PROJECT2_CASH_H
#define PROJECT2_CASH_H

class Cash{
public:
    bool available;
    double endTime=0;
    int index;
    double utilizationTime=0;

    Cash(int i);
    bool getAvailable();
    void setAvailable(bool t);
    double getEndTime();
    void setEndTime(double t);
    double getUtilization();
    void setUtilization(double t);
};

#endif //PROJECT2_KASA_H
