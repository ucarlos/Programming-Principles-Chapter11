#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 *
 * Created by ulysses on 11/15/2019
 *
 * Problem 11_10
 * Write a function vector<string> split(const string& s) that returns a vector
 * of whitespace-separated substrings from the argument s.
 * 
 * -----------------------------------------------------------------------------
 */


vector<string> split(const string &s){
    vector<string> temp;
    stringstream stream{s};

    for (string str; stream >> str;)
	temp.push_back(str);

    return temp;
}

int main(void){
    string temp = "The quick brown fox jumped over the lazy dog. 0123456789";
    vector<string> v = split(temp);

    for (const string &s : v)
	cout << s << " ";

    return 0;
    

}
