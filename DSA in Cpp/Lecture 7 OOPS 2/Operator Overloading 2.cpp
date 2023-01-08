#include<iostream>
using namespace std;

class Fraction {
    private :
        int numerator;
        int denominator;

    public :
        Fraction(int numerator, int denominator) {
            this -> numerator = numerator;
            this -> denominator = denominator;
        }

        void print() {
            cout << this -> numerator << " / " << denominator << endl;
        }

        void simplify() {
            int gcd = 1;
            int j = min(this -> numerator, this -> denominator);
            for(int i = 1; i <= j; i++) {
                if(this -> numerator % i == 0 && this -> denominator % i == 0) {
                    gcd = i;
                }
            }
            this -> numerator = this -> numerator / gcd;
            this -> denominator = this -> denominator / gcd;
        }

        // pre-increment
        Fraction operator++(){
            numerator=numerator+denominator;
            simplify();

            // return this // return address of this block
            return *this;
        }

};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    /*
    f1.print();
    ++f1;
    f1.print();
    // output:
    // 10 / 2
    // 6 / 1
    */
    
    /*
    f1.print();
    //++f1;
    Fraction f3=++f1;
    f3.print();
    f1.print();
    // output:
    // 10 / 2
    // 6 / 1
    // 6 / 1
    */

    /*
    f1.print();
    ++(++f1);
    f1.print();
    // output:
    // 10 / 2
    // 6 / 1
    */


    f1.print();
    Fraction f3=++(++f1);
    f1.print();
    f3.print();
    // output:
    // 10 / 2
    // 6 / 1
    // 7 / 1



}
