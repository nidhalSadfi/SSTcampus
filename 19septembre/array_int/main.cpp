#include <iostream>

using namespace std;


int main()
{
    cout << "Hello world!\n";
     int j = 19;
     int a = 12;
     //expresion rvalue !!!! ===> a + j = 100;

     j++;
     cout << "j="<< j << endl;
     cout << "j+1="<< j+1 << endl;
     cout << "j="<< j++ << endl;//20
     cout << "j="<< j << endl;//21
     //cout << "j="<< 21++ << endl;//21
     //cout << "(j+1)+1="<< (j+1)++<< endl;//21

    //Mannipultion dâ€™un tableau
    int numbers[] = {11, 22, 33};
    int * iPtr = numbers;
    cout << iPtr << endl;        // 0x22cd30
    cout << iPtr + 1 << endl;    // 0x22cd34 (increase by 4 - sizeof int)
    cout << *iPtr << endl;       // 11
    //cout << "0. " << *(iPtr + 1)++ << endl; // Expression lvalue!
    cout << "0. " << (*(iPtr + 1))++ << endl; // 22
    cout << "1. " << (*(iPtr++))++ << endl; // 22
    cout << "1. " << *iPtr << endl; // 23
    cout << "2. " << *iPtr + 1 << endl;   // 24
    cout << "3. "<< *iPtr << endl;       // 23
    iPtr+=1; // iPtr+1 est une instruction muette !!!!!!!
    
    int i = 10;
    i + 1; //muette

    cout << "3. " << *iPtr << endl;       // 22 13 17 11 12

    return 0;
}
