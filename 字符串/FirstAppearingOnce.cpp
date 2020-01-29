#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
private:
    vector<char> str;
    map<char,int> char_map;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str.push_back(ch);
        map<char,int>::iterator it = char_map.find(ch);
        if(it == char_map.end()){
          char_map.insert(pair<char,int>(ch,1));
        }else{
          it->second ++;
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
      int len = str.size();
      for(int i = 0;i < len;i++){
        map<char,int>::iterator it = char_map.find(str[i]);
        if(it->second == 1){
          return it->first;
        }
      }
      return  '#';
    }

};