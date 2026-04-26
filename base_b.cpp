#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 获取字符集
void getCharSet(bool upper, bool lower, bool digit, bool symbol, string& charset) {
    charset.clear();
    if (upper) charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (lower) charset += "abcdefghijklmnopqrstuvwxyz";
    if (digit) charset += "0123456789";
    if (symbol) charset += "!@#$%^&*()_+-=[]{}|;:,.<>?";
}

// 生成密码
string generatePwd(int len, bool upper, bool lower, bool digit, bool symbol) {
    string charset;
    getCharSet(upper, lower, digit, symbol, charset);
    if (charset.empty()) return "错误：未选择任何字符类型";

    string pwd;
    for (int i = 0; i < len; i++) {
        int idx = rand() % charset.size();
        pwd += charset[idx];
    }
    return pwd;
}

// 分析密码
void analyzePwd(const string& pwd) {
    int upper = 0, lower = 0, digit = 0, symbol = 0;
    for (char c : pwd) {
        if (c >= 'A' && c <= 'Z') upper++;
        else if (c >= 'a' && c <= 'z') lower++;
        else if (c >= '0' && c <= '9') digit++;
        else symbol++;
    }

    cout << "\n密码分析：" << endl;
    cout << "大写字母: " << upper << endl;
    cout << "小写字母: " << lower << endl;
    cout << "数字: " << digit << endl;
    cout << "符号: " << symbol << endl;

    int score = upper + lower + digit * 2 + symbol * 3;
    cout << "强度: ";
    if (score < 10) cout << "弱";
    else if (score < 20) cout << "中";
    else cout << "强";
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "===== 随机密码生成器 =====" << endl;

    int len;
    cout << "请输入密码长度: ";
    cin >> len;

    bool useUpper, useLower, useDigit, useSymbol;
    cout << "使用大写字母(1/0): "; cin >> useUpper;
    cout << "使用小写字母(1/0): "; cin >> useLower;
    cout << "使用数字(1/0): "; cin >> useDigit;
    cout << "使用符号(1/0): "; cin >> useSymbol;

    string pwd = generatePwd(len, useUpper, useLower, useDigit, useSymbol);
    cout << "\n生成密码: " << pwd << endl;

    analyzePwd(pwd);

    return 0;
}
