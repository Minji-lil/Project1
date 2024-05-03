#include<iostream>
using namespace std;

class rational
{
    private:
    int num;
    int den;

    public:
    
    rational(int n= 0, int d=0)//constructor
    {
        num=n;
        den=d;
    };

    friend ostream &operator <<(ostream &os, rational&r);
    friend  rational operator + (rational r1, rational r2); //overloading + operator
};

rational operator + (rational r1, rational r2) //defining + overloaded operator
{
    rational temp;
    temp.den = r1.den * r2.den;
    temp.num = (r2.den*r1.num)+(r1.den*r2.num);
    return temp; 
};
ostream &operator << (ostream& os, rational& r) //defining cout<< overloaded operator
    {
        os<<r.num<<"/"<<r.den;
        return os;
    };  

int main()
{
    rational r1(4,2), r2(3,9);//initializing rational numbers
    rational r3 = r1 + r2;
    cout<<"The sum of "<<r1<<" and "<<r2<<" is: "<<r3;

    return 0;
}