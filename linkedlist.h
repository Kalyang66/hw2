#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct node {
  int index; 
  string name;
  int age;
  int deposit;
  int numDrinks;
  node *next;

};
class linkedList {
private:
  node *head;
  int size; 
public:
  linkedList() { head = nullptr; size = 0;}

  void insertAtHead(string n, int a, int d, int nDrinks){
    node * tempNode = new node; 
    tempNode -> name = n;
    tempNode -> age = a;
    tempNode -> deposit = d;
    tempNode -> numDrinks = nDrinks;
    tempNode -> next = nullptr;
    if (head == nullptr){
      head = tempNode; 
      size++;
      return; 
    }
    tempNode -> next = head;
    head = tempNode; 
    size++;
    return; 
  }
  void insertAtEnd(string n, int a, int d, int nDrinks) { 
    node * tempNode = new node; 
    tempNode -> name = n;
    tempNode -> age = a;
    tempNode -> deposit = d;
    tempNode -> numDrinks = nDrinks;
    tempNode -> next = nullptr; 
    // You have an head, you want to insert at end tempNode.
    if (head == nullptr){
      head = tempNode; 
      size++; 
      return; 
    } else {
    node * cur = head; 
    while (cur-> next != nullptr){
      cur = cur-> next; 
    }
    cur -> next = tempNode; 
    size++; 
    }
  }
  void add(string n, int a, int d, int nDrinks, int index){
    if (head == nullptr || index == 0){
      insertAtHead(n, a, d, nDrinks);
      return;
      //size++;
    } else if (index >= size){
      insertAtEnd(n, a, d, nDrinks);
      return; 
      //size++;
    } else {
      node * tempNode = new node; 
      tempNode -> name = n;
      tempNode -> age = a;
      tempNode -> deposit = d;
      tempNode -> numDrinks = nDrinks;
      tempNode -> next = nullptr;
       node * cur = head;
       node * prev = nullptr;
      bool dup = false;
      
       while (cur -> next != nullptr){
        if (cur -> name == n && cur -> age == a){
          cur -> deposit = d;
          cur -> numDrinks = nDrinks;
          dup = true;
          break; 
        } 
         cur = cur -> next; //
      }
     /*  if (!dup){
        prev -> next = tempNode;
        tempNode -> next = cur; 
        size++; 
      } else {
        delete tempNode; 
      } */
      node * cu = head;
      node * pre = nullptr; 
      if (dup == false){
       for (int i = 0; i < index; i++){
         pre = cu;
         cu = cu -> next; 
       }
        pre -> next = tempNode;
        tempNode -> next = cu;
        size++;
      }
    }
  }
  //[name: Rob; age: 34; deposit: 1234; number of drinks: 1]
  void remove(string & s, int val, string personN) {
    node * cur = head;
    node * prev = nullptr; 
    while (cur != nullptr){
      if (s == "name" && cur -> name == personN){
        if (prev == nullptr){
          head = cur -> next;
          delete cur;
          size--;
          cur = head; 
        } else {
          prev -> next = cur -> next;
          delete cur;
          size--;
          cur = prev -> next; 
        }
      }
      if (s == "age" && cur -> age == val){
        if (prev == nullptr){
          head = cur -> next;
          delete cur;
          size--;
          cur = head; 
        } else {
          prev -> next = cur -> next;
          delete cur;
          size--;
          cur = prev -> next; 
        }
      } else if (s == "deposit" && cur -> deposit == val || s=="number of drinks" && cur -> numDrinks == val){
         if (prev == nullptr){
          head = cur -> next;
          delete cur;
          size--;
          cur = head; 
        } else {
          prev -> next = cur -> next;
          delete cur;
          size--;
          cur = prev -> next; 
        }
      } else {
         prev = cur;
        cur = cur -> next; 
       }
    }
  }
   void sort(const string & s){
     if (size <= 1){
       return;
     }
     if (s == "name"){
       bool swap;
       node * ptr1;
       node * ptr2 = nullptr;
        do{
          swap = false;
          ptr1 = head;
          while (ptr1 -> next != ptr2){
            if (ptr1 -> name > ptr1 -> next -> name){
              swapN(ptr1, ptr1 -> next);
              swap = true; 
            }
            ptr1 = ptr1 -> next; 
          }
          ptr2 = ptr1; 
        } while (swap);
     } else if (s == "deposit"){
       bool swap;
       node * ptr1;
       node * ptr2 = nullptr;
        do{
          swap = false;
          ptr1 = head;
          while (ptr1 -> next != ptr2){
            if (ptr1 -> deposit > ptr1 -> next -> deposit){
              swapN(ptr1, ptr1 -> next);
              swap = true; 
            }
            ptr1 = ptr1 -> next; 
          }
          ptr2 = ptr1; 
        } while (swap);
     } else if (s == "age"){
       bool swap;
       node * ptr1;
       node * ptr2 = nullptr;
        do{
          swap = false;
          ptr1 = head;
          while (ptr1 -> next != ptr2){
            if (ptr1 -> age > ptr1 -> next -> age){
              swapN(ptr1, ptr1 -> next);
              swap = true; 
            }
            ptr1 = ptr1 -> next; 
          }
          ptr2 = ptr1; 
        } while (swap);
     } else if (s == "number of drinks"){
       bool swap;
       node * ptr1;
       node * ptr2 = nullptr;
        do{
          swap = false;
          ptr1 = head;
          while (ptr1 -> next != ptr2){
            if (ptr1 -> numDrinks > ptr1 -> next -> numDrinks){
              swapN(ptr1, ptr1 -> next);
              swap = true; 
            }
            ptr1 = ptr1 -> next; 
          }
          ptr2 = ptr1; 
        } while (swap);
      }
   }
   void swapN(node * x, node * y){
     string tempName = x -> name;
     int tempAge = x -> age;
     int tempDeposit = x -> deposit;
     int tempNumDrinks = x -> numDrinks;
     
     x -> name = y -> name;
     x -> age =  y -> age;
     x -> deposit = y -> deposit;
     x -> numDrinks = y -> numDrinks;
    
    y -> name = tempName;
    y -> age = tempAge;
    y -> deposit =  tempDeposit;
    y -> numDrinks =  tempNumDrinks;
   }
  void print(ofstream &ofs) {
    //[name: Rob; age: 34; deposit: 1234; number of drinks: 1]
    if (head == nullptr){
      return; 
    }
    node * cur =  head;
    while (cur != nullptr){
      ofs << "[name: " << cur -> name << "; age: " << cur -> age <<"; deposit: " << cur -> deposit << "; number of drinks: " << cur -> numDrinks << "]" << endl;  
      cur = cur -> next; 
    }
  }
  
}; 

#endif