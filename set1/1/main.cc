#include "main.ih"

void testNumbers()
{
    std::cout << "CONSTRUCT 1 ARG 4\n";
    std::cout << "EXPECT: 0 0 0 0\n";
    Numbers one(4);
    std::cout << one << std::endl;

    std::cout << "CONSTRUCT 2 ARG 2,3\n";
    std::cout << "EXPECT: 3 3\n";
    Numbers two(2, 3);
    std::cout << two << std::endl;

    std::cout << "CONSTRUCT 3 ARG 4 arr:1,2,3,4\n";
    std::cout << "EXPECT: 1 2 3 4\n";
    int arr[] = {1, 2, 3, 4};
    Numbers three(4, arr);
    std::cout << three << std::endl;

    std::cout << "CONSTRUCT 4 ARG {1,2,3}\n";
    std::cout << "EXPECT: 1 2 3\n";
    Numbers four(std::initializer_list<int>{1, 2, 3});
    std::cout << four << std::endl;

    std::cout << " COPY CONST\n";
    std::cout << "EXPECT COPY OF FOUR\n";
    Numbers c(four);
    std::cout << c << std::endl;

    std::cout << "MOVE CONS\n";
    std::cout << "EXPECT MOVE CONS OF Number(2)\n";
    Numbers m(Numbers(2));
    std::cout << m << std::endl;

    std::cout << "SWAP m and c\n";
    std::cout << "EXPECT c = 0 0, m = 1 2 3\n";
    c.swap(m);
    std::cout << "M: " << m << std::endl;
    std::cout << "C: " << c << std::endl;

    std::cout << "OP = on LVALUE\n";
    std::cout << "EXPECT c = 1 2 3\n";
    c = m;
    std::cout << c << std::endl;

    std::cout << "OP = on RVALUE\n";
    std::cout << "EXPECT C = 2 2 2\n";
    c = Numbers(3, 2);
    std::cout << c << std::endl;

    std::cout << "OP = on SELF\n";
    std::cout << "EXPECT C = 2 2 2\n";
    c = c;
    std::cout << c << std::endl;

    std::cout << "OP [] on non CONST" << std::endl;
    std::cout << "EXPECT 5" << std::endl;
    Numbers div(5, 5);
    std::cout << div[1] << std::endl;

    std::cout << "OP [] on const OBJ" << std::endl;
    std::cout << "EXPECT 10" << std::endl;
    Numbers const con(4, 10);
    std::cout << con[2] << std::endl;

    std::cout << "OP == on EQUAL OBJ" << std::endl;
    std::cout << "EXPECT  1" << std::endl;
    Numbers eq1(1, 1);
    Numbers eq2(1, 1);
    std::cout << (eq1 == eq2) << std::endl;

    std::cout << "OP != on non EQUAL OBJ" << std::endl;
    std::cout << "EXPECT 0" << std::endl;
    std::cout << (eq1 != eq2) << std::endl;

    std::cout << "\nENDING TESTS\n";
}
int main()
{
    testNumbers(); // used for testing the implementation of Numbers
    return 0;
}