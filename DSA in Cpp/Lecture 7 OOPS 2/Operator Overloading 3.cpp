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

        // post-increment
        Fraction operator++(int) {
            Fraction fNew(numerator,denominator);
            numerator=numerator+denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }

        // Plus-equal-to operator(+=)
        Fraction&  operator+=(Fraction const &f2){
            int lcm=denominator*f2.denominator;
            int x=lcm/denominator;
            int y=lcm/f2.denominator;

            int num=x*numerator + (y*f2.numerator);

            numerator=num;
            denominator=lcm;
            simplify();
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    /*
    f1.print();
    Fraction f3=f1++;
    f1.print();
    f3.print();
    // output:
    // 10 / 2
    // 6 / 1
    // 5 / 1
    */

    Fraction f3(10,3);
    Fraction f4(5,2);
    /*
    f3+=f4;
    f3.print();
    f4.print();
    // output:
    // 35 / 6
    // 5 / 2
    */

    (f1+=f2)+=f2;
    f1.print();
    f2.print();
    // output
    // 25 / 2
    // 15 / 4
}
