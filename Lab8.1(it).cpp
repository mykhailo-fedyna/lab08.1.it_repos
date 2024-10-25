//Дано літерний рядок, який містить послідовність символів s0, …, sn, … .
//1. Підрахувати кількість входжень кожного із символів “ + ”, “ - ”, “ = ” в послідовність
//s1, …, sn.
//2. Замінити кожну пару символів “++”, “--”, “ == ” трійкою зірочок “ ***”.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку кількості входжень символів '+', '-', '=' у рядку
void Count(char* s, int& plusCount, int& minusCount, int& equalCount)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '+')
            plusCount++;
        else if (s[i] == '-')
            minusCount++;
        else if (s[i] == '=')
            equalCount++;
    }

    cout << "Number of elements '+': " << plusCount << endl;
    cout << "Number of elements '-': " << minusCount << endl;
    cout << "Number of elements '=': " << equalCount << endl;
}

// Функція для заміни пар '++', '--', '==' на '***'
char* Change(char* s)
{
    size_t len = strlen(s);
    if (len < 2) 
        return s;

    char* tmp = new char[len * 3. / 2. + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && s[i + 1] != '\0')
    {
        if (s[i] == s[i + 1] && (s[i] == '+' || s[i] == '-' || s[i] == '='))
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = s[i++];  // Копіюємо символ без змін бо тут може залишитися один елемент максимум
            *t = '\0';
        }
    }

    *t++ = s[i++];
    *t = '\0';
    strcpy(s, tmp);
    return tmp;
}
int main()
{
    char s[101];
    cout << "Enter string:" << endl;
    cin.getline(s, 100);

    // Підраховуємо кількість символів '+', '-', '='
    int plusCount = 0, minusCount = 0, equalCount = 0;
    Count(s, plusCount, minusCount, equalCount);


    // Замінюємо пари символів на '***'
    char* dest = new char[201];
    dest = Change(s);

    cout << "Modified string (param) : " << s << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
