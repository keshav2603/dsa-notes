#include <iostream>
using namespace std;
void perm(char s[], int k)
{
    static int a[10] = {0};
    static char res[10];
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perm(s, k + 1);
                a[i] = 0;
            }
        }
    }
}
void perm1(char s[], int l, int h)
{
    if (l == h)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(s[i], s[l]);
            perm1(s, l + 1, h);
            swap(s[i], s[l]);
        }
    }
}
int main()
{
    char s[] = "abc";
    perm(s, 0);
    cout << "\n\n\n\n";
    perm1(s, 0, 2);
    return 0;
}