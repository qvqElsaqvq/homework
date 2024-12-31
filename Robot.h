//
// Created by elsa on 24-12-30.
//

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

class Robot
{
public:
    Robot() {
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
    void SetBloodThreshold(int bloodThreshold){ blood_threshold_ = bloodThreshold; } //设置血量上限
    void SetHeatThreshold(int heatThreshold){ heat_threshold_ = heatThreshold; } //设置热量上限
    void SetBlood(int blood){ blood_ = blood; } //设置血量
    void SetHeat(int heat){ heat_ = heat; } //设置热量
    void SetTeam(int team){ team_ = team; }; //设置所属队伍
    void SetFeature(int feature){ feature_ = feature; }; //设置机器人标识符
    void SetLevel(int level){ level_ = level; }; //设置当前等级
    void SetStatus(bool status){ status_ = status; }; //设置是否存活
    void SetLastTime(int last_time){ last_time_ = last_time; }; //设置上次处理该机器人的时间
    void SetType(int type){ type_ = type; };
    int GetBloodThreshold(){ return blood_threshold_; }
    int GetHeatThreshold(){ return heat_threshold_; }
    int GetBlood(){ return blood_; }
    int GetHeat(){ return heat_; }
    int GetTeam(){ return team_; }
    int GetFeature(){ return feature_; }
    int GetLevel(){ return level_; }
    bool GetStatus(){ return status_; }
    int GetLastTime(){ return last_time_; }
    int GetType(){ return type_; }

    void Print() { //输出被击毁机器人的信息
        std::cout << "D " << team_ << " " << feature_ << std::endl;
    }

protected:
    int blood_threshold_; //血量上限
    int heat_threshold_; //热量上限
    int blood_; //当前血量
    int heat_; //当前热量
    int team_; //所属队伍
    int feature_; //机器人标识符
    int level_; //当前等级
    bool status_; //当前状态（是否存活）
    int last_time_;
    int type_;
};

#endif //ROBOT_H
