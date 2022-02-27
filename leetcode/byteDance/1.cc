#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int N;
	cin >> N;
	stack<char> q;
	vector<int> po;
	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		q.push(s[0]);
		for(int j = 1; j < s.size(); ++j){
			if(s[j] == q.top()){
				q.push(s[j]);
				if(q.size() == 3 || q.size() == 4){
					po.push_back(j);
					q.pop();
				}
			}
			else{
				if(q.size() == 2)
					q.push(s[j]);
				else{
					while (!q.empty())
						q.pop();
					q.push(s[j]);
				}
			}
		}
        while (!q.empty())
			q.pop();
		cout << po.size() << endl;
		for(int x = (int)po.size()-1; x >=0; --x)
			s.erase(po[x]);
		cout << s << endl;
	}
}
