#include <iostream>
#include <string>
using namespace std;

const int n=10;

class stack{
    public:
    int top;
    string shelf[n];
    stack(){top=-1;}
};
class ret{
    public:
    void insert(stack &s, string name){
        if(s.top==n-1){
            cout<<"Shelf full\n";
        }
        else{
            s.top++;
            s.shelf[s.top]=name;
        }
    }
    void display(stack &s){
        if(s.top==-1){
            cout<<"Shelf empty\n";
        }
        else{
            while(s.top>-1){
                cout<<"| "<<s.shelf[s.top]<<" |";
                cout<<endl;
                s.top--;
            }
        }
    }
};

int main(){
    stack s;
    ret r;
    string name; char c;
    do{
        cout<<"Enter book name: ";
        cin>>name;
        r.insert(s, name);
        cout<<"y/n: ";
        cin>>c;
    }while(c=='y' || c=='Y');

    r.display(s);
    
    return 0;
}