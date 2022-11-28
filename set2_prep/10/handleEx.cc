#include "main.ih"

int handleException()
{
    try
    {
        std::rethrow_exception(std::current_exception());
    }
    catch (int val)
    {
        if (val != 0)
            return 1;

        return 0;
    }
    catch (std::string &ex)
    {
        std::cout << ex << "\n";
        return 1;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << "\n";
        return 1;
    }
}