#include <iostream>
using namespace std;




int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int a=arr[0];
    int b=arr[n-1];
    int sum=0;
    int actualsum=0;
    
    for(int i=a;i<=b;i++)
    sum=sum+i;
    
    for(int j=0;j<n;j++)
    actualsum=actualsum+arr[j];
    
   int missednum= sum-actualsum;
    cout<<"Missing number was "<<missednum;
}


  
