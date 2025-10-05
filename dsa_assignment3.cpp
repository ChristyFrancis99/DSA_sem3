#include<iostream>
using namespace std;

void merge(int a[], int m, int l, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    int i, j, k;
    
    for(i=0; i<n1; i++){
        left[i]=a[l+i];
    }
    for(j=0; j<n2; j++){
        right[j]=a[m+1+j];
    }
    i=0; j=0; k=l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        } k++;
    }
    while(i<n1){
        a[k]=left[i];
        i++;k++;
    }
    while(j<n2){
        a[k]=right[j];
        j++;k++;
    }
}

void mergesort(int a[], int l, int r){
    if(l<r){
        int m = (l + (r))/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, m, l, r);
    }
}

int main() {
    int n, i;
    cout<<"No of plane tickets: ";
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cout<<"Enter plane ticket "<<i+1<<": ";
        cin>>a[i];
    }
    int l=0, r=n-1;

    cout<<"Unsorted plane tickets: ";
    for(i=0; i<n; i++){
        cout<<endl<<a[i];
    }
    cout<<endl;

    mergesort(a, l, r);

    cout<<"Sorted plane tickets low to high: ";
    for(i=0; i<n; i++){
        cout<<endl<<a[i];
    }
    cout<<endl;
    return 0;
}