#include <bits/stdc++.h>
using namespace std;
int encrypt_or_decrypt()
{
    int num;
    while(true)
    {
        cout<<"Choose the number whether you want to encrypt or decrypt."<<endl;
        cout<<"1. Encrypt"<<endl;
        cout<<"2. Decrypt"<<endl;
        cin>>num;
        if(num==1 || num==2)return num;
        cout<<"Invalid Choice, please enter 1 or 2"<<endl;
    }
}
string valid_string(int num)
{
    string e;
    while(true)
    {
        if(num==1)cout<<"Enter the string you want to encrypt"<<endl;
        else if(num==2)cout<<"Enter the string you want to decrypt"<<endl;
        cin.ignore();
        getline(cin,e);
        bool can=true;
        for(auto &x:e)
        {
            if(x==' ')continue;
            if(!isalpha(x))
            {
                can=false;
                break;
            }
        }
        if(can)return e;
        cout<<"Invalid string, please enter letters only"<<endl;
    }
}
void substitution()
{
    string test;
    while(true)
    {
        cout<<"Enter they key ( 26 letters corresponding for each letter )"<<endl;
        cin.ignore();
        getline(cin,test);
        for(auto &x:test)x=tolower(x);
        multiset<char> st;
        for(auto x:test)if(x>='a' && x<='z')st.insert(x);
        if(st.size()==26)break;
        cout<<"Invalid key, please enter valid 26 letters"<<endl;
    }
    string key="";
    for(auto x:test)if(x!=' ')key+=x;
    map<char,char> toenc;
    map<char,char> todec;
    for(int i=0;i<26;i++)
    {
        toenc['a'+i]=key[i];
        toenc['A'+i]=toupper(key[i]);
        todec[key[i]]='a'+i;
        todec[toupper(key[i])]='A'+i;
    }
    toenc[' ']=' ';
    todec[' ']=' ';
    int num=encrypt_or_decrypt();
    if(num==1)
    {
        string e=valid_string(1);
        for(auto x:e)cout<<toenc[x];
        cout<<endl;
    }
    else if(num==2)
    {
        string e=valid_string(2);
        for(auto x:e)cout<<todec[x];
        cout<<endl;
    }
}
void caesar()
{
    string key;
    while(true)
    {
        cout<<"Enter the shift value"<<endl;
        cin>>key;
        bool can=true;
        for(auto &x:key)
        {
            if(!isdigit(x))
            {
                can=false;
                break;
            }
        }
        if(can)break;
        cout<<"Invalid value, please enter digits only"<<endl;
    }
    int k=stoll(key);
    map<char,char> toenc;
    map<char,char> todec;
    for(int i=0;i<26;i++)
    {
        toenc['a'+i]='a'+(i+k)%26;
        toenc['A'+i]='A'+(i+k)%26;
        todec['a'+(i+k)%26]='a'+i;
        todec['A'+(i+k)%26]='A'+i;
    }
    toenc[' ']=' ';
    todec[' ']=' ';
    int num=encrypt_or_decrypt();
    if(num==1)
    {
        string e=valid_string(1);
        for(auto x:e)cout<<toenc[x];
        cout<<endl;
    }
    else if(num==2)
    {
        string e=valid_string(2);
        for(auto x:e)cout<<todec[x];
        cout<<endl;
    }
}
void vigenere()
{
    string test;
    while(true)
    {
        cout<<"Enter the key"<<endl;
        cin.ignore();
        getline(cin,test);
        for(auto &x:test)x=tolower(x);
        bool can=true;
        for(auto x:test)
        {
            if(x==' ')continue;
            if(!isalpha(x))
            {
                can=false;
                break;
            }
        }
        if(can)break;
        cout<<"Invalid key, please enter valid letters"<<endl;
    }
    string key="";
    for(auto x:test)if(x!=' ')key+=x;
    for(auto &x:key)x=tolower(x);
    int num=encrypt_or_decrypt();
    if(num==1)
    {
        string e=valid_string(1);
        string origin="";
        for(auto x:e)if(x!=' ')origin+=x;
        while(key.size()<origin.size())key+=key;
        int ptr1=0,ptr2=0;
        while(ptr1<e.size())
        {
            if(e[ptr1]==' ')cout<<" ",ptr1++;
            else
            {
                int diff=0;
                if(e[ptr1]<='Z' && e[ptr1]>='A')diff=e[ptr1]-'A';
                else diff=e[ptr1]-'a';
                char x='a'+(diff+key[ptr2]-'a')%26;
                if(e[ptr1]<='Z' && e[ptr1]>='A')x=toupper(x);
                cout<<x;
                ptr1++;
                ptr2++;
            }
        }
        cout<<endl;
    }
    else if(num==2)
    {
        string e=valid_string(2);
        string origin="";
        for(auto x:e)if(x!=' ')origin+=x;
        while(key.size()<origin.size())key+=key;
        int ptr1=0,ptr2=0;
        while(ptr1<e.size())
        {
            if(e[ptr1]==' ')cout<<" ",ptr1++;
            else
            {
                int diff=0;
                if(e[ptr1]<='Z' && e[ptr1]>='A')diff=e[ptr1]-'A';
                else diff=e[ptr1]-'a';
                char x='a'+(diff-(key[ptr2]-'a')+26)%26;
                if(e[ptr1]<='Z' && e[ptr1]>='A')x=toupper(x);
                cout<<x;
                ptr1++;
                ptr2++;
            }
        }
        cout<<endl;
    }
}
void rowtransposition()
{
    string a,b;
    while(true)
    {
        cout<<"Enter the rows and columns of the matrix"<<endl;
        cin>>a>>b;
        bool can=true;
        for(auto &x:a)
        {
            if(!isdigit(x))
            {
                can=false;
                break;
            }
        }
        for(auto &x:b)
        {
            if(!isdigit(x))
            {
                can=false;
                break;
            }
        }
        if(can)break;
        cout<<"Invalid value, please enter digits only"<<endl;
    }
    int rows=stoll(a);
    int columns=stoll(b);
    set<int> s;
    vector<int> perm;
    vector<int> invperm(columns+1);
    while(true)
    {
        cout<<"Enter a valid permutation of the columns"<<endl;
        bool can=true;
        perm.clear();
        s.clear();
        perm.push_back(0);
        for(int i=1;i<=columns;i++)
        {
            int x;
            cin>>x;
            perm.push_back(x);
            s.insert(x);
            if(x<1 || x>columns)can=false;
        }
        if(s.size()!=columns || !can)cout<<"Please enter "<<columns<<" numbers between 1 and "<<columns<<endl;
        else break;
    }
    for(int i=1;i<=columns;i++)invperm[perm[i]]=i;
    int num=encrypt_or_decrypt();
    if(num==1)
    {
        string e=valid_string(1);
        string origin=" ";
        for(auto x:e)if(x!=' ')origin+=x;
        while(origin.size()<=rows*columns)origin+="*";
        set<pair<int,string>> toprint;
        for(int i=1;i<=columns;i++)
        {
            int x=perm[i];
            string r="";
            for(int j=i;j<origin.size();j+=columns)r+=origin[j];
            toprint.insert({perm[i],r});
        }
        for(auto x:toprint)cout<<x.second<<" ";
        cout<<endl;
    }
    else if(num==2)
    {
        string e;
        while(true)
        {
            cout<<"Enter the string you want to decrypt ( enter * for empty characters )"<<endl;
            cin.ignore();
            getline(cin,e);
            bool can=true;
            for(auto &x:e)
            {
                if(x==' ')continue;
                if(!isalpha(x) && (x!='*'))
                {
                    can=false;
                    break;
                }
            }
            if(can)break;
            cout<<"Invalid string, don't enter numbers please"<<endl;
        }
        string origin=" ";
        for(auto x:e)if(x!=' ')origin+=x;
        while(origin.size()<=rows*columns)origin+="*";
        string ans[columns+1];
        int ptr=1;
        for(int i=1;i<=columns;i++)
        {
            for(int j=1;j<=rows;j++)
            {
                ans[i]+=origin[ptr];
                ptr++;
            }
        }
        vector<pair<int,string>> toenc;
        toenc.push_back({0,""});
        for(int i=1;i<=columns;i++)toenc.push_back({invperm[i],ans[i]});
        sort(toenc.begin(),toenc.end());
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=columns;j++)
            {
                cout<<toenc[j].second[i-1]<<" ";
            }
        }
        cout<<endl;
    }
}
void playfair()
{
    string test;
    while(true)
    {
        cout<<"Enter the key"<<endl;
        cin.ignore();
        getline(cin,test);
        for(auto &x:test)x=tolower(x);
        bool can=true;
        for(auto x:test)
        {
            if(x==' ')continue;
            if(!isalpha(x))
            {
                can=false;
                break;
            }
        }
        if(can)break;
        cout<<"Invalid key, please enter distinct and valid letters"<<endl;
    }
    string key="";
    for(auto x:test)if(x!=' ')key+=x;
    for(auto &x:key)x=tolower(x);
    for(auto &x:key)if(x=='j')x='i';
    set<char> st;
    for(char a='a';a<='z';a++)
    {
        if(a=='j')continue;
        st.insert(a);
    }
    char mat[5][5];
    int px=0,py=0;
    for(auto x:key)
    {
        if(st.find(x)!=st.end())
        {
            st.erase(st.find(x));
            mat[px][py]=x;
            py++;
            if(py==5)px++,py=0;
        }
    }
    for(auto x:st)
    {
        mat[px][py]=x;
        py++;
        if(py==5)px++,py=0;
    }
    map<char,pair<int,int>>mp;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            mp[mat[i][j]]={i,j};
        }
    }
    int num=encrypt_or_decrypt();
    if(num==1)
    {
        string e;
        while(true)
        {
            cout<<"Enter the string you want to encrypt"<<endl;
            cin.ignore();
            getline(cin,e);
            bool can=true;
            for(auto &x:e)
            {
                if(x==' ')continue;
                if(!isalpha(x))
                {
                    can=false;
                    break;
                }
            }
            if(can)break;
            cout<<"Invalid string, please don't enter numbers"<<endl;
        }
        string origin="";
        for(auto x:e)if(x!=' ')origin+=x;
        int sz=origin.size();
        if(sz%2)origin+="x",sz++;
        string tobe="";
        for(int i=0;i<sz;i++)
        {
            if(i && origin[i]==origin[i-1])tobe+="x";
            tobe+=origin[i];
        }
        int sztobe=tobe.size();
        for(int i=0;i<sztobe-1;i+=2)
        {
            char a1=tolower(tobe[i]);
            char a2=tolower(tobe[i+1]);
            pair<int,int>pos1=mp[a1];
            pair<int,int>pos2=mp[a2];
            if(pos1.first==pos2.first && pos1.second!=pos2.second)
            {
                pos1.second++;
                pos1.second%=5;
                pos2.second++;
                pos2.second%=5;
            }
            else if(pos1.first!=pos2.first && pos1.second==pos2.second)
            {
                pos1.first++;
                pos1.first%=5;
                pos2.first++;
                pos2.first%=5;
            }
            else
            {
                int c1=pos1.second;
                int c2=pos2.second;
                pos1.second=c2;
                pos2.second=c1;
            }
            char x1=mat[pos1.first][pos1.second];
            char x2=mat[pos2.first][pos2.second];
            if(isupper(tobe[i]))x1=toupper(x1);
            if(isupper(tobe[i+1]))x2=toupper(x2);
            cout<<x1<<x2<<" ";
        }
        cout<<endl;
    }
    else if(num==2)
    {
        string e;
        while(true)
        {
            cout<<"Enter the string you want to decrypt"<<endl;
            cin.ignore();
            getline(cin,e);
            bool can=true;
            for(auto &x:e)
            {
                if(x==' ')continue;
                if(!isalpha(x))
                {
                    can=false;
                    break;
                }
            }
            if(can)break;
            cout<<"Invalid string, please don't enter numbers"<<endl;
        }
        string origin="";
        for(auto x:e)if(x!=' ')origin+=x;
        int sz=origin.size();
        if(sz%2)origin+="x",sz++;
        string tobe="";
        for(int i=0;i<sz;i++)tobe+=origin[i];
        int sztobe=tobe.size();
        for(int i=0;i<sztobe-1;i+=2)
        {
            char a1=tolower(tobe[i]);
            char a2=tolower(tobe[i+1]);
            pair<int,int>pos1=mp[a1];
            pair<int,int>pos2=mp[a2];
            if(pos1.first==pos2.first && pos1.second!=pos2.second)
            {
                pos1.second--;
                pos1.second=(pos1.second+5)%5;
                pos2.second--;
                pos2.second=(pos2.second+5)%5;
            }
            else if(pos1.first!=pos2.first && pos1.second==pos2.second)
            {
                pos1.first--;
                pos1.first=(pos1.first+5)%5;
                pos2.first--;
                pos2.first=(pos2.first+5)%5;
            }
            else
            {
                int c1=pos1.second;
                int c2=pos2.second;
                pos1.second=c2;
                pos2.second=c1;
            }
            char x1=mat[pos1.first][pos1.second];
            char x2=mat[pos2.first][pos2.second];
            if(isupper(tobe[i]))x1=toupper(x1);
            if(isupper(tobe[i+1]))x2=toupper(x2);
            cout<<x1<<x2<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    while(true)
    {
        cout<<"Enter the number of the encryption technique you want to use"<<endl;
        cout<<"1. Substitution Cypher"<<endl;
        cout<<"2. Caesar Cypher"<<endl;
        cout<<"3. Vigenere Cypher"<<endl;
        cout<<"4. Transposition Cypher"<<endl;
        cout<<"5. Playfair Cypher"<<endl;
        cout<<"6. End the program"<<endl;
        int type;
        cin>>type;
        if(type==1)substitution();
        else if(type==2)caesar();
        else if(type==3)vigenere();
        else if(type==4)rowtransposition();
        else if(type==5)playfair();
        else if(type==6)exit(0);
        else cout<<"Wrong choice! Try again"<<endl;
    }
}
