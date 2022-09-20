#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
        }
    }
}

class NameCard
{
private:
    char* name;
    char* comp_name;
    char* phone_num;
    int position;
public:
    NameCard(char* _name, char* _comp_name, char* _phone_num, int pos)
        : position(pos)
    {
        name = new char[strlen(_name) + 1];
        comp_name = new char[strlen(_comp_name) + 1];
        phone_num = new char[strlen(_phone_num) + 1];
        strcpy(name, _name);
        strcpy(comp_name, _comp_name);
        strcpy(phone_num, _phone_num);
    }
    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << comp_name << endl;
        cout << "전화번호: " << phone_num << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    // ~NameCard()
    // {
    //     delete []name;
    //     delete []comp_name;
    //     delete []phone_num;
    // }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}