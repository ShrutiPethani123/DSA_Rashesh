#include<iostream>
using namespace std;
#define size 5

int q[size];
int front=-1;
int rear=-1;

int isFull()
{
    return rear==size-1 && front==0;
}

int isEmpty()
{
    return front==-1;
}

void addFront( int n)
{
    if(isFull())
    {
        cout<<"Queue is Full"<<endl;
    }else if(front>0)
    {
        front--;
        q[front]=n;
    }
    else{
        if(front==-1)
        {
            front=0;
        }
        for(int i=rear;i>=front;i--)
        {
            q[i+1]=q[i];
        }
        rear++;
        q[front]=n;    
        
    }

}

void addLast(int n)
{
    if(isFull())
    {
        cout<<"Queue is Full!!"<<endl;
    }else{

        if(front==-1)
        {
            front=0;
        }
        rear++;
        q[rear]=n;
    }
}

int deleteFront()
{
    int n;
    if(isEmpty())
    {
        cout<<"Queue is Empty!!"<<endl;
    }else{
        n=q[front];
        cout<<n<<"is removed"<<endl;
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

int deleteLast()
{
    int n;
    if(isEmpty())
    {
        cout<<"Queue is Empty!!"<<endl;
    }else{
        n=q[rear];
        
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
    int choice,a;

    while (1)
    {
        cout << "0---exit" << endl;
        cout << "1---Add front" << endl;
        cout << "2---Add last" << endl;
        cout << "3---Delete front" << endl;
        cout << "4---Delete last" << endl;
        cout<<"5--Display"<<endl;

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
            addFront(n);
            break;
        case 2:
            cout << "Enter a no: ";
            cin >> n;
            addLast(n);
            break;
            
        case 3:
            deleteFront();           
            break;
        case 4:
            a= deleteLast();
            cout<<a<<" is Removed"<<endl;
            break;
        case 5:
            display();
            break;

        default:
            cout << "Invalid choice!!" << endl;
        }
    }
    return 0;
}