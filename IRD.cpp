#include <iostream>
using namespace std;
#define size 5


int q[size];
int front=-1 , rear=-1;


int isEmpty()
{
    return front==-1;
}

int isFull()
{
    cout<<rear<<endl;
    return rear==size-1;
}

void enqueue(int n)
{
    if(isFull())
    {
        cout<<"Queue is full!!"<<endl;
    }else{

        if(front==-1)
        {
            front=0;
        }
        rear++;
        q[rear]=n;
       
        
    }
}

int dequeueBeg()
{
    int n;
    if(isEmpty())
    {
        cout<<"Queue is Empty!!"<<endl;
    }else{

        n=q[front];
        cout<<n<<"is poped!!"<<endl; 
        if(front==rear)
        {
            front=-1;
            rear=-1;
            return n;
        }
        front++;

    }
    return n;

}

int dequeueEnd()
{
    int n;
    if(isEmpty())
    {
        cout<<"Queue is Empty!!"<<endl;
    }else{

        n=q[rear];
        cout<<n<<"is poped!!"<<endl;
        
        if(front==rear)
        {
            front=-1;
            rear=-1;
            return n;
        }
        rear--;

    }
    return n;
}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty!!"<<endl;
    }else{
        for(int i=front;i<=rear;i++)
        {
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }

}


int main()
{
    int choice;

    while (1)
    {
        cout << "0---exit" << endl;
        cout << "1---Add" << endl;
        cout << "2---Display" << endl;
        cout << "3---delete end" << endl;
        cout << "4---delete begining" << endl;

        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            int n;
            cout << "Enter a no: ";
            cin >> n;
            enqueue(n);
            break;
        case 2:
            display();
            break;
        case 3:
            dequeueEnd();
            break;
        case 4:
            dequeueBeg();
            break;

        default:
            cout << "Invalid choice!!" << endl;
        }
    }
    return 0;
}