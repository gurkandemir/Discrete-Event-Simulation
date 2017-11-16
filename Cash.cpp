//
// Created by user on 10.11.2017.
//
#include "Cash.h"

Cash::Cash(int i) {
    index=i;
    available=true;
    utilizationTime=0;
}

bool Cash::getAvailable() {
    return this->available;
}

void Cash::setAvailable(bool t) {
    this->available=t;
}

void Cash::setEndTime(double t) {
    this->endTime=t;
}

double Cash::getEndTime() {
    return this->endTime;
}

void Cash::setUtilization(double t) {
    this->utilizationTime=t;
}

double Cash::getUtilization() {
    return this->utilizationTime;
}