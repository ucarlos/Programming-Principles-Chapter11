#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by ulysses on 11/13/2019
 *
 * Problem 11_04
 * 
 * Write a program called multi_input.cpp that prompts the user to enter
 * several integers in any combination of octal, decimal, or hexadecimal,
 * using the 0 and 0x base suffixes; interprets the numbers correctly; and
 * converts them to decimal form. Then your program should output the
 * values in properly spaced columns like this:
 *
 *  0x43 hexadecimal converts to 67 decimal
 *  0123 octal converts to 83 decimal
 *    65 decimal converts to 65 decimal
 *
 * -----------------------------------------------------------------------------
 */

void unset_base_input(istream &is) {
    is.unsetf(ios::hex);
    is.unsetf(ios::dec);
    is.unsetf(ios::oct);

}

void reset_base_input(istream &is){
    is.setf(ios::hex);
    is.setf(ios::dec);
    is.setf(ios::oct);

}

void print_conversion(ostream &os, int number, string base){
    os << number << "(" << base << ") is equivalent to " << dec << number << " (Decimal)\n";

}

string check_base(ostream &os, string temp){
    string base = temp.substr(0, 2); // Check for 0 or 0x
    if (base == "0x" || base == "0X") {
        os << hex;
        return "hex";
    }
    else if (base[0] == '0' && isdigit(base[1])) {
        os << oct;
        return "oct";
    }
    else {
        os << dec;
        return "dec";
    }
}



void read_integers(istream &is, int count){

    int value;
    string temp, base;
    stringstream stream;
    unset_base_input(stream);
    cout << "Now, please input Decimal values, Hex Values(0x or 0X) and Octal Values (Start with 0): ";
    cout << showbase;
    for (int i = 0; (i < count) && (is.good()); i++){
        is >> temp;
        stream.clear();

        stream.str(temp);
        if (!(stream >> value)) { // Just skip messed up input
            cout << "Could not parse \"" << temp << "\" . Skipping.\n";
            continue;
        }

        base = check_base(cout, temp);
        print_conversion(cout, value, base);

    }

    reset_base_input(stream);
}

int main(void){
    int count;
    cout << "How many numbers do you want to convert?\n";
    cin >> count;
    read_integers(cin, count);
    return 0;
}
