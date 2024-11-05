#include <iostream>
#include <string>
using namespace std;
string ch_a, ch_b;
int a[1001] = { 0 }, b[1001] = { 0 }, c[2002] = { 0 }; // c的长度为a和b长度之和
int main() {
    cin >> ch_a >> ch_b; // 输入两个大整数
    int a_size = ch_a.size(), b_size = ch_b.size(); // 获取两个数的长度
    // 将数字逆序存储到数组中
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0'; // 存储a的每一位
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0'; // 存储b的每一位
    // 模拟乘法操作
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < b_size; j++) {
            c[i + j] += a[i] * b[j]; // 逐位相乘，并累加到c的对应位置
            if (c[i + j] >= 10) { // 如果结果大于等于10
                c[i + j + 1] += c[i + j] / 10; // 处理进位
                c[i + j] %= 10; // 取余数，保留个位数字
            }
        }
    }

    int max_size = a_size + b_size; // 结果的最大长度
    // 去除前导零
    while (max_size > 1 && c[max_size - 1] == 0)
        max_size--;

    // 输出结果
    for (int i = max_size - 1; i >= 0; i--)
        cout << c[i]; // 从高位到低位输出结果
    cout << endl;

    return 0;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ch_a, ch_b;
vector<int> a, b, c;

bool lessThan(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size())
        return A.size() < B.size(); // 比较长度，长度短的数小
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] != B[i])
            return A[i] < B[i]; // 长度相同，逐位比较
    }
    return false;
}

void subtract(vector<int>& A, vector<int>& B) {
    for (int i = 0; i < B.size(); ++i) {
        A[i] -= B[i]; // 逐位相减
        if (A[i] < 0) { // 如果结果为负数
            A[i] += 10; // 向当前位借位，+10
            A[i + 1]--; // 高位借1
        }
    }
    while (A.size() > 1 && A.back() == 0) {
        A.pop_back(); // 去除前导零
    }
}

int main() {
    cin >> ch_a >> ch_b; // 输入两个大整数
    for (int i = ch_a.size() - 1; i >= 0; --i)
        a.push_back(ch_a[i] - '0'); // 存储a的每一位
    for (int i = ch_b.size() - 1; i >= 0; --i)
        b.push_back(ch_b[i] - '0'); // 存储b的每一位

    while (!lessThan(a, b)) { // 当a不小于b时
        vector<int> temp(b);
        int count = 0;
        while (!lessThan(a, temp)) {
            subtract(a, temp); // 从a中减去b
            ++count; // 计数
        }
        c.push_back(count); // 存储商的位数
    }

    // 输出结果
    for (int i = c.size() - 1; i >= 0; --i)
        cout << c[i]; // 从高位到低位输出结果
    cout << endl;

    return 0;
}
