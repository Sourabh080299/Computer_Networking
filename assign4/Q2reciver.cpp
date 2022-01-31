#include <bits/stdc++.h> 
using namespace std; 
string a="", b="", c="", d=""; 
string comp(string s){ 
        int t; 
        for(int i = 0; i < 4; i++){ 
                if(s[i]>='A'){ 
                    t= 15 - (s[i]-55); 
                    s[i] = t+48 ; 
                } 
                else{ 
                    t = (15 - s[i]+48); 
                    if(t>=10){ 
                        s[i] = t+55; 
                    } 
                    else{ 
                        s[i] = t+48; 
                    } 
                } 
        } 
        return s; 
} 
string hex(string s, string &a, int i){ 
        string p=""; 
        for(int j=i; j<i+2; j++){ 
            int c= s[j]; 
            int temp; 
            while(c>0){ 
                temp = c%16;
                if(temp > 9){ 
                   p+= temp+55; 
                } 
                else{ 
                  p += temp+48; 
                } 
                c = c/16; 
            } 
            reverse(p.begin(), p.end()); 
            a += p; p=""; 
        } 
        return a; 
} 
string add(string a, string b) { 
        int sum=0, carry=0; 
        char ans[4]; 
        for(int i=3; i>=0; i--){ 
                if(a[i]>='A'){ 
                sum+= a[i]-65+10; 
                } 
                else{ 
                sum+=a[i]-48; 
                } 
                if(b[i]>='A'){ 
                sum+= b[i]-65+10; 
                } 
                else{ 
                sum+=b[i]-48; 
                } 
                sum+=carry; 
                carry = sum/16; 
                sum %= 16; 
                if(sum>=10){ 
                ans[i]= 55+sum; 
                } else{ 
                ans[i]= sum+48; 
                } 
                sum=0; 
        } 
        
        //wrapping around the final carry 
        string final=""; 
        if(carry){ 
                for(int i=3; i>=0; i--){ 
                    if(ans[i]>='A'){ 
                    sum+= ans[i]-55 ; 
                    } 
                    else{ 
                    sum+= ans[i]-48; 
                    } 
                    sum+=carry; 
                    carry = sum/16;
                    sum %= 16; 
                    if(sum>=10){ 
                    final+= sum+55; 
                    } 
                    else{ 
                    final+= sum+48; 
                    } 
                    sum=0; 
                } 
                reverse(final.begin(), final.end()); 
        } 
        else{ 
               final = ans; 
        } 
        return final; 
} 
int main(){ 
        string s, checksum; 
        cout << "Enter the data string: "; 
        cin >> s; 
        cout << "Enter the Checksum: "; 
        cin >> checksum; 

        //converting every 2 chars of input string to hex string 
        hex(s, a, 0); hex(s, b, 2); hex(s, c, 4); hex(s, d, 6);

        //adding first two strings 
        string sum1= add(a,b); 
        
        //adding 3rd and 4th string 
        string sum2= add(c,d); 
        
        //adding the sum1 and sum2 
        string data= add(sum1, sum2); 
        
        //adding final datasum to checksum 
        string ans = add(data,checksum); 
        
        //taking complement of data + checksum 
        string complement= comp(ans); 
        
        //if complement of data+checksum = "0000", then no error 
        for(int i=0;i<4;i++){ 
            if(complement[i]!='0'){ 
                cout << "Error detected!"; 
                return 0; 
            } 
        } 
        cout << "No Error detected"; 
        return 0; 
} 