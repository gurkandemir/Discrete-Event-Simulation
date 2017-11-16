//
// Created by user on 11.11.2017.
//
#include "Bar.h"

Bar::Bar(int i) {
    index=i;
    available=true;
    maxQue=0;
    utilizationTime=0;
}

void Bar::setUtilization(double t) {
    this->utilizationTime=t;
}

double Bar::getUtilization() {
    return this->utilizationTime;
}

void Bar::setEndTime(double t) {
    this->endTime=t;
}

double Bar::getEndTime() {
    return this->endTime;
}

void Bar::setAvailable(bool t) {
    this->available=t;
}

bool Bar::getAvailable() {
    return this->available;
}
