#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n :";
    cin>>n;
    int arr[n][n];
    cout<<endl<<"Enter the elements of "<<n<<"X"<<n<<" matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        int j=0;
        int k=(n-1);
        while(j<k){
            int temp=arr[i][k];
            arr[i][k]=arr[i][j];
            arr[i][j]=temp;
            j++;
            k--;
        }
    }
    cout<<endl<<"THE 90 DEGREE CLOCKWISE ROTATION OF THE GIVEN MATRIX IS : "<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}