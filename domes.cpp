#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <cmath>
#include "LinkedList.h"
#include "UtilFunc.h"





int main() {

	Vec2 suntetagmenes;
	suntetagmenes.x = 15;
	suntetagmenes.y = 55;
	std::cout << suntetagmenes << '\n';


	std::string file;
	std::cout << "Παρακαλώ δώστε το όνομα του αρχείου που θέλετε να χρησιμοποιήσετε" <<
		"ως έισοδο στο πρόγραμμα" << '\n';
	std::getline(std::cin, file);
	std::ifstream myfile(file);
	if (!myfile) {
		throw std::runtime_error("Could not open file");
	}
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
		garbage >> garbage >> garbage >> garbage  \
		>> vertex_number[0] >> x[0] >> y[0] >> visiting_duration[0] >> \
		score_of_location[0] >> start_tour >> finish_tour;

	while (line_counter > 0 && line_counter <= number_of_vertices && myfile >> vertex_number[line_counter]) {
		while (col_counter > 0 && col_counter <= 21 && myfile >> tmp) {
			switch (col_counter) {

			case 2:
				x[line_counter] = tmp;
				break;

			case 3:
				y[line_counter] = tmp;
				break;

			case 4:
				visiting_duration[line_counter] = tmp;
				break;


			case 5:
				score_of_location[line_counter] = tmp;
				break;


			case 6:
				garbage = tmp;
				break;


			case 7:
				open[line_counter][0] = tmp;
				break;


			case 8:
				close[line_counter][0] = tmp;
				break;


			case 9:
				open[line_counter][1] = tmp;
				break;


			case 10:
				close[line_counter][1] = tmp;
				break;


			case 11:
				open[line_counter][2] = tmp;
				break;


			case 12:
				close[line_counter][2] = tmp;
				break;


			case 13:
				open[line_counter][3] = tmp;
				break;


			case 14:
				close[line_counter][3] = tmp;
				break;


			case 15:
				open[line_counter][4] = tmp;
				break;


			case 16:
				close[line_counter][4] = tmp;
				break;


			case 17:
				open[line_counter][5] = tmp;
				break;


			case 18:
				close[line_counter][5] = tmp;
				break;


			case 19:
				open[line_counter][6] = tmp;
				break;


			case 20:
				close[line_counter][6] = tmp;
				break;


			default:
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


	std::cout << line_counter << std::endl;
	std::cin.get();
	std::cout << "#EPAN: "; // Arithmos #epan epanalhpsewn poy dinetai gia ton algorithmo
	std::cout << Tours;


	std::cin.get();
	list<int> dromologia[Days]; // Δημιουργια Κ άδειων δρομολογίων

	for (int i = 0; i < Days; i++) {
		dromologia[i].isempty(); // Επιβεβαίωση του ότι τα δρομολόγια είναι κενά
	}
	std::cin.get();

	std::cout << vertex_number[0] << '\n';
	std::cout << x[0] << '\n';
	std::cout << y[0] << '\n';
	std::cout << visiting_duration[0] << '\n';
	std::cout << score_of_location[0] << '\n';
	std::cout << start_tour << '\n';
	std::cout << finish_tour << '\n';





	return 0;
}
