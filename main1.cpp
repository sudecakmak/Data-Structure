#include <stdio.h>
#include <string>

using namespace std;

extern string Infix2Postfix(string& s);
extern int EvaluatePostfixExpression(string& s);

int Test1();
int Test2();
int Test3();
int Test4();
int Test5();
int Test6();
int Test7();
int Test8();
int Test9();
int Test10();
int Test11();
int Test12();
int Test13();
int Test14();
int Test15();

int main() {
	int grade = 0;

	printf("======================= TEST1 ========================\n");
	grade += Test1();

	if (grade > 0) {
		printf("======================= TEST2 ========================\n");
		grade += Test2();

		printf("======================= TEST3 ========================\n");
		grade += Test3();

		printf("======================= TEST4 ========================\n");
		grade += Test4();

		printf("======================= TEST5 ========================\n");
		grade += Test5();

		printf("======================= TEST6 ========================\n");
		grade += Test6();

		printf("======================= TEST7 ========================\n");
		grade += Test7();

		printf("======================= TEST8 ========================\n");
		grade += Test8();

		printf("======================= TEST9 ========================\n");
		grade += Test9();

		printf("======================= TEST10 ========================\n");
		grade += Test10();
		
		printf("======================= TEST11 ========================\n");
		grade += Test11();
		
		printf("======================= TEST12 ========================\n");
		grade += Test12();
		
		printf("======================= TEST13 ========================\n");
		grade += Test13();
		
		printf("======================= TEST14 ========================\n");
		grade += Test14();
		
		printf("======================= TEST15 ========================\n");
		grade += Test15();

	} //end-if

	printf("------------------------------------------------------\n");
	printf("Final grade: %d\n", grade);
} //end-main


  /****************************************************
   * Test1
   ****************************************************/
int Test1() {
	// infixExpr: 3500 - ((43*12) + (47/2));    
	// Let the C++ compiler do the evaluation :-)
	int expressionValue = 3500 - ((43 * 12) + (47 / 2));

	// postfix: 3500 43 12 * 47 2 / + -
	string postfixExpr = "3500 43 12 * 47 2 / + -";
	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test1

/****************************************************
 * Test2
 ****************************************************/
int Test2() {
	int expressionValue = 20 + 2 * 3 + (2 * 8 + 5) * 4;

	string infixExpr = "20 + 2 * 3     + (2*8 + 5)* 4";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test2

/****************************************************
 * Test3
 ****************************************************/
int Test3() {
	// Let the C++ compiler do the evaluation :-)
	int expressionValue = 20 * 2 + 3 - (2 * 8 + 5) * 4;

	string infixExpr = "20* 2 + 3 - (2*8 + 5)* 4";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test3

/****************************************************
 * Test4
 ****************************************************/
int Test4() {
	int expressionValue = 220 - 45 - 10;

	string infixExpr = "220 - 45 - 10";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test4

/****************************************************
 * Test5
 ****************************************************/
int Test5() {
	int expressionValue = (((13 + 35) * 22) / 45) - (45 + 34 * (190 - 34)) / 100;

	string infixExpr = "(((13+35)*22)/45) - (45+34*(190-34))/100";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test6() {
	int expressionValue = (2 + 45) * (46 + 2345);

	string infixExpr = "(2 + 45) * (46 + 2345)";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test7() {
	int expressionValue = 56 + 3 + 3455+123;

	string infixExpr = "56 + 3 + 3455+123";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test8() {
	int expressionValue = 234 + 98 * 5 + 0;

	string infixExpr = "234+98 *   5 +   0 ";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test9() {
	int expressionValue = (34 -8 + (12- 9)/3) * (34-2*2/1);

	string infixExpr = "(34 -8 + (12- 9)/3) * (34-2*2/1)";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test10() {
	int expressionValue = 56 * 7890 + 3 * 12;

	string infixExpr = "56 *    7890 +  3*12";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test11() {
	int expressionValue =  (22 + (33 * 0));

	string infixExpr = "(22 + (33 * 0))  ";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test12() {
	int expressionValue = ((23 + (1 * 345)) / (21 -45));

	string infixExpr = "((23 + (1 * 345)) / (21 -45))";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test13() {
	int expressionValue = ((7 +  589 ) * (234+111));

	string infixExpr = "  ((7 +  589 ) * (234+111))  ";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test14() {
	int expressionValue = (234 * (123 * (((1 + 4) - 34) / 12)));

	string infixExpr = "(234 * (123 * (((1 + 4) - 34) / 12)))";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5

int Test15() {
	int expressionValue = ((12 * ((((34 + ((4 + 5) * 1)) *4)* 6) * 7)) +123);

	string infixExpr = "((12 * (((  (34 +    ((4 + 5) * 1)) *4)* 6) * 7)) +123)";
	string postfixExpr = Infix2Postfix(infixExpr);
	printf("Infix Expr: <%s>\nPostfixExpr: <%s>\n", infixExpr.c_str(), postfixExpr.c_str());

	int result = EvaluatePostfixExpression(postfixExpr);
	if (result != expressionValue) return 0;

	return 20;
} //end-Test5