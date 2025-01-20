#include <iostream>
#include <memory>

// Polynomial:
// p(x) = 3x^5 + 2x^4 + 5x^2 + 2x + 7
// It is a collection of terms where each has a coefficient and exponent

class Term
{
    public:
        Term()
        {
            coefficient = 0;
            power = 0;
        }

        Term(int coeff, int pwr) : coefficient(coeff), power(pwr)
        {}

        int coefficient;
        int power;
};

class Polynomial
{
    public:
        Polynomial()
        {
            noOfTerms = 0;
            terms = nullptr;
        }

        void SetTerm(const Term& t)
        {
            int termIdx = termExists(t);

            if(termIdx != -1L)
            {
                std::cout << "Term with the exponent: " << t.power << " already exists. Replaced." << std::endl;
                terms[termIdx].coefficient = t.coefficient;
                return;
            }
            else
            {
                std::unique_ptr<Term[]> newTerms = std::make_unique<Term[]>(noOfTerms + 1);

                for(unsigned int i = 0; i < noOfTerms; ++i)
                {
                    newTerms[i] = terms[i];
                }

                newTerms[noOfTerms] = t;
                noOfTerms += 1;
                terms = std::move(newTerms);
            }
        }

        Polynomial operator+(const Polynomial& p)
        {
            Polynomial resultPolynomial;

            unsigned int i = 0;
            unsigned int j = 0;

            while(i < noOfTerms || j < p.noOfTerms)
            {
                if(terms[i].power > p.terms[j].power)
                {
                    resultPolynomial.SetTerm(terms[i++]);
                }
                else if (terms[i].power < p.terms[j].power)
                {
                    resultPolynomial.SetTerm(p.terms[j++]);
                }
                else
                {
                    resultPolynomial.SetTerm(Term(terms[i].coefficient + p.terms[j].coefficient, terms[i].power));
                    i++;
                    j++;
                }
            }

            for(; i < noOfTerms; ++i)
            {
                resultPolynomial.SetTerm(terms[i]);
            }

            for(; j < p.noOfTerms; ++j)
            {
                resultPolynomial.SetTerm(p.terms[j]);
            }

            return resultPolynomial;
        }

        friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    private:
        unsigned int noOfTerms;
        std::unique_ptr<Term[]> terms;

        int termExists(const Term& t) const
        {
            for(unsigned int i = 0; i < noOfTerms; ++i)
            {
                if(terms[i].power == t.power)
                {
                    return i;
                }
            }

            return -1L;
        }
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
    os << "p(x) = ";

    for(unsigned int i = 0; i < p.noOfTerms - 1; ++i)
    {        
        os << p.terms[i].coefficient << "x^" << p.terms[i].power << " + ";
    }
    
    if(p.terms[p.noOfTerms - 1].power == 0)
    {
        os << p.terms[p.noOfTerms - 1].coefficient << std::endl;
    }
    else
    {
        os << p.terms[p.noOfTerms - 1].coefficient << "x^" << p.terms[p.noOfTerms - 1].power << std::endl;
    }

    return os;
}

int main()
{
    Polynomial p1, p2;

    p1.SetTerm(Term(6, 4));
    p1.SetTerm(Term(5, 3));
    p1.SetTerm(Term(9, 2));
    p1.SetTerm(Term(2, 1));
    p1.SetTerm(Term(3, 0));

    p2.SetTerm(Term(5, 4));
    p2.SetTerm(Term(2, 2));
    p2.SetTerm(Term(5, 0));

    std::cout << p1;
    std::cout << p2;

    std::cout << p1 + p2;

    return 0;
}