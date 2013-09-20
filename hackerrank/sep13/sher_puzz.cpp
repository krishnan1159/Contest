#include<iostream>
#include<queue>
#include<string>
#include<stack>
using namespace std;

typedef struct zeros
{
	int ei,cnt;
}Z;

typedef struct ones
{
	int si,ei,zero,one;
}O;

stack<Z> z;
stack<O> o;

void merge()
{
	if( o.size() <= 1 )
		return;

	O& top = o.top();
	o.pop();
	O& sec = o.top();
	if( sec.ei + 1 == top.si ) // Consecutive Ones
	{
		sec.ei = top.ei;
		sec.one += top.one;
		sec.zero += top.zero;
		merge();
	}
	else
		o.push(top);

	if( z.size() > 0 && z.top().ei+1 == top.si )
	{
		int rem = (top.one*3 - top.zero*2)/2;
		if( rem > 0 )
		{
			if( z.top().cnt <= rem )
			{
				top.zero += z.top().cnt;
				z.pop();
			}
			else
			{
				z.top().cnt -= rem;
				top.zero += rem;
			}
		}
		merge();
	}
}

int main()
{
	string s;
	int k;
	cin>>s>>k;
	while(o.size() > 0)
		o.pop();
	while( z.size()  > 0)
		z.pop();

	for(int i=0;i<s.size();i++)
	{
		if( s[i] == '0' )
		{
			if( o.empty() || ( (o.top().zero + 1)*2 > (o.top().one*3) ) ) // When One's are empty (or) when the top stack can't accomadate this zero
			{
				if( z.empty() || (z.top().ei+1 != i ) ) // Pushing a new value into the zero stack
				{
					Z temp;
					temp.ei = i;
					temp.cnt = 0;
					z.push(temp);
				}
				else
				{
					z.top().ei = i;
					z.top().cnt++;
				}

			}
			else
			{
				o.top().zero++;
				o.top().ei = i;
			}

		}
		else
		{
			O temp;
			temp.si = i;
			temp.ei = i;
			temp.zero = 0;
			temp.one = 1;
			o.push(temp);
			merge();
		}
	}

	
}
