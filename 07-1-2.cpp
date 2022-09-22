#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char * fname, int fage) : age(fage)
    {
        name = new char[strlen(fname) + 1];
        strcpy(name, fname);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * fname, int fage, char * adr, char * pnum)
        :MyFriendInfo(fname, fage)
    {
        addr = new char[strlen(adr) + 1];
        phone = new char[strlen(pnum) + 1];
        strcpy(addr, adr);
        strcpy(phone, pnum);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo fren1("Andrew", 22, "충남 아산", "010-1234-5678");
    MyFriendDetailInfo fren2("Bndrew", 20, "경기 가평", "010-1234-5679");
    fren1.ShowMyFriendDetailInfo();
    fren2.ShowMyFriendDetailInfo();
    return 0;
}