#include<iostream>
using namespace std;

#define size 100
class Stack{
    int* arr;
    int top;
    public:
    Stack(){
        arr=new int[size];
        top=-1;
    }
    int push(int);
    int pop();
    int getTop();
    void isEmpty();
    void toClear();
    void getSize();
    void display();

};

int Stack :: push(int n){
    if(top==size-1){
        cout<<"Stack overflowed."<<endl;
        return 0;
    }
    top++;
    arr[top]=n;
    return n;
}
int Stack :: pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    int temp;
    temp=arr[top];
    --top;
    return temp;
}

int Stack :: getTop(){
    if(top==-1){
        return -1;
    }
    return arr[top];
}

void Stack :: isEmpty(){
    if(top==-1){
        cout<<"Stack is Empty."<<endl;

    }
    else{
    cout<<"Stack is not Empty."<<endl;
    }
}

void Stack :: toClear(){
    for(int i=top;i>=0;i--){
        pop();
    }
    
}

void Stack :: display(){
    cout<<"Stack is  ";
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void Stack :: getSize(){
     cout<<"Size of the stack: "<<top+1<<endl;
}

int main(){
   //declare object
    Stack st;
    int choice, n,temp;
     
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push an element to the stack."<<endl;
        cout<<"2 - Pop an element from the stack."<<endl;
        cout<<"3 - Display the stack. "<<endl;
        cout<<"4 - To return the top element."<<endl;
        cout<<"5 - To check if stack is empty."<<endl;
        cout<<"6 - To get the size of the stack."<<endl;
        cout<<"7 - To clear the stack."<<endl;
        

        cout<<"---------------------------------"<<endl; 
        cout<<"Enter your choice: ";
        cin>>choice; 
        cout<<"---------------------------------"<<endl;

        switch(choice){
            case 0: break;
            case 1:
            
                cout<<"\nEnter the element to push: ";
                cin>>n;
                st.push(n);
                cout<<"-----------------------------"<<endl;
            break;

            case 2:
                temp=st.pop();
                cout<<"\n"<<temp<<" is removed"<<endl;
                cout<<"-----------------------------"<<endl;
            break;
            case 3:
             
                 st.display();
                 cout<<"-----------------------------"<<endl;

            break;
            case 4:
                 cout<<"\nElement at the top of the stack: ";
                 cout<<st.getTop();
                 cout<<endl;
                 cout<<"-----------------------------"<<endl;
                 
            break;
            case 5:
                st.isEmpty();
                cout<<endl;
                cout<<"-----------------------------"<<endl;
                 
            break;
            case 6:
                st.getSize();
                cout<<"-------------------------------"<<endl;
            case 7:
                  st.toClear();
                  
            break;      

            default:
                 cout<<"An invalid choice."<<endl;  
            
        }
    }while(choice!=0);

}