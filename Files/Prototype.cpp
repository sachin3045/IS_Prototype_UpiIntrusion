#include <bits/stdc++.h>
using namespace std;

set<int> validPins;

void generate()
{
  cout<<"Enter your original pin (Pin must be of 6 digits) : ";
  int orig;
  cin>>orig;
  int dig=log10(orig)+1;
  if(dig!=6)
  {
      cout<<"Please enter a 6 digit UPI Pin\n";
      return;
  }
  else
  {
      int pin=0;
      while(pin==0 || validPins.count(pin))
      pin=rand()%900000+100000;
      validPins.insert(pin);
      cout<<"Pin generated successfully\n";
      cout<<"You One Time Pin is "<<pin<<endl;
      cout<<"Remember that it can be used only once and will be expired after used."<<endl;
  }
}

void makepayment()
{
    cout<<"Enter the amount of the transaction you want : \n";
    int amt;
    cin>>amt;
    cout<<"Enter your UPI Pin to proceed with your transaction : \n";
    int pn;
    cin>>pn;
    if(validPins.count(pn))
    {
        cout<<"Payment Successful\n";
        validPins.erase(pn);
    }
    else
    {
    cout<<"Invalid PIN. Please try again\n";
    }
}

int main() {
    int flag=1;
    while(flag)
    {
    cout<<"1. Generate One Time Pin\n2. Make Payment\n3. Exit\nEnter Your Choice : ";
    int c;
    cin>>c;
    switch(c)
    {
        case 1:generate(); break;
        case 2:makepayment(); break;
        case 3:flag=0;
    }
    }
    cout<<"Thank you for using our service.";
}