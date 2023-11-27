#include<iostream>

using namespace std;

class node{
    public:
    int val;
    node*next;
    node(int val){
        this->val=val;
       this->next=NULL;
    }
};
class linkedlist{

node*head;
node*tail;
int s;
public:
linkedlist(){
    head=NULL;
    tail=NULL;
    s=0;
}

void addlast(int val){
    node*temp=new node(val);
    if(s==0){
        head=temp;
        tail=temp;
    }else{
        tail->next=temp;
        tail=tail->next;

    }
    s++;
}
void display(){
    node*curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}

node* middleoflinkedlist(){
    node*s=head;
    node*f=head;
    while(f->next!=NULL and f->next->next!=NULL){
        s=s->next;
        f=f->next->next;
    }
    return s;
}


node* reverselinkedlist(node*head){
    node*prev=NULL;
    node*curr=head;
    node*forw=NULL;
    while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
   return prev;


}
void fold(){
    node*mid=middleoflinkedlist();
    node*shead=mid->next;
    mid->next=NULL;
    shead=reverselinkedlist(shead);
    node*f1=NULL;
    node*f2=NULL;
    node*c1=head;
    node*c2=shead;
    while(c1!=NULL and c2!=NULL){
        f1=c1->next;
        f2=c2->next;
        c1->next=c2;
        c2->next=f1;
        c1=f1;
        c2=f2;

    }
    display();

}

void unfold(){
    node*fhead=head;
    node*shead=head->next;
    node*curr=fhead;
    node*curr2=shead;
    node*forw;
    while(curr2!=NULL and curr2->next!=NULL){
        forw=curr2->next;
        curr->next=forw;
        curr2->next=forw->next;
        curr=curr->next;
        curr2=curr2->next;
        
    }
    curr->next=NULL;
    shead=reverselinkedlist(shead);
    curr->next=shead;
    display();

    

}

    

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
     a.addlast(6);
      a.fold();
   cout<<"after unfold"<<endl;
   a.unfold();
}



