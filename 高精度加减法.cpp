#include <iostream>
#include <string>
using namespace std;
string ch_a, ch_b;
int a[1001] = { 0 }, b[1001] = { 0 }, c[1001] = { 0 };
int main() {
    cin >> ch_a >> ch_b;
    int a_size = ch_a.size(), b_size = ch_b.size();
    //倒序存入数字
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0';
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0';
    //模拟加法
    int max_size = max(a_size, b_size);
    for (int i = 0; i < max_size; i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    //处理首位0
    if (c[max_size] > 0)
        max_size++;
    for (int i = max_size - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

string ch_a, ch_b; // 用于存储输入的大整数
int a[1001] = { 0 }, b[1001] = { 0 }, c[1001] = { 0 }; // 用于存储每位数字的数组

bool isGreaterOrEqual() {
    if (ch_a.size() != ch_b.size())
        return ch_a.size() > ch_b.size(); // 比较长度，长度长的数大
    return ch_a >= ch_b; // 长度相同，逐位比较
}

int main() {
    cin >> ch_a >> ch_b; // 输入两个大整数
    int a_size = ch_a.size(), b_size = ch_b.size(); // 获取两个数的长度

    // 将数字逆序存储到数组中
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0'; // 存储a的每一位
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0'; // 存储b的每一位

    if (!isGreaterOrEqual()) {
        swap(a, b); // 交换数组a和b，使得a始终大于等于b
        swap(ch_a, ch_b); // 交换原始字符串，以便输出时处理
    }

    int max_size = max(a_size, b_size); // 取a和b中较大长度

    // 模拟减法操作
    for (int i = 0; i < max_size; i++) {
        c[i] += a[i] - b[i]; // 逐位相减，存储到c中
        if (c[i] < 0) { // 如果结果为负数
            c[i] += 10; // 向当前位借位，+10
            a[i + 1]--; // 高位借1
        }
    }

    // 去除前导零
    while (max_size > 1 && c[max_size - 1] == 0)
        max_size--;

    // 输出结果
    for (int i = max_size - 1; i >= 0; i--)
        cout << c[i]; // 从高位到低位输出结果
    cout << endl;

    return 0;
}

