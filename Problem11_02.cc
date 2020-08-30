#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/12/2019
 *
 * Problem 11_02
 *
 *  Write a program that given a file name and a word outputs each line that
 * contains that word together with the line number. Hint: getline() .
 * -----------------------------------------------------------------------------
 */

void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}

void str_tolower(string &str){
    for (char &c : str)
        c = tolower(c);

}

void search_file(fstream &fs, string &str){
    unsigned long long int line_number = 0;
    unsigned long long int count = 0;
    istringstream temp;
    string word;
    str_tolower(str);
    while (fs.good()){
	    getline(fs, word);
	    temp.str(word);
	    temp >> word;
	    str_tolower(word);
	    line_number++;
	    if (word == str) {
            cout << word << " found on Line Number " << line_number << "\n";
            count++;
        }



    }

    if (!count)
        cout << "No results found for string \"" << str << "\"" << endl;

}

int main(void){
    fstream fs{"../File03.txt", ios_base::in};
    if (!fs) error("Cannot open File03.txt. Aborting.");
    set_badbit_exception(fs);
    string word = "Computer";
    search_file(fs, word);
    
    


}
