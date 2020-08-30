#include "../std_lib_facilities.h"
/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/13/2019
 *
 * Problem 11_05
 * Write a program that reads strings and for each string outputs the char-
 * acter classification of each character, as defined by the character classifica-
 * tion functions presented in §11.6. Note that a character can have several
 * classifications (e.g., x is both a letter and an alphanumeric).
 *
 * -----------------------------------------------------------------------------
 */


void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void check_character(char c){
    if (ispunct(c))
	cout << "(Punctuation)";
    if (isspace(c))
	cout << "(Whitespace)\t";
    if (isupper(c))
	cout << "(Uppercase)\t";
    if (islower(c))
	cout << "(Lowercase)\t";
    if (isalpha(c))
	cout << "Alphabetical\t";
    if (isdigit(c))
	cout << "Numerical\t";
    if (isalnum(c))
	cout << "Alphanumerical\t";
    cout << endl;

}

void read_file(fstream &fs){
    for (string temp; fs >> temp;){
	    cout << "String \"" << temp << "\" :\n";
	    for (const char &c : temp) {
	        cout << "Character '" << c << "': ";
		check_character(c);
	    }
	    cout << "\n";
    }

}


int main(void){
    fstream fs{"../File01.txt", ios_base::in};
    if (!fs) error("Cannot open File10.txt. Aborting.");
    read_file(fs);

}
