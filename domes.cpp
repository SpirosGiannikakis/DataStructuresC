#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "LinkedList.h"
#include "Stack.h"


using namespace std;


int main () {



  char s[40] = "124.5 45.6 745.7 78442 541 1 1";

  char mpalanter[40]; //char array gia na apothikefsei kathe ena arithmo
  string mpalanter2; //string gia na apothikeusei to char array ws string

  double n[50];


  int i, z, j = 0, x = 0, count = 0;

  //loop gia na pigenei se kathe stixio
  for(i = 0; i < strlen(s); i++){
    if(s[i] == ' ') { //otan entopizei keno
      int counter = 0;

      for(z = x; z < i; z++) {
        mpalanter[counter] = s[z]; //gemizoume to char arrays me tous arithmous enan enan

        counter++;

      }

      i++;
      x = i;

      mpalanter2 = string(mpalanter); //convert char array se string
      n[count] = std::stod(mpalanter2); //convert string to int
      count++;
      memset(mpalanter, 0, 40); //empty chararray
    }


  }

  for(int y = 0; y < 8; y++) {
    cout << n[y] << endl;
  }


 }
