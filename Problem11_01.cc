#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/12/2019
 *
 * Problem 11_01
 *
 * Write a program that reads a text file and converts its input to all lower
 * case, producing a new file.
 * -----------------------------------------------------------------------------
 */

void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}


void str_tolower(string &str){
    for (char &c : str)
	c = tolower(c);

}

void file_tolower(fstream &fs){
    ofstream output{"../File02.txt"};
    if (!output) error("Cannot open File02.txt. Aborting.");

    string temp;
    while (fs.good()){
	    getline(fs, temp);
	    str_tolower(temp);
	    output << temp << endl;
    }

}


int main(void){
    fstream fs{"../File01.txt", ios_base::in};
    if (!fs) error("Cannot open File01.txt. Aborting.");
    set_badbit_exception(fs);
    file_tolower(fs);
    puts("Done!");

}    
