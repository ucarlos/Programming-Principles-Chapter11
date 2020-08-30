#include "../std_lib_facilities.h"
//--------------------------------------------------------------------------------------------------
// Created by Ulysses Carlos on 11/14/19 using Ulysses-H270-HD3.
//
// Problem 11_06
// Write a program that replaces punctuation with whitespace. Consider
// . (dot), ; (semicolon), , (comma), ? (question mark), - (dash), ' (single
// quote) punctuation characters. Don’t modify characters within a pair of
// double quotes ( " ). For example, “ - don't use the as-if rule. ” becomes
// “ don t use the as if rule ”.
//
//--------------------------------------------------------------------------------------------------

void set_bad_bit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void read_file(fstream &input, fstream &output){
    stringstream stream;
    string temp;
    while (input.good()){
        getline(input, temp);

        for (int i = 0; i < temp.length(); i++){
            if (temp[i] == '\"') continue;
            if (ispunct(temp[i]))
                temp[i] = ' ';
            else continue;
        }
        output << temp << "\n";
    }
}

int main(void){
    string filename = "../File01.txt";
    fstream input {filename, ios_base::in};
    if (!input) error("Cannot open " + filename + ". Aborting.");
    filename = "../File11.txt";
    fstream output {filename, ios_base::out};
    if (!input) error ("Cannot open " + filename + ". Aborting.");

    set_bad_bit_exception(input);
    set_bad_bit_exception(output);

    read_file(input, output);
    cout << "It is done." << endl;

}
