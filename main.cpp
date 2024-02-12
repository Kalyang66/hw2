#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "ArgumentManager.h"
#include "linkedlist.h"
using namespace std;

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  string input = am.get("input");
  string command = am.get("command");
  string output = am.get("output");

  // string input = "input3.txt";
  // string command = "command3.txt";
  // string output = "output3.txt";

  ifstream ifs(input); 
  ifstream cms(command); 
  ofstream ofs(output);

  // variables
  string inputline = "";
  string name, data;
  int age, nDrinks;
  float deposit;
  linkedList list;
  while (getline(ifs, inputline)) {
    // clean the inputline
    cout << inputline << endl;
    if (inputline == ""){
      break; 
    }
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'),
                    inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'),
                    inputline.end());
    name = inputline.substr(7, inputline.find(';') - 7);
    //cout << name << endl;
    inputline = inputline.substr(inputline.find(';') + 2);
    //cout << "Now inputline is: " << inputline << endl;
       
    age = stoi(inputline.substr(5, inputline.find(';') - 5));
    inputline = inputline.substr(inputline.find(';') + 2);
    
    deposit = stoi(inputline.substr(9, inputline.find(';') - 9));
    inputline = inputline.substr(inputline.find(';') + 2);
   
    nDrinks = stoi(inputline.substr(18, inputline.find(']') - 18));
    //cout << nDrinks << endl;
    
    list.insertAtEnd(name, age, deposit, nDrinks);
  } 
   //list.print(ofs); 
  //ofs << endl; 
  string com = "";           
  string cmndStr = "";        
  string indxStr = "";     
  string valStr = ""; 
  int val; 
  while (getline(cms, com)){
    if (com == " "){
      break; //empty file 
    }
    cout << com << endl;
    com.erase(remove(com.begin(), com.end(), '\n'),
                    com.end());
    com.erase(remove(com.begin(), com.end(), '\r'),
                    com.end());
    if (com.empty()) {
      continue;
    }
    stringstream ss(com); 
    while (ss >> cmndStr){
      if (cmndStr == "Add"){
        ss >> indxStr;
        indxStr.erase(remove(indxStr.begin(), indxStr.end(), '('),
                      indxStr.end());
        indxStr.erase(remove(indxStr.begin(), indxStr.end(), ')'),
                      indxStr.end());
        int ind = stoi(indxStr); 
        name = com.substr(15, com.find(';') - 15); 
        com = com.substr(com.find(';') + 2);
         cout << name << endl; 
        age = stoi(com.substr(5, com.find(';') - 5));
        com = com.substr(com.find(';') + 2);
        cout << age << " " << com<< endl; 
        deposit = stof(com.substr(9, com.find(';') - 9));
        com = com.substr(com.find(';') + 2);
        cout << deposit << endl; 
        nDrinks = stoi(com.substr(18, com.find(']') - 18));
        cout << nDrinks << endl;
        list.add(name, age, deposit, nDrinks, ind);
        
      } else if (cmndStr == "Remove"){
        string newStr; 
        getline(ss, valStr);
        valStr.erase(remove(valStr.begin(), valStr.end(), '('),
                  valStr.end());
        valStr.erase(remove(valStr.begin(), valStr.end(), ')'),
                  valStr.end());
        size_t pos = valStr.find(':');
        string art; 
        if (!valStr.empty() && pos != string::npos) {
          art = valStr.substr(1, pos - 1);
          if (art == "name"){
            newStr = valStr.substr(pos + 1);
            val = 0;
            list.remove(art, val, newStr); 
          }
          //art.erase(remove_if(art.begin(), art.end(), ::isspace), art.end());
          if (pos + 1 < valStr.size()) {
            newStr = valStr.substr(pos + 1);
            val = stoi(newStr);
        } else {
            // Handle the case where there's no value or it's empty
            val = 0; // or another default value
        }
    } else {
        // Handle the case where ':' is not found or valStr is empty
        cout << "Invalid Remove command format: " << valStr << endl;
    }
      string fake = "place holder"; 
      list.remove(art, val, fake);
      } else if (cmndStr == "Sort"){
        ss >> valStr;
        valStr.erase(remove(valStr.begin(), valStr.end(), '('),
                  valStr.end());
        valStr.erase(remove(valStr.begin(), valStr.end(), ')'),
                  valStr.end());
        valStr.erase(remove(valStr.begin(), valStr.end(), '\n'),
                    valStr.end());
        valStr.erase(remove(valStr.begin(), valStr.end(), '\r'),
                    valStr.end());
        list.sort(valStr); 
      }
    }
  }
  //print out the list
  list.print(ofs);
  return 0; 
  }