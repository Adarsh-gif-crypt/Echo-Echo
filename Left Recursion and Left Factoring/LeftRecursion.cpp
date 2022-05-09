#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter number of non terminals: ";
    cin>>n;
    cout<<"\nEnter non terminals one by one --> \n ------------------- ";
    int i;
    vector<string> nonterminal(n);
    vector<int> leftrecr(n,0);
    for(i=0;i<n;++i) {
            cout<<"\nNon terminal "<<i+1<<" : ";
        cin>>nonterminal[i];
    }
    vector<vector<string> > prod;
    cout<<"\nEnter 'esp' for null";
    for(i=0;i<n;++i) {
        cout<<"\nNumber of productions for "<<nonterminal[i]<<" : ";
        int k;
        cin>>k;
        int j;
        cout<<"\nOne by one enter all "<<nonterminal[i]<<" productions";
        vector<string> temp(k);
        for(j=0;j<k;++j) {
            cout<<"\nRHS of production "<<j+1<<": ";
            string abc;
            cin>>abc;
            temp[j]=abc;
            if(nonterminal[i].length()<=abc.length()&&nonterminal[i].compare(abc.substr(0,nonterminal[i].length()))==0)
                leftrecr[i]=1;
        }
        prod.push_back(temp);
    }
    for(i=0;i<n;++i) {
        cout<<leftrecr[i];
    }
    for(i=0;i<n;++i) {
        if(leftrecr[i]==0)
            continue;
        int j;
        nonterminal.push_back(nonterminal[i]+"'");
        vector<string> temp;
        for(j=0;j<prod[i].size();++j) {
            if(nonterminal[i].length()<=prod[i][j].length()&&nonterminal[i].compare(prod[i][j].substr(0,nonterminal[i].length()))==0) {
                string abc=prod[i][j].substr(nonterminal[i].length(),prod[i][j].length()-nonterminal[i].length())+nonterminal[i]+"'";
                temp.push_back(abc);
                prod[i].erase(prod[i].begin()+j);
                --j;
            }
            else {
                prod[i][j]+=nonterminal[i]+"'";
            }
        }
        temp.push_back("esp");
        prod.push_back(temp);
    }
    cout<<"\n\n";
    cout<<"\nNew set of non-terminals: ";
    for(i=0;i<nonterminal.size();++i)
        cout<<nonterminal[i]<<" ";
    cout<<"\n\nNew set of productions: ";
    for(i=0;i<nonterminal.size();++i) {
        int j;
        for(j=0;j<prod[i].size();++j) {
            cout<<"\n"<<nonterminal[i]<<" -> "<<prod[i][j];
        }
    }
    return 0;
}
