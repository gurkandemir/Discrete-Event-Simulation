//
// Created by user on 10.11.2017.
//
#include "Customer.h"

Customer::Customer() {}

Customer::Customer(int _index,double _kasagelis, double _kasasure, double _baristasure, double _ucret) {
    arrivalTime=(_kasagelis);
    orderTime=(_kasasure);
    brewTime=(_baristasure);
    price=(_ucret);
    bar=false;
    index=_index;
    cashierInt=0;
    curTime=arrivalTime;
}

void Customer::setBarArrival(double t) {
    this->baristaArrival=t;
}

double Customer::getBarArrival() {
    return (this->baristaArrival);
}

double Customer::getArrivalTime() {
    return (this->arrivalTime);
}

void Customer::setBarEnd(double t) {
    this->baristaEnd=t;
}

double Customer::getBarEnd() {
    return (this->baristaEnd);
}

void Customer::setStatus(int t){
    this->status=t;
}

int Customer::getStatus(){
    return (this->status);
}

void Customer::setCurTime(double t) {
    this->curTime=t;
}

double Customer::getOrderTime() {
    return this->orderTime;
}

double Customer::getBrewTime() {
    return this->brewTime;
}

