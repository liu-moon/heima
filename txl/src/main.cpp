#include <iostream>
using namespace std;

struct Person
{
    string m_Name;  // 姓名
    int m_Sex;    // 性别 1 男 2 女
    int m_Age;  // 年龄
    string m_Phone; // 电话
    string m_Addr;  // 地址
};

#define MAX 1000

struct Addressbooks
{
    struct Person personArray[MAX]; // 通讯录中保存的联系人数组
    int m_Size; // 通讯录中当前记录的联系人个数
};

void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

// 添加联系人
void addPerson(Addressbooks * abs)
{
    // 判断通讯录是否已满，如果满了，提示用户通讯录已满
    if(abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        // 添加联系人
        // 添加姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        // 添加性别
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while(true)
        {
            cin >> sex;

            // 判断用户输入是否合法
            if (sex ==1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        // 添加年龄
        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 添加电话
        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 添加地址
        string addr;
        cout << "请输入地址：" << endl;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        // 更新通讯录中当前记录的联系人个数
        abs->m_Size++;

        // 提示添加成功
        cout << "添加成功" << endl;
        
        // 按任意键继续
        getchar();
        getchar();

        system("clear");
    }
}

void showPerson(Addressbooks * abs)
{
    // 判断通讯录中是否有联系人
    if (abs->m_Size == 0)
    {
        cout << "当前没有任何联系人" << endl;
    }else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
        }
    }

    getchar();
    getchar();
    system("clear");
    
}


// 检查联系人是否存在，如果存在返回联系人在通讯录中的位置，如果不存在返回-1
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 找到用户输入的姓名
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

// 删除指定的联系人
void deletePerson(Addressbooks *abs)
{
    cout << "请输入要删除的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // 找到了要删除的联系人
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }else
    {
        cout << "查无此人" << endl;
    }
    
    getchar();
    getchar();
    system("clear");
}

// 查找指定联系人信息
void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男":"女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "地址：" << abs->personArray[ret].m_Addr << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    getchar();
    getchar();
    system("clear");
}

// 修改指定联系人信息
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1)
    {
        // 姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        // 性别
        int sex;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while(true)
        {
            cin >> sex;
            if (sex == 0 || sex == 1)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        
        // 年龄
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        // 电话
        string phone;
        cout << "请输入电话" << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        
        // 住址
        string addr;
        cout << "请输入住址" << endl;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

        cout << "修改成功" << endl;

    }else{
        cout << "查无此人" << endl;
    }
    getchar();
    getchar();
    system("clear");

}

void cleanPerson(Addressbooks * abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
    getchar();
    getchar();
    system("clear");
}

int main(int argc, char const *argv[])
{
    // 创建通讯录结构体变量
    Addressbooks abs;

    // 初始化通讯录中当前记录的联系人个数
    abs.m_Size = 0;


    int select = 0;

    while(true)
    {
        showMenu();
        cin >> select;
        switch(select)
        {
            case 1:
                addPerson(&abs);    // 利用地址传递，可以修改实参
                // cout << "添加联系人" << endl;
                break;
            case 2:
                showPerson(&abs);
                // cout << "显示联系人" << endl;
                break;
            case 3:
                // {cout << "请输入要删除的联系人姓名" << endl;
                // string name;
                // cin >> name;
                // if (isExist(&abs, name) != -1)
                // {
                //     cout << "找到了" << endl;
                // }else
                // {
                //     cout << "没有找到" << endl;
                // }
                // }
                deletePerson(&abs);
                // cout << "删除联系人" << endl;
                break;
            case 4:
                findPerson(&abs);
                // cout << "查找联系人" << endl;
                break;
            case 5:
                modifyPerson(&abs);
                // cout << "修改联系人" << endl;
                break;
            case 6:
                cleanPerson(&abs);
                // cout << "清空联系人" << endl;
                break;
            case 0:
                cout << "退出通讯录" << endl;
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                cout << "输入有误" << endl;
                break;
        }
    }
    return 0;
}