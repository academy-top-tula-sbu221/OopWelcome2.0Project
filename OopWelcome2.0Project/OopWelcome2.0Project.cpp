#include <iostream>

struct SFraction
{
    int numerator;
    int denominator;
};

class Fraction
{
    

    int numerator;
    int denominator;

    void Reduction()
    {
        int nod = denominator;
        int a = numerator;
        int b = denominator;
        while (nod)
        {
            nod = a % b;
            if (!nod)
                break;
            a = b;
            b = nod;
        }
        numerator /= b;
        denominator /= b;
    }

public:
    static int var;

    Fraction() : Fraction(0, 1) {};

    Fraction(int numerator, int denominator)
        : numerator{ numerator } 
    {
        if (denominator != 0)
            this->denominator = denominator;
        else
            this->denominator = 1;
    };

    ~Fraction() 
    {

    }
    
    int GetNumerator() { return numerator; }

    void SetNumerator(int value) { numerator = value; }

    int GetDenominator() { return denominator; }

    void SetDenominator(int value)
    {
        if (value != 0)
            denominator = value;
    }

    void Add(Fraction f)
    {
        this->numerator = this->numerator * f.denominator
                        + this->denominator * f.numerator;
        
        this->denominator *= f.denominator;
        Reduction();
    }

    void Del(Fraction f);

    Fraction Plus(Fraction f)
    {
        Fraction res;
        res.numerator = this->numerator * f.denominator
            + this->denominator * f.numerator;
        res.denominator = this->denominator * f.denominator;
        res.Reduction();

        return res;
    }

    Fraction Minus(Fraction f)
    {
        Fraction res;
        res.numerator = this->numerator * f.denominator
            - this->denominator * f.numerator;
        res.denominator = this->denominator * f.denominator;
        res.Reduction();

        return res;
    }
};

int Fraction::var = 0;

void Fraction::Del(Fraction f)
{
    this->numerator = this->numerator * f.denominator
        + this->denominator * f.numerator;

    this->denominator *= f.denominator;
    Reduction();
}



class Vector
{
    int size;
    int* array;
public:
    Vector(int size = 0)
        : size{ size }, array{ new int[size] } {}
    ~Vector()
    {
        if (array)
            delete[] array;
    }
};

int main()
{
    {
        Vector v1(10);
    }

    SFraction sf1;
    sf1.numerator = 10;
    sf1.denominator = 0;


    Fraction cf1;
    cf1.SetNumerator(7);
    cf1.SetDenominator(10);
    
    std::cout << "[" << cf1.GetNumerator() 
              << "/" << cf1.GetDenominator() << "]\n";

    Fraction cf2;
    cf2.SetNumerator(5);
    cf2.SetDenominator(8);

    Fraction cf4(3, 16);
    

    std::cout << "[" << cf2.GetNumerator()
        << "/" << cf2.GetDenominator() << "]\n";

    //cf1.Add(cf2);
    Fraction cf3 = cf1.Plus(cf2).Minus(cf4).Plus(cf1);

    std::cout << "[" << cf3.GetNumerator()
        << "/" << cf3.GetDenominator() << "]\n";

    cf1.var = 100;
    std::cout << cf2.var << " " << cf3.var << "\n";
    cf4.var = 200;
    std::cout << cf2.var << " " << cf3.var << "\n";

    Fraction::var = 300;

}
