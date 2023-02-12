#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int arrSize;
    int top;
    public:
    Stack(int size);
    bool Push(int item);
    bool Pop(int& item);
    bool Peek(int& item)const;
    void Print()const;
    bool isFull();
    bool isEmpty();
};

Stack :: Stack(int size):top(-1),arrSize(size){
    arr = new int[arrSize];
}

bool Stack::Push(int  item){
    bool success = false;
    if(!isFull()){
        arr[++top] = item;
        success = true; 
    }
    return success;
}

bool Stack::Pop(int& item){
    bool success = false;
    if(!isEmpty()){
        item = arr[top--];
        success = true;
    }
    return success;
}

bool Stack:: Peek(int &item)const{
    bool success = false; 
    if(top!= -1){
        item = arr[top];
        success = true;
    }
    return success;
}

void Stack::Print()const{
    for(int i = 0 ;  i <= top ; i++){
        cout<<arr[i]<<"_";
    }
    cout<<endl;
}

bool Stack:: isFull(){
    return (top == arrSize-1);
}

bool Stack:: isEmpty(){
    return (top == -1);
}

int main()
{
    int x;
    int element;
    cout<<"Enter the size of stack ";
    cin>>x;
    Stack s1(x);

    for(int i = 0; i < x ; i++){
        cout<<"Enter the element you want to add in stack: ";
        cin>>element;
        s1.Push(element);
        s1.Print();

    }
    cout<<endl;
    int e;
    s1.Pop(e);
    s1.Print();
    return 0;
}