#include <iostream>
#include <vector>
#include <iomanip>

#define TEST_EIN
#ifdef TEST_EIN
    #define TESTANWEISUNG(irgendwas) irgendwas
#else
    #define TESTANWEISUNG(irgendwas) /* nichts */
#endif
const double PI = 3.1415926535;
const bool TEST_EIN_B = false;

using namespace std;
// class traits = char_traits<charT> ist der Defualt Template parameter
// (Ähnlich wie der Standard Allokator bei container-typen)

typedef basic_ostream<char, std::char_traits<char>> ostream2;

ostream& myManipulator(ostream& os) {
    string myStr = ">>>Here I am<<<";
    os.write(myStr.c_str(), myStr.length());

    return os;
}

int main()
{
    std::cout << "Start" << std::endl;



    int n_a = 0;
    int* n_pA = &n_a;
    int n_b = 0;


    if (TEST_EIN_B) {
            std::cout << "Test ein B!" << std::endl;
    }

    const int WIDTH = 15;

    std::cout.setf(std::ios::right);  //equivalent: cout << right;
    std::cout << std::setw(WIDTH / 2) << "radius"
        << std::setw(WIDTH) << "circumference" << '\n';

    std::cout.setf(std::ios::fixed);
    for (double radius = 1; radius <= 6; radius += 0.5) {
        std::cout << std::setprecision(1) << std::setw(WIDTH / 2)
            << radius
            << std::setprecision(2) << std::setw(WIDTH)
            << (2 * PI * radius) << '\n';
    }

    /* Switch overload */
    unsigned long someAddress = 0x0000ABCD;
    cout << "Treat as unsigned long: " << someAddress << endl;
    cout << "Treat as address: " << (void*)someAddress << endl;

    /* Print boolean */

    cout << "Boolean output without using boolalpha: " << true << " / " << false << endl;
    cout << "Boolean output using boolalpha: " << boolalpha << true << " / " << false << endl;

    /* Print right-justified*/

    cout.setf(ios::right, ios::adjustfield);
    cout.width(50);
    cout << "This text is right justified \n";
    cout << "This text is left justified again" << endl;

    /* width and fill only applied to the subsequent data */

    cout << right << setfill('.') << setw(30) << 500 << " pcs" << endl;
    cout << right << setfill('.') << setw(30) << 3000 << " pcs" << endl;
    cout << right << setfill('.') << setw(30) << 24500 << " pcs" << endl;

    /* combine right- and left justified output*/
    
    cout << left << setfill('.') << setw(20) << "Flour" << right << setfill('.') << setw(20) << 0.7 << " kg" << endl;
    cout << left << setfill('.') << setw(20) << "Honey" << right << setfill('.') << setw(20) << 2 << " Glasses" << endl;
    cout << left << setfill('.') << setw(20) << "Noodles" << right << setfill('.') << setw(20) << 800 << " g" << endl;
    cout << left << setfill('.') << setw(20) << "Beer" << right << setfill('.') << setw(20) << 20 << " Bottles" << endl;


    /* Print addresses */

    cout << left << setw(10) << "&n_a" << right << setw(10) << "0x" << n_pA << endl;
    cout << left << setw(10) << "&n_b" << right << setw(10) << "0x" << &n_b << endl;

    cout.fill(0);
    /* number format */


    int myInt = 123;

    cout << "Decimal: " << myInt << endl;

    cout.setf(ios::hex, ios::basefield);
    cout << "Hexadecimal: " << myInt << endl;

    cout << "Octal: " << resetiosflags(ios::basefield) <<  setiosflags(ios::oct) << myInt << endl;

    cout.unsetf(ios::basefield);

    /* leading zeros */


    cout << setfill('0') << setw(7) << 3 << endl;
    cout << setfill('0') << setw(7) << 35 << endl;
    cout << setfill('0') << setw(7) << 357 << endl;
    cout << setfill('0') << setw(7) << 3579 << endl;

    /* FLoating point values */

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

    cout.imbue(std::locale("en_US.UTF-8"));
    cout << showbase << put_money(specialOffering) << endl;
    cout.imbue(std::locale("de_DE.UTF-8"));
    cout << showbase << put_money(specialOffering) << endl;
    cout.imbue(std::locale("ru_RU.UTF-8"));
    cout << showbase << put_money(specialOffering) << endl;


    cout << "Mz custom manipulator: " << myManipulator << endl;

    TESTANWEISUNG(std::cout << "Test ein!" << std::endl;)
}   

