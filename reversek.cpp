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

int length(node*head){
    int l=0;
    node*curr=curr->next;
    while(curr!=NULL){
        l++;
        curr=curr->next;
    }
    return l;
}
node*th=NULL;
node*tt=NULL;
void addfirst(node*temp){
    if(th==NULL){
        th=temp;
        tt=temp;
    }else{
        temp->next=th;
        th=temp;
    }

}

void reverse_in_k_groups(int k,int size){

if(head==NULL or head->next==NULL or k==0){
    return ;
}

int len=size;

node*curr=head;
node*oh=NULL;
node*ot=NULL;
  while(len>=k){
    int tempk=k;
    while(tempk-->0){
        node*forw=curr->next;
        curr->next=NULL;
        addfirst(curr);
        curr=forw;
    }
    if(oh==NULL){
        oh=th;
        ot=tt;
    }else{
        ot->next=th;
        ot=tt;
    }
    th=NULL;
    tt=NULL;
    len-=k;

  }
  ot->next=curr;
 
  display(oh);

}

void display(node*head){
    node*curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
    a.reverse_in_k_groups(2,5);
}



