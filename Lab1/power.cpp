#include <iostream>
using namespace std;


    
int pow(int x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    int m = n;
    int z = x;
    int pow_result = 1;
    while(m>1)
    {
        if(m%2==0)
        {
            z=z*z;
            m=m/2;
        }
        else
        {
            pow_result = pow_result * z;
            m = m - 1;
        }
    }
    return pow_result;
}


int main()
{
    int x, n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    cout << "Result = " << pow(x, n);
    return 0;
}