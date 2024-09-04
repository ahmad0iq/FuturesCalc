#include<iostream>
using namespace std;
int main()
{
    int lev,combo,conti;
    float margin,size,entryprice,quantity,exitprice,pnl,liqprice;
    cout<<"Enter leverage multiplier: ";
    cin>>lev;
    cout<<"Choose input variables\n1. Margin and Entry Price\n2. Entry Price and Quantity\n";
    cin>>combo;
    switch (combo)
    {
    case 1:
        cout<<"Enter margin(USDT): ";
        cin>>margin;
        cout<<"Enter entry price(USDT): ";
        cin>>entryprice;
        size=margin*lev;
        quantity=size/entryprice;
        break;
    case 2:
        cout<<"Enter entry price(USDT): ";
        cin>>entryprice;
        cout<<"Enter coins quantity: ";
        cin>>quantity;
        size=quantity*entryprice;
        margin=size/lev;
        break;
    default:
        cout<<"Enter 1 or 2.";
        break;
    }

    liqprice=(size-margin)/quantity;
    cout<<"The liquidation price is "<<liqprice<<"$.\n1. Calculate PNL\n2. Calculate required exit price for given PNL\n0. Exit\n";
    cin>>conti;
    
    switch (conti)
    {
    case 1:
        cout<<"Enter exit price(USDT): ";
        cin>>exitprice;
        
        pnl=(quantity*exitprice)-size;
        cout<<"Final PNL would be "<<pnl<<"$";
        break;
    
    case 2:
        cout<<"Enter required PNL: ";
        cin>>pnl;
        exitprice=(size+pnl)/quantity;
        cout<<"Required price of the coin needs to be "<<exitprice<<" to make PNL "<<pnl<<"$.";
        break; 

    default:
        return 0;
    }

    //this is just a test for Git
    

    return 0;
}