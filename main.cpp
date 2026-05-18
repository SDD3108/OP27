#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <map>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <numeric>
using namespace std;

// int main(){
//     srand(static_cast<unsigned int>(time(0))); // 1 января 1970
//     int random = rand() % 101 - 50;
//     cout << random << endl;
// };

// скользящие окно, смотрит k количество элементов в массиве и какое самое большое комбо того и выводит
// int maxSum(const vector<int>& arr, int k){
//     int n = arr.size();
//     if(n < k){
//         return -1;
//     }
// 
//     int currentWindowSum = 0;
//     for(int i = 0; i < k; i++){
//         currentWindowSum += arr[i];
//     }
//     int maxSum = currentWindowSum;
//     for(int i = k; i < n; i++){
//         currentWindowSum += arr[i] - arr[i - k];
//         maxSum = max(maxSum,currentWindowSum);
//     }
//     return maxSum;
// }
// int main(){
//     vector<int> array = {1,4,5,7,10,9,11};
//     // vector<int> array = {1,4,2,10,2,3,1,0,20};
//     int k = 3;
//     int result = maxSum(array,k);  
//     if(result != -1){
//         cout << "max summ of sub array " << k << " equal " << result << endl;
//     }
// }
// у меня не работает sidebar, у меня он просто напросто белый, какие могут быть причины этого
// 1. ктото накосячил с feature/sidebar or common/sidebar or app/layout.ts


// ctime and cstdlib
// int main(){
//     srand(time(0)); // 1 января 1970
// 
//     vector<int> arr(5);
//     for(int i = 0; i < 5; i++){
//         arr[i] = rand() % 100 + 1;
//         cout << arr[i] << endl;
//     }
// }

// game project, у нас будет матрица и это типо игровое поле, игрок отображается как "P" и там будут всякие еще стены итд, пользователь будет управлять игроком через консоль вписывая wasd, 
// типо нажал w и "P" поднялся на 1 клетку вверх в матрице итд

