#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//* Decode String
string decodeString(string s)
{
  stack<string> st;

  for (auto ch : s)
  {
    if (ch == ']')
    {
      string stringToRepeat = "";
      while (!st.empty() && st.top() != "[")
      {
        string top = st.top();
        stringToRepeat += top;
        st.pop();
      }
      st.pop();
      string numericTimes = "";
      while (!st.empty() && isdigit(st.top()[0]))
      {
        numericTimes += st.top();
        st.pop();
      }
      reverse(numericTimes.begin(), numericTimes.end());

      int n = stoi(numericTimes);

      // final decoding
      string currentDecode = "";
      while (n--)
      {
        currentDecode += stringToRepeat;
      }
      st.push(currentDecode);
    }
    else
    {
      string temp(1, ch);
      st.push(temp);
    }
  }

  string ans;
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string s = "3[a]2[bc]";
  cout << decodeString(s);
  return 0;
}