#include<iostream>
#include<string>
using namespace std;
#define size 5

class queue{
    public:
    int front, rear, prio[size];
    string name[size], symn[size];
    queue(){front=-1;rear=-1;}

    void enqueue(string n, string s, int p){
        if(rear==size-1){
            cout<<"Queue full\n";
        }
        else if(rear==-1){
            rear=0; front=0;
            name[rear]=n;
            symn[rear]=s;
            prio[rear]=p;
        }
        else{
            int i;
            for(i=rear; i>=front && prio[i]<p; i--){
                name[i+1]=name[i];
                symn[i+1]=symn[i];
                prio[i+1]=prio[i];
            }
            name[i+1]=n;
            symn[i+1]=s;
            prio[i+1]=p;
            rear++;
        }
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue empty\n";
        }
        else{
            string tempd=name[front];
            string temps=symn[front];
            int tempp=prio[front];
            cout<<"Data: "<<tempd<<"Symt: "<<temps<<" Priority: "<<tempp<<endl;
            front++;
        }
    }
    void display(){
        if(rear==-1){
            cout<<"Queue empty\n";
        }
        else{
            for(int i=front; i<=rear; i++){
                cout<<"Data: "<<name[i]<<" | Symt: "<<symn[i]<<" | Prio: "<<prio[i]<<endl;
            }
        }
    }
};

int main(){
    int p, x; char c; string n, s;
    queue q;
    cout<<"1.Enter queue\n2.Delete queue\n";
    do{
        cout<<"Enter choice: ";
        cin>>x;
        switch(x){
            case 1:
                cout<<"Enter name: ";
                cin>>n;
                cout<<"Enter Symptom: ";
                cin>>s;
                cout<<"Enter priority: ";
                cin>>p;
                q.enqueue(n, s, p);
                break;
            case 2:
                q.dequeue();
                break;
            default:
                cout<<"Out of scope\n";
                break;
        }
        cout<<"y/n: ";
        cin>>c;
    }while(c=='y' ||c=='Y');

    q.display();
    return 0;
}