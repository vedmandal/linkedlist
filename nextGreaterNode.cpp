#include<iostream>
#include<vector>
#include<stack>

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
 vector<int> nextLargerNodes(node* head) {
        vector<int> ans;
    stack<int> stack;

    for (; head; head = head->next) {
      while (!stack.empty() && head->val > ans[stack.top()]) {
        int index = stack.top();
        stack.pop();
        ans[index] = head->val;
      }
      stack.push(ans.size());
      ans.push_back(head->val);
    }

    for (; !stack.empty(); stack.pop())
      ans[stack.top()] = 0;

    return ans;
        
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



