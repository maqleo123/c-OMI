/*reservar memoria para un arreglo dinamico*/
#include <iostream>
using namespace std;
int main()
{
    int* arr=new int [3];
    arr[0]=1;
    arr[1]=5;
    arr[2]=6;

    for(int i=0; i<3; i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;
}