#include <iostream>
using namespace std;
int main(){
    int col1, str1, col2, str2;
    cin >> col1 >> str1 >> col2 >> str2;
    if ((col1 - col2) * (col1 - col2) == (str1 - str2) * (str1 - str2) || (col1 == col2 || str1 == str2)){
        cout << "YES";
    }
    else if (col1 == col2 && str1 == str2) {
        cout << "NO";
    }
    else{
        cout << "NO";
    }
    return 0;
}

