#include <iostream>
#include "Car.h"

using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void ShowSalesResult()
    {
        cout << "Apples Remaining: " << numOfApples << endl;
        cout << "Money: " << myMoney << endl;
    }
};

class FruitBuyer
{
    int myMoney;        // private
    int numOfApples;    // private

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;    // before any purchase
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }

    void ShowBuyResult()
    {
        cout << "Money Remaining: " << myMoney << endl;
        cout << "Number of Apples: " << numOfApples << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);

    cout << "Seller Status" << endl;
    seller.ShowSalesResult();
    cout << "Buyer Status" << endl;
    buyer.ShowBuyResult();
    cout << endl;

    buyer.BuyApples(seller, 2000);
    cout << "Buyer give 2000 to Seller" << endl << endl;

    cout << "Seller Status" << endl;
    seller.ShowSalesResult();
    cout << "Buyer Status" << endl;
    buyer.ShowBuyResult();

    return 0;
}
