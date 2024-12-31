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
    explicit Manage(int N);

    /*
     * @brief 在机器人池中搜索机器人
     * @param std::shared_ptr<Robot> &robot 待搜索的机器人的引用，找到后返回改引用
     * @return true 找到
     * @return false 没找到
     */
    bool FindRobot(std::shared_ptr<Robot> &robot);

    /*
     * @brief 在复活机器人或新建一个机器人
     * @param std::shared_ptr<Robot> &robot 待复活/新建的机器人的引用
     */
    void CreateRobot(std::shared_ptr<Robot> &robot);

    /*
     * @brief 判断机器人是否被击毁
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     * @return true 被击毁
     * @return false 未被击毁
     */
    bool isDead(std::shared_ptr<Robot> &robot);

    /*
     * @brief 更新机器人血量
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     */
    void SaveBlood(std::shared_ptr<Robot> &robot);

    /*
     * @brief 更新机器人热量
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     */
    void SaveHeat(std::shared_ptr<Robot> &robot);

    /*
     * @brief 判断机器人是否是步兵
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     * @return true 是步兵
     * @return false 是工程
     */
    bool isHelm(std::shared_ptr<Robot> &robot);

    /*
     * @brief 机器人升级
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     */
    void Update(std::shared_ptr<Robot> &robot);

    /*
     * @brief 判断是否超热量死亡
     * @param std::shared_ptr<Robot> &robot 机器人的引用
     * @return true 超热量死亡
     * @return false 未超热量死亡
     */
    bool isOverHeat(std::shared_ptr<Robot> &robot);

    /*
     * @brief 执行任务
     * @param int time 裁判系统时间
     * @param char id 命令字
     * @param int team 所属队伍
     * @param int feature 机器人标识符
     * @param int param 传入参数
     */
    void Read(int time, char id, int team, int feature, int param);

    /*
     * @brief 重置要读取的参数
     */
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
