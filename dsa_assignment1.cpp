#include <iostream>
using namespace std;

class Temp {
    float* cel;
    int n;
public:
    Temp(int size) {
        n = size;
        cel = new float[n];
    }
    void getdata() {
        for (int i = 0; i < n; i++) {
            cout << "Enter temperature for entry " << i + 1 << ": ";
            cin >> cel[i];
        }
    }
    void insertionsort() {
        for (int i = 1; i < n; i++) {
            float key = cel[i];
            int j = i - 1;
            while (j >= 0 && cel[j] > key) {
                cel[j + 1] = cel[j];
                j--;
            }
            cel[j + 1] = key;
        }
    }
    void display() {
        cout << "\nTemperatures after sorting:\n";
        for (int i = 0; i < n; i++) {
            cout << cel[i] << " \n";
        }
        cout << endl;
        cout<<"Minimum temperature: "<<cel[0]<<endl;
        cout<<"Maximum temperature: "<<cel[n-1];
    }
};

int main() {
    int n;
    cout <<"\nEnter number of temperature readings: ";
    cin >> n;

    Temp t(n);
    t.getdata();
    t.insertionsort();
    t.display();

    return 0;
}