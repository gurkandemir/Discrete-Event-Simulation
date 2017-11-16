//
// Created by user on 10.11.2017.
//
#include "Cashier.h"

Cashier::Cashier(int i) {
    index=i;
    available=true;
    utilizationTime=0;
}

bool Cashier::getAvailable() {
    return this->available;
}

void Cashier::setAvailable(bool t) {
    this->available=t;
}

void Cashier::setEndTime(double t) {
    this->endTime=t;
}

double Cashier::getEndTime() {
    return this->endTime;
}

void Cashier::setUtilization(double t) {
    this->utilizationTime=t;
}

double Cashier::getUtilization() {
    return this->utilizationTime;
}