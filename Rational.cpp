//Adnan Yeasir
#include <iostream>
using namespace std;

class Rat{
    
private:
    int n;
    int d;
public:
    // constructors
    // default constructor
    Rat(){
        n=0;
        d=1;
    }
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    }
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    //accessor functions (usually called get() and set(...) ) 
    int getN(){ 
      return n;
    }
    int getD(){
        return d;
    }
    void setN(int i){
        n=i;
    }
    void setD(int i){
        d=i;
    }
    //arithmetic operators
    //add
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d+d*r.n;
        t.d = d*r.d;
        t.simplify();// I made a simplification function. We call the simplification function and simplify the numbers.
        return t;
    }
    //subtract
    Rat operator-(Rat r){ // same step as adding but subtraction instead
        Rat t;
        t.n = n*r.d-d*r.n;
        t.d = d*r.d;
        t.simplify();
        return t;
    }
    //multiply
    Rat operator*(Rat r){
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        t.simplify();
        return t;
    }
    //divide
    Rat operator/(Rat r){
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        t.simplify();
        return t;
    }
    
    void simplify(){
     int gcd_ = gcd(n, d);
      n /= gcd_; // numerator
      d /= gcd_;// denominator 
      if (d < 0) { // Make sure the denominator is positive
         d = -d;
         n = -n;
      }
   }
    

		
int gcd(int n, int d){
      return d == 0 ? n : gcd(d, n%d); // basically saying if d== 0 return n; else return gcd(d, n%d)
   }
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    // this is like "cout " but cout is not part of the rat class, so we use friend ostream&
    
    friend istream& operator>>(istream& is, Rat& r);
}; 
// operator<<() is not a member function but since it was declared a friend of Rat // it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
  
  os << r.n << "/"<< r.d << endl; // "cout "
  return os;
}

istream& operator>>(istream& is, Rat& r){
  
  
    is>>r.n>>r.d; // "cin"
   // simplify(r.n, r.d); //reduce the numbers before using them
    return is;
}



int main(){
    Rat r1(5, -3), r2(5, -9);
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    
    return 0;
}