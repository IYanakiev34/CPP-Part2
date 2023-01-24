#include "main.ih"

int main(int argc, char **argv)
{
    /* Exercise 52
     */

    std::string const fileName{argv[1]};
    std::string const text{argv[2]};

    Handler h{};
    std::ofstream of{fileName};

    if (!of.is_open())
    {
        std::cerr << "Could not open the file\n";
        return 1;
    }

    std::thread thr{&Handler::shift, std::ref(h), std::ref(of), std::ref(text)};
    thr.join();

    // I am not sure by what a second thread defines an object means
    // Does it mean that we make a thread which returns a Handler object
    // and then pass this object into another thread?
    // What does a thread that defines an object mean

    // I am going with my best guess
    std::thread thr2{&Handler::shift, Handler{}, std::ref(of), std::ref(text)};
    thr2.join();
    return 0;
}