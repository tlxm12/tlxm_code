#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// 功能1：学生信息结构体
struct Student {
    int id;
    string name;
    int score;
};

vector<Student> stuList;

// 功能1：添加学生信息
void addStudent() {
    cout << "\n====== 功能1：添加学生信息 ======" << endl;
    Student s;
    cout << "请输入学号：";
    cin >> s.id;
    cout << "请输入姓名：";
    cin >> s.name;
    cout << "请输入成绩：";
    cin >> s.score;
    stuList.push_back(s);
    cout << "✅ 添加成功！" << endl;
}

// 功能2：显示所有学生信息
void showStudents() {
    cout << "\n====== 功能2：显示所有学生 ======" << endl;
    if (stuList.empty()) {
        cout << "暂无学生信息！" << endl;
        return;
    }
    cout << left << setw(10) << "学号" 
         << setw(15) << "姓名" 
         << setw(10) << "成绩" << endl;
    cout << "-----------------------------------------" << endl;
    for (auto &s : stuList) {
        cout << left << setw(10) << s.id
             << setw(15) << s.name
             << setw(10) << s.score << endl;
    }
}

// 功能3：按学号查询学生
void searchStudent() {
    cout << "\n====== 功能3：查询学生 ======" << endl;
    int searchId;
    cout << "请输入要查询的学号：";
    cin >> searchId;
    bool found = false;
    for (auto &s : stuList) {
        if (s.id == searchId) {
            cout << "找到学生：" << endl;
            cout << "学号：" << s.id << endl;
            cout << "姓名：" << s.name << endl;
            cout << "成绩：" << s.score << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "❌ 未找到该学生！" << endl;
    }
}

// 功能4：统计平均分
void calculateAvg() {
    cout << "\n====== 功能4：计算平均分 ======" << endl;
    if (stuList.empty()) {
        cout << "暂无学生数据！" << endl;
        return;
    }
    int sum = 0;
    for (auto &s : stuList) {
        sum += s.score;
    }
    double avg = sum * 1.0 / stuList.size();
    cout << "总人数：" << stuList.size() << endl;
    cout << "总分：" << sum << endl;
    cout << "平均分：" << fixed << setprecision(2) << avg << endl;
}

// 菜单
void showMenu() {
    cout << "\n================================" << endl;
    cout << "       学生成绩管理系统         " << endl;
    cout << "================================" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 显示所有学生" << endl;
    cout << "3. 按学号查询学生" << endl;
    cout << "4. 计算学生平均分" << endl;
    cout << "0. 退出系统" << endl;
    cout << "================================" << endl;
    cout << "请输入功能编号：";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                calculateAvg();
                break;
            case 0:
                cout << "感谢使用，再见！" << endl;
                return 0;
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
        system("pause");
    }
    return 0;
}
