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
int length( node*&head){
    int l=0;
     ListNode*curr=head;
     while(curr!=NULL){
         curr=curr->next;
         l++;
     }
     return l;
}
    node* removeNthFromEnd(node* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
       
        int size=length(head);
        if(size==n){
            return head->next;
        }

        node*curr=head;
         for(int i=1;i<size-n;i++){
             curr=curr->next;
         }
         curr->next=curr->next->next;
         return head;
        
    }
};
int main(){
    linkedlist a;
    a.addlast(1);
    a.addlast(2);
    a.addlast(3);
    a.addlast(4);
    a.addlast(5);
    a.display();
}



