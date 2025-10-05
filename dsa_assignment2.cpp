#include<iostream>
#include<string>
using namespace std;

class market{
    public:
    float price; 
    string pro;

    void getdata(){
        cout<<"Enter product name: ";
        cin>>pro;
        cout<<"Enter product price of "<<pro<<": ";
        cin>>price;
    }

    void setdata(){
        cout<<pro<<"\t"<<price<<endl;
    }
};

void quicksort(int f, int l, market a[]){
    if(f < l){
        int i = f, j = l;
        market pvt = a[f];
        while(i < j){
            while(i <= l && a[i].price <= pvt.price) i++;
            while(a[j].price > pvt.price) j--;

            if(i < j) {
                swap(a[i], a[j]);
            }
        }
        swap(a[f], a[j]);

        quicksort(f, j-1, a);
        quicksort(j+1, l, a);
    }
}

int main(){
    int n;
    cout<<"Enter no of products: ";
    cin>>n;
    market a[n];
    for(int i=0; i<n; i++){
        a[i].getdata();
    }

    quicksort(0, n-1, a);

    cout<<"\nSorted products by price low to high:\n";
    for(int i=0; i<n; i++){
        a[i].setdata();
    }

    cout<<"\nSorted products by price high to low:\n";
    for(int i=n-1; i>=0; i--){
        a[i].setdata();
    }

    return 0;
}