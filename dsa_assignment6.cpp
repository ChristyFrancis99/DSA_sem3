#include<iostream>
#include<string>
using namespace std;

class File{
    public:
    string name; File *next; File *prev;
    File(){name=""; next=nullptr; prev=nullptr;}
    File(string foldername){name=foldername; next=nullptr; prev=nullptr;}
};

class FileNavigator{
    public:
    File *head; File *curr;
    FileNavigator(){head=NULL; curr=NULL;}
    
    void navigate(string foldername){
        File *newfile = new File(foldername);
        if(head==NULL){
            head=newfile;
            curr=newfile;
        }
        else{
            File *temp = head;
            while(temp->next!=NULL){
                if(temp->name==foldername){
                    cout<<"File already exist\n";
                    return;
                }
                else{
                    temp=temp->next;
                }
            }
            temp->next = newfile;
            newfile->prev=temp;
            curr=newfile;
        }
    }
    void goback(){
        if(curr->prev!=NULL){
            curr=curr->prev;
            cout<<"Previous file: "<<curr->name<<endl;
        }
        else{
            cout<<"No previous file.\n";
        }
    }
    void goforward(){
        if(curr->next!=NULL){
            curr=curr->next;
            cout<<"Next file: "<<curr->name<<endl;
        }
        else{
            cout<<"No next file.\n";
        }
    }
    void display(){
        if(head==NULL){
            cout<<"No file to access\n";
        }
        else{
            File *temp = head;
            while(temp->next!=curr->next){
                cout<<temp->name<<" -> ";
                temp = temp->next;
            }
            cout<<temp->name<<endl;
        } 
    }
};

int main(){
    FileNavigator n;

    int choice; char x;
    string foldername;

    cout<<"\n---- File Navigation System ----\n";
    cout<<"1. Navigate to New Folder\n2. Go Back\n3. Go Forward\n4. Display Current Path\n";

    do{
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                cin >> foldername;
                n.navigate(foldername);
                break;
            case 2:
                n.goback();
                break;
            case 3:
                n.goforward();
                break;
            case 4:
                n.display();
                break;
            default:
                cout << "Invalid choice.\n";
            }
        cout<<"Do you want to continue (y/n): ";
        cin>>x;
    }while(x=='y' || x=='Y');

    return 0;
}