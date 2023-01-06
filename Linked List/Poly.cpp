// Sude Çakmak
// 152120201044

#include <iostream>  
#include <string>
#include <algorithm>
#include <vector>  
#include <sstream>  
#include "Poly.h"

using namespace std;

PolyNode *CreatePoly(char *expr) {

	PolyNode * head = NULL;
	PolyNode * p = head;

	double coef;
	int exp;
	int i = 0, k, l = 0, h = 0;
	bool strcoef = false;
	bool fin = false, findt = true;

	string s, exp_s = "nnnnnnnn", coef_s = "nnnnnnnnn";

	while (expr[i] != 0)
	{
		s += expr[i];
		++i;
	}

	s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

	stringstream X(s);

	i = 0;

	if (i == 0)
	{
		if (s[0] == 'x')
		{
			coef = 1;
			strcoef = true;
		}
		else if (s[0] == '-' && s[1] == 'x')
		{
			coef = -1;
			i++;
			strcoef = true;
		}
	}

	while (s[i] != 0)
	{
		if (p == NULL)
		{
			p = new PolyNode;
			head = p;
		}
		else
		{
			p->next = new PolyNode;
			p = p->next;
		}

		k = 0;

		while (s[i] != 'x')
		{
			strcoef = false;
			coef_s[k] = s[i];
			i++;
			k++;

			if (s[i] == 0)
			{
				fin = true;
				break;
			}
		}

		if (coef_s[0] == '+' && coef_s[1] == 'n')
		{
			coef = 1;
			strcoef = true;
		}
		if (coef_s[0] == '-' && coef_s[1] == 'n')
		{
			coef = -1;
			strcoef = true;
		}

		if (coef_s[0] == '+' && coef_s[1] == 0)
		{
			coef = 1;
			strcoef = true;
		}
		if (coef_s[0] == '-' && coef_s[1] == 0)
		{
			coef = -1;
			strcoef = true;
		}


		if (strcoef == false)
		{
			coef = stod(coef_s);

			h = 0;

			while (coef_s[h] != 0)
			{
				coef_s[h] = '\0';
				h++;
			}

			p->coef = coef;
		}
		else
		{
			p->coef = coef;
		}

		k = 0;

		while (s[i] != '+' && s[i] != '-')
		{
			findt = true;

			if (s[i] != '^' && s[i] != 'x')
			{
				findt = false;
				exp_s[k] = s[i];
				k++;
			}

			if (s[i] == 0)
				break;

			i++;

			if (s[i] == 0)
				break;

		}


		if (findt)
		{
			exp = 1;
			p->exp = exp;
		}
		else
		{
			if (fin == false)
			{
				exp = stoi(exp_s);

				h = 0;

				while (exp_s[h] != 0)
				{
					exp_s[h] = '\0';
					h++;
				}

				p->exp = exp;
			}
			else
			{
				exp = 0;
				p->exp = exp;
			}
		}
	}

	p->next = NULL;

	PolyNode *p1, *p2;
	p1 = p2 = head;

	while (p1->next != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL)
		{
			if (p1->exp < p2->exp)
			{
				coef = p1->coef;
				exp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = coef;
				p2->exp = exp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	return head;
}


void DeletePoly(PolyNode* poly) {

	PolyNode* temp = new PolyNode();

	while (poly != NULL) {
		temp = poly;
		poly = poly->next;

		free(temp);
	}

	poly = NULL;
}


PolyNode* AddNode(PolyNode *head, double coef, int exp) {

	PolyNode* node = new PolyNode();
	PolyNode* q = head;
	PolyNode* p1 = NULL, *p2 = NULL, *prev = NULL;

	node->coef = coef;
	node->exp = exp;
	node->next = NULL;

	if (q == NULL)
	{
		node->next = head;
		head = node;
	}
	else
	{
		node->next = q->next;
		q->next = node;
	}


	p1 = p2 = head;

	while (p1->next != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL)
		{
			if (p1->exp < p2->exp)
			{
				coef = p1->coef;
				exp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = coef;
				p2->exp = exp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}


	p1 = head;
	prev = head;

	while (p1 != NULL) {
		p2 = p1->next;

		while (p2 != NULL && p2->exp == p1->exp) {

			p1->coef = p1->coef + p2->coef;
			p2 = p2->next;
			p1->next = p2;

			if (p1->coef == 0 && prev != NULL)
			{
				p1->exp = p1->coef * p1->exp;
				prev->next = p2;
			}
			else
			{
				prev = p1;
			}
		}

		p1 = p2;
	}


	p1 = p2 = head;

	while (p1->next != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL)
		{
			if (p1->exp < p2->exp)
			{
				coef = p1->coef;
				exp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = coef;
				p2->exp = exp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	p1 = head;

	while (p1 != NULL) {
		p2 = p1->next;

		while (p2 != NULL && p2->coef == 0) {

			p2 = p2->next;
			p1->next = p2;
		}

		p1 = p2;
	}

	if (head->coef == 0)
		head = NULL;

	return head;
}


PolyNode *Add(PolyNode *poly1, PolyNode *poly2) {

	PolyNode* poly3 = NULL;
	PolyNode* head = NULL;

	while (poly1 != NULL && poly2 != NULL)
	{
		if (poly3 == NULL)
		{
			poly3 = new PolyNode;
			head = poly3;
		}
		else
		{
			poly3->next = new PolyNode;
			poly3 = poly3->next;
		}

		if (poly1->exp < poly2->exp)
		{
			poly3->coef = poly2->coef;
			poly3->exp = poly2->exp;
			poly2 = poly2->next;
		}
		else
		{
			if (poly1->exp > poly2->exp)
			{
				poly3->coef = poly1->coef;
				poly3->exp = poly1->exp;
				poly1 = poly1->next;
			}
			else
			{
				if (poly1->exp == poly2->exp)
				{
					poly3->coef = poly1->coef + poly2->coef;
					poly3->exp = poly1->exp;
					poly1 = poly1->next;
					poly2 = poly2->next;

					if (poly3->coef == 0)
					{
						poly3->exp = 0;
					}
				}
			}
		}
	}

	poly3->next = NULL;

	PolyNode *p1, *prev, *p2;
	double coef;
	int exp;

	p1 = p2 = head;

	while (p1->next != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL)
		{
			if (p1->exp < p2->exp)
			{
				coef = p1->coef;
				exp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = coef;
				p2->exp = exp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	p1 = head;
	prev = head;

	while (p1 != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL && p2->exp == p1->exp)
		{
			p1->coef = p1->coef + p2->coef;
			p2 = p2->next;
			p1->next = p2;

			if (p1->coef == 0 && prev != NULL)
			{
				p1->exp = p1->coef * p1->exp;
				prev->next = p2;
			}
			else
			{
				prev = p1;
			}
		}
		p1 = p2;
	}

	if (head->coef == 0)
		head = NULL;

	poly3 = head;

	return poly3;
}


PolyNode *Subtract(PolyNode *poly1, PolyNode *poly2) {

	PolyNode* poly3 = NULL;
	PolyNode* head = NULL;

	while (poly1 != NULL && poly2 != NULL)
	{
		if (poly3 == NULL)
		{
			poly3 = new PolyNode;
			head = poly3;
		}
		else
		{
			poly3->next = new PolyNode;
			poly3 = poly3->next;
		}

		if (poly1->exp < poly2->exp)
		{
			poly3->coef = poly2->coef;
			poly3->exp = poly2->exp;
			poly2 = poly2->next;
		}
		else
		{
			if (poly1->exp > poly2->exp)
			{
				poly3->coef = poly1->coef;
				poly3->exp = poly1->exp;
				poly1 = poly1->next;
			}
			else
			{
				if (poly1->exp == poly2->exp)
				{
					poly3->coef = poly1->coef - poly2->coef;

					poly3->exp = poly1->exp;
					poly1 = poly1->next;
					poly2 = poly2->next;

					if (poly3->coef == 0)
					{
						poly3->exp = 0;
					}
				}
			}
		}
	}

	poly3->next = NULL;

	PolyNode *p1, *prev, *p2;
	double coef;
	int exp;

	p1 = p2 = head;

	while (p1->next != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL)
		{
			if (p1->exp < p2->exp)
			{
				coef = p1->coef;
				exp = p1->exp;
				p1->coef = p2->coef;
				p1->exp = p2->exp;
				p2->coef = coef;
				p2->exp = exp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	p1 = head;
	prev = head;

	while (p1 != NULL)
	{
		p2 = p1->next;

		while (p2 != NULL && p2->exp == p1->exp)
		{
			p1->coef = p1->coef + p2->coef;
			p2 = p2->next;
			p1->next = p2;

			if (p1->coef == 0 && prev != NULL)
			{
				p1->exp = p1->coef * p1->exp;
				prev->next = p2;
			}
			else
			{
				prev = p1;
			}
		}
		p1 = p2;
	}

	if (head->coef == 0)
		head = NULL;

	poly3 = head;

	return poly3;
}


PolyNode *Multiply(PolyNode *poly1, PolyNode *poly2) {

	PolyNode* poly3 = NULL;
	PolyNode* dup = NULL, *ptr1 = NULL, *ptr2 = NULL;
	PolyNode* head = NULL, *head1 = NULL;

	head1 = poly2;

	while (poly1 != NULL)
	{
		poly2 = head1;

		while (poly2 != NULL)
		{
			if (poly3 == NULL)
			{
				poly3 = new PolyNode;
				head = poly3;
			}
			else
			{
				poly3->next = new PolyNode;
				poly3 = poly3->next;
			}

			poly3->coef = poly2->coef * poly1->coef;
			poly3->exp = poly2->exp + poly1->exp;
			poly2 = poly2->next;
		}
		poly1 = poly1->next;

	}

	poly3->next = NULL;

	ptr1 = head;

	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		while (ptr2->next != NULL)
		{
			if (ptr1->exp == ptr2->next->exp)
			{
				ptr1->coef = ptr1->coef + ptr2->next->coef;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
			}
			else
				ptr2 = ptr2->next;
		}

		ptr1 = ptr1->next;
	}

	poly3 = head;

	return poly3;

}

double Evaluate(PolyNode *poly, double x) {

	double result = 0;

	while (poly != NULL)
	{
		result += poly->coef * pow(x, poly->exp);
		poly = poly->next;
	}

	return result;
}

PolyNode *Derivative(PolyNode *poly) {

	PolyNode *derivpoly = NULL;
	PolyNode *head = NULL;

	while (poly != NULL)
	{
		if (derivpoly == NULL)
		{
			derivpoly = new PolyNode;
			head = derivpoly;
		}
		else if (poly->exp == 0)
		{
			derivpoly->next = NULL;
			break;
		}
		else
		{
			derivpoly->next = new PolyNode;
			derivpoly = derivpoly->next;
		}

		if (poly->exp == 1)
		{
			derivpoly->coef = poly->coef * poly->exp;
			derivpoly->exp = 0;

			if (poly->next == NULL)
			{
				derivpoly->next = NULL;
				break;
			}
			else
			{
				poly = poly->next;
			}
		}
		else
		{
			derivpoly->coef = poly->coef * poly->exp;
			derivpoly->exp = ((poly->exp) - 1);
			poly = poly->next;
		}
	}

	return head;
}


void Plot(PolyNode *poly, int x1, int x2) {

	PolyNode *head = NULL;
	head = poly;

	int i, j, y, x;
	int a = 0;

	for (i = 13; i >= -12; i--)
	{
		y = i;

		for (j = x1; j <= x2; j++)
		{
			x = j;

			poly = head;
			a = 0;

			while (poly != NULL)
			{
				a += (poly->coef*pow(x, poly->exp));
				poly = poly->next;
			}
			if (y == a)
			{
				printf("*");
			}

			if (i == 0 & j == 0)
			{
				if (y == a)
					continue;

				printf("|");
			}

			if (j == 0 & i != 13)
			{
				if (y == a)
					continue;

				if (i == 0)
					continue;

				printf("|");
			}

			if (i == 13 & j == 0)
			{
				printf("y");
			}

			if (i == 0)
			{
				if (y == a)
					continue;

				if (j == 0)
					continue;

				printf("-");
			}
			else
			{
				if (y == a)
					continue;

				if (j == 0)
					continue;

				printf(" ");
			}

			if (j == 30 & i == 0)
			{
				printf("x");
			}
		}

		cout << endl;
	}

}
