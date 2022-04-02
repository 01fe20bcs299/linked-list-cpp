#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
void append(struct node *&head)
{
    node *temp=new node;
    cout<<"enter data to insert"<<endl;
    cin>>temp->data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
};
void print(struct node *&head)
{
node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
void insert1(node *&head)
{
    node *temp=new node;
    cout<<"enter data to insert"<<endl;
    cin>>temp->data;
    temp->next=head;
    head=temp;

}
void insert2(node *&head,int pos)
{
    node *temp=new node;
    node *ptr=head;
    cout<<"enter data to insert"<<endl;
    cin>>temp->data;
    temp->next=NULL;
    node *curr=NULL;
    for(int i=0;i<pos;i++)
    {
        curr=ptr;
        ptr=ptr->next;
    }
    curr->next=temp;
    temp->next=ptr;
}
void delete1(node *&head)
{
    node *temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
void delete2(node *&head,int pos)
{
    node *temp=head;
    node *curr=NULL;
    for(int i=0;i<pos;i++)
    {
        curr=temp;
        temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=NULL;
    delete temp;

}
void delete3(node *&head)
{
    node *ptr=head;
    node *curr=NULL;
     while(ptr->next!=NULL)
        {
            curr=ptr;
            ptr=ptr->next;
        }
        curr->next=NULL;
        delete ptr;

}
void rever(node *&head)
{
    node *prev=NULL;
    node *curr=head;
    node *post=NULL;
    while(curr!=NULL)
    {
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
    }
    head=prev;

}
void returnmid(node *&head)
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
void endk(node *&head,int pos)
{
    node *ptr=head;
    int countt=0;
    while(ptr!=NULL)
    {
        countt++;
        ptr=ptr->next;
    }
    int l=countt-pos;
    node *curr=head;
    for(int i=1;i<=l;i++)
    {
        curr=curr->next;
    }
    cout<<curr->data<<endl;
}
void reversek(node *&head,int k)
{
    node *prev=NULL;
    node *curr=head;
    node *post=NULL;
    for(int i=0;i<k;i++)
    {
        while(curr!=NULL)
        {
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
        }
        head=prev;
    }

}
void mergesortll(node *&head1,node *&head2,node *&head3)
{
    node *curr1=head1;
    node *curr2=head2;
   node *curr=new node;
    while(curr1!=NULL&&curr2!=NULL)
    {
        if(curr1->data>curr2->data&&head3==NULL)
        {
            curr->data=curr2->data;
            curr->next=NULL;
            curr2=curr2->next;
            head3=curr;

        }
        if(curr1->data<curr2->data&&head3==NULL)
        {
             curr->data=curr1->data;
            curr->next=NULL;
            curr1=curr1->next;
            head3=curr;
        }
        if(curr1->data>curr2->data)
        {
            node *temp=new node;
            temp->data=curr2->data;
            temp->next=NULL;
            node *ptr=head3;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            curr2=curr2->next;
        }
         if(curr1->data<curr2->data)
        {
            node *temp=new node;
            temp->data=curr1->data;
            temp->next=NULL;
            node *ptr=head3;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            curr1=curr1->next;
        }



    }
    while(curr1!=NULL)
    {
        node *temp=new node;
            temp->data=curr1->data;
            temp->next=NULL;
            node *ptr=head3;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
             ptr->next=temp;
            curr1=curr1->next;
    }
    while(curr2!=NULL)
    {
        node *temp=new node;
            temp->data=curr2->data;
            temp->next=NULL;
            node *ptr=head3;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
             ptr->next=temp;
            curr2=curr2->next;
    }
    }
int main()
{
    node *head1=NULL;
    append(head1);
    append(head1);
    append(head1);
    append(head1);
    append(head1);
    append(head1);
    node *head2=NULL;
    append(head2);
    append(head2);
    append(head2);
    node *head3=NULL;
    mergesortll(head1,head2,head3);
    print(head3);
   // reversek(head,2);

    //returnmid(head);
    //endk(head,2);

}
