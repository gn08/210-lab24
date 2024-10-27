#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;


int select_goat(set<Goat>& trip);
void delete_goat(set<Goat>& trip);
void add_goat(set<Goat>& trip, string names[], string colors[]);
void display_trip(const set<Goat>& trip);
int main_menu();


int main() {
   srand(time(0));


   // read & populate arrays for names and colors
   ifstream fin("names.txt");
   string names[SZ_NAMES];
   int i = 0;
   while (fin >> names[i++]);
   fin.close();
   ifstream fin1("colors.txt");
   string colors[SZ_COLORS];
   i = 0;
   while (fin1 >> colors[i++]);
   fin1.close();


   set<Goat> trip;
   bool quit = false;
   while (!quit){
       int choice = main_menu();
       switch (choice){
           case 1:
               add_goat(trip, names, colors);
               break;
           case 2:
               delete_goat(trip);
               break;
           case 3:
               display_trip(trip);
               break;
           case 4:
               quit = true;
               break;
       }
   }
   return 0;
}


int main_menu(){
   int choice;
   bool valid_choice = false;


   do{
       cout << "\n*** GOAT MANAGER 3001 ***" << endl;
       cout << "[1] Add a goat" << endl;
       cout << "[2] Delete a goat" << endl;
       cout << "[3] List goats" << endl;
       cout << "Choice -->";


       cin >> choice;


       if (cin.fail() || choice < 1 || choice > 4){
           cin.clear();
           cin.ignore(1000, '\n');
           cout << "Invalid" << endl;
       } else {
           valid_choice = true;
       }
   }while (!valid_choice);


   return choice;
}


void add_goat(set<Goat>&trip, string names[], string colors[]){
   int name_index = rand() % SZ_NAMES;
   int color_index = rand() % SZ_COLORS;
   int age = rand() % (MAX_AGE + 1);
   Goat new_goat(names[name_index], age, colors[color_index]);
   trip.push_back(new_goat);
   cout << "Goat added: " << new_goat.get_name() << "(" << new_goat.get_age() << "," << new_goat.get_color() << ")" << endl;
}


void delete_goat(set<Goat> &trip){
   if (trip.empty()){
       cout << "No goats" << endl;
       return;
   }


   int index = select_goat(trip);
   if (index == -1) return;
   auto it = trip.begin();
   advance(it, index);
   trip.erase(it);
   cout << "Deleted" << endl;
   trip.erase(it);
}


void display_trip(list<Goat> &trip){
   if (trip.empty()){
       cout << "No goats" << endl;
       return;
   }


   int count = 1;
   for (const Goat &g : trip){
       cout << "[" << count ++ << "]" << g.get_name() << " (" << g.get_age() << "," << g.get_color() << ")" << endl;
   }
}


int select_goat(set<Goat>&trip){
   if (trip.empty()){
       cout << "No goats" << endl;
       return - 1;
   }


   int count = 1;
   for (const Goat& g : trip){
       cout << "[" << count++ << "]" << g.get_name() << " (" << g.get_age() << "," << g.get_color() << ")" << endl;
   }


   int selection;
   cout << "Select goat number: ";
   cin >> selection;


   if (selection < 1 || selection > trip.size()){
       cout << "Invalid" << endl;
       return -1;
   }


   return selection - 1;


}
