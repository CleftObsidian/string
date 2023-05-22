#include <iostream>
#include "atoi.h"

int main()
{
    const auto data = {
        "42",
        "0x2A", // treated as "0" and junk "x2A", not as hexadecimal
        "3.14159",
        "31337 with words",
        "words and 2",
        "-012345",
        "10000000000" // note: out of int32_t range
    };

    for (const char* s : data)
    {
        const int i{ ObStr::atoi(s) };
        std::cout << "atoi('" << s << "') is " << i << '\n';
        if (const long long ll{ ObStr::atoll(s) }; i != ll)
        {
            std::cout << "atoll('" << s << "') is " << ll << '\n';
        }
    }

	return 0;
}