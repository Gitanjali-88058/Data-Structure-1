#include<iostream>
using namespace std;

class symmetric{
    int * arr;
    int len;
    public:
         symmetric(int n){
             len=n;
             if(n!=0){
                 arr=new int[n*(n+1)/2];
             }
             else{
                arr=0;
             }
         }
         ~symmetric()
         {
             delete[] arr;
         }
         void store(int val,int i,int j){
             int k=0;
             if(i<1 || i>len || j<1 || j>len){
                 cout<<"Out of Bound"<<endl;
             }
             if(i<j){
                 return;

             }
             k=i*(i-1)/2+j-1;
             
             arr[k]=val;
         }
         int retrieve(int i,int j){
             if(i<1 || j<1 || j>len || i>len){
                 cout<<"Out of Bound"<<endl;
                 exit(0);
             }
             if(i<j){
                 int temp=i;
                 i=j;
                 j=temp;
             }
             return (arr[i*(i-1)/2+j-1]);

         }
         void display(){
             for(int i=1;i<=len;i++){
                 for(int j=1;j<=len;j++){
                     if(i<j){
                         cout<<arr[j*(j-1)/2+i-1]<<" ";
                     }
                     else{
                         cout<<arr[i*(i-1)/2+j-1]<<" ";
                     }
                     
                 }
                 cout<<"\n";
             }

         }
         
};
int main(){
    int m=0,n=0,val=0,i=0,j=0;
    cout<<"Enter the number of rows and columns int the symmetric matrix:  ";
    cin>>m>>n;
    if(m!=n){
        cout<<"Invalid size entered";
        exit(0);
    }
    symmetric a1(m);
    cout<<"\n Enter  the lower triangle matrix-\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"Enter the value:";
            cin>>val;
            a1.store(val,i,j);
        }

    }
   cout<<"\nSymmetric matrix is: "<<endl;
   a1.display();
   cout<<"\n Enter the loation for retrieval \n";
   cin>>i>>j;
   cout<<"\n Retrieved value is: "<<a1.retrieve(i,j);

}