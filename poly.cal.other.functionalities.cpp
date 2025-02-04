// poly.cal.other.functionalities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//JUST DECLARATIONS
double my_pow(double num, int power);
double my_abs(double x);  

//PRINT POLY
void printPolynomial(const vector<double>& poly) {
    bool isFirst = true;
    int degree = poly.size() - 1;  

    for (int i = degree; i >= 0; i--) {  
        double coeff = poly[i];  

        
        if (coeff == 0) continue;

        
        if (!isFirst) {
            if (coeff > 0) cout << " + ";
            else cout << " - ";
        }
        else if (coeff < 0) {
            cout << "-";
        }

        
        if (my_abs(coeff) != 1 || i == 0) cout << my_abs(coeff);

        
        if (i > 0) cout << "x";

       
        if (i > 1) cout << "^" << i;

        isFirst = false;
    }

    
    if (isFirst) cout << "0";

    cout << endl;
}

//ENTER POLY
void enterPolynomial(vector<double>& poly, int degree) {
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> poly[i];
    }
}

//ADD TWO POLY
static vector<double> addPolynomials(const vector<double>& poly1, const vector<double>& poly2, int degree1, int degree2) {
    size_t maxDegree = (degree1 > degree2 ? degree1 : degree2);
    vector<double> result(maxDegree + 1);
    for (size_t i = 0; i < maxDegree + 1; i++) {
        double coeff1 = (i < poly1.size()) ? poly1[i] : 0;
        double coeff2 = (i < poly2.size()) ? poly2[i] : 0;
        result[i] = coeff1 + coeff2;
    }
    return result;
}

//SUBTRACT TWO POLY
static vector<double> subtractPolynomials(const vector<double>& poly1, const vector<double>& poly2, int degree1, int degree2) {
    size_t maxDegree = (degree1 > degree2 ? degree1 : degree2);
    vector<double> result(maxDegree + 1);


    for (size_t i = 0; i < maxDegree + 1; i++) {
        double coeff1 = (i < poly1.size()) ? poly1[i] : 0;
        double coeff2 = (i < poly2.size()) ? poly2[i] : 0;
        result[i] = coeff1 - coeff2;
    }

    return result;
}

