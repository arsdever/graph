#pragma once

inline std::unordered_map<std::string, std::string> parse_args(int argc,
                                                               char** argv)
{
    std::unordered_map<std::string, std::string> args;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[ i ];
        if (arg.find("--") == 0)
        {
            std::string key = arg.substr(2);
            if (i + 1 < argc)
            {
                std::string value = argv[ i + 1 ];
                if (value.find("--") != 0)
                {
                    args[ key ] = value;
                    ++i;
                }
            }
        }
    }
    return args;
}