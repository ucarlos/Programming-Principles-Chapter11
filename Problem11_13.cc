#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/15/2019
 *
 * Problem11_13
 * 
 * Reverse the order of words (defined as whitespace-separated strings) in a
 * file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian .
 * You are allowed to assume that all the strings from the file will fit into
 * memory at once.
 * -----------------------------------------------------------------------------
 */

vector<string> read_file(fstream &input){
    vector<string> temp;

    for (string str; input >> str;)
	temp.push_back(str);

    return temp;
}


void reverse_vector(vector<string> &list){
    string temp;
    int midpoint = list.size() / 2;
    for (int i = 0; i < midpoint; i++){
	temp = list[i];
	list[i] = list[list.size() - 1 - i];
	list[list.size() - 1 - i] = temp;
    }

    
}

void write_to_file(fstream &output, vector<string> &list){
    int word_per_line = 10;
    for (int i = 0; i < list.size(); i++){
	if ((i > 0) && !(i % word_per_line)){
	    output << list[i] << "\n";
	}
	else output << list[i] << " ";

    }

}

int main(void){
    string filename = "../File01.txt";
    fstream input{filename, ios_base::in};
    if (!input) error("Cannot open " + filename + " . Aborting.");
    filename = "../File130.txt";
    fstream output{filename, ios_base::out};
    if (!output) error("Cannot open " + filename + " . Aborting.");
    
    vector<string> list = read_file(input);
    reverse_vector(list);
    write_to_file(output, list);

    cout << "It has been done.";
    return 0;
    


}
