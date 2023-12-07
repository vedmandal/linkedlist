#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node*random;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->random=NULL;
    }

};