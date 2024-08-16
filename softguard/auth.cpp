#include "auth.h"
#include <iostream>
#include <cstdlib>

#include "skcrypt.h"

extern "C" bool __cdecl checkLicense ( const char* license )
{
    Auth auth;
    return auth.checkLicenseEx ( license );
}

bool Auth::checkLicenseEx ( std::string license )
{
    // Add your own.

    if ( license == ( std::string )skCrypt ( "VALID_LICENSE" ) )
    {
        std::cout << skCrypt ( "License is valid\n" );
        return true;
    }
    else
    {
        std::cout << skCrypt ( "License is invalid\n" );
        return false;
    }
}
