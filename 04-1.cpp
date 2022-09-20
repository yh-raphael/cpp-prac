# include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    bool InitMembers(int price, int num, int money)
    {
        if (price < 0 || num < 0 || money <0) {
            cout << "negative value error" << endl;
            return false;
        }
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;

        return true;
    }
    int SaleApples(int money)
    {
        if (money < 0) {
            cout << "negative value" << endl;
            return 0;
        }
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;

public:
    bool InitMembers(int money)
    {
        if (money <0) {
            cout << "negative value error" << endl;
            return false;
        }
        myMoney = money;
        numOfApples = 0;
        
        return true;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        if (money < 0) {
            cout << "negative value" << endl;
            return;
        }
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller; // declare
    if (!seller.InitMembers(1000, 20, 0))    // init
        cout << "init failure ..." << endl;
    FruitBuyer buyer;   // declare
    if (!buyer.InitMembers(5000))            // init
        cout << "init failure ..." << endl;
    buyer.BuyApples(seller, -2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}