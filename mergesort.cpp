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

node*middle(node*head){
    node*s=head;
    node*f=head;
    while(f->next!=NULL and f->next->next!=NULL){
        f=f->next->next;
        s=s->next;
    }
    return s;

}
node*mergetwolist(node*list1,node*list2){
    node*c1=list1;
    node*c2=list2;
    node*dummy=new node(-1);
    node*itr=dummy;
    while(c1!=NULL and c2!=NULL){
        if(c1->val<=c2->val){
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

  node*mergesort(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node*mid=middle(head);
    node*shead=mid->next;
    mid->next=NULL;
    node*left=mergesort(head);
    node*right=mergesort(shead);
    return mergetwolist(left,right);
    
  }
  void mergesortlist(){
   
    node*temp=mergesort(head);
    display(temp);
  }

};
int main(){
    linkedlist a;
    a.addlast(5);
    a.addlast(9);
    a.addlast(1);
    a.addlast(2);
    a.addlast(6);
    a.mergesortlist();
}



