#include <iostream>
#include <stack>
#include <string>
#include "d_tnode.h"
#include "d_tnodel.h"
#include "inf2pstf.h"

using namespace std;

void prefixoutput(tnode<char> *exp);
tnode<char> *buildExpTree(const string& exp);

int main(){

    tnode<char> *oneTree;
	tnode<char> *twoTree;
	tnode<char> *threeTree;

    string one = "a*b";
	string two = "a+b+c";
	string three = "a+b*c/d-e";

    infix2Postfix infix1 = infix2Postfix(one);
    infix2Postfix infix2 = infix2Postfix(two);
    infix2Postfix infix3 = infix2Postfix(three);



    oneTree = buildExpTree(infix1.postfix());
    twoTree = buildExpTree(infix2.postfix());
    threeTree = buildExpTree(infix3.postfix());

    cout << endl;

    prefixoutput(oneTree);
    cout << endl;
    prefixoutput(twoTree);
    cout << endl;
    prefixoutput(threeTree);
    cout << endl;

    cout << endl;
    cout << endl;

    postorderOutput(oneTree, " ");
    cout << endl;
    postorderOutput(twoTree, " ");
    cout << endl;
    postorderOutput(threeTree, " ");
    cout << endl;

    cout << endl;
    cout << endl;

    displayTree(oneTree, 1);
    cout << endl;
    displayTree(twoTree, 1);
    cout << endl;
    displayTree(threeTree, 1);
    cout << endl;

}
void prefixoutput(tnode<char> *exp){
	if(!exp){
        return;
    }
    cout << " " << exp->nodeValue;
    prefixoutput(exp->left);
    prefixoutput(exp->right);
    
}

// build an expression tree from a postfix expression.
// the operands are single letter identifiers in the range from
// 'a' .. 'z' and the operators are selected from the characters
// '+', '-', '*' and '/'
tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}