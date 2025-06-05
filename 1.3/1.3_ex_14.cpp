#include <iostream>
using namespace std;
int main(){
    int height, day, night, speed;
    cin >> height >> day >> night;
    height = height - day;
    speed = day - night;
    cout << (height + speed - 1)/speed + 1;;
    return 0;
}
