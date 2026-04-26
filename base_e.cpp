#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// RGB颜色结构体
struct Color {
    int r, g, b;
};

// 生成随机RGB颜色
Color randRGB() {
    Color c;
    c.r = rand() % 256;
    c.g = rand() % 256;
    c.b = rand() % 256;
    return c;
}

// RGB转十六进制
string rgbToHex(Color c) {
    stringstream ss;
    ss << "#";
    ss << hex << setw(2) << setfill('0') << c.r;
    ss << hex << setw(2) << setfill('0') << c.g;
    ss << hex << setw(2) << setfill('0') << c.b;
    string res = ss.str();
    // 转大写
    for (char& ch : res) ch = toupper(ch);
    return res;
}

// 判断颜色明暗
string getBrightness(Color c) {
    double brightness = (c.r * 0.299 + c.g * 0.587 + c.b * 0.114);
    if (brightness > 127) return "明亮";
    return "暗色";
}

// 生成渐变色
void gradient(Color start, Color end, int steps) {
    cout << "\n渐变色(" << steps << "阶):" << endl;
    for (int i = 0; i < steps; i++) {
        double p = static_cast<double>(i) / (steps - 1);
        int r = start.r + (end.r - start.r) * p;
        int g = start.g + (end.g - start.g) * p;
        int b = start.b + (end.b - start.b) * p;
        cout << "阶" << setw(2) << i + 1 << ": RGB("
             << setw(3) << r << ","
             << setw(3) << g << ","
             << setw(3) << b << ")" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "===== 随机颜色生成器 =====" << endl;

    // 生成单个颜色
    Color c = randRGB();
    string hex = rgbToHex(c);
    string bright = getBrightness(c);

    cout << "\n随机颜色:" << endl;
    cout << "RGB: " << c.r << ", " << c.g << ", " << c.b << endl;
    cout << "十六进制: " << hex << endl;
    cout << "明暗: " << bright << endl;

    // 生成多个颜色
    cout << "\n生成10个随机颜色:" << endl;
    for (int i = 0; i < 10; i++) {
        Color temp = randRGB();
        cout << rgbToHex(temp) << "  ";
        if ((i + 1) % 5 == 0) cout << endl;
    }

    // 渐变色测试
    Color startColor = randRGB();
    Color endColor = randRGB();
    gradient(startColor, endColor, 8);

    return 0;
}
