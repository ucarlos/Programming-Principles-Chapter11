//--------------------------------------------------------------------------------------------------
// Created by Ulysses Carlos on 11/14/19 using Ulysses-H270-HD3.
// Problem 11_09
//
// Split the binary I/O program from §11.3.2 into two: one program that
// converts an ordinary text file into binary and one program that reads
// binary and converts it to text. Test these programs by comparing a text
// file with what you get by converting it to binary and back.
//--------------------------------------------------------------------------------------------------
#include "../std_lib_facilities.h"
void file_to_binary(fstream &input, fstream &output);
void file_to_text(fstream &input, fstream &output);

void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void file_to_binary(fstream &input, ofstream &output){
    string temp;
    while (input.good()){
        getline(input, temp);
        temp += "\n";
        char *c_temp = (char *) temp.c_str();
        output.write(c_temp, temp.length());
    }
}

void file_to_text(ifstream &input, ofstream &output){
    char ch;
    for (;input.read(as_bytes(ch), sizeof(char));){
        output << ch;
    }
}

int main(){
    string filename = "../File20.txt";
    fstream fstream1;
    fstream1.open(filename, ios_base::in);
    if (!fstream1) error("Cannot open " + filename + " Aborting.");

    filename = "../File30.txt";
    ofstream fstream2;
    fstream2.open(filename,  ofstream::binary);
    if (!fstream2) error("Cannot open " + filename + " Aborting.");

    file_to_binary(fstream1, fstream2);
    fstream1.close();
    fstream2.close();

    ifstream fstream2_in;
    fstream2_in.open(filename,  ios_base::binary);
    if (!fstream2) error("Cannot open " + filename + " Aborting.");

    filename = "../File31.txt";
    ofstream fstream3;
    fstream3.open(filename, ios_base::out);
    if (!fstream3) error("Cannot open \"" + filename + "\" Aborting.");
    file_to_text(fstream2_in, fstream3);

    fstream2_in.close();
    fstream3.close();



    return 0;
}


