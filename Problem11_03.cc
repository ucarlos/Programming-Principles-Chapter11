#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by Ulysses on 11/12/2019
 *
 * Problem 11_03
 * Write a program that removes all vowels from a file (“disemvowels”). For
 * example, Once upon a time! becomes nc pn tm! . Surprisingly often, the
 * result is still readable; try it on your friends.
 *
 * -----------------------------------------------------------------------------
 */

class vowel_checker{
public:
    vowel_checker() = default;

    explicit vowel_checker(string str) : vowel{str}{};
    bool is_vowel(char c);
    string vowel_list();
    bool add_vowel(char c);
    bool remove_vowel(char c);
    int search_vowel(char c);
    void clear();
private:
    string vowel{"aeiou"};
};

void vowel_checker::clear(){
    vowel = "";
}

bool vowel_checker::is_vowel(char c){
    for (const char &v : vowel)
	if (v == c) return true;

    return false;
}

bool vowel_checker::add_vowel(char c){
    if (!is_vowel(c) && isalpha(c)){
	    vowel += tolower(c);
	    return true;
    }
    else return false;
    
}

string vowel_checker::vowel_list() {
    return vowel;
}

int vowel_checker::search_vowel(char c){
    for (int i = 0; i < vowel.length(); i++)
        if (vowel[i] == c) return i;

    return -1; // Not found;

}
bool vowel_checker::remove_vowel(char c){
    int check = search_vowel(c);
    if (check != -1){
        if (vowel.empty())
            clear();
        else
            vowel.erase(check, 1);

        return true;
    }
    else return false;

}

void set_badbit_exception(fstream &fs){
    fs.exceptions(fs.exceptions() | ios_base::badbit);
}


void str_tolower(string &str){
    for (char &c : str)
	    c = tolower(c);

}

void read_file(fstream &fs){
    ofstream output{"../Problem11_03_Output.txt"};
    vowel_checker v;
    string temp;
    if (!output)
        error("Cannot open Problem11_03_Output.txt. Aborting.");

    // This method preserves white space/formatting from file.
    while(fs.good()){
        getline(fs, temp);

        for (char &c : temp) {
            if (v.is_vowel(tolower(c)))
                c = ' ';
        }
        output << temp << "\n";
    }
}

int main(void){
    fstream input{"../File01.txt", ios_base::in};
    if (!input) error("Cannot open File01.txt. Abort.");
    set_badbit_exception(input);
    read_file(input);
    cout << "It is done." << endl;
    

}
