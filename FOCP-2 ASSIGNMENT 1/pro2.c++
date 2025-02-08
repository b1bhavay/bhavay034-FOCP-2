#include <iostream>
using namespace std;
int main() {
    int m,n;
    int arr[m][n];

     cin>>m;
     cin>>n;
cout<<"matrix is of size:"<<m<<"X"<< n ;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int arr[20];
 for(int i=0;i<=9;i++){       
     cin>>arr[i];
   }
 for(int i=9;i>=0;i--){  

cout<<arr[i]<<endl;
}
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
  int size=0;
    int a[10];

    for(int i=0; i<10;i++) {
    cin>>a[i];
    size++;
    }
      
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<10; j++) { 
        if(a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
   
 
      cout<<" second largest element "<<a[size-2]<<endl;
       cout<<" second smallest element "<<a[1]<<" ";
   return 0;
}