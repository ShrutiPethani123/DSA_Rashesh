#include <iostream>
#define size 5
using namespace std;

int q[size];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    if (rear == size - 1 && front == 0)
    {
        return 1;
    }
    else if (front == rear + 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int n)
{
    if (isFull())
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        if (rear == size - 1)
        {
            rear = 0;
            q[rear] = n;
        }
        else
        {
            rear++;
            q[rear] = n;
        }
    }
}

int dequeue()
{
    int n;
    if (isEmpty())
    {
        cout << "Queue is Empty!!" << endl;
    }
    else if(front == rear)
    {
        n = q[front];
        cout << n << "is poped!!" << endl;
        rear=-1;
        front=-1;
    }
    else
    {
        n = q[front];
        if(front==size-1)
        {
            front=0;
        }else{
            
            front++;
        }
        
        cout << n << "is poped!!" << endl;      
    }
    return n;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!!" << endl;
    }
    else
    {
        if (front > rear)
        {
                for(int i=front;i<size;i++)
                {
                    cout<<q[i]<<" ";
                }
                for(int i=0;i<=rear;i++)
                {
                    cout<<q[i]<<" ";
                }
        }
        else
        {

            for (int i = front; i <= rear; i++)
            {
                cout << q[i] << " ";
            }
        }

        cout << endl;
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
        cout << "3---delete" << endl;

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
            dequeue();
            break;
        default:
            cout << "Invalid choice!!" << endl;
        }
    }
    return 0;
}