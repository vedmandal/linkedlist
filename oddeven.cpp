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

node*separateoddeven(){
    node*odddummy=new node(-1);
    node*odditr=odddummy;
    node*evendummy=new node(-1);
    node*evenitr=evendummy;
    node*curr=head;
    while(curr!=NULL){
        if(curr->val%2==0){
            odditr->next=curr;
            odditr=odditr->next;
        }else{
            evenitr->next=curr;
            evenitr=evenitr->next;
        }
        curr=curr->next;
    }
    evenitr->next=odddummy->next;
    odditr->next=NULL;
    return evendummy->next;
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
    a.separateoddeven();
    a.display();
}



