#include <iostream>
#include <ostream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;


ostream& myManipulator(ostream& os) {
    string myStr = ">>>Here I am<<<";
    os << myStr;
    return os;
}


struct T_Importance {
     int levelOfSignificance;
};


T_Importance importance(int lvl){ 

    T_Importance x = {.levelOfSignificance = lvl };
    return x;
}



ostream& operator<<(ostream& __os, T_Importance t){

    for(int i = 0; i < t.levelOfSignificance; ++i){
        __os.put('!');
    }
    
    return __os;
}



int main()
{
    std::cout << "Start" << std::endl;    

    /* print right-justified*/

    cout.setf(ios::right, ios::adjustfield);
    cout.width(50);
    cout << "This text is right justified" << endl;
    cout << "This text is left justified again" << endl;


    /* padding with zeros */

    cout << right << setfill('.') << setw(30) << 500 << " pcs" << endl;
    cout << right << setfill('.') << setw(30) << 3000 << " pcs" << endl;
    cout << right << setfill('.') << setw(30) << 24500 << " pcs" << endl;


    /* combine right- and left justified output*/
    
    cout << left << setfill('.') << setw(20) << "Flour" << right << setfill('.') << setw(20) << 0.7 << " kg" << endl;
    cout << left << setfill('.') << setw(20) << "Honey" << right << setfill('.') << setw(20) << 2 << " Glasses" << endl;
    cout << left << setfill('.') << setw(20) << "Noodles" << right << setfill('.') << setw(20) << 800 << " g" << endl;
    cout << left << setfill('.') << setw(20) << "Beer" << right << setfill('.') << setw(20) << 20 << " Bottles" << endl;

    /* print boolean */

    cout << "Boolean output without using boolalpha: " << true << " / " << false << endl;
    cout << "Boolean output using boolalpha: " << boolalpha << true << " / " << false << endl;

    /* addresses */

    unsigned long someAddress = 0x0000ABCD;
    cout << "Treat as unsigned long: " << someAddress << endl;
    cout << "Treat as address: " << (void*)someAddress << endl;



    /* integers */

    int myInt = 123;

    cout << "Decimal: " << myInt << endl;

    cout.setf(ios::hex, ios::basefield);
    cout << "Hexadecimal: " << myInt << endl;

    cout << "Octal: " << resetiosflags(ios::basefield) <<  setiosflags(ios::oct) << myInt << endl;

    cout.unsetf(ios::basefield);


    /* padding with zeros */

    cout << setfill('0') << setw(7) << 3 << endl;
    cout << setfill('0') << setw(7) << 35 << endl;
    cout << setfill('0') << setw(7) << 357 << endl;
    cout << setfill('0') << setw(7) << 3579 << endl;


    /* floating point values */

    double myFloat = 1234.123456789012345;
    int defaultPrecision = cout.precision();

    cout << "Default precision: " << myFloat << endl;
    cout.precision(4);
    cout << "Modified precision: " << myFloat << endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << "Modified precision & scientific format: " << myFloat << endl;
    /* back to default */
    cout.precision(defaultPrecision);
    cout.setf(ios::fixed, ios::floatfield);
    cout << "Default precision & fixed format:  " << myFloat << endl;


    /* money */

    long double specialOffering = 9995;

    cout.imbue(locale("en_US.UTF-8"));
    cout << showbase << put_money(specialOffering) << endl;
    cout.imbue(locale("de_DE.UTF-8"));
    cout << showbase << put_money(specialOffering) << endl;
    cout.imbue(locale("ru_RU.UTF-8"));
    cout  << showbase << put_money(specialOffering) << endl;


    /* time */

    time_t now = time(nullptr);
    tm localtm = *localtime(&now);
    
    
    cout.imbue(locale("en_US.UTF-8"));
    cout << "en_US : " << put_time(&localtm, "%c") << endl;
    cout.imbue(locale("de_DE.UTF-8"));
    cout << "de_DE : " << put_time(&localtm, "%c") << endl;
    cout.imbue(locale("ru_RU.UTF-8"));
    cout << "ru_RU : " << put_time(&localtm, "%c") << endl;


    /* custom modifiers */

    cout << "My custom manipulator: " << myManipulator << endl;
    cout << "I have something important to say" << importance(5) << endl;

}   

