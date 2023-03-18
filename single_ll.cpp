#include <iostream>
using namespace std;

struct node
{

    int data;
    struct node *next;
} *head = NULL, *last = NULL;

struct node *createNode(int n)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = n;
    tmp->next = NULL;
    return tmp;
}
void insert_at_last(int data)
{

    struct node *tmp;
    if (head == NULL)
    {
        head = createNode(data);
        last = head;
    }
    else
    {
        tmp = createNode(data);
        last->next = tmp;
        last = tmp;
    }
}

void display()
{
    struct node *tmp;

    if (head == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
}

void delete_at_last()
{
    struct node *tmp = head;
    if (head == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {

        while (tmp->next != last)
        {
            tmp = tmp->next;
        }

        tmp->next = NULL;
        cout << last->data << " deleted...." << endl;
        free(last);
        last = tmp;
    }
}

void insert_at_beg(int data)
{
    struct node *tmp;
    tmp=createNode(data);
    if(head==NULL)
    {
        head=tmp;
        last=head;
    }else{
        tmp->next=head;
        head=tmp; 
    }
     

}

void delete_at_beg()
{

    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    struct node* tmp;
    tmp=head;
    cout<<head->data<<" deleted"<<endl;
    head=head->next;
    free(tmp);
}

int main()
{
    while (1)
    {
        cout << endl
             << "---------------------------" << endl;
        cout << "0- exit" << endl;
        cout << "1- insert at last" << endl;
        cout << "2- display" << endl;
        cout << "3- Delete last" << endl;
        cout << "4 - insert front" << endl;
        cout << "5 - delete front" << endl;
        int choice;
        cout << "Enter a choice ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            int data;
            cout << "Enter data:";
            cin >> data;
            insert_at_last(data);
            break;
        case 2:
            display();
            break;
        case 3:
            delete_at_last();
            break;
        case 4:
            // int data;
            cout << "Enter data:";
            cin >> data;
            insert_at_beg(data);
            break;
        case 5:
            delete_at_beg();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}