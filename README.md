# rate_my_professor
## An example for demonstrating the use of functors and std::map in EECS 280

This demo is meant to explain how to use functors as predicates or comparators, as well as how to use some key data structures which will be useful in project 5 (like std::map, std::pair, and iterators). Please contact me at mmgeorg@umich.edu or post on Piazza if you have questions about this demo after lab!

### To use this demo:
1. Clone the repository (git clone https://github.com/MelGeorge/rate_my_professor.git) and "cd" into it
2. Open rate_my_professor.cpp and implement the "TODO" sections
3. Compile and run with:
> g++ -std=c++11 rate_my_professor.cpp -o rmp
>
> ./rmp

### Demo introduction:

You may have used Rate My Professor before to help you choose courses. You are a developer for Rate My Professor and your mission is to implement different ways for users to compare/ evaluate professors, like, "does this professor have a chili pepper?" "is this professor's GPA lower than the other professor's GPA?" etc. You also want to organize your database as a std::map, so that users can quickly look up course times by looking up the professor whose lecture we want to attend.

### Appendix

#### Functors

Functors are class-type objects that behave like functions. They "behave like functions" because they have overloaded ( ) operators.

#### Comparators

A comparator is a special type of functor used to compare objects. Comparators often follow a "less than pattern," and return true when the first object passed into the comparator is "less than" the second object passed into the comparator. Here's an example of a functor you may have seen in lecture, which compares two Duck objects:

>class DuckNameLess {
>
>public:
>
>    bool operator()(const Duck &d1, const Duck &d2) const {
>
>       return d1.getName() < d2.getName();
>
>   }
>
>};

This returns true whenever Duck d1 has a name that is less than Duck d2's name. This functor might be useful to us if we are trying to, for example, sort Ducks by name. If we wanted to use std::sort to sort our Ducks for us (get our Ducks in a row, if you will), we would need some way to tell std::sort what it means for a Duck to be "less than" another Duck.

#### Predicates

A predicate is another special type of functor used to check a property of an object. Predicates return either "true" or "false" when passed a single object. For example, this functor can be instantiated with a private member variable "height". You can then pass "Person" objects into it and return whether Person "perry" is taller than "height."

>class TestHeight {
>
>public:
>
>   TestHeight(int height_in) : height(height_in) {}
>
>   bool operator()(const Person& perry) {
>
>      return perry.getHeight() > height;
>
>   }
>
>private:
>
>   int height;
>
>};

#### std::map

A map is basically a binary search tree whose elements are of type std::pair. Each std::pair element will contain two values-- a "key", and a "value". These things are called "key" and "value" because we search for elements in the tree/ map that match the "key" we're looking for, and we hope to find a "value" that corresponds with that "key" in the map.

##### The [ ] operator

It can sometimes be tricky to see what the [ ] operator is supposed to do in a map. The following example demonstrates how it works:

>// people_gpas is a map that contains keys of type std::string and values of type double
>
>// we have constructed the map this way so that we can look up people by name to find
>
>// their GPA
>
>std::map<std::string, double> people_gpas;
>
>// add a person to the map and set their GPA -- using [ ] on a key that doesn't exist adds the key to the map
>
>// and default constructs a value
>
>people_gpas["Eric"] ;             // now the pair ("Eric", 0.0) is in the map
>
>people_gpas["Eric"] = 4.0;    // now the pair ("Eric", 4.0) is in the map
>
>// note that this statement would have done exactly the same thing as the two combined statements above:
>
>// change Eric's GPA -- using [ ] on a key that already exists will not add any elements to the map, but will
>
>// simply return the value by reference (so we can change it if we want)
>
>people_gpas["Eric"] = 4.0;

#### std::pair

std::pair is what it sounds like-- it's a pair of elements. We can make a pair with any two object types we want-- we just have to let std::pair know which one we want. We can make a std::pair<int, int>, a std::pair<std::string, double>, even a std::pair<Duck, std::map>!

We can make a pair and access its elements as demonstrated below:
>// make a pair with a string and a double
>
>std::pair<std::string, double> my_pair;
>
>// now set the first value in the pair to be "Eric"
>
>my_pair.first = "Eric";
>
>// now set the second value in the pair to be 4.0
>
>my_pair.second = 4.0


