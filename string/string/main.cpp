#include <iostream>
#include "ObStr.h"

int main()
{
    {
        std::cout << "atoi test" << std::endl;

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
    }

    {
        std::cout << "\nReserveString test" << std::endl;

        const char* sourceString = "Hello World!";
        size_t sourceSize = 0;
        while (sourceString[sourceSize] != '\0') ++sourceSize;
        const size_t destSize = 20;
        char destString[destSize];

        ObStr::ReserveString(destString, destSize, sourceString, sourceSize);

        std::cout << "sourceString: " << sourceString << '\n';
        std::cout << "size of sourceString: " << sourceSize << std::endl;
        std::cout << "destString: " << destString << '\n';
        std::cout << "size of destString: " << sizeof(destString) << std::endl;
    }

	return 0;
}