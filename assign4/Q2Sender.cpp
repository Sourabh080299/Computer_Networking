#include <bits/stdc++.h> 
using namespace std; 
string s, a="", b="", c="", d="";   

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
                    p+= temp+48; 
                } 
                c = c/16; 
            } 

            reverse(p.begin(), p.end()); 
            a += p; 
            p=""; 
        } 
        return a; 
} 
string sum(string s, string a, string b, string c, string d){ 
        int j=0, sum=0, carry=0; 
        char ans[4]; 
        
        //converting every 2bits of character string to hex string
        hex(s, a, 0); 
        hex(s, b, 2); 
        hex(s, c, 4);
        hex(s, d, 6); 

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
                
                if(c[i]>='A'){ 
                    sum+= c[i]-65+10; 
                } 
                else{ 
                    sum+=c[i]-48; 
                } 


                if(d[i]>='A'){ 
                    sum+= d[i]-65+10; 
                } 
                else{ 
                    sum+=d[i]-48; 
                } 


                sum+=carry; 
                carry = sum/16; 
                sum %= 16; 


                if(sum>=10){ 
                    ans[i]= 55+sum; 
                } 
                else{ 
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
        //returning complemented value of the final sum to obtain the checksum 
        return comp(final); 
} 


int main(){ 
cout << "Input String: "; 
cin >> s; 
cout << "Checksum: "<<sum(s,a,b,c,d); 
return 0; 
}