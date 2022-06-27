#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main(){
  string req;
  bool first = true;
  int prev_sell_quantity, prev_sell_price, prev_buy_quantity, prev_buy_price = 0;
  while(cin >> req) {
    if (req == "buy"){
      int quantity, price;
      cin >> quantity >> price;
      if(first){
        first = false;
        prev_buy_price = price;
        prev_buy_quantity = quantity;
        cout << 0 << endl;
      } else {
        prev_buy_price = price;
        prev_buy_quantity = quantity;
        //TODO
        cout << abs()
      }
    } else if (req == "sell") {
      int quantity, price;
      cin >> quantity >> price;
      if(first){
        first = false;
        prev_sell_price = price;
        prev_sell_quantity = quantity;
        cout << 0 << endl;
      } else {
        prev_sell_price = price;
        prev_sell_quantity = quantity;
        //TODO
      }
    }  else {
      return 0;
    }
  }
  return 0;
}
