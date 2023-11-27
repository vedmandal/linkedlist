

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


node*mergetwoLinkedlist(node*head1,node*head2){
    node*dummy=new node(-1);
    node*itr=dummy;
    node*c1=head1;
    node*c2=head2;
    while(c1!=NULL and c2!=NULL){
        if(c1->val<c2->val){
            itr->next=c1;
            c1=c1->next;
        }else{
            itr->next=c2;
            c2=c2->next;
        }
        itr=itr->next;
    }
    itr->next=c1!=NULL?c1:c2;
    return dummy->next;
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




