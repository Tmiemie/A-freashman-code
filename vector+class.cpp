#include<iostream>
#include<vector>
using namespace std;
class Joseph 
{
public:
    Joseph(int n, int m, int k) : n(n), m(m), k(k) 
    {
        for (int i = 1; i <= n; ++i) 
        {
            people.push_back(i);
        }
    }
    void simulate() 
    {
        int pos = k - 1; 
        while (!people.empty()) 
        {
            pos = (pos + m -1) % people.size();
            cout << people[pos] << " ";
            people.erase(people.begin() + pos);
        }
    }
private:
    int n; 
    int m; 
    int k; 
    vector<int> people; 
};

int main() {
    int n, m, k;
    cin >> n >> m >> k; 
    Joseph obj(n, m, k);
    obj.simulate();
    return 0;
}
