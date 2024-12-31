//
// Created by elsa on 24-12-30.
//

#include "Engine.h"

Engine::Engine() {
    blood_threshold_ = 300;
    blood_ = blood_threshold_;
    heat_threshold_ = 0;
    heat_ = heat_threshold_;
    team_ = 0;
    feature_ = 0;
    level_ = 0;
    status_ = true;
    last_time_ = 0;
    type_ = 1;
}
