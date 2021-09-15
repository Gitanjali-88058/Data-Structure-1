#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        
        
    }
    else{
    int topele=st.top();
    
    st.pop();

    insertAtBottom(st,ele);
    
    st.push(topele);
    }
    

}
void ReverseStack(stack<int> &st)
{
    if(!st.empty()){
        
    int ele=st.top();
    st.pop();
    
    ReverseStack(st);
    
    insertAtBottom(st,ele);
      
    }
    
   
}

int main(){
    
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    ReverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();

    }cout<<endl;
}
    

