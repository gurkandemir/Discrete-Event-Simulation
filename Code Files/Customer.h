//
// Created by user on 10.11.2017.
//

#ifndef PROJECT2_CUSTOMER_H
#define PROJECT2_CUSTOMER_H
#include <iostream>

class Customer{
public:
    double orderTime=0;
    double price=0;
    double brewTime=0;
    bool bar=0;
    int index=0;
    int cashierInt=0;
    int status=1;
    double curTime=0;
    int barInt=0;

    Customer();
    Customer(int index,double arrivalTime,double orderTime, double brewTime ,double price);
    void setBarArrival(double t);
    double getBarArrival();
    double getArrivalTime();
    void setBarEnd(double t);
    double getBarEnd();
    void setStatus(int t);
    int getStatus();
    void setCurTime(double t);
    double getOrderTime();
    double getBrewTime();

private:
    double baristaArrival=0;
    double arrivalTime=0;
    double baristaEnd=0;


};
#endif //PROJECT2_CUSTOMER_H
