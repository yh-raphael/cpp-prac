#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum) { cout << "일반 생성자!" <<endl; }
    void Shot() {
        cout << "BBANG!" << endl;
        bullet --;
    }
    void Show()
    {
        cout << "bullet: " << bullet << endl;
    }
};

class Police
{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police & ref)
        : handcuffs(ref.handcuffs)
    {
        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));        // Gun의 복사 생성자 호출!
        else
            pistol = NULL;
    }
    Police& operator= (const Police& ref)           // Gun의 대입 연산자 오버로딩.
    {
        cout << "대입 연산자!" << endl;
        if (pistol != NULL)
            delete pistol;

        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;

        handcuffs = ref.handcuffs;
        return *this;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs --;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
    void Show()
    {
        cout << handcuffs << ", "; pistol->Show();
    }
};

int main(void)
{
    Police pman1(5, 3);     // 일반생성자
    Police pman2 = pman1;       // 복사 생성자의 호출
    pman2.PutHandcuff();
    pman2.Shot();

    pman1.Show();
    pman2.Show();

    Police pman3(20, 40); pman3.Show();     // 일반생성자

    pman3=pman1;                // 대입 연산자의 호출
    pman3.PutHandcuff();
    pman3.Shot();

    pman1.Show();
    pman3.Show();

    return 0;
}