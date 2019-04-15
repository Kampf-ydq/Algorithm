#include <iostream>
#include <string>
using namespace std;
     
int main()  
{      
    int i;      
    string str;      
    getline(cin,str);      
    int max=0;      
    int ch[3][26]={0};         
    for(i=0; i<str.size(); i++)      
    {          
        if(str[i]>='A' && str[i]<='Z')         
        {              
            ch[0][str[i]-'A']++;              
            if(max<ch[0][str[i]-'A'])                  
            max=ch[0][str[i]-'A'];          
        }    
        else if(str[i]>='a' && str[i]<='z')          
        {              
            ch[1][str[i]-'a']++;              
            if(max<ch[1][str[i]-'a'])                  
            max=ch[1][str[i]-'a'];            
        }          
        else if (str[i]>='0' && str[i]<='9')          
        {              
            ch[2][str[i]-'0']++;              
            if(max<ch[2][str[i]-'0'])                  
            max=ch[2][str[i]-'0'];            
        }      
    }      
    cout<<max<<endl;      
    while(max--)      
    {          
        for(i=0; i<26; i++)          
        {              
            //cout<<char('A'+i)<<char('a'+i)<<char('0'+i);              
            if(ch[2][i])              
            {                  
                cout<<char('0'+i);                  
                --ch[2][i];              
            }                 
            if(ch[0][i])              
            {                  
                cout<<char('A'+i);                  
                --ch[0][i];              
            }              
            if(ch[1][i])              
            {                  
                cout<<char('a'+i);                  
                --ch[1][i];              
            }             
        }          
        //max--;      
    }      
    return 0;  
}  

