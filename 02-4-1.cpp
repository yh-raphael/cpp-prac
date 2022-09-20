#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[] = "ABC 123";
    char *str2 = "DEF 456";
    char str3[50];

    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;
    strcpy(str3, str1);
    strcat(str3, str2);
    cout << str3 << endl;

    cout << strlen(str3) << endl;

    if (strcmp(str1, str2) == 0)
        cout << "문자열이 같다." << endl;
    else
        cout << "문자열이 같지 않다." << endl;
    return 0;
}

// int main(void)
// {
//     char str[25] = "hello world!";
//     cout << "len: " << strlen(str) << endl;

//     char* str2 = strcat(str, " bravo");
//     cout << str2 << endl;

//     str[1] = 'i';
//     cout << str << endl;
//     cout << str2 << endl;

//     char str3[30];
//     strcpy(str3, str);
//     cout << str3 << endl;

//     char str4[] = "hi";
//     cout << strcmp(str, str3) << endl;  // 1
//     cout << strcmp(str4, str2) << endl;  // 0

//     return 0;
// }