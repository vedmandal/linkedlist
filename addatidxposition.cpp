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

void addathead(int val){
    node*newnode=new node(val);
    newnode->next=head;
    head=newnode;
    s++;
    display();
}

void addattail(int val){
    node*newnode=new node(val);
    tail->next=newnode;
    tail=tail->next;
    s++;
    display();
}

void addatidx(int val,int idx){
    if(idx<0 or idx>s){
        return;
    }
    
    if(idx==0){
        addathead(val);

    }else if(idx==s-1){
        addattail(val);
    }else{
        node*newnode=new node(val);
        node*curr=head;
        for(int i=0;i<idx-1;i++){
            curr=curr->next;

        }
        newnode->next=curr->next;
        curr->next=newnode;
        s++;
        display();

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
   // a.addathead(9);
  // a.addattail(6);
  //a.addatidx(7,3);

    
   
}