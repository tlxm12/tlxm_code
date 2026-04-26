#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// 生成指定范围整数
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 生成指定范围浮点数
double randDouble(double min, double max) {
    double random = static_cast<double>(rand()) / RAND_MAX;
    return min + random * (max - min);
}

// 生成随机整数数组
void randIntArray(int min, int max, int size, vector<int>& arr) {
    arr.clear();
    for (int i = 0; i < size; i++) {
        arr.push_back(randInt(min, max));
    }
}

// 加权随机抽取
int weightedRand(const vector<int>& weights) {
    int total = 0;
    for (int w : weights) total += w;
    int randVal = randInt(1, total);
    int current = 0;
    for (int i = 0; i < weights.size(); i++) {
        current += weights[i];
        if (randVal <= current) return i;
    }
    return -1;
}

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << setw(4) << num;
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "===== 随机数生成器 =====" << endl;

    // 测试整数
    int intNum = randInt(1, 100);
    cout << "1-100随机整数: " << intNum << endl;

    // 测试浮点数
    double doubleNum = randDouble(0.0, 10.0);
    cout << "0-10随机浮点数: " << fixed << setprecision(2) << doubleNum << endl;

    // 测试随机数组
    vector<int> arr;
    randIntArray(10, 50, 10, arr);
    cout << "10-50随机数组(10个): ";
    printArray(arr);

    // 测试加权随机
    vector<int> weights = {10, 20, 30, 40};
    vector<string> items = {"A", "B", "C", "D"};
    int idx = weightedRand(weights);
    cout << "加权随机结果: " << items[idx] << endl;

    // 多次加权测试
    cout << "\n10次加权测试结果: ";
    for (int i = 0; i < 10; i++) {
        cout << items[weightedRand(weights)] << " ";
    }
    cout << endl;

    return 0;
}
