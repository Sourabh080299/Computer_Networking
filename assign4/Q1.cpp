#include <bits/stdc++.h>
using namespace std;
int main(){ 
        string data, key, ans="";
        cout << "Enter the dataword: "; 
        cin >> data; 
        int len1= data.length(); 
        
        cout << "Enter the key: "; 
        cin >> key; 

        int len2= key.length();


        //appending zeroes to dataword 
        for(int i=0; i<len2-1; i++){ 
             data += "0"; 
        } 

        string temp2 = ""; 

        for(int i=0; i<len2; i++){ 
             temp2 += "0"; 
        } 
        string temp1 = data.substr(0, len2); 
        
        //sender side 
        int c=len2; 
        while(c!= len1+len2){ 
            if(temp1[0] == '1'){ 
                for(int i=0;i<len2;i++){ 
                    if(temp1[i]==key[i]){ 
                        ans += "0"; 
                    } 
                    else{ 
                        ans += "1"; 
                    } 
                } 
                ans.erase(ans.begin()); 
                temp1= ans + data[c++]; 
                if(c!=len1+len2){ 
                    ans=""; 
                } 
            } 
            else { 
                for(int i=0;i<len2;i++){ 
                    if(temp1[i]==temp2[i]){ 
                       ans += "0"; 
                    } 
                    else{ 
                       ans += "1"; 
                    } 
                } 
                ans.erase(ans.begin()); 
                temp1=ans + data[c++]; 
                if(c!=len1+len2){ 
                    ans=""; 
                } 
            } 
        } 
        string code = data.substr(0,len1) + ans; 
        cout << "Codeword to be sent: " << code << endl;

        //receiver side
        temp1 = code.substr(0, len2); 
        c=len2; 
        ans= ""; 

        while(c!= len1+len2){
            if(temp1[0] == '1'){ 
                for(int i=0;i<len2;i++){ 
                    if(temp1[i]==key[i]){ 
                       ans += "0"; 
                    } 
                    else{ 
                       ans += "1"; 
                    } 
                } 
                ans.erase(ans.begin()); 
                temp1= ans + code[c++]; 
                if(c!=len1+len2){ 
                   ans=""; 
                } 
            } 
            else { 
            for(int i=0;i<len2;i++){ 
                if(temp1[i]==temp2[i]){ 
                  ans += "0"; 
                } 
                else{ 
                  ans += "1"; 
                } 
            } 
            ans.erase(ans.begin()); 
            temp1=ans + code[c++]; 
            if(c!=len1+len2){ 
                ans=""; 
            } 
            } 
        } 
        if(ans == temp2.substr(0,len2-1)){ 
            cout<< "No error"; 
        } 
        return 0; 
} 