#include <iostream>
#include <vector>
using namespace std;
class Trie {
private:
	char val;
	vector<Trie*> children;
	bool isEnd;

	void dfs_insert(string& word, int po, Trie* r){
		if(po == word.size()){
			r->isEnd = true;
			return;
		}
		for(auto& n : r->children)
			if(n->val == word[po])
				return dfs_insert(word, po+1, n);
		// add the rest string 
		while(po != word.size()){
			auto n = new Trie(word[po++]);
			r -> children.push_back(n);
			r = n;
		}
		r->isEnd = true;
		return;
	}

	bool dfs_search(string& word, int po, Trie* r, bool startsWith = false){
		if(po == word.size())
			return startsWith || r->isEnd == true;
		for(auto& n : r->children)
			if(n->val == word[po])
				return dfs_search(word,po+1,n, startsWith);
		return false;
	}
public:
	Trie(char v = '*', bool f = false): val(v), isEnd(f) {}
	
	void insert(string word) {
		dfs_insert(word,0,this);
	}
	
	bool search(string word) {
		return dfs_search(word,0,this);
	}
	
	bool startsWith(string prefix) {
		return dfs_search(prefix,0,this,true);	
	}
};

int main(){
	auto t = new Trie;
	t->insert("hello");
	t->insert("hel");
	t->insert("world");
	if(t->search("hell"))
		cout<<"13"<<endl;
	if(t->startsWith("hell"))
		cout<<"13"<<endl;
}
