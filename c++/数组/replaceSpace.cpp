#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        sort(numbers,numbers + length);
        for(int i = 0;i < length - 1;i++){
            if(numbers[i] == numbers[i+1]){
                *duplication = numbers[i];
                return true; 
            }
        }
        duplication = NULL;
        return  false;
    }
};
