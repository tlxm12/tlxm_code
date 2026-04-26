#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// 添加参与者
void addParticipant(vector<string>& list, string name) {
    list.push_back(name);
}

// 显示所有参与者
void showParticipants(const vector<string>& list) {
    cout << "\n参与者名单: " << endl;
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i] << endl;
    }
}

// 抽取1人
string drawOne(vector<string>& list, vector<string>& winners) {
    if (list.empty()) return "无人可抽";

    int idx = rand() % list.size();
    string winner = list[idx];
    winners.push_back(winner);

    // 移除已中奖者
    for (auto it = list.begin(); it != list.end(); it++) {
        if (*it == winner) {
            list.erase(it);
            break;
        }
    }
    return winner;
}

// 抽取多人
vector<string> drawMulti(vector<string>& list, vector<string>& winners, int count) {
    vector<string> result;
    if (count > list.size()) {
        cout << "人数不足" << endl;
        return result;
    }

    for (int i = 0; i < count; i++) {
        result.push_back(drawOne(list, winners));
    }
    return result;
}

// 显示中奖者
void showWinners(const vector<string>& winners) {
    cout << "\n中奖名单: " << endl;
    for (int i = 0; i < winners.size(); i++) {
        cout << i + 1 << ". " << winners[i] << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<string> participants;
    vector<string> winners;

    cout << "===== 随机抽奖系统 =====" << endl;

    // 添加测试人员
    addParticipant(participants, "张三");
    addParticipant(participants, "李四");
    addParticipant(participants, "王五");
    addParticipant(participants, "赵六");
    addParticipant(participants, "钱七");

    showParticipants(participants);

    // 抽奖
    int num;
    cout << "\n请输入中奖人数: ";
    cin >> num;

    vector<string> res = drawMulti(participants, winners, num);
    cout << "\n中奖者: ";
    for (string s : res) cout << s << " ";
    cout << endl;

    showWinners(winners);
    showParticipants(participants);

    return 0;
}
