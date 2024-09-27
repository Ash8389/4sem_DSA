bool ispar(string x)
{
    // Your code here
    stack<char> Stack;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
        {
            Stack.push(x[i]);
        }
        else
        {
            if (Stack.empty())
            {
                return false;
            }
            char ch = Stack.top();
            Stack.pop();

            if ((ch == '(' && x[i] != ')') || (ch == '{' && x[i] != '}') || (ch == '[' && x[i] != ']'))
            {
                return false;
            }
        }
    }
    if (!Stack.empty())
    {
        return false;
    }

    return true;
}