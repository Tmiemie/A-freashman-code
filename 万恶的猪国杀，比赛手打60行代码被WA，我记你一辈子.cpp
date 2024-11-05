/*Problem G. 猪国杀
众所粥之，Galaxy 最喜欢猪国杀了，而一场 AK 杯又要放个大模拟，所以 Galaxy 就把猪国杀放上来了。
佩奇和乔治这天在一起玩猪国杀。
开始游戏时，牌堆中有 n 张牌，大家的手牌为都空，各有 4 滴血。
从佩奇开始，轮流执行以下操作：
摸牌阶段： 由牌堆顶摸一张牌，这张牌必然是 杀（K），闪（D），桃（P）之一；
出牌阶段： 依次尝试执行以下操作：
若手中有杀，则立即向对手打出，对手需要响应一张闪，否则扣一滴血；
若手中有桃且不满血，则打出桃，恢复一滴血；
两操作可同时执行；
弃牌阶段： 若手牌数大于血量，则弃牌直到手牌数等于血量，有闪则优先弃置闪，无闪则弃置桃。
若某只小猪血量降为 0，可以立即打出桃以回血，否则它就输掉了游戏；
若牌堆的牌被摸完，小猪们都无牌可出，它们就会握手言和，回家吃饭。
afanafan 并不能解决这个问题，所以把题目丢给了你，你需要告诉 afanafan，游戏的结果
输入
第一行包含 
T
T 
(
1
≤
T
≤
1
0
0
)
(1≤T≤100)——测试用例数。

每个测试用例的第一行包含一个整数 
n
n 
(
1
≤
n
≤
1
0
0
,
0
0
0
)
(1≤n≤100,000)——初始牌堆中的牌数。

每个测试用例的第二行包含一个长度为 
n
n 的字符串 
s
s，仅由 
K
，
D
，
P
K，D，P 三个字符组成，左边为牌堆顶，右边为牌堆底

保证所有样例中 
n
n 的和小于等于 
1
0
5
10 
5
 。

输出

若佩奇胜利，输出 Peppa； 若乔治胜利，输出 George； 若牌堆的牌被摸完并无牌可出，则平局回家吃饭，输出 fanfan。

样例

标准输入
3
10
KKKKKKKKKK
21
KDPDPDPDKKKKKKKKKKKKK
17
KKDPDPDPKKKKKKKKK
标准输出
Peppa
Peppa
fanfan*/
#include <iostream>
using namespace std;
int T;
int n, m,j;
string str;
char ch;

 void hanshu()
 {
	 cin >> n;
	 j = 1;
	 cin >> str;
	 int  p1 = 4, p2 = 4, p1_k=0, p2_k=0, p1_d=0, p2_d=0, p1_p=0, p2_p=0;
	 for (char ch : str)
	 {       
			 if (j & 1)
			 {
				 if (ch == 'K')p1_k++; if (ch == 'D') p1_d++; if (ch == 'P')p1_p++;
				 if (p1_k != 0 && p2_d == 0) { p1_k--; p2--; }
				 if (p2 == 0) { if (p2_p != 0) { p2_p--; p2++; } else { cout << "Peppa\n"; return; } }
				 if (p1_k != 0 && p2_d != 0) { p1_k--; p2_d--; }
				 if (p1_p != 0 && p1 != 4) { p1_p--; p1++; }
				 while (p1_k + p1_d + p1_p > p1) { if (p1_d != 0)p1_d--; else if (p1_p != 0)p1_p--; else p1_k--; }
			 }
			 else
			 {
				 if (ch == 'K')p2_k++; if (ch == 'D')p2_d++; if (ch == 'P')p2_p++;
				 if (p2_k != 0 && p1_d == 0) { p2_k--; p1--; }
				 if (p1 == 0) { if (p1_p != 0) { p1_p--; p1++; } else { cout << "George\n"; return; } }
				 if (p2_k != 0 && p1_d != 0) { p2_k--; p1_d--; }
				 if (p2_p != 0 && p2 != 4) { p2_p--; p2++; }
				 while (p2_k + p2_d + p2_p > p2) { if (p2_d != 0)p2_d--; else if (p2_p != 0)p2_p--; else p2_k--; }
			 }
			 j++;
	 }cout << "fanfan\n";	return;
 }

int main()
{
	cin >> T;
	while (T--)
	{	
		hanshu();
	}
	return 0;
}