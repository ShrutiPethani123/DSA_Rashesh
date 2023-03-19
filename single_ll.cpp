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

void search(int data)
{
    bool found=false;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }else{

        struct  node *tmp=head;
        while(tmp!=NULL)
        {
            if(tmp->data==data)
            {
                found=true;
                printf("found !!!!");
                break;
            }
            tmp=tmp->next;
        }

        if(found==false)
        {
            printf("Not found!!!!");
        }
        
    }

}

void insert_at_any_after(int data,int new_data ){

    bool found=false;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }else{
        struct node *tmp=head;
        struct node * newNode = createNode(new_data);

        while(tmp!=NULL)
        {
            if(tmp->data==data)
            {
                if(tmp==last)
                {
                    insert_at_last(new_data);
                    found=true;
                    break;
                }

                newNode->next=tmp->next;
                tmp->next=newNode;
                found=true;
                break;
            }
            tmp=tmp->next;
        }
        if(found==false)
        {
            cout<<"data not Found!!!"<<endl;
        }
    }
}

void insert_at_any_before(int data,int new_data)
{
    bool found=false;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }else{

        struct node *tmp=head;
        struct node * newNode=createNode(new_data);

        while(tmp!=NULL)
        {
            if(head->data==data)
            {
                insert_at_beg(new_data);
                found=true;
                break;
            }
            else if(tmp->next->data==data)
            {
                newNode->next=tmp->next;
                tmp->next=newNode;
                found = true;
                break;
            }
            tmp=tmp->next;
        }
        if(found==false)
        {
            cout<<"data not Found!!!"<<endl;
        }
    }
}


void delete_any(int data)
{
    bool found = false;
    if(head==NULL)
    {
        cout<<"list is Empty!!"<<endl;
    }else{
        struct node*tmp=head;
        struct node*p=head;

        while(tmp->next!=NULL)
        {
            if(head->data==data)
            {
                tmp=head;
                cout<<tmp->data<<" deleted"<<endl; 
                head=head->next;
                free(tmp);                
                found=true;
                break;
            }
            else if(tmp->next->data==data)
            {
                p=p->next;
                // tmp->next = tmp->next->next;
                tmp->next=p->next;
                cout<<p->data<<" deleted"<<endl;
                free(p);
                found=true;
                break;
            }
            cout<<"Data: "<<tmp->data<<endl;
            tmp=tmp->next;
            p=p->next;
        }
        if(found==false)
        {
            cout<<"data not Found!!!"<<endl;
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
        case 6:
            cout << "Enter data:";
            cin >> data;
            search(data);
            break;
        case 7:
            int new_data;
            cout << "Enter data:";
            cin >> data;
            cout << "Enter  new data:";
            cin >> new_data;
            insert_at_any_after(data,new_data);
            break;
        case 8:
            cout << "Enter data:";
            cin >> data;
            cout << "Enter  new data:";
            cin >> new_data;
            insert_at_any_before(data,new_data);
            break;
        case 9:
            cout<<"Enter data:";
            cin >> data;
            delete_any(data);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}