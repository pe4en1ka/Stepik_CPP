#include <iostream>

using namespace std;

int main(){
    int col1, str1, col2, str2;
    cin >> col1 >> str1 >> col2 >> str2;
    if ((col1 - col2 == 1 && str1 - str2 == 1) || (col2 - col1 == 1 && str1 - str2 == 1) || (col1 - col2 == 1 && str2 - str1 == 1) || (col2 - col1 == 1 && str2 - str1 == 1) || (col1 - col2 == 1 && str1 - str2 == 0) || (col2 - col1 == 0 && str1 - str2 == 1) || (col1 - col2 == 0 && str2 - str1 == 1) || (col2 - col1 == 1 && str2 - str1 == 0)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}

