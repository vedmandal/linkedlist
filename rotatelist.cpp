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

    void rotateRight( int k) {
        if(head==NULL || head->next==NULL  || k==0){
            return ;
        }

        node*curr=head;
        int length=0;
        while(curr->next){
            curr=curr->next;
            length++;

        }
        curr->next=head;
        k=k%(length+1);
        int jump=length-k;
        curr=head;
        while(jump){
            curr=curr->next;
            jump--;

        }
        node*returnhead=curr->next;
        curr->next=NULL;
        display(returnhead);
    }

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
   a.rotateRight(2);
}



