#pragma once
# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <string>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

class ScalarConvert
{
    private :
        ScalarConvert();
        ScalarConvert(const ScalarConvert& copy);
        ScalarConvert& operator=(const ScalarConvert& src);
        ~ScalarConvert();

    public :

        static void convert(const std::string& literal);
};