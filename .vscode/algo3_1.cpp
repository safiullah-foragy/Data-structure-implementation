#include <bits/stdc++.h>
using namespace std;

void removeChar(char *s, char c)
{

    int j, n = strlen(s);
    for (int i = j = 0; i < n; i++)
    {
        if (s[i] != c)
            s[j++] = s[i]; 
    }
       

    s[j] = '\0';
}

int main()
{
    char s[] = "geeksforgeeks";
    removeChar(s, 'a');
    cout << s;
    return 0;
}