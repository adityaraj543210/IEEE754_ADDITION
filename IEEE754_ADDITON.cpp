#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

string Rshift(string str, int n){
    string temp(24,'0');
    for(int i=n; i<24; i++)
    {
        temp[i]=str[i-n];
    }
   return temp;
}

// string Lshift(string str, int n){
//     string temp(24,'0');
//     for(int i=n; i<24; i++)
//     {
//         temp[i]=str[i-n];
//     }
//    return temp;
// }

string addMantissa(string num1, string num2){
    string res;
    num1='0'+num1;
    num2='0'+num2;
    int carry = 0;
    int n = num1.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (num1[i] == '1' && num2[i] == '1')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 1;
        }

        else if (num1[i] == '0' && num2[i] == '0')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 0;
        }
        else
        {
            if (carry == 0)
            {
                res.push_back('1');
                carry = 0;
            }
            else
            {
                res.push_back('0');
                carry = 1;
            }
        }
    }

    if (carry == 1)
        res.push_back('1');

    reverse(res.begin(), res.end());

    return res;
}

string add_exp(string num1,string num2)
{
    string res;
  int carry = 0;
    int n = num1.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (num1[i] == '1' && num2[i] == '1')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 1;
        }

        else if (num1[i] == '0' && num2[i] == '0')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 0;
        }
        else
        {
            if (carry == 0)
            {
                res.push_back('1');
                carry = 0;
            }
            else
            {
                res.push_back('0');
                carry = 1;
            }
        }
    }

    if (carry == 1)
        res.push_back('1');

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    string A,B;
    cin>>A>>B;
    string A_Exp=A.substr(1,8);
    string B_Exp=B.substr(1,8);

    int a_exp=binaryToDecimal(A_Exp);
    int b_exp=binaryToDecimal(B_Exp);

    

    if(a_exp<b_exp) swap(A,B);

    A_Exp=A.substr(1,8);
    B_Exp=B.substr(1,8);

    char A_Sign=A[0];
    char B_Sign=B[0];
    string A_Mantissa='1'+A.substr(9,23);
    string B_Mantissa='1'+B.substr(9,23);
    string temp_Mantissa;

    int diffExponent=binaryToDecimal(A_Exp)-binaryToDecimal(B_Exp);


    B_Mantissa=Rshift(B_Mantissa,diffExponent);

    bool netSign=!((A_Sign-'0') ^ (B_Sign-'0'));

    

    if(netSign){
        temp_Mantissa=addMantissa(A_Mantissa, B_Mantissa);
    }

    cout<<temp_Mantissa<<endl;

    char carry=temp_Mantissa[0];
    if(carry=='1'){
        temp_Mantissa=Rshift(temp_Mantissa.substr(1),1);
        A_Exp=addMantissa(A_Exp,"00000001");
    }
   

   string res="";
   res=A[0]+A_Exp+temp_Mantissa.substr(2);
    cout<<res<<endl;
    return 0;
}