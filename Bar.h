//
// Created by user on 11.11.2017.
//
#include <queue>
#include <vector>
#include "Customer.h"
#ifndef PROJECT2_BAR_H
#define PROJECT2_BAR_H

class Bar{
public:
    bool available;
    double endTime=0;
    int index;
    double utilizationTime=0;
    int maxQue;

    Bar(int i);
    bool getAvailable();
    void setAvailable(bool t);
    double getEndTime();
    void setEndTime(double t);
    double getUtilization();
    void setUtilization(double t);
};

#endif //PROJECT2_BARİSTA_H
