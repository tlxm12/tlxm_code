#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 单词库
vector<string> nouns = {"cat", "dog", "tree", "book", "computer", "sun", "moon", "student", "teacher", "city"};
vector<string> verbs = {"run", "eat", "sleep", "read", "write", "play", "work", "study", "drive", "sing"};
vector<string> adjectives = {"happy", "big", "small", "beautiful", "smart", "fast", "slow", "kind", "funny", "calm"};

// 首字母大写
string capitalize(string s) {
    if (!s.empty()) s[0] = toupper(s[0]);
    return s;
}

// 随机单词
string getWord() {
    int type = rand() % 3;
    if (type == 0) return nouns[rand() % nouns.size()];
    if (type == 1) return verbs[rand() % verbs.size()];
    return adjectives[rand() % adjectives.size()];
}

// 随机句子
string getSentence() {
    stringstream ss;
    ss << capitalize(adjectives[rand() % adjectives.size()]) << " ";
    ss << nouns[rand() % nouns.size()] << " ";
    ss << verbs[rand() % verbs.size()] << " ";
    ss << adjectives[rand() % adjectives.size()] << " ";
    ss << nouns[rand() % nouns.size()] << ".";
    return ss.str();
}

// 随机段落
string getParagraph(int count) {
    stringstream ss;
    for (int i = 0; i < count; i++) {
        ss << getSentence() << " ";
    }
    return ss.str();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "===== 随机文本生成器 =====" << endl;

    // 单词
    cout << "\n随机单词: " << getWord() << endl;

    // 句子
    cout << "随机句子: " << getSentence() << endl;

    // 段落
    int sentenceCount = 5;
    cout << "\n随机段落(" << sentenceCount << "句):\n" << getParagraph(sentenceCount) << endl;

    // 批量生成
    cout << "\n生成5个句子:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << getSentence() << endl;
    }

    return 0;
}
