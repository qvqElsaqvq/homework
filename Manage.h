//
// Created by elsa on 24-12-30.
//

#ifndef MANAGE_H
#define MANAGE_H

#include <memory>
#include <vector>
#include "Engine.h"
#include "Helm.h"

class Manage
{
public:
    Manage(int N);
    bool FindRobot(std::shared_ptr<Robot> &robot);
    void CreateRobot(std::shared_ptr<Robot> &robot);
    bool isDead(std::shared_ptr<Robot> &robot);
    void SaveBlood(std::shared_ptr<Robot> &robot);
    void SaveHeat(std::shared_ptr<Robot> &robot); //计算并保存当前热量
    bool isHelm(std::shared_ptr<Robot> &robot);
    void Update(std::shared_ptr<Robot> &robot);
    bool isOverHeat(std::shared_ptr<Robot> &robot); //判断是否超热量死亡
    void Read(int time, char id, int team, int feature, int param);
    void Reset();

private:
    char id_; //命令字
    int time_; //时间
    int team_; //所属队伍
    int feature_; //机器人标识符
    int level_; //当前等级
    int type_; //机器人类型，0步兵，1工程
    int damage_; //对机器人的伤害量
    int heating_; //增加的热量

    std::vector<std::shared_ptr<Robot>> robots_;
};

#endif //MANAGE_H
