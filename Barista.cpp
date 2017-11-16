//
// Created by user on 11.11.2017.
//
#include "Barista.h"

Barista::Barista(int i) {
    index=i;
    available=true;
    maxQue=0;
    utilizationTime=0;
}

void Barista::setUtilization(double t) {
    this->utilizationTime=t;
}

double Barista::getUtilization() {
    return this->utilizationTime;
}

void Barista::setEndTime(double t) {
    this->endTime=t;
}

double Barista::getEndTime() {
    return this->endTime;
}

void Barista::setAvailable(bool t) {
    this->available=t;
}

bool Barista::getAvailable() {
    return this->available;
}
