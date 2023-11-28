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
node* iscyclepresent(){
    node*s=head;
    node*f=head;
    while(f!=NULL and f->next!=NULL){
        f=f->next->next;
        s=s->next;
        if(s==f){
             break;
        }
    }

    s=head;
    while(s!=f){
        s=s->next;
        f=f->next;
    }
    return s;
    

}

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
   cout<< a.iscyclepresent();
}



