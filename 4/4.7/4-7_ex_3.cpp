#include <iostream>
using namespace std;

void lower(string &s) {
    for (char & i : s) {
        if (i >= 'A' && i <= 'Z') {
            i = char('a' + (i - 'A'));
        }
    }
}

int main() {
    string animal;
    cin >> animal;
    lower(animal);
    if (animal == "cat") {
        cout << "meow";
    }
    else if (animal == "dog") {
        cout << "woof";
    }
    else if (animal == "pig") {
        cout << "grunt";
    }
    else if (animal == "rooster") {
        cout << "cock-a-doodle-doo";
    }
    else if (animal == "cow") {
        cout << "moo";
    }
    else {
        cout << "joff-tchoff-tchoffo-tchoffo-tchoff";
    }
}