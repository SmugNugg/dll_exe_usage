#ifndef AUTH_H
#define AUTH_H

#include <string>

extern "C" {
    __declspec( dllexport ) bool __cdecl checkLicense ( const char* license );
}

class Auth
{
public:


    bool checkLicenseEx ( std::string license );

};

#endif // !AUTH_H
