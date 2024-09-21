#include<bits/stdc++.h>
using namespace std;

// void insert(int arr[], int x, int* siz){
//     if(*siz==-1) *siz = 0;
//     arr[*siz]  = x;
//     *siz += 1;
// }

// void remove(int arr[], int place, int* siz){
//     for(int i=place; i<*siz; i++){
//         arr[i] = arr[i+1];
//     }
//     *siz -= 1; 
// }

void remove(vector<int> arr, int place, int* rem){ // Not working as expected
    *rem += 1;
    cout<<"Removed element = "<<arr[place]<<endl;
    for(int i=place; i<arr.size()-*rem; i++){
        arr.insert(arr.begin()+i, arr[i+1]);
    }
    arr.pop_back();
    cout<<"Length after popping back = "<<arr.size()<<endl;
}

int main(){
    // Simple array implementation of a list
    // int arr[1000];
    // int siz = -1; 
    // insert(arr, 2, &siz);
    // insert(arr, 4, &siz);
    // insert(arr, 6, &siz);
    // insert(arr, 8, &siz);
    // remove(arr, 2, &siz);
    // remove(arr, 1, &siz);
    // for(int i=0; i<siz; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"Length = "<<siz<<endl;

    // Dynamic array implementation of a list
    vector<int> arr;
    int rem = 0;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    remove(arr, 1, &rem);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Length after last operation = "<<arr.size()-rem<<endl;
}
