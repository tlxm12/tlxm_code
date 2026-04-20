#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 学生结构体
struct Student {
    int id;
    string name;
    int score;
};

// 函数声明（提前告诉编译器有这些函数）
void showMenu();
void addStudent(vector<Student>& students);
void showAllStudents(const vector<Student>& students);
void searchById(const vector<Student>& students);
void showAverage(const vector<Student>& students);

int main() {
    // 学生列表（放在main里，更规范）
    vector<Student> students;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                showAllStudents(students);
                break;
            case 3:
                searchById(students);
                break;
            case 4:
                showAverage(students);
                break;
            case 0:
                cout << "程序已退出~" << endl;
                return 0;
            default:
                cout << "输入无效，请重新选择！" << endl;
        }

        system("pause");
    }
}

// 显示菜单
void showMenu() {
    system("cls");  // 清屏，界面更干净
    cout << "\n====== 学生成绩管理系统 ======" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 显示所有学生" << endl;
    cout << "3. 按学号查询学生" << endl;
    cout << "4. 计算平均分" << endl;
    cout << "0. 退出系统" << endl;
    cout << "================================" << endl;
    cout << "请输入选项：";
}

// 添加学生
void addStudent(vector<Student>& students) {
    Student s;
    cout << "\n→ 添加学生" << endl;
    cout << "学号：";
    cin >> s.id;
    cout << "姓名：";
    cin >> s.name;
    cout << "成绩：";
    cin >> s.score;

    students.push_back(s);
    cout << "✅ 添加成功！" << endl;
}

// 显示所有学生
void showAllStudents(const vector<Student>& students) {
    cout << "\n→ 所有学生信息" << endl;
    if (students.empty()) {
        cout << "暂无学生记录" << endl;
        return;
    }

    // 左对齐 + 宽度设置
    cout << left;
    cout << setw(10) << "学号" 
         << setw(15) << "姓名" 
         << setw(8) << "成绩" << endl;
    cout << "----------------------------------" << endl;

    for (const auto& s : students) {
        cout << setw(10) << s.id
             << setw(15) << s.name
             << setw(8) << s.score << endl;
    }
}

// 按学号查找
void searchById(const vector<Student>& students) {
    int id;
    cout << "\n→ 查询学生" << endl;
    cout << "请输入学号：";
    cin >> id;

    bool found = false;
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "找到学生：" << endl;
            cout << "姓名：" << s.name << endl;
            cout << "成绩：" << s.score << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ 未找到该学生" << endl;
    }
}

// 计算平均分
void showAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\n暂无学生数据" << endl;
        return;
    }

    int total = 0;
    for (const auto& s : students) {
        total += s.score;
    }

    double avg = (double)total / students.size();
    cout << "\n→ 成绩统计" << endl;
    cout << "总人数：" << students.size() << endl;
    cout << "总分：" << total << endl;
    cout << "平均分：" << fixed << setprecision(2) << avg << endl;
}
