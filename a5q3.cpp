//BOTTOM-UP approach

#include <bits/stdc++.h>
using namespace std;

double maximumOf(double a, double b){
return a>b?a:b;
}

double bottom_up_cut_rod(int rod_length, double price[]){
double r[rod_length+1];
r[0] = 0;
double max_revenue;
for(int j=1; j<=rod_length; j++){
    max_revenue = INT_MIN;
    for(int i=1; i<=j; i++){
        max_revenue = maximumOf(max_revenue, price[i]+r[j-i]);
    }
    r[j]= max_revenue;
}
return r[rod_length];
}

int main(){
cout<<"Enter length of rod & price factor\n";
int rod_length;
double price_factor;
cin>>rod_length>>price_factor;
double price[rod_length+1] = {};

srand(time(0));

for(int i=0; i<rod_length; i++){

    //prices assigned to the pieces
    price[i+1] = (i+1)*price_factor;//to check

    // Random price assigned to the pieces -------- does not function that nicely for fraction price_factor
        // it belongs to the set { x,2x,3x ... } but all elements are not necessarily covered
    // price[i+1] = (double)(rand()%(int)(((rod_length-1)*price_factor + 1) + price_factor));
    
    cout<<price[i+1]<<" ";
}

cout<<"\nmax_revenue : "<<bottom_up_cut_rod(rod_length, price);

return 0;
}

/*============BLIN===============*/