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

node* middleoflinkedlist(){
    node*s=head;
    node*f=head;
    while(f->next!=NULL and f->next->next!=NULL){
        s=s->next;
        f=f->next->next;
    }
    return s;
}

node* reverselinkedlist(node*head){
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

bool palindrome(){
    node*mid=middleoflinkedlist();
    node*shead=mid->next;
    mid->next=NULL;
    shead=reverselinkedlist(shead);
    node*c1=head;
    node*c2=shead;
    bool res=true;
    while(c1!=NULL and c2!=NULL){
        if(c1->val!=c2->val){
            res=false;
            break;
        }
        c1=c1->next;
        c2=c2->next;
    }
    return res;
    

}

};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(3);
    a.addlast(2);
    a.addlast(1);
    cout<<a.palindrome();
}



