#include<iostream>
using namespace std;

struct node{

    int data;
    struct node *next , *prev;
}*head=NULL,*last=NULL;


struct node* createNode(int data)
{
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp-> data = data;
    tmp->next=NULL;
    tmp->prev=NULL;
    return tmp;
}

int isEmpty()
{    if(head==NULL)
        return 1;
    return 0;
}


void insert_at_last(int data)
{
    struct node*tmp;
    tmp=createNode(data);
    if(isEmpty())
    {
        head=tmp;
        last=tmp;   
    }else{

        last->next=tmp;
        tmp->prev=last;
        last=tmp;
    }
}

void display1()
{
    if(isEmpty())
    {
        cout<<"List is Empty!!!"<<endl;
    }else{
        struct node *tmp;
        tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
}

void display2()
{
    if(isEmpty())
    {
        cout<<"List is Empty!!!"<<endl;
    }else{
        struct node *tmp;
        tmp=last;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->prev;
        }
    }
}


void delete_at_last()
{
    if(isEmpty())
    {
        cout<<"List is Empty!!!"<<endl;
    }else{
        struct node*tmp;
        tmp=last;

        cout<<tmp->data<<" deleted"<<endl;
        if(tmp==head)
        {
            
            head=NULL;
            last=NULL;
            
        }else{
            
            last=last->prev;
            last->next=NULL;
            
        }
        free(tmp);
        

    }
}

void insert_at_beg(int data){

    struct node*tmp;
    tmp=createNode(data);
    if(isEmpty())
    {
        head=tmp;
        last=tmp;   
    }else{

        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }

}

void delete_at_beg()
{
    if(isEmpty())
    {
        cout<<"List is Empty!!!"<<endl;
    }else{
        struct node*tmp;
        tmp=head;
        cout<<tmp->data<<" deleted"<<endl;
        if(tmp==last)
        {
            last=NULL;
            head=NULL;
        }else{
            head=head->next;
            head->prev=NULL;
        }
        free(tmp);

    }
}

void search(int data)
{
    if(isEmpty())
    {
        cout<<"List is Empty!!"<<endl;
    }else{
        struct node *tmp;
        tmp=head;
        int flag=0;
        while(tmp!=NULL)
        {
            if(tmp->data==data)
            {
                cout<<"Found!!!"<<endl;
                flag=1;
                break;
            }
            tmp=tmp->next;
        }

        if(flag==0)
        {
            cout<<"Not Found!!"<<endl;
        }

    }
    
}

int search2(int data)
{
    if(isEmpty())
    {
        cout<<"List is Empty!!"<<endl;   
    }else{
        struct node *tmp;
        tmp=head;

        while(tmp!=NULL)
        {
            cout<<"Before: "<<tmp->data<<endl;
            if(tmp->data==data)
            {
                cout<<"Found!!!"<<endl;
                cout<<"After: "<<tmp->data<<endl;
                return 1;
            }
            
            tmp=tmp->next;
        }

    }
    return 0;
}

void insert_at_any_after(int data,int new_data){

    if(isEmpty())
    {
        cout<<"List is Empty!!"<<endl;
    }else{
        struct node *tmp;
        struct node *p=head;
        tmp=createNode(new_data);
        bool flag=false;

        while(p!=NULL)
        {
            if(search2(p->data)==1)
            {
                cout<<p->data<<endl;
                tmp->next=p->next;
                tmp->prev=p;
                p->next=tmp;
                tmp->next->prev=tmp;
                flag=true;
                break;
            }
            cout<<p->data<<endl;
            p=p->next;
        }
        if(flag==false)
        {

            cout<<"Data Not Found!!!"<<endl;
        }


    }
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
        cout<< "6 - Search"<<endl;
        cout<< "7 - Insert any After" << endl;
        cout<< "8 - Insert any Before" << endl;
        cout<< "9 - delete any" << endl;

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
            display1();
            cout<<endl;
            // display2();
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
        case 6:
            cout << "Enter data:";
            cin >> data;
            search2(data);
            break;
        case 7:
            int new_data;
            cout << "Enter data:";
            cin >> data;
            cout << "Enter  new data:";
            cin >> new_data;
            insert_at_any_after(data,new_data);
            break;
        // case 8:
        //     cout << "Enter data:";
        //     cin >> data;
        //     cout << "Enter  new data:";
        //     cin >> new_data;
        //     insert_at_any_before(data,new_data);
        //     break;
        // case 9:
        //     cout<<"Enter data:";
        //     cin >> data;
        //     delete_any(data);
        //     break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}