#include<iostream>
#include<string>
using namespace std;

class song{
    public:
    string data;
    song *next;
    song(){data="0"; next=NULL;}
    song(string n){data=n;next=NULL;}
};
class playlist{
    public:
    song *head;
    playlist(){head=NULL;}

    void insert_end(string n){
        song *ns = new song(n);
        if(head==NULL){
            head=ns;
        }
        else{
            song *t = head;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=ns;
        }
    }
    void insert_start(string n){
        song *ns = new song(n);
        if(head==NULL){
            head=ns;
        }
        else{
            ns->next = head;
            head = ns;
        }
    }
    void insert_bet(string n, int key){
        song *ns = new song(n);
        if(head==NULL){
            head=ns;
        }
        else{
            song *t = head;
            int count = 0;
            while(t->next!=NULL && count<key){
                t=t->next;
                count ++;
            }
            ns->next = t->next;
            t->next=ns;
        }
    }
    void delete_start(){
        if(head==NULL){
            cout<<"No song to delete.\n";
        }
        else{
            song* t = head;
            head = head -> next;
            delete t; 
        }
    }
    void delete_end(){
        if(head==NULL){
            cout<<"Playlist empty.\n";
        }
        else{
            song *t = head;
            song *p = NULL;
            while(t->next!=NULL){
                p=t;
                t=t->next;
            }
            p->next=NULL;
            delete t;
        }
    }
    void delete_pos(int key){
        if(head==NULL){
            cout<<"Playlist empty.\n";
        }
        else if(key==1){
            song* t = head;
            head = head -> next;
            delete t; 
        }
        else{
            song *t= head;
            int count = 1;
            while(t->next != NULL && count<key){
                t=t->next;
                count ++;
            }
            song *del = t->next;
            t->next=del->next;
            delete del;
        }
    }
    void navigate(string name){
        if(head==NULL){
            cout<<"Playlist empty.\n";
        }
        song *p = NULL;
        song *t = head;
        while (t != NULL && t -> data != name) {
            p = t;
            t = t->next;
        }
        if (p != NULL)
            cout<<"Previous: "<<p->data<<endl;
        else
            cout<<"Previous: NULL"<<endl;
        if (t ->next != NULL)
            cout<<"Next: "<<t->next->data<<endl;
        else
            cout<<"Next: NULL"<<endl;
    }
    void countsong(){
        int countsg = 0;
        if(head==NULL){
            cout<<"Playlist empty.\n";
        }
        else{
            song *t = head;
            countsg = 1;
            while(t->next!=NULL){
                t=t->next;
                countsg++;
            }
        }
        cout<<"Total song queued "<<countsg<<endl;
    }
    void reverse(){
        song *t = head;
        song *p = NULL;
        while(t != NULL){
            song *nn = t->next;
            t->next = p;
            p = t;
            t = nn;
        }
        head = p;
    }
    void display(){
        if(head==NULL){
            cout<<"Playlist empty.\n";
        }
        else{
            song *t = head;
            while(t!=NULL){
                cout<<t->data<<"\t";
                t=t->next;
            }
        }cout<<endl;
    }
};

int main(){
    playlist p;
    string name;
    char c;
    int x, key;
    cout<<"1: Insert at End\t2: Insert at Start\t3: In between\n";
    cout<<"4: Delete at start\t5: Delete at end\t6: Delete at position\n";
    cout<<"7: Navigate next and previous songs\n";
    do{
        cout<<"Enter case: "; cin>>x;
        switch(x){
            case 1:
                cout<<"Enter song name: ";
                cin>>name;
                p.insert_end(name);
            break;
            case 2:
                cout<<"Enter song name: ";
                cin>>name;
                p.insert_start(name);
            break;
            case 3:
                cout<<"Enter song name: ";
                cin>>name;
                cout<<"Enter position: ";
                cin>>key;
                p.insert_bet(name, key);
            break;
            case 4:
                p.delete_start();
            break;
            case 5:
                p.delete_end();
            break;
            case 6:
                cout<<"Enter position: ";
                cin>>key;
                p.delete_pos(key);
            break;
            case 7:
                cout<<"Enter song name: ";
                cin>>name;
                p.navigate(name);
            break;
            default:
            cout<<"Error\n";
            break;
        }
        cout<<"Do you want to continue (y/n): ";
        cin>>c;
    }while(c=='y'||c=='Y');
    p.countsong();
    cout<<"Before reverse.\n"; p.display();    
    p.reverse();
    cout<<"After reverse.\n"; p.display();
    cout<<"End of playlist.\n";
    return 0;
}