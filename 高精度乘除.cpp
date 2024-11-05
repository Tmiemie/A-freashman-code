#include <iostream>
#include <string>
using namespace std;
string ch_a, ch_b;
int a[1001] = { 0 }, b[1001] = { 0 }, c[2002] = { 0 }; // c�ĳ���Ϊa��b����֮��
int main() {
    cin >> ch_a >> ch_b; // ��������������
    int a_size = ch_a.size(), b_size = ch_b.size(); // ��ȡ�������ĳ���
    // ����������洢��������
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0'; // �洢a��ÿһλ
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0'; // �洢b��ÿһλ
    // ģ��˷�����
    for (int i = 0; i < a_size; i++) {
        for (int j = 0; j < b_size; j++) {
            c[i + j] += a[i] * b[j]; // ��λ��ˣ����ۼӵ�c�Ķ�Ӧλ��
            if (c[i + j] >= 10) { // ���������ڵ���10
                c[i + j + 1] += c[i + j] / 10; // �����λ
                c[i + j] %= 10; // ȡ������������λ����
            }
        }
    }

    int max_size = a_size + b_size; // �������󳤶�
    // ȥ��ǰ����
    while (max_size > 1 && c[max_size - 1] == 0)
        max_size--;

    // ������
    for (int i = max_size - 1; i >= 0; i--)
        cout << c[i]; // �Ӹ�λ����λ������
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
        return A.size() < B.size(); // �Ƚϳ��ȣ����ȶ̵���С
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] != B[i])
            return A[i] < B[i]; // ������ͬ����λ�Ƚ�
    }
    return false;
}

void subtract(vector<int>& A, vector<int>& B) {
    for (int i = 0; i < B.size(); ++i) {
        A[i] -= B[i]; // ��λ���
        if (A[i] < 0) { // ������Ϊ����
            A[i] += 10; // ��ǰλ��λ��+10
            A[i + 1]--; // ��λ��1
        }
    }
    while (A.size() > 1 && A.back() == 0) {
        A.pop_back(); // ȥ��ǰ����
    }
}

int main() {
    cin >> ch_a >> ch_b; // ��������������
    for (int i = ch_a.size() - 1; i >= 0; --i)
        a.push_back(ch_a[i] - '0'); // �洢a��ÿһλ
    for (int i = ch_b.size() - 1; i >= 0; --i)
        b.push_back(ch_b[i] - '0'); // �洢b��ÿһλ

    while (!lessThan(a, b)) { // ��a��С��bʱ
        vector<int> temp(b);
        int count = 0;
        while (!lessThan(a, temp)) {
            subtract(a, temp); // ��a�м�ȥb
            ++count; // ����
        }
        c.push_back(count); // �洢�̵�λ��
    }

    // ������
    for (int i = c.size() - 1; i >= 0; --i)
        cout << c[i]; // �Ӹ�λ����λ������
    cout << endl;

    return 0;
}
