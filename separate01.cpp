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

node* separate01(){
    node*zerodummy=new node(-1);
    node*zeroitr=zerodummy;
    node*onedummy=new node(-1);
    node*oneitr=onedummy;
    node*curr=head;
    while(curr!=NULL){
        if(curr->val==1){
            oneitr->next=curr;
            oneitr=oneitr->next;
        }else{
            zeroitr->next=curr;
            zeroitr=zeroitr->next;
        }
        curr=curr->next;
    }
    oneitr->next=NULL;
    zeroitr->next=onedummy->next;
    return  zerodummy->next;
   


}


};
int main(){
    linkedlist a;
    a.addlast(0);
    a.addlast(1);
    a.addlast(0);
    a.addlast(0);
    a.addlast(1);
  node*temp= a.separate01();
   a.display(temp);
}



