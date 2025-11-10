#include <iostream>
#include <string>
using namespace std;
#define size 10

class hh {
    int eid[size];
    string ename[size];
    bool check[size];
    
public:
    hh() {
        for (int i = 0; i < size; i++) {
            check[i] = false;
            eid[i] = -1; ename[i] = "";
        }
    }

    void insert(string name, int id) {
        int key = id % size;
        int start = key;

        while (check[key] == true) {
            key = (key + 1) % size;
            if (key == start) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        
        eid[key] = id;
        ename[key] = name;
        check[key] = true;
    }

    void display() {
        cout << "ID | Name\n";
        for (int i = 0; i < size; i++) {
            if (check[i])
                cout<<eid[i]<<" | "<<ename[i]<<endl;
            else
                cout<<"Empty"<< endl;
        }
    }
};

int main() {
    string name;
    int id;
    char c;
    hh h;

    do {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        h.insert(name, id);

        cout << "Continue? (y/n): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    h.display();
    return 0;
}
