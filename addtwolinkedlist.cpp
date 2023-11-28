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


node* reverselinkedlist(node*&head){
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


node*addtwolinkedlist(node*head1,node*head2){
    node*dummy=new node(-1);
    node*itr=dummy;
    node*c1=reverselinkedlist(head1);
    node*c2=reverselinkedlist(head2);
    int carry;
    while(c1!=NULL or c2!=NULL or carry!=0 ){
        int sum=carry+(c1!=NULL?c1->val:0)+(c2!=NULL?c2->val:0);
        int lastdigit=sum%10;
        carry=sum/10;
        node *temp=new node(lastdigit);
        itr->next=temp;
        itr=itr->next;
        if(c1!=NULL) c1=c1->next;
        if(c2!=NULL) c2=c2->next;
    }

    return reverselinkedlist(dummy->next);


}

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
    a.display();
}