//MULTIPLY TWO POLY
vector<double> multiplyPolynomials(const vector<double>& poly1, const vector<double>& poly2, int degree1, int degree2) {

    size_t maxDegree = degree1 + degree2;
    vector<double> result(maxDegree + 1, 0);


    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

//MULTIPLY POLY BY SCALAR
vector<double> multiplyPolynomialByScalar(const vector<double>& poly, double scalar, int degree) {
    vector<double> result(degree + 1);


    for (int i = 0; i <= degree; i++) {
        result[i] = poly[i] * scalar;
    }

    return result;
}

//VALUE OF THE POLY FOR A NUMBER
double evaluatePolynomial(const vector<double>& poly, double scalar, int degree) {
    double result = 0.0;


    for (int i = 0; i <= degree; i++) {
        result += poly[i] * my_pow(scalar, degree - i);
    }

    return result;
}

// VIET'S FORMULAS
void VietsFormulas(const vector<double>& poly) {
    int degree = poly.size() - 1;

    if (degree < 1) {
        cout << "The polynomial degree must be at least 1." << endl;
        return;
    }

    cout << "Vieta’s Formulas for polynomial: ";
    printPolynomial(poly);

    double a_n = poly[degree]; 

    
    for (int i = 1; i <= degree; i++) {
        double numerator = (i % 2 == 1) ? -poly[degree - i] : poly[degree - i];
        cout << "SIGMA_" << i << " = " << numerator << "/" << a_n << endl;
    }
}

double my_pow(double num, int power) {
    double result = 1;
    while (power-- > 0) result *= num;
    return result;
}
double my_abs(double x) {
    if (x < 0) {
        return -x;  
    }
    return x;  
}

int main()
{
    cout << "Welcome to Polynomial Calculator - a mini project intended to work with polynomials with rational coefficients" << endl;
    cout << "Choose one of the following functionalities:" << endl;
    cout << "1) Add polynomials" << endl;
    cout << "2) Subtract polynomials" << endl;
    cout << "3) Multiply polynomials" << endl;
    cout << "4) Multiply polynomial by scalar" << endl;
    cout << "5) Find value of polynomial at a given number" << endl;
    cout << "6) Display Vieta’s formulas for a given polynomial" << endl;
    cout << "7) Quit program" << endl;


    while (true) {


        cout << endl << "Enter your option here: ";
        int action;
        cin >> action;


        switch (action)
        {

        case 1:
        {
            int degree1, degree2;

            cout << "Enter degree of first polynomial: ";
        again1: //use operator "goto" to correct input
            cin >> degree1;
            if (degree1 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again1;
            }

            //enter and print poly1
            vector<double> poly1(degree1 + 1);
            enterPolynomial(poly1, degree1);
            cout << endl << "P(x) = ";
            printPolynomial(poly1);
            cout << endl;

            cout << "Enter degree of second polynomial: ";
        again2: // same as in again1;
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again2;
            }

            //same as in poly1
            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);
            cout <<endl<< "Q(x) = ";
            printPolynomial(poly2);

            //the actual action is happening here
            cout << endl << "Sum of the two polynomials:";
            cout << endl << "P(x) + Q(x) = ";
            vector<double> result = addPolynomials(poly1, poly2, degree1, degree2);
            cout << "Sum of polynomials: ";
            printPolynomial(result);
        }
        break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
        {
            int degree1, degree2;

            cout << "Enter degree of first polynomial: ";
        again3:
            cin >> degree1;
            if (degree1 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again3;
            }

            vector<double> poly1(degree1 + 1);
            enterPolynomial(poly1, degree1);

            cout << endl << "P(x) = ";
            printPolynomial(poly1);
            cout << endl;

            cout << "Enter degree of second polynomial: ";
        again4:
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again4;
            }

            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);

            cout << endl << "Q(x) = ";
            printPolynomial(poly2);

            cout << endl << "Result of the subtraction of the two polynomials:";
            cout << endl << "P(x) - Q(x) = ";

            vector<double> result = subtractPolynomials(poly1, poly2, degree1, degree2);
            //cout << "Sum of polynomials: ";
            printPolynomial(result);
        }
        break;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3:
        {
            int degree1, degree2;

            cout << "Enter degree of first polynomial: ";
        again5:
            cin >> degree1;
            if (degree1 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again5;
            }

            vector<double> poly1(degree1 + 1);
            enterPolynomial(poly1, degree1);

            cout << endl << "P(x) = ";
            printPolynomial(poly1);
            cout << endl;

            cout << "Enter degree of second polynomial: ";
        again6:
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again6;
            }

            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);

            cout << endl << "Q(x) = ";
            printPolynomial(poly2);
            cout << endl;

            cout << endl << "Result of the multiplication of the two polynomials:";
            cout << endl << "P(x) * Q(x) = ";

            vector<double> result = multiplyPolynomials(poly1, poly2, degree1, degree2);
            printPolynomial(result);
        }
        break;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 4:
        {
            int degree;
            double scalar;

            cout << "Enter degree of the polynomial: ";
        again7:
            cin >> degree;
            if (degree < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again7;
            }

            vector<double> poly(degree + 1);
            enterPolynomial(poly, degree);
            cout << endl;

            cout << endl << "P(x) = ";
            printPolynomial(poly);
            cout << endl;

            cout << "Enter a scalar to multiply by:";
            cin >> scalar;
            cout << endl;

            cout << "Result of the multiplication of the polynomial P(x) by " << scalar << " :";
            cout << endl << "P(x) " << scalar << " = ";

            vector<double> result = multiplyPolynomialByScalar(poly, scalar, degree);
            printPolynomial(result);

        }
        break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 5:
        {
            int degree;
            double scalar;

            cout << "Enter degree of the polynomial: ";
        again8:
            cin >> degree;
            if (degree < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again8;
            }

            vector<double> poly(degree + 1);
            enterPolynomial(poly, degree);

            cout << endl << "P(x) = ";
            printPolynomial(poly);

            cout << endl << "Enter a value for x:";
            cin >> scalar;


            cout << endl << "The value of the polinomial P(x) for  x=" << scalar << " is: ";
            cout << endl << "P(" << scalar << ")  = " << evaluatePolynomial(poly, scalar, degree) << endl;


        }
        break;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 6:
        {
            int degree;

            cout << "Enter degree of the polynomial: ";
        again9:
            cin >> degree;
            if (degree < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again9;
            }

            vector<double> poly(degree + 1);
            enterPolynomial(poly, degree);

            cout << endl << "P(x) = ";
            printPolynomial(poly);
            VietsFormulas(poly);

        }
        break;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 7:
            cout << "Exiting the program." << endl;
            return 0;
            break;
        default:
            cout << "Invalid action. " << endl;
            break;
        }

    }
}