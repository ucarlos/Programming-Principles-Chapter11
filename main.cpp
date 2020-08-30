#include "../std_lib_facilities.h"

// Test some stuff here:
void unset_stuff(void){
    cin.unsetf(ios::hex);
    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);


}
void precision(){
    double value = 123456.0;
    cout << value << "\n" << fixed
	 << value << "\n" << scientific
	 << value << "\n";
}

void show_different_bases(void){
    int birth_year = 1997;
    cout << showbase
         << "Birth Year: " << birth_year << " (Decimal)\n" << hex
         << "Birth Year: " << birth_year << " (Hex)\n" << oct
         << "Birth Year: " << birth_year << " (Oct)\n" << endl;

}

void width_check(void){
    int width_size = 25;
    setw(width_size);
    cout << "Name: " << setw(width_size) << "Email: " << setw(width_size) << "Phone" << "\n"
	 << "Ulysses Carlos " << setw(width_size + 8) << "ucarlos1@student.gsu.edu"
	 <<  setw(width_size / 2 + 5) << "(000) 000-0000" << "\n";
 
}


void test_seek(void){
    fstream fs {"../test.txt", ios_base::in};
    cout << "H e l l o   W o r l d  !" << endl;
    cout <<"0 1 2 3 4 5 6 7 8 9 10 11" << endl;
    if (!fs) error("Cannot open test.txt. Aborting.");

    //fs.seekg(4); // Considers white space as well:
    cout << "Please input a numerical value (0 - 11):";
    int value;
    cin >> value;
    if (!(0 <= value && value <= 11)) exit(EXIT_FAILURE);
    char ch;

    fs.seekg(value);
    fs >> ch;
    cout << ch << endl;
}

int main(void){
    //precision();
    //show_different_bases();
    //unset_stuff();
    //width_check();
    test_seek();
}
