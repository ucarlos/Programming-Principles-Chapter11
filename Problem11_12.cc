#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/15/2019
 *
 * Problem 11_12
 * 
 * Reverse the order of characters in a text file. For example, asdfghjkl be-
 * comes lkjhgfdsa . Warning: There is no really good, portable, and efficient
 * way of reading a file backward.
 * -----------------------------------------------------------------------------
 */
#define MAX_CHARS_PER_LINE (80)
void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void reverse_string(string &str){
    char temp;

    for (int i = 0; i < (str.length() / 2); i++){
	    temp = str[i];
	    str[i] = str[str.length() - 1 - i];
	    str[str.length() - 1 - i] = temp;
    }

}

void reverse_line(fstream &input, fstream &output){
    string temp;
    while (input.good()){
        getline(input, temp);
        reverse_string(temp);
        output << temp << "\n";

    }

}

void reverse_file(fstream &input, fstream &output){
    unsigned long int char_len = 0;
    for (string temp; input >> temp;){
        char_len += temp.length() + 1; // Acount for space as well
        reverse_string(temp);
        if (char_len >= MAX_CHARS_PER_LINE){
            output << "\n";
            char_len = 0;
        }

        output << temp << " ";
    }
}

int main(void){
    string filename = "../File120.txt";
    fstream input{filename, ios_base::in};
    if (!input) error("Cannot open " + filename + " . Aborting.");

    filename = "../File121.txt";
    fstream output{filename, ios_base::out};
    if (!output) error("Cannot open " + filename + " . Aborting.");

    reverse_file(input, output);
    cout << "It is done." << endl;
    return 0;
    

}


