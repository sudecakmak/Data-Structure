// Sude Çakmak
// 152120201044

#include "WordFreq.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <string>
#include <algorithm> 

#define Height(p) ((p) == NULL? -1:(p)->height)

using namespace std;

struct AVLNode {
	WordFreq *key;
	int height;
	AVLNode *right;
	AVLNode *left;

	AVLNode(WordFreq *key) {
		this->key = key;
		key->freq = 1;
		left = right = NULL;
		height = 0;
	}
};

vector<WordFreq> GetMostFrequentKWords(string filename, int k) {

	vector<WordFreq> result;
	vector<WordFreq*> arr;
	AVLNode* root = NULL;
	fstream file;
	string word;
	int most_freq = 1;
	bool notword = false, already = false;

	file.open(filename);

	while (file >> word) {

		for (int j = 0; j < word.length(); j++)
			word[j] = tolower(word[j]);

		int l = 0;
		for (int i = 0; i < word.length(); i++) {

			if (word[i] >= 'a' && word[i] <= 'z') {

				word[l] = word[i];
				l++;
			}
		}
		word.erase(l);

		if (word.length() < 3)
			notword = true;
		else
			notword = false;

		if (!notword) {

			WordFreq * w = new WordFreq(word);
			stack <AVLNode*> S;

			// AVL tree
			AVLNode *q = NULL;
			AVLNode *p = root;

			while (p) {

				S.push(p);
				q = p;

				if (p->key->word == w->word) {

					p->key->freq = p->key->freq++;

					if (p->key->freq > most_freq) { most_freq = p->key->freq; }

					already = true;
					break;
				}
				else if (w->word < p->key->word) { p = p->left; already = false; }
				else if (w->word > p->key->word) { p = p->right; already = false; }
			}

			if (!already) {

				arr.push_back(w);
				AVLNode * node = new AVLNode(w);
				if (root == NULL) root = node;
				else if (w->word < q->key->word) q->left = node;
				else if (w->word > q->key->word)  q->right = node;
			}

			// Balance
			while (!S.empty()) {

				AVLNode* p = S.top(); S.pop();
				AVLNode* parent = NULL;

				int hl = Height(p->left);
				int hr = Height(p->right);

				p->height = 1 + max(hl, hr);

				int balance_factor = hl - hr;
				if (balance_factor >= -1 && balance_factor <= 1) continue;

				if (!S.empty()) parent = S.top();

				if (balance_factor == 2) {

					AVLNode* l = p->left;

					hl = Height(l->left);
					hr = Height(l->right);
					balance_factor = hl - hr;

					if (balance_factor == 0 || balance_factor == 1) {

						p->left = l->right;
						l->right = p;

						p->height = 1 + max(Height(p->left), Height(p->right));
						l->height = 1 + max(Height(l->left), Height(l->right));

						if (parent == NULL)
							root = l;
						else
						{
							if (p == parent->left) parent->left = l;
							else parent->right = l;
						}

					}
					else {

						AVLNode* x = l->right;

						l->right = x->left;
						x->left = l;

						p->left = x->right;
						x->right = p;

						p->height = 1 + max(Height(p->left), Height(p->right));
						l->height = 1 + max(Height(l->left), Height(l->right));
						x->height = 1 + max(Height(x->left), Height(x->right));

						if (parent == NULL)
							root = x;
						else
						{
							if (p == parent->left) parent->left = x;
							else parent->right = x;
						}
					}
				}
				else {

					AVLNode* r = p->right;

					hl = Height(r->left);
					hr = Height(r->right);
					balance_factor = hl - hr;

					if (balance_factor == 0 || balance_factor == -1) {

						p->right = r->left;
						r->left = p;

						p->height = 1 + max(Height(p->left), Height(p->right));
						r->height = 1 + max(Height(r->left), Height(r->right));

						if (parent == NULL)
							root = r;
						else
						{
							if (p == parent->left) parent->left = r;
							else parent->right = r;
						}
					}
					else {

						AVLNode* x = r->left;

						r->left = x->right;
						x->right = r;

						p->right = x->left;
						x->left = p;

						p->height = 1 + max(Height(p->left), Height(p->right));
						r->height = 1 + max(Height(r->left), Height(r->right));
						x->height = 1 + max(Height(x->left), Height(x->right));

						if (parent == NULL)
							root = x;
						else
						{
							if (p == parent->left) parent->left = x;
							else parent->right = x;
						}
					}
				}
			}
		}
	}

	file.close();

	vector<vector<string>> words(most_freq + 1);

	for (int i = 0; i < arr.size(); i++)
	{
		words[arr[i]->freq].push_back(arr[i]->word);
	}

	for (int i = 0; i < words.size(); i++)
	{
		sort(words[i].begin(), words[i].end());
	}

	int counter = 0;

	for (int i = (words.size() - 1); i > 0; i--)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			string str;
			str = words[i][j];

			WordFreq f = WordFreq(str);
			f.freq = i;

			result.push_back(f);
			counter++;

			if (counter == k) { break; }
		}
		if (counter == k) { break; }
	}

	return result;
}