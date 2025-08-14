/*los arreglos se comportan como punteros*/
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {12, 20, 30};
    int *p = arr;

    cout<<*(p+1); //20
}