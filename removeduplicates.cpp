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

void removeduplicates(){
    node*dummy=new node(-1);
    node* itr=dummy;
    node*curr=head;
    if(curr==NULL){
        return ;
    }
    if(curr->next==NULL){
        return ;
    }
    itr->next=curr;
    itr=itr->next;
    curr=curr->next;
    while(curr!=NULL){
        if(itr->val!=curr->val){
            itr->next=curr;
           itr=itr->next;
            
        }
        curr=curr->next;

    }
    itr->next=NULL;
    head=dummy->next;
    display();

}

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(2);
    a.addlast(4);
    a.addlast(4);
   a.removeduplicates();
}



