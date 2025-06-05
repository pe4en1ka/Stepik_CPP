#include <iostream>
using namespace std;
int main(){
    int col1, str1, col2, str2;
    cin >> col1 >> str1 >> col2 >> str2;
    if (((str1 - str2) * (str1 - str2) == 4 && (col1 - col2) * ( col1 - col2) == 1) || ((str1 - str2) * (str1 - str2) == 1 && (col1 - col2) * ( col1 - col2) == 4)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}

