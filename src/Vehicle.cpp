//
// Created by Andrei Nechaev on 11/23/17.
//

#include "Vehicle.h"

Vehicle::Vehicle(double s, double d, double speed): s_(s), d_(d), speed_(speed) {

    if (d >= 0 && d <= 4) {
        lane_ = 0;
    } else if (d >= 4 && d <= 8) {
        lane_ = 1;
    } else if (d >= 8 && d <= 12) {
        lane_ = 2;
    }
}

Vehicle::~Vehicle() = default;

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    os << "s: " << vehicle.s_ << " d: " << vehicle.d_ << " speed: " << vehicle.speed_ << " lane: " << vehicle.lane_;
    return os;
}

bool Vehicle::is_same_line(Vehicle& that) const{
    return lane_ == that.lane_;
}

bool Vehicle::is_too_close(Vehicle &that) const {
    return that.s_ > s_ && that.s_ - s_ < MAX_DISTANCE;
}

bool Vehicle::can_merge(Vehicle &that) const {
    return that.s_ - s_ > MAX_DISTANCE + 5 || s_ - that.s_ > 5;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    return lane_ == rhs.lane_;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

int Vehicle::getLane() const {
    return lane_;
}

double Vehicle::getS() const {
    return s_;
}

double Vehicle::getSpeed() const {
    return speed_;
}
