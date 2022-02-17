/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}   //1
    int value;//2
    std::string name;//3
};

struct Values                                  //4
{
    const T* compare(const T& a, const T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        
        return nullptr;
    }
};

struct U
{
    float unit1 { 0.0f }, unit2 { 0.0f };
    float updateU(const float& newVal)     //12 
    {
        std::cout << "U's unit1 value: " << this->unit1 << std::endl;
        this->unit1 = newVal;
        std::cout << "U's unit1 updated value: " << this->unit1 << std::endl;
        while( std::abs(this->unit2 - this->unit1) > 0.001f )
        {
            if(this->unit2 < this->unit1)
                this->unit2 += 0.1f;
            else
                this->unit2 -= 0.1f;
        }
        std::cout << "U's unit2 updated value: " << this->unit2 << std::endl;
        return this->unit2 * this->unit1;
    }
};

struct MultiplyValues
{
    static float updateU(U& that, const float& newVal)         //10 
    {
        std::cout << "U's unit1 value: " << that.unit1 << std::endl;
        that.unit1 = newVal;
        std::cout << "U's unit1 updated value: " << that.unit1 << std::endl;

        while( std::abs(that.unit2 - that.unit1) > 0.001f )
        {
            /*
             write something that makes the distance between that->unit2 and that->unit1 get smaller
             */
            if (that.unit2 < that.unit1)
            {
                that.unit2 += 0.1f;
                std::cout << "unit2: " << that.unit2 << std::endl;
            }
            else
            {
                that.unit2 -= 0.1f;
                std::cout << "unit2: " << that.unit2 << std::endl;
            }
        }
        std::cout << "U's unit2 updated value: " << that.unit2 << std::endl;
        return that.unit2 * that.unit1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T typeA( 5, "typeA");                                             //6
    T typeB( 2, "typeB");                                             //6
    
    Values f;                                            //7
    auto* smaller = f.compare(typeA, typeB);                              //8
    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    else
        std::cout << "f.compare() returns nullptr because the values are equal" << std::endl; //9
    
    U u1;
    float updatedValue = 1.2f;
    std::cout << "[static func] u1's multiplied values: " << MultiplyValues::updateU(u1, updatedValue) << std::endl;  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateU( updatedValue ) << std::endl;
}
