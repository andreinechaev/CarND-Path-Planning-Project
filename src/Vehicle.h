//
// Created by Andrei Nechaev on 11/23/17.
//

#ifndef PATH_PLANNING_VEHICLE_H
#define PATH_PLANNING_VEHICLE_H


#include <ostream>

const double MAX_DISTANCE = 20.;

class Vehicle {

private:

    double s_;
    double d_;
    double speed_;

private:
    int lane_;

public:
    Vehicle(double s, double d, double speed);
    ~Vehicle();

    double getS() const;

    int getLane() const;

    double getSpeed() const;

    bool is_same_line(Vehicle &that) const;

    bool is_too_close(Vehicle& that) const;

    bool can_merge(Vehicle& that) const;

    bool operator==(const Vehicle &rhs) const;

    bool operator!=(const Vehicle &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);
};


#endif //PATH_PLANNING_VEHICLE_H
