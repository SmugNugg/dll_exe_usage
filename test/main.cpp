#include <iostream>
#include <windows.h>

typedef bool ( __cdecl* CheckLicenseFunc )( const char* );

int main ( )
{

    HMODULE hModule = LoadLibrary ( "softguard.dll" );
    if ( !hModule )
    {
        std::cerr << "Failed to load DLL." << std::endl;
        return 1;
    };


    CheckLicenseFunc checkLicense = ( CheckLicenseFunc )GetProcAddress ( hModule , "checkLicense" );
    if ( !checkLicense )
    {
        std::cerr << "Failed to get function address." << std::endl;
        FreeLibrary ( hModule );
        return 1;
    }


    const char* license = "INVALID_LICENSE";  
    bool result = checkLicense ( license );

    std::cout << "License check result: " << ( result ? "Valid" : "Invalid" ) << std::endl;

    FreeLibrary ( hModule );

    return 0;
}
