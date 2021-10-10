#include<bits/stdc++.h>
using namespace std;
#define n 20
stack<int> st1;
stack<int> st2;

class Queue{
    int* arr;
    int front;
    int back;
    public:
    Queue(){
    arr=new int[n];
    front=-1;
    back=-1;
    }
     void pushcostly(int);
     void pop();
     void push(int);
     void popcostly();
     void display1();
     void display2();


};
void Queue::push(int x){
        if(st1.size()>=n-1){
        cout<<"Queue is full.\n";
        return;
        }
        st1.push(x);
  
}
void Queue:: popcostly(){
        if(st1.empty() and st2.empty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }   
             
            int ele;
            ele=st2.top();
            st2.pop();
            cout<<"-->>"<<ele<<" is removed."<<endl;
            

}
void  Queue::display1(){
        cout<<"-->>";
        stack <int> temp=st2;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
}


    
void Queue::pushcostly(int x){
        if(st1.empty() and st2.empty()){
            st1.push(x);
            return;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
                st2.pop();
            
        }

}
void Queue:: pop(){
       if(st1.empty()){
           cout<<"Queue is empty\n";
           return;
       }
       int ele;
            ele=st1.top();
            st1.pop();
            cout<<"-->>"<<ele<<" is removed."<<endl;
       
}




void Queue:: display2(){
    cout<<"-->>";
    stack<int> temp=st1;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
        
    }
    cout<<endl;
}

int main(){
    Queue q;
    int choice,val,ch;
    do{
        cout<<"Menu-- "<<endl;
        cout<<"0-To exit."<<endl;
        cout<<"1- Implement by making push operation costly."<<endl;
        cout<<"2- Implement by making pop operation costly."<<endl;
        
        cout<<"Enter the choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                break;
            case 1:
                cout<<"1- Push the element into the queue.\n";
                cout<<"2- Pop the element from the queue.\n";
                cout<<"3- Display the queue.\n";
                do{
                cout<<"Enter the choice:";
                cin>>ch;
                switch(ch){
                    case 0:
                         break;
                    case 1:
                         cout<<"Enter the element to be pushed: ";
                         cin>>val;
                         q.pushcostly(val);
                         break;
                    case 2:
                         q.pop();
                         break;               
                    case 3:
                         q.display2();
                         break;
                    default:
                          cout<<"Invalid choice."<<endl;  break;       
                }
                }while(ch!=0);
            break;    
            case 2:
                     cout<<"1- Push the element into the queue.\n";
                     cout<<"2- Pop the element from the queue.\n";
                     cout<<"3- Display the queue.\n";
                     
                     
                    do{ 
                    cout<<"Enter the choice:";
                    cin>>ch;    
                    switch(ch){
                    case 0:
                         break;
                    case 1:
                         cout<<"Enter the element to be pushed: ";
                         cin>>val;
                         q.push(val);
                         break;
                    case 2:
                         q.popcostly();
                         break; 
                    case 3:
                        q.display1();
                        break;      
     
                    default:
                          cout<<"Invalid Choice!"<<endl;
                          break;                   
                        
                    }
                    }while(ch!=0);
            break;
            default:
                   cout<<"Invalid choice."<<endl;
                   break;      

        }

    }while(choice!=0);

}