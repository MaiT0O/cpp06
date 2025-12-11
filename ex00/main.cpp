#include "Scalar.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./scalar_convert <literal_value>" << std::endl;
        return 1;
    }

    ScalarConvert::convert(argv[1]);

    return 0;
}