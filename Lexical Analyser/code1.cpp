#include<iostream>
#include<cstring>
#include<ctype.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

string key[]={"void","using","int","include","namespace","iostream","std","main","cin","cout","return","float","double","string"};

bool iskeyword(string k)
{
    for(int i=0;i<14;i++)
    {
        if(key[i]==k)
        {
            return true;
        }
    }
    return false;
}


int main(){
    fstream file;
    string s,filename;

    filename = "./program.txt";

    file.open(filename.c_str());

    while(file>>s)
    {
        if(s=="+" || s=="-" || s=="" || s=="/" || s=="^" || s=="&&" || s=="||" || s=="=" || s=="==" || s=="&" || s=="|" || s=="%" || s=="++" || s=="--" || s=="+=" || s=="-=" || s=="/=" || s=="=" || s=="%=")
        {
            cout<<s<<" is an opertaor"<<endl;
            s="";
        }
        else if(iskeyword(s))
        {
            cout<<s<<" is a keyword"<<endl;
            s="";

        }
        else if(s=="(" || s=="{" || s=="[" || s==")" || s=="}" || s=="]" || s=="<" || s==">" || s=="()" || s==";" || s=="<<" || s==">>" || s=="," || s=="#")
        {
            cout<<s<<" is a symbol"<<endl;
            s="";
        }
        else if(s=="\n" || s==" " || s==" ")
        {
            s="";
        }
        else if(isdigit (s[0]))
        {
            int x=0;
            if(!isdigit (s[x++]))
            {
                continue;
            }
            else{
                cout<<s<<" is a constant"<<endl;
                s="";
            }
        }
        else{
            cout<<s<<" is an identifier"<<endl;
            s="";
        }
    }

    return 0;
}
