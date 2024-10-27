// Goat.h


#ifndef GOAT_H
#define GOAT_H
#include <iostream>
#include <string>
using namespace std;


class Goat {
private:
   string name;
   int age;
   string color;
public:
   Goat()                          { name = ""; age = 0; color = ""; }
   // write three more constructors
   Goat(const string& n)                  {name = n; age=0; color= "";}


   Goat(const string& n, int a)           {name =n; age= a; color = "";}


   Goat(const string& n, int a, const string& c) : name(n), age(a), color(c){}


   // setters and getters
   void set_name(const string& n)         { name = n; };
   string get_name() const         { return name; };
   void set_age(int a)             { age = a; };
   int get_age() const             { return age; }
   void set_color(const string& c)        { color = c; }
   string get_color() const        { return color; }


   // write overloaded < operator for the std::list
   bool operator<(const Goat& other) const{
       return name < other.name;
   }
};


#endif
