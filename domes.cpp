#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


int main () {


  char s[40] = "1256 8942 1965 42";

  int n = atoi(s);

  cout << n << endl;

  int j = 0;
  for(int i = 0; i < strlen(s); i++){
    if(s[i] == ' ') {

    }

  }


}

//   list<double> eisodos;
//
//
//
//   string line;
//   ifstream myfile in("test.txt");
//   if (myfile.is_open())
//
//     while (!myfile.eof())
//     {
//       double d;
//       in >> d;
//     }
//     myfile.close();
//     return 0;
//   }
// }

















// template<class T>
// struct node {
//   T info;
//   node *next;
// };
//
// template<class T>
// class list {
// private:
//   //pointer typou node gia to telos kai tin arxi
//   node *head, *tail;
// public:
//   //constructor
//   list(){
//     head=NULL;
//     tail=NULL;
//   }
// };
//
// template<class T>
// void  push_back(T value){
//   node *temp=new node;
//   temp->info=value;
//   temp->next=NULL;
//
//   if(head==NULL) {
//     head=temp;
//     tail=temp;
//     temp=NULL;
//   }
//
//   else {
//     tail->next=temp;
//     tail=temp;
//   }
// }
