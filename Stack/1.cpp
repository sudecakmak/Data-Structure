// 152120201044
// Sude ÇAKMAK

#include <string>
#include <stack>

using namespace std;

string Infix2Postfix(string &s) {

	stack<string> a;
	string result;
	string num_s, b = " ";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '(' && s[i] != ')' && s[i] != '/' && s[i] != '*' && s[i] != '+' && s[i] != '-' && s[i] != ' ')
		{

			while (s[i] != '(' && s[i] != ')' && s[i] != '/' && s[i] != '*' && s[i] != '+' && s[i] != '-' && s[i] != ' ' && s[i] != 0)
			{
				num_s += s[i];
				i++;
			}

			result += num_s;
			result += b;
		}
		if (s[i] == '(')
		{
			num_s = s[i];
			a.push(num_s);
		}
		if (s[i] == ')')
		{
			while (1)
			{
				if (a.top() == "(")
				{
					a.pop();
					break;
				}

				num_s = a.top();
				result += num_s;
				result += b;
				a.pop();
			}
		}
		if (s[i] == '+' || s[i] == '-')
		{
			if (a.size() > 0)
			{
				if (a.top() == "*" || a.top() == "/" || a.top() == "+" || a.top() == "-")
				{
					while (1)
					{
						num_s = a.top();
						result += num_s;
						result += b;
						a.pop();

						if (a.empty())
						{
							break;
						}

						if (a.top() == "(")
						{
							break;
						}
					}

					num_s = s[i];
					a.push(num_s);
				}
				else
				{
					num_s = s[i];
					a.push(num_s);
				}
			}
			else
			{
				num_s = s[i];
				a.push(num_s);
			}
		}
		if (s[i] == '*' || s[i] == '/')
		{
			if (a.empty())
			{
				num_s = s[i];
				a.push(num_s);
			}
			else if (a.top() == "+" || a.top() == "-" || a.top() == "(")
			{
				num_s = s[i];
				a.push(num_s);
			}
			else
			{
				while (1)
				{
					num_s = a.top();
					result += num_s;
					result += b;
					a.pop();

					if (a.empty())
					{
						break;
					}

					if (a.top() == "+" || a.top() == "-" || a.top() == "(")
					{
						break;
					}
				}

				num_s = s[i];
				a.push(num_s);
			}

		}


		num_s.clear();
	}

	if (!a.empty())
	{
		while (1)
		{
			num_s = a.top();
			result += num_s;
			result += b;
			a.pop();

			if (a.empty())
				break;
		}
	}

	return result;
}


int EvaluatePostfixExpression(string& s) {

	stack<int> b;
	double n1 = 0, n2 = 0, num;
	string int_s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '(' && s[i] != ')' && s[i] != '/' && s[i] != '*' && s[i] != '+' && s[i] != '-')
		{
			while (s[i] != ' ')
			{
				int_s += s[i];
				i++;
			}

			num = stoi(int_s);
			b.push(num);

			int_s.clear();

		}
		else if (s[i] == '*')
		{
			i++;
			n1 = b.top();
			b.pop();
			n2 = b.top();
			b.pop();

			b.push(n1*n2);
		}
		else if (s[i] == '+')
		{
			i++;
			n1 = b.top();
			b.pop();
			n2 = b.top();
			b.pop();

			b.push(n1 + n2);
		}
		else if (s[i] == '/')
		{
			i++;
			n1 = b.top();
			b.pop();
			n2 = b.top();
			b.pop();

			b.push(n2 / n1);
		}
		else if (s[i] == '-')
		{
			i++;
			n1 = b.top();
			b.pop();
			n2 = b.top();
			b.pop();

			b.push(n2 - n1);
		}

	}

	return b.top();
}