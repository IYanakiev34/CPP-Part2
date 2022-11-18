#include "main.ih"
#include <bitset> // Add it to main.ih

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

    std::cout << "OP += on LVALUE\n";
    std::cout << "EXPECT c = 4 4 4\n";
    c += c;
    std::cout << c << std::endl;

    std::cout << "OP += on DIFFERENT SIZES\n";
    std::cout << "EXPECT TO FAIL\n";
    std::cout << (c += Numbers(5)) << std::endl;

    std::cout << "OP += on RVALUE\n";
    std::cout << "EXPECT c = 5 5 5\n";
    std::cout << (c += Numbers(3, 1)) << std::endl;

    std::cout << "OP + ON LVALUE\n";
    std::cout << "EXPECT bin: 2 2 2\n";
    Numbers op(3, 1);
    Numbers op1(3, 1);
    Numbers bin(3);
    bin = op + op1;
    std::cout << bin << std::endl;

    std::cout << "OP + ON RVALUE\n";
    std::cout << "EXPECT bin: 5 5 5\n";
    bin = op + Numbers(3, 4);
    std::cout << bin << std::endl;

    std::cout << "OP -= ON LVALUE\n";
    std::cout << "EXPECT G: 1 1 1\n";
    Numbers g(3, 5);
    Numbers s(3, 4);
    g -= s;
    std::cout << g << std::endl;

    std::cout << "OP -= ON RVALUE\n";
    std::cout << "EXPECT G: -1 -1 -1\n";
    std::cout << (g -= Numbers(3, 2)) << std::endl;

    std::cout << "OP -= ON DIFFERENT SIZES\n";
    std::cout << "EXPECT TO FAIL\n";
    std::cout << (g -= Numbers(10)) << std::endl;

    std::cout << "OP - on LVALUE\n";
    std::cout << "EXPECT min: 4 4 4\n";
    Numbers m1(3, 5);
    Numbers m2(3, 1);
    Numbers min(3);
    min = m1 - m2;
    std::cout << min << std::endl;

    std::cout << "OP - on RAVLUE\n";
    std::cout << "EXPECT min: 2 2 2\n";
    min = m1 - Numbers(3, 3);
    std::cout << min << std::endl;

    std::cout << "\n ENDING EXTENSIVE TEST ONLY FEW TEST NOW FOR * / *= /= [] const []\n";
    std::cout << "OP /= by 5" << std::endl;
    std::cout << "EXPECT 1 1 1" << std::endl;
    Numbers div(3, 5);
    div /= 5;
    std::cout << div << std::endl;

    std::cout << "OP *= by 5" << std::endl;
    std::cout << (div *= 5) << std::endl;

    std::cout << "OP [] on non CONST" << std::endl;
    std::cout << "EXPECT 5" << std::endl;
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

void testCopy(std::string const &from, std::string const &to)
{
    copyFile(from, to);
}

void fun(First::Enum t)
{
    std::cout << "Called from main function\n";
}

void testBits()
{
    std::bitset<8> bits((1 << 0) | (1 << 1));

    std::cout << "Print bitset\n";
    std::cout << bits << std::endl;

    std::cout << "Convert bitset to number\n";
    std::cout << static_cast<int>(bits.to_ulong()) << std::endl;

    std::cout << "Size of bitset\n";
    std::cout << bits.size() << std::endl;

    std::cout << "Bitset count\n";
    std::cout << bits.count() << std::endl;

    std::cout << "Iterate over bitset\n";
    for (std::size_t i = 0; i != bits.size(); ++i)
        std::cout << bits.test(i) << std::endl;

    std::bitset<8> m(3);
    std::cout << "Bitset <8> (3)\n";
    std::cout << m << std::endl;
}

void testPrintNamesEnums()
{
    show(Msg::NONE);
    show(Msg::NONE | Msg::EMERG);
    show(Msg::ALERT | Msg::CRIT);
    show(Msg::ALL & (Msg::ERR | Msg::WARNING));
    show(~Msg::NOTICE);
}
int main()
{
    // testNumbers(); used for testing the implementation of Numbers
    // testCopy("../main.cpp", "../main.copy"); used for copying the file
    // fun(First::Enum{}); Ambigious call cannot understand if it should call main fun or First::fun
    testPrintNamesEnums();
    // testBits();
    return 0;
}