#include <iostream>
#include <string>
using namespace std;
string ch_a, ch_b;
int a[1001] = { 0 }, b[1001] = { 0 }, c[1001] = { 0 };
int main() {
    cin >> ch_a >> ch_b;
    int a_size = ch_a.size(), b_size = ch_b.size();
    //�����������
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0';
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0';
    //ģ��ӷ�
    int max_size = max(a_size, b_size);
    for (int i = 0; i < max_size; i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    //������λ0
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

string ch_a, ch_b; // ���ڴ洢����Ĵ�����
int a[1001] = { 0 }, b[1001] = { 0 }, c[1001] = { 0 }; // ���ڴ洢ÿλ���ֵ�����

bool isGreaterOrEqual() {
    if (ch_a.size() != ch_b.size())
        return ch_a.size() > ch_b.size(); // �Ƚϳ��ȣ����ȳ�������
    return ch_a >= ch_b; // ������ͬ����λ�Ƚ�
}

int main() {
    cin >> ch_a >> ch_b; // ��������������
    int a_size = ch_a.size(), b_size = ch_b.size(); // ��ȡ�������ĳ���

    // ����������洢��������
    for (int i = 0; i < a_size; i++)
        a[i] = ch_a[a_size - i - 1] - '0'; // �洢a��ÿһλ
    for (int i = 0; i < b_size; i++)
        b[i] = ch_b[b_size - i - 1] - '0'; // �洢b��ÿһλ

    if (!isGreaterOrEqual()) {
        swap(a, b); // ��������a��b��ʹ��aʼ�մ��ڵ���b
        swap(ch_a, ch_b); // ����ԭʼ�ַ������Ա����ʱ����
    }

    int max_size = max(a_size, b_size); // ȡa��b�нϴ󳤶�

    // ģ���������
    for (int i = 0; i < max_size; i++) {
        c[i] += a[i] - b[i]; // ��λ������洢��c��
        if (c[i] < 0) { // ������Ϊ����
            c[i] += 10; // ��ǰλ��λ��+10
            a[i + 1]--; // ��λ��1
        }
    }

    // ȥ��ǰ����
    while (max_size > 1 && c[max_size - 1] == 0)
        max_size--;

    // ������
    for (int i = max_size - 1; i >= 0; i--)
        cout << c[i]; // �Ӹ�λ����λ������
    cout << endl;

    return 0;
}

