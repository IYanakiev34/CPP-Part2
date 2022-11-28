#include <iostream>
#include "Identified.h"

void exceptionTest(bool byValue)
{
    std::cout << "Throwing by " << (byValue ? "value" : "reference") << ":\n";
    auto id = Identified(0);
    std::cout << "Before throw ";
    id.showId();

    if (byValue)
    {
        try {
            throw id;
        }
        catch (Identified id1)
        {
            std::cout << "Caught by value ";
            id1.showId();
        }
    } else {
        try {
            throw id;
        }
        catch (Identified &id1)
        {
            std::cout << "Caught by reference ";
            id1.showId();
        }
    }
}

int main()
{
    /* Show that exception catchers catching objects result in additional copies of
     * thrown objects, compared to exception catchers catching references to objects */
    exceptionTest(true);
    std::cout << '\n';
    exceptionTest(false);
    return 0;
}
