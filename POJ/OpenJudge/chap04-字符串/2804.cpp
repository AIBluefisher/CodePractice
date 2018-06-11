#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 30
map<const char*,const char*> dic;
char str[MAXN];
char str1[100010][MAXN],str2[100010][MAXN];
int num = 0;

void split()
{
    int len = strlen(str);
    int i,j = 0;
    for(i = 0; i < len; i++)
    {
        if(str[i] == ' ') break;
        str1[num][i] = str[i];
    }
    str1[num][++i] = '\0';
    for(; i < len; i++)
    {
        str2[num][j++] = str[i];
    }
    str2[num][j] = '\0';
    //dic.insert(make_pair(str2[num],str1[num]));
    dic[str2[num]] = str1[num];
    puts(dic[str2[num]]);
    num++;
}

void solve()
{
    map<const char*,const char*>::iterator ite;
    /*
    for(ite = dic.begin(); ite != dic.end(); ite++)
    {
        printf("%s: %s\n",ite->first,ite->second);
    }
*/
    //puts("solve");
    //ite = dic.find(str);
    //printf("%s\n",ite->first);
    //puts("");
    //printf("%s\n",dic[str]);
}

int main()
{
    freopen("in.txt","r",stdin);
    char b;
    bool flag = false;
    while(gets(str))
    {
        if(strcmp(str,"") == 0)
        {
            flag = true;
            continue;
        }
        if(!flag) split();
        else solve();
    }

}
