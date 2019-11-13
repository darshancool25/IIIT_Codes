#include<bits/stdc++.h>
#define ll 			long long int

using namespace std;
ll makeEqualLength(string &str1, string &str2) 
{ 
    ll i;
    ll len1 = str1.size(); 
    ll len2 = str2.size(); 
    if (len1 < len2) 
    { 
        for (i = 0 ; i < len2 - len1 ; i++) 
            str1 = '0' + str1; 
        return len2; 
    } 
    else if (len1 > len2) 
    { 
        for (i = 0 ; i < len1 - len2 ; i++) 
            str2 = '0' + str2; 
    } 
    return len1; 
} 
  
 
string addBitStrings( string first, string second ) 
{ 
    string result;       
    ll length = makeEqualLength(first, second); 
    ll carry = 0;   
   
    for (ll i = length-1 ; i >= 0 ; i--) 
    { 
        ll firstBit = first.at(i) - '0'; 
        ll secondBit = second.at(i) - '0'; 
    
        ll sum = (firstBit ^ secondBit ^ carry)+'0'; 
  
        result = (char)sum + result;   

        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry); 
    } 
    if (carry)  
    	result = '1' + result;  
    return result; 
} 
  
// Multiply single bits of strings a and b 
ll MultiplyiSingleBit(string a, string b) 
{    
	return (a[0] - '0')*(b[0] - '0');
} 
  
ll Multiply(string X, string Y) 
{ 
   
    ll n;
    n = makeEqualLength(X, Y); 
  
    // Base cases 
    if (n == 0) 
    	return 0; 
    if (n == 1) 
    	return MultiplyiSingleBit(X, Y); 
  
    ll fh = n/2;   
    ll sh = (n-fh);   
    
    string Xl = X.substr(0, fh); 
    string Xr = X.substr(fh, sh);   
   
    string Yl = Y.substr(0, fh); 
    string Yr = Y.substr(fh, sh);   
   
    ll P1 = Multiply(Xl, Yl); 
    ll P2 = Multiply(Xr, Yr); 
    ll P3 = Multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 
 
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
}

int main()
{
	// boost;
	string num1, num2;
	cout << "Enter two Binary Strings : ";
	cin >> num1 >> num2;
	cout << "\nMultiplication of two numbers is: " << Multiply(num1,num2);
	return 0;


}