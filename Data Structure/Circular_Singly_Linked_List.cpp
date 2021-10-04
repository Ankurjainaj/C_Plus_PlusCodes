#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node *next;
};
Node *head=NULL;

void insert_beginning()  
{  
    Node *ptr=new Node();   
    int item;
    if(ptr==NULL)  
    {  
        cout<<"\nOVERFLOW"<<endl;  
    }  
    else   
    {  
        cout<<"\nEnter the element: ";  
        cin>>item;  
        ptr->data=item;  
        if(head==NULL)  
        {  
            head=ptr;  
            ptr->next=head;  
        }  
        else   
        {     
            Node *temp=head;  
            while(temp->next!=head)  
                temp=temp->next;  
            ptr->next=head;   
            temp->next=ptr;   
            head=ptr;  
        }   
        cout<<"\nnode inserted at beginning!!!"<<endl;  
    }          
}

void insert_last()  
{  
    Node *ptr=new Node();   
    int item;  
    if(ptr==NULL)  
    {  
        cout<<"\nOVERFLOW"<<endl;  
    }  
    else  
    {  
        cout<<"\nEnter the element: ";  
        cin>>item;  
        ptr->data=item;  
        if(head==NULL)  
        {  
            head=ptr;  
            ptr->next=head;    
        }  
        else  
        {  
            Node *temp=head;  
            while(temp->next!=head)  
            {  
                temp=temp->next;  
            }  
            temp->next=ptr;   
            ptr->next=head;  
        } 
        cout<<"\nnode inserted at last"<<endl;  
    } 
}

void delete_beginning()  
{   
    if(head==NULL)  
    {  
        cout<<"\nUNDERFLOW"<<endl;    
    }  
    else if(head->next==head)  
    {  
        head=NULL;  
        free(head);  
        cout<<"\nnode deleted from beginning!!!"<<endl;  
    }  
    else  
    {   
        Node *temp=head;   
        while(temp->next!=head)  
            temp=temp->next;   
        temp->next=head->next;  
        free(head);  
        head=temp->next;  
        cout<<"\nnode deleted from beginning!!!"<<endl; 
    }  
}

void delete_end()  
{  
    Node *ptr,*temp;  
    if(head==NULL)  
    {  
        cout<<"\nUNDERFLOW"<<endl;  
    }  
    else if (head->next==head)  
    {  
        head=NULL;  
        free(head);  
        cout<<"\nnode deleted from end!!!"<<endl;  
    }  
    else   
    {  
        temp=head;  
        while(temp->next!=head)  
        {  
            ptr=temp;  
            temp=temp->next;  
        }  
        ptr->next=temp->next;  
        free(temp);  
        cout<<"\nnode deleted from end!!!"<<endl;
    }  
}

void search()  
{  
    int n,position=1;
    cout<<"Enter the element to be searched: ";
    cin>>n;
    if(head==NULL)
    {
        cout<<"\nList is empty!!!"<<endl;
        return;
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            cout<<endl<<n<<" is found at position "<<position<<endl;
            return;
        }
        temp=temp->next;
        position++;
    }
    cout<<"\nelement not found!!!"<<endl;
}  

void display()  
{  
    Node *temp=head;  
    if(head==NULL)  
    {  
        cout<<"\nList is empty!!!"<<endl; 
    }     
    else  
    {  
        cout<<"\nList is: ";  
        while(temp->next!=head)  
        {  
            cout<<temp->data<<" ";  
            temp=temp->next;  
        }  
        cout<<temp->data<<endl;
    }          
}  

int main()  
{  
    insert_beginning();      
    insert_last();         
    delete_beginning();       
    delete_end();        
    search();         
    display();        
    return 0;
}  
