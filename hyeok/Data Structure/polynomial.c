#include <stdio.h>
#define Max(a,b) (((a) > (b)) ? (a) : (b))
#define Max_degree 101

typedef struct {
    int degree;
    float coef[Max_degree];
}polynomial;

polynomial add_polynomial(polynomial A, polynomial B){
    
    polynomial C;
    int Aef = 0, Bef = 0, Cef = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    int degree_c = Max(A.degree, B.degree);

    while(Aef <= A.degree && Bef <= B.degree)
    {
        if(degree_a > degree_b)
        {
            C.coef[Cef++] = A.coef[Aef++];
            degree_a--;
        }
        else if(degree_a == degree_b)
        {
            C.coef[Cef++] = A.coef[Aef++] + B.coef[Bef++];
            degree_a--;
            degree_b--;
        }
        else
        {
            C.coef[Cef++] = B.coef[Bef++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p)
{
    if(p.coef[0] == 0)
    {
        for(int i = p.degree -1 ; i > 0; i--)
        {
            printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
        }
        printf("%3.1f", p.coef[p.degree]);
    }
    else
    {
        for(int i = p.degree; i > 0; i--)
        {
            printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
        }
        printf("%3.1f", p.coef[p.degree]);
    }
}

int main()
{
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;
    c = add_polynomial(a, b);

    print_poly(a);
    print_poly(b);
    print_poly(c);
    return 0;
}