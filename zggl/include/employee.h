// 普通职工文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker
{
    public:
        // 显示个人信息
        virtual void showInfo();
        // 获取岗位名称
        virtual string getDeptName();
        // 构造函数
        Employee(int id, string name, int dId);
};