#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include "LinkedList.h"
#include "Stack.h"


using namespace std;
using string = std::string;


int main() {



  ifstream myfile("t250.txt");
  int Days, Tours, start_Day, number_of_vertices, sth;
  double garbage;
  double tmp;

  myfile >> Days >> Tours >> start_Day >> number_of_vertices;

  int line_counter = 1;
  int col_counter = 2;
  int vertex_number[number_of_vertices];
  int start_tour;
  int finish_tour;
  double x[number_of_vertices];
  double y[number_of_vertices];
  int visiting_duration[number_of_vertices];
  int score_of_location[number_of_vertices];
  int open[number_of_vertices][6];
  int close[number_of_vertices][6];


  myfile >> garbage >> garbage >> garbage >> garbage >> \
        garbage >> garbage >> garbage >> garbage >> \
        garbage >> garbage >> garbage  >> garbage  \
        >> vertex_number[0] >> x[0] >> y[0] >> visiting_duration[0] >> \
        score_of_location[0] >> start_tour >> finish_tour;

  while(line_counter > 0 && line_counter <= number_of_vertices && myfile >> vertex_number[line_counter]) {
    while(col_counter > 0 && col_counter <= 21 && myfile >> tmp) {
      if(col_counter == 2) {
        x[line_counter] = tmp;
      }

      else if(col_counter == 3) {
        y[line_counter] = tmp;
      }

      else if(col_counter == 4) {
        visiting_duration[line_counter] = tmp;
      }

      else if(col_counter == 5) {
        score_of_location[line_counter] = tmp;
      }

      else if(col_counter == 6) {
        garbage = tmp;
      }

      else if(col_counter == 7) {
        open[line_counter][0] = tmp;
      }

      else if(col_counter == 8) {
        close[line_counter][0] = tmp;
      }

      else if(col_counter == 9) {
        open[line_counter][1] = tmp;
      }

      else if(col_counter == 10) {
        close[line_counter][1] = tmp;
      }

      else if(col_counter == 11) {
        open[line_counter][2] = tmp;
      }

      else if(col_counter == 12) {
        close[line_counter][2] = tmp;
      }

      else if(col_counter == 13) {
        open[line_counter][3] = tmp;
      }

      else if(col_counter == 14) {
        close[line_counter][3] = tmp;
      }

      else if(col_counter == 15) {
        open[line_counter][4] = tmp;
      }

      else if(col_counter == 16) {
        close[line_counter][4] = tmp;
      }

      else if(col_counter == 17) {
        open[line_counter][5] = tmp;
      }

      else if(col_counter == 18) {
        close[line_counter][5] = tmp;
      }

      else if(col_counter == 19) {
        open[line_counter][6] = tmp;
      }

      else if(col_counter == 20) {
        close[line_counter][6] = tmp;
      }

      else  {
        garbage = tmp;
      }


      std::cout << "tmp" << tmp << '\n';
      std::cout << "col counter : " << col_counter << '\n';
      col_counter++;
    }
    std::cout << "line counter: " << line_counter << '\n';
    line_counter++;
    col_counter = 2;
  }

  for (int i = 0; i < number_of_vertices; i++) {
    std::cout << x[i] << '\n';
  }


  cout << line_counter << endl;


  return 0;
}
