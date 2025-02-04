// poly-cal-main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// PRINT POLY
void printPolynomial(const vector<double>& poly) {
    bool isFirst = true;
    for (int i = 0; i < poly.size(); i++) {
        int degree = i;
        double coeff = poly[i];

        if (coeff == 0) continue;


        if (!isFirst) {
            if (coeff > 0) cout << " + ";
            else cout << " - ";
        }
        else if (coeff < 0) {
            cout << "-";
        }


        if (abs(coeff) != 1 || degree == 0) cout << abs(coeff);


        if (degree > 0) cout << "x";


        if (degree > 1) cout << "^" << degree;

        isFirst = false;
    }


    if (isFirst) cout << "0";

    cout << endl;
}

// ENTER POLY
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

// SUBTRACT TWO POLY
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
        again1:
            cin >> degree1;
            if (degree1 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again1;
            }

            vector<double> poly1(degree1 + 1);
            enterPolynomial(poly1, degree1);
            cout << "P(x) = ";
            printPolynomial(poly1);

            cout << "Enter degree of second polynomial: ";
        again2:
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again2;
            }

            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);

            cout << "Q(x) = ";
            printPolynomial(poly2);

            cout << "Sum of the two polynomials:";

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

            cout << "P(x) = ";
            printPolynomial(poly1);

            cout << "Enter degree of second polynomial: ";
        again4:
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again4;
            }

            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);

            cout << "Q(x) = ";
            printPolynomial(poly2);

            cout << "Result of the subtraction of the two polynomials:";

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

            cout << "p(x) = ";
            printPolynomial(poly1);

            cout << "Enter degree of second polynomial: ";
        again6:
            cin >> degree2;
            if (degree2 < 0) {
                cout << "Degree cannot be negative!" << endl;
                goto again6;
            }

            vector<double> poly2(degree2 + 1);
            enterPolynomial(poly2, degree2);

            cout << "Q(x) = ";
            printPolynomial(poly2);

            cout << "Result of the multiplication of the two polynomials:";

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

            cout << "P(x) = ";
            printPolynomial(poly);

            cout << "Enter a scalar to multiply by:";
            cin >> scalar;
            cout << "Result of the multiplication of the polynomial P(x) by " << scalar<<" :";

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

            cout << "P(x) = ";
            printPolynomial(poly);

            cout << "Enter a value for x:";
            cin >> scalar;


            cout << "The value of the polinomial P(x) for  x=" << scalar << " is: " << evaluatePolynomial(poly, scalar, degree) << endl;


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

            cout << "P(x) = ";
            printPolynomial(poly);

            displayVietasFormulas(poly);

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