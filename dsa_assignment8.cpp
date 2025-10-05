#include <iostream>
#include <string>
using namespace std;

class word {
    public:
    int top;
    string stack[100];

    word() {
        top = -1;
    }

    void insert(int n, string name) {
        if (top == n - 1) {
            cout << "Stack full" << endl;
        } else {
            top++;
            stack[top] = name;
        }
    }

    void reverse() {
        while (top != -1) {
            cout << stack[top] << " ";
            top--;
        }
        cout << endl;
    }
};

int main() {
    string name; int n;
    word w;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter words:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> name;
        w.insert(n, name);
    }

    cout << "Reversed words: ";
    w.reverse();

    return 0;
}
