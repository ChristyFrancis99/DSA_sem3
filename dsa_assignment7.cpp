#include <iostream>
#include <string>
using namespace std;
 
class order{
    public:
    string name;
    order *next; order *prev;
    order(){name=""; next=NULL; prev=NULL;}
    order(string itemname){name=itemname; next=NULL; prev=NULL;}
};
class store{
    public:
    order *head; order *curr;
    store(){head=NULL; curr=NULL;}

    void add(string itemname){
        order *newname = new order(itemname);
        if(head==NULL){
            head=newname;
            head->prev=head;
            head->next=head;
        }
        else{
            order *t = head;
            while(t->next!=head){
                t=t->next;
            }
            t->next=newname;
            newname->prev=t;
            newname->next=head;
        }
        curr=newname;
        cout<<"Item added\n";
    }
    void goback(){
        if(curr==NULL || curr->prev==NULL){
            cout<<"Previous empty.\n";
        }
        else{
            curr=curr->prev;
            cout<<"Previous order: "<<curr->name<<endl;
        }
    }
    void goforward(){
        if(curr==NULL || curr->next==NULL){
            cout<<"Next empty.\n";
        }
        else{
            curr=curr->next;
            cout<<"Next order: "<<curr->name<<endl;
        }
    }
    void edit(int no, string itemname){
        if(head==NULL){
            cout<<"Order history empty\n";
        }
        else{
            order *t = head;
            int count = 1;
            while(t->next!=head && count!=no){
                t=t->next;
                count++;
            }
            if(count==no){
                t->name=itemname;
                curr=t;
                cout<<"Item changed\n";
            }
            else{cout<<"Invalid order number\n";}
        }
    }
    void display(){
        if(head==NULL){
            cout<<"No order in history\n";
        }
        else{
            order *t = head;
            while(t->next!=curr->next || t->next!=head){
                cout<<t->name<<" -> ";
                t = t->next;
            }
            cout<<t->name<<endl;
        } 
    }
};

int main(){
    store s;

    int choice, no; char x;
    string itemname;

    cout<<"\n---- Order History----\n";
    cout<<"1. Add order\n2. Go Back\n3. Go Forward\n4. Edit order\n5. Display order history\n";

    do{
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> itemname;
                s.add(itemname);
                break;
            case 2:
                s.goback();
                break;
            case 3:
                s.goforward();
                break;
            case 4:
                cout<<"Enter order number you want to edit: ";
                cin>>no;
                cout<<"Enter item name: ";
                cin>>itemname;
                s.edit(no, itemname);
                break;
            case 5:
                s.display();
                break;
            default:
                cout<<"Invalid choice.\n";
            }
        cout<<"Do you want to continue (y/n): ";
        cin>>x;
    }while(x=='y' || x=='Y');
    cout<<"Exiting store.";
    return 0;
}