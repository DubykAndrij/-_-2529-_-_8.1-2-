#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


bool Include(const char* s, int i)
{
    if (s[i] == '\0' || s[i + 1] == '\0')
        return false;

    if ((s[i] == 'n' && s[i + 1] == 'o') || (s[i] == 'o' && s[i + 1] == 'n'))
        return true;

    return Include(s, i + 1);
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] == '\0' || str[i + 1] == '\0')
    {
        while (str[i] != '\0')
        {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }

    if (str[i] == 'n' && str[i + 1] == 'o')
    {
        strcat(t, "***");
        return Change(dest, str, t + 3, i + 2);
    }
    else
    {
        *t++ = str[i++];
        *t = '\0';
        return Change(dest, str, t, i);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str, 0))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String does not contain 'no' or 'on'" << endl;

    char* dest = new char[151];
    dest[0] = '\0';

    char* result = Change(dest, str, dest, 0);

    cout << "Modified string (param) : " << dest << endl;
    cout << "Modified string (result): " << result << endl;

    delete[] dest;
    return 0;
}