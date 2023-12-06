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
void display(node*head){
    node*curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}
void partition( int x) {
         node*gtedummy=new  node(-1);
          node*gteitr=gtedummy;
           node*ltdummy=new  node(-1);
            node*ltitr=ltdummy;
             node*curr=head;
             while(curr!=NULL){
                 if(curr->val<x){
                     ltitr->next=curr;
                     ltitr=ltitr->next;
                 }else{
                     gteitr->next=curr;
                     gteitr=gteitr->next;
                 }
                 curr=curr->next;
             }
             ltitr->next=gtedummy->next;
             gteitr->next=NULL;
             display(ltdummy->next);
        
    }

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
     a.addlast(5);
     a.addlast(2);
     a.addlast(5);
     a.addlast(1);
     a.addlast(3);
    a.addlast(4);
    a.partition(3);
   
   
}



