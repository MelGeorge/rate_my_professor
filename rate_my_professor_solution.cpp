// Rate My Professor example
// Remember that functors are class-type objects that behave
// "like functions" because they have overloaded () operators.
// Below is a Professor class, and two functors which can be
// used to check properties of professors. Our task is to
// implement these functors, as well as the "select_all" function.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// This class represents a professor
class Professor{
public:
    Professor(string name_in, double gpa_in, bool pepper_in) :
    name(name_in), gpa(gpa_in), pepper(pepper_in) {}
    
    string name;  // Professor's name
    double gpa;   // Rate my professor GPA
    bool pepper;  // Does this professor have a pepper?
};


// HasPepper is a special kind of functor called a "predicate"
// It returns true if "prof" has a pepper, and false otherwise
class HasPepper {
public:
    // TODO : Implement this
    bool operator()(const Professor& prof) const {
        return prof.pepper;
    }
};


// ProfessorComp is a special kind of functor called a "comparator"
// It returns true if Professor "a" is "less than" Professor "b"
// ("less than" is defined as having a lower gpa)
class ProfessorComp {
public:
    // TODO : Implement this
    bool operator()(const Professor& a, const Professor& b) const {
        return a.gpa < b.gpa;
    }
};



// select_all is a function that uses iterators to traverse the
// profs array, and adds all the class times for Professors for
// whom Pred returns "true" to a vector to return.

// TODO: Implement this
template<typename Pred>
vector<string> select_all(map<Professor,
                          string, ProfessorComp>& profs, Pred& c) {
    vector<string> selected;
    for(auto it = profs.begin(); it != profs.end(); ++it) {
        if((*it).first.pepper) {
            selected.push_back((*it).second);
        }
    }
    return selected;
}

// iterates through all of the professors and prints them
void print_profs(map<Professor, string, ProfessorComp>& profs) {
    cout << "Current Professors: " << endl;
    for(auto it = profs.begin(); it != profs.end(); ++it) {
        cout << "Professor: " << (*it).first.name << endl;
        cout << "Time: " << (*it).second << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    // These people weren't all professors... just computer scientists
    Professor Turing("Alan Turing", 3.5, true);
    Professor Liskov("Barbara Liskov", 3.8, true);
    Professor Lovelace("Ada Lovelace", 3.9, true);
    Professor Dijkstra("Edsger Dijkstra", 4.5, false);
    Professor Hopper("Grace Hopper", 4.0, true);

    
    // "professors" is a map with:
    // key type = Professor object
    // value type = string (time the professor teaches)
    // comparator type = ProfessorComp
    ProfessorComp profComp;
    map<Professor, string, ProfessorComp> professors(profComp);
    
    cout << "Before [] operator:" << endl;
    print_profs(professors);
    
    // TODO : Add 3 professors and set times for them to teach
    professors[Lovelace] = "10:30 am MWF";
    professors[Dijkstra] = "12:00 pm MWF";
    professors[Hopper] = "4:00 pm TuTh";
    
    cout << "After [] operator:" << endl;
    print_profs(professors);
    
    // TODO : Update a professor's time
    professors[Hopper] = "6:00 pm MWF";
    
    cout << "After time update:" << endl;
    print_profs(professors);
    
    // TODO : Call select_all function to get a vector of the times
    // the professors with peppers teach
    HasPepper hp;
    vector<string> times = select_all(professors, hp);
    
    cout << "Printing best lecture times:" << endl;
    for(unsigned int i = 0; i < times.size(); ++i) {
        cout << times[i] << endl;
    }
}
