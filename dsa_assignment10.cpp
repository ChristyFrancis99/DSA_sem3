#include <iostream>
#include <string>
using namespace std;
#define size 5

class queue{
    string tk;
    public:
    queue(){tk="";}
    queue(string t){tk=t;}
    
    void settask(string t) {tk=t;}
    string gettask() {return tk;}
};

class tasks{
    int front, rear;
    queue q[size];
    public:
    tasks(){front=-1; rear=-1;}

    void insert(string t){
        if((front==0 && rear==size-1) || rear==front-1){
            cout<<"Queue is full\n";
        }
        else if(front==-1){
            front=0; rear=0;
            q[rear].settask(t);
        }
        else{
            rear=(rear+1)%size;
            q[rear].settask(t);
        }
    }
    void remove(){
        if(front==-1){
            cout<<"Empty\n";
        }
        else{
            string temp=q[front].gettask();
            front=(front+1)%size;
        }
    }
    void display(){
        if(front==-1){
            cout<<"Empty\n";
        }
        else{
            int i=front;
            while(true){
                cout<<q[i].gettask()<<endl;
                if (i==rear)
                    break;
                i=(i+1)%size;
            }
        }
    }
};

int main(){
    int x; string task; char c;
    tasks t;
    cout<<"1.Insert\n2.Remove\n";
    do{
        cout<<"Enter choice: ";
        cin>>x;
        switch (x){
        case 1:    
            cout<<"Enter task: ";
            cin.ignore();
            getline(cin, task);
            t.insert(task);
            break;
        case 2:
            t.remove();
            break;
        default:
            cout<<"Out of scope\n";
            break;
        }
        cout<<"y/n: ";
        cin>>c;
    }while(c=='y' || c=='Y');

    t.display();
    
    return 0;
}