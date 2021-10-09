#include<iostream>
using namespace std;

#define n 50
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;

    }
    void push(int);
    void pop();
    int getfront();
    bool isempty();
    bool isfull();
    void display();
};
bool queue:: isfull(){
    if(front==0 && back==n-1 || front==back+1){
        return true;
    }
    return false;
}
void queue::push(int x){
    if(isfull()){
        cout<<"Queue is Overflowed.\n";
    }
    else{    
        if(back==n-1 || back==-1 ){
            arr[0]=x;
            back=0;
            if(front==-1){
                
                front=0;
            }
        }
        else{    
            back++;
            arr[back]=x;
        }
    }
    
  
}
void queue::pop(){
        if(front==-1 and back==-1){
            cout<<"Queue is empty.\n";
            return;
        }
    
        if(front==back){
            front=-1;
            back=-1;
        }
        else if(back==n-1){
            front=0;

        }
        else{
            front++;
        }
    
}

int queue:: getfront(){
    if(front==-1 and back==-1){
            
            return -1;
    }
    return arr[front];
}

bool queue:: isempty(){
    if(front==-1 and back==-1){
        return true;
    }
    return false;
}
void queue::display(){
    for(int i=front;i<=back;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    queue q;
    int choice,val;
    do
    {
    cout<<"Menu: "<<endl;
    cout<<"0. To exit"<<endl;
    cout<<"1. To add an element to the queue."<<endl;
    cout<<"2. To remove an element to the queue."<<endl;
    cout<<"3. To get the top element from the queue."<<endl;
    cout<<"4. To check if the queue is empty."<<endl;
    cout<<"5. To display the queue."<<endl;
    
    
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 0:
           break;
        case 1:
           cout<<"Enter the element to push:";
           cin>>val;
           q.push(val);
        break;   
        case 2:
             int rem;
             rem=q.getfront();
             q.pop();
             cout<<"-->> "<<rem<<" get rmeoved."<<endl;
             
             
        break;     
        case 3:
            int topele;
            topele=q.getfront();
            cout<<"-->> "<<topele<<" is the top element."<<endl;
            break;

        case 4:
            bool flag; 
            flag=q.isempty(); 
            if(flag==1){
                cout<<"-->> Queue is empty."<<endl;
            }    
            else{
                cout<<"-->> Queue is not empty."<<endl;
            } 
        break;

        case 5:
             cout<<"-->> ";
             q.display();
        break;

             
    }        
    }while(choice!=0);
    
}

