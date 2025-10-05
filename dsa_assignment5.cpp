#include <iostream>
using namespace std;

class var{
public:
    int data, pow;
    var *next;
    var(){
        data = 0; pow = 0;
        next = NULL;
    }
    var(int a, int b){
        data = a; pow = b;
        next = NULL;
    }
};

class eq{
public:
    var *head;
    eq() { head = NULL; }

    void insert(int a, int b)
    {
        var *nn = new var(a, b);
        if (head == NULL){
            head = nn;
        }
        else{
            var *t = head;
            while (t->next != NULL){
                t = t->next;
            }
            t->next = nn;
        }
    }

    void display(){
        if (head == NULL){
            cout << "Empty\n";
        }
        else{
            var *t = head;
            while (t != NULL){
                cout << t->data << "x^" << t->pow;
                if (t->next != NULL)
                    cout << " + ";
                t = t->next;
            }
            cout << endl;
        }
    }
};

void add(eq &e1, eq &e2, eq &e3)
{
    var *t1 = e1.head;
    var *t2 = e2.head;

    while (t1 != NULL && t2 != NULL){
        if (t1->pow == t2->pow){
            int sum = t1->data + t2->data;
            e3.insert(sum, t1->pow);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->pow > t2->pow){
            e3.insert(t1->data, t1->pow);
            t1 = t1->next;
        }
        else{
            e3.insert(t2->data, t2->pow);
            t2 = t2->next;
        }
    }

    while (t1 != NULL){
        e3.insert(t1->data, t1->pow);
        t1 = t1->next;
    }
    while (t2 != NULL){
        e3.insert(t2->data, t2->pow);
        t2 = t2->next;
    }
}

int main(){
    eq e1, e2, e3;
    int a, b, c;
    char x;

    cout << "1: Insert term in Equation 1\n";
    cout << "2: Insert term in Equation 2\n";

    do{
        cout << "Choice: ";
        cin >> c;
        switch (c){
        case 1:
            cout << "Enter Coefficient and Power for E1: \n";
            cin >> a >> b;
            e1.insert(a, b);
            break;
        case 2:
            cout << "Enter Coefficient and Power for E2: \n";
            cin >> a >> b;
            e2.insert(a, b);
            break;
            default:
            cout <<"ERROR!\n";
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> x;
        cout<<endl;
    } while (x == 'y' || x == 'Y');
    
    cout <<"Equation 1: ";
    e1.display();
    cout <<"Equation 2: ";
    e2.display();
    cout <<"Result: ";
    add(e1, e2, e3);
    e3.display();

    return 0;
}