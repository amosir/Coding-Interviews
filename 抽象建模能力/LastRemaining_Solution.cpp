#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
    // n表示小朋友的数量,m是随机指定的数
    int LastRemaining_Solution(int n, int m)
    {
        if(m < 1 || m < 1){
            return -1;
        }

        // 给孩子编号
        list<int> kids;
        for(int i = 0;i < n;i++){
            kids.push_back(i);
        }

        list<int>::iterator it = kids.begin();
        while(kids.size() > 1){
            int cnt = 0;
            while(cnt < m - 1){
                it++;
                if(it == kids.end()){
                    it = kids.begin();
                }
                cnt++;
            }
            // 去掉第m个编号
            it = kids.erase(it);
            if(it == kids.end()){
                it = kids.begin();
            }
        }
        return *it;
    }
};

int main(){
    Solution so;
    int n,m;
    cin >> n >> m;
    cout << so.LastRemaining_Solution(n,m) << endl;
    return 0;
}