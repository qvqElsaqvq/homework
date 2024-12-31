//
// Created by elsa on 24-12-30.
//

#include "Manage.h"

Manage::Manage(int N) {
    id_ = 0;
    time_ = 0;
    team_ = 0;
    feature_ = 0;
    level_ = 0;
    type_ = 0;
    damage_ = 0;
    heating_ = 0;
    robots_.reserve(N);
}

bool Manage::isOverHeat(std::shared_ptr<Robot> &robot) {
    if(robot->GetHeat() > robot->GetHeatThreshold()) { //判断是否超热量
        return true;
    }
    return false;
}

void Manage::SaveHeat(std::shared_ptr<Robot> &robot) {
    if(isDead(robot) || !isHelm(robot)) { //不是步兵或已经死亡，结束处理
        robot->SetLastTime(time_);
        return;
    }
    int current_heat = std::max(robot->GetHeat() - time_ + robot->GetLastTime(), 0); //剩余热量
    if(isOverHeat(robot)) { //超热量上限扣血
        robot->SetBlood(std::max(robot->GetBlood() - std::min(time_ - robot->GetLastTime(),
            robot->GetHeat() - robot->GetHeatThreshold()), 0));
    }
    if(robot->GetBlood() == 0) { //血量为0
        robot->SetStatus(false);
        robot->Print();
        return;
    }
    robot->SetHeat(current_heat + heating_);
    robot->SetLastTime(time_);
}

bool Manage::isDead(std::shared_ptr<Robot> &robot) {
    if(!robot->GetStatus()) {
        return true;
    }
    return false;
}

bool Manage::isHelm(std::shared_ptr<Robot> &robot) {
    if(!robot->GetType()) {
        return true;
    }
    return false;
}

void Manage::Reset() {
    id_ = 0;
    time_ = 0;
    team_ = 0;
    feature_ = 0;
    level_ = 0;
    type_ = 0;
    damage_ = 0;
    heating_ = 0;
}

void Manage::Read(int time, char id, int team, int feature, int param) {
    Reset();
    time_ = time;
    id_ = id;
    team_ = team;
    feature_ = feature;
    std::shared_ptr<Robot> robot = std::make_shared<Robot>();
    for(auto &i : robots_) {
        SaveHeat(i);
    }
    switch (id_) {
        case 65: //A
            type_ = param;
            CreateRobot(robot);
            break;
        case 70: //F
            damage_ = param;
            if(FindRobot(robot)) {
                SaveBlood(robot);
            }
            break;
        case 72: //H
            heating_ = param;
            if(FindRobot(robot)) {
                SaveHeat(robot);
            }
            break;
        case 85: //U
            level_ = param;
            if(FindRobot(robot)) {
                Update(robot);
            }
            break;
        default: ;
    }
}

void Manage::Update(std::shared_ptr<Robot> &robot) {
    if(isDead(robot) || !isHelm(robot) || level_ > 3 || level_ < 0) {
        robot->SetLastTime(time_);
        return;
    }
    if(robot->GetLevel() < level_) {
        robot->SetLevel(level_);
        switch(level_) {
            case 1:
                robot->SetBloodThreshold(100);
                robot->SetHeatThreshold(100);
                break;
            case 2:
                robot->SetBloodThreshold(150);
                robot->SetHeatThreshold(200);
                break;
            case 3:
                robot->SetBloodThreshold(250);
                robot->SetHeatThreshold(300);
                break;
        }
        robot->SetBlood(robot->GetBloodThreshold());
    }
    robot->SetLastTime(time_);
}

void Manage::CreateRobot(std::shared_ptr<Robot> &robot) {
    if(FindRobot(robot)) {
        if(!robot->GetStatus() && robot->GetType() == type_) { //复活机器人
            robot->SetStatus(true);
            robot->SetBlood(robot->GetBloodThreshold());
            robot->SetHeat(0);
            robot->SetLastTime(time_);
        }
    }
    else { //未找到机器人，新建
        if(type_ == 0) {
            robot = std::make_shared<Helm>();
            robot->SetFeature(feature_);
            robot->SetTeam(team_);
            robot->SetLastTime(time_);
            robots_.push_back(robot);
        }
        else {
            robot = std::make_shared<Engine>();
            robot->SetFeature(feature_);
            robot->SetTeam(team_);
            robot->SetLastTime(time_);
            robots_.push_back(robot);
        }
    }
}

bool Manage::FindRobot(std::shared_ptr<Robot> &robot) {
    if(robots_.empty())
        return false;
    for(auto &i : robots_) {
        if(i->GetTeam() == team_ && i->GetFeature() == feature_) { //找到，返回引用
            robot = i;
            return true;
        }
    }
    return false;
}

void Manage::SaveBlood(std::shared_ptr<Robot> &robot) {
    if(isDead(robot)) {
        robot->SetLastTime(time_);
        return;
    }
    int blood = std::max(robot->GetBlood() - damage_, 0);
    if(blood == 0) {
        robot->SetBlood(0);
        robot->SetStatus(false);
        robot->Print();
    }
    else {
        robot->SetBlood(blood);
    }
    robot->SetLastTime(time_);
}