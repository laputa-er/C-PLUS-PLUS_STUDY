/*****************************************
* 练知识点：命名空间 输入输出 bool
*******************************************/
#include <iostream>
using namespace std;

namespace CommonA
{
    // 找出一个整型数组中的最大值或最小值
    int getMaxOrMin(int *arr, int count, bool isMax)
    {
        int temp = arr[0];
        for(int i = 1; i < count; i++) {
            if(isMax)
            {
                if(temp < arr[i])
                {
                    temp = arr[i];
                }
            }
            else
            {
                if(temp > arr[i])
                {
                    temp = arr[i];
                }
            }
            
        }
        return temp;
    }

}

int main(void)
{
    int arr1[4] = {3, 5, 9, 2};
    bool isMax = false;
    
    // 指定输出最大值还是最小值(0： 最小值， 1:最大值)
    cin >> isMax;
    
    cout << CommonA::getMaxOrMin(arr1, 4, isMax) << endl;
    return 0;
}