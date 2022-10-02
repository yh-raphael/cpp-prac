#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * title, char * isbn, int value) : price(value)
    {
        this->title = new char[strlen(title) + 1];
        this->isbn = new char[strlen(isbn) + 1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }
    Book(const Book& ref) : price (ref.price)           // 복사생성자.
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }
    Book& operator= (const Book& ref)
    {
        delete []title;
        delete []isbn;

        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(char * title, char * isbn, int value, char * key)
        : Book(title, isbn, value)
    {
        DRMKey = new char[strlen(key) + 1];
        strcpy(DRMKey, key);
    }
    EBook(const EBook& ref)         // 복사생성자.
        : Book(ref)                 // C++ 참조자의 참조 가능 범위!
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }
    EBook& operator= (const EBook& ref)
    {
        Book::operator=(ref);       // 기본클래스 대입연산: C++ 참조자의 참조 가능 범위!
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;      // 복사 생성자의 호출.
    ebook2.ShowEBookInfo();
    cout << endl;

    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2;            // 대입 연산자의 호출.
    ebook3.ShowEBookInfo();
    return 0;
}