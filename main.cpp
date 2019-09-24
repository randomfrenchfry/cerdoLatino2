#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* next;
};

class list {
public:
    Node* head = NULL;
    Node* tail = NULL;
    void create(char c);
    void display();
};

void list::create(char c){
    Node* p = new Node;
    p->data = c;
    p->next = NULL;
    if(head==NULL){ //First Node
        head = p;
        tail = p;
        p = nullptr;
    }
    else{   //So on nude
        tail->next = p;
        tail = p;
    }
}

void list::display(){
    Node* p = head;
    while(p!= nullptr){
        cout << p->data;
        p=p->next;
    }
}

bool isVowel(char c){
    char Array[12] = {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    for(int i = 0;i<12;i++){
        if(c == Array[i])
            return true;
    }   return false;
}

int main() {
    string word ="";
    char c = ' ';
    list list1;
    cout << "Enter Word: " << endl;
    cin >> word;
    for(int i=0; i < word.length();i++){
        list1.create(word[i]);
    }
    //cout << "madeit";
    //list1.create('-');
    if(isVowel(list1.head->data)){
        list1.create('-');
        list1.create('w');
        list1.create('a');
        list1.create('y');
        list1.display();
        return 1;
    }
    list1.create('-');
    while(!isVowel(list1.head->data)){




        if(list1.head->data == '-'){
            list1.tail->next = list1.head;
            list1.tail = list1.head;
            list1.head = list1.head->next;
            list1.tail->next = nullptr;
            list1.create('w');
            list1.create('a');
            list1.create('y');
            list1.display();
            return 1;
        }else {
                list1.tail->next = list1.head;
                list1.tail = list1.head;
                list1.head = list1.head->next;
                list1.tail->next = nullptr;
        }
    }
    list1.create('a');
    list1.create('y');
    list1.display();
}