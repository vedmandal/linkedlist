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

    void headdata(){
        cout<<head->val;
    }

     void  taildata(){
        cout<<tail->val;
    }
    void idxdata(int idx){
        if(idx<0 or idx>=s ){
            return;
        }
        if(idx==0){
            headdata();
        }else if(idx==s-1){
            taildata();
        }else{
            node*curr=head;
            for(int i=0;i<idx;i++){
                curr=curr->next;
            }
            cout<<curr->val;
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
   a.idxdata(4);

}