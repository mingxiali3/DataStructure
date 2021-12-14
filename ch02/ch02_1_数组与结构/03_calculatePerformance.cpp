/*
  [名称]:03_calcultatePerformance.cpp
  [示范]:1.每个业务代表的前半年业绩总额
        2.1~6月每个月这三个业务代表的总业绩
  [给出的信息]:
   业务员  一月  二月  三月  四月 五月 六月
    1     112  76    95   120  98   68
    2     90   120   88   112  108  120
    3     108  99    126   90   76  98
*/
#include <iostream>
using namespace std;
int main()
{
    int salesman[3][6] = {{112,76,95,120,98,68},{90,120,88,112,108,120},{108,99,126,90,76,98}};
    int sum[3] ={};
    int total_3 = 0;
    int total_6 = 0;
    //计算每个业务代表的前半年的业绩总额
    for (int i = 0; i< 3 ; i++)
    {
        for (int j = 0;j < 6 ; j++)
        {
          total_3 += salesman[i][j]; 
        }
     cout << "Salesman  " << i+1 << "'s performance: " << total_3 << endl;
     total_3 = 0;//置于0
    }
    //计算每个月三个业务代表的总业绩
    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0; j < 3 ; j++)
        {

        total_6 += salesman[j][i];   
        
        }
    cout << "Month " << i+1 << " 's all performance: " << total_6 << endl;
    total_6 = 0;//置于0
    }
   return 0; 
}