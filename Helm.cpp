//
// Created by elsa on 24-12-30.
//

#include "Helm.h"

Helm::Helm() {
    blood_threshold_ = 100;
    blood_ = blood_threshold_;
    heat_threshold_ = 100;
    heat_ = heat_threshold_;
    team_ = 0;
    feature_ = 0;
    level_ = 1;
    status_ = true;
    last_time_ = 0;
    type_ = 0;
}
