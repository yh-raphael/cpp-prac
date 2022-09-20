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
    NameCard(char* name, char* comp_name, char* phone_num, int pos)
        : position(pos)
    {
        this->name = new char[strlen(name) + 1];
        this->comp_name = new char[strlen(comp_name) + 1];
        this->phone_num = new char[strlen(phone_num) + 1];
        strcpy(this->name, name);
        strcpy(this->comp_name, comp_name);
        strcpy(this->phone_num, phone_num);
    }
    NameCard(const NameCard &copy)                // Deep copy constructor!!!
        : position(copy.position)
    {
        name = new char[strlen(copy.name) + 1];
        comp_name = new char[strlen(copy.comp_name) + 1];
        phone_num = new char[strlen(copy.phone_num) + 1];
        strcpy(name, copy.name);
        strcpy(comp_name, copy.comp_name);
        strcpy(phone_num, copy.phone_num);
    }
    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << comp_name << endl;
        cout << "전화번호: " << phone_num << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }
    ~NameCard()
    {
        cout << name << " destructor is being called!" << endl;

        delete []name;
        delete []comp_name;
        delete []phone_num;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    // NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    // NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    // copy2.ShowNameCardInfo();
    
    // NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    
    manClerk.ShowNameCardInfo();
    // manSENIOR.ShowNameCardInfo();
    // manAssist.ShowNameCardInfo();
    return 0;
}