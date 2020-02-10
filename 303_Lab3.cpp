//Justin Foster - CS303 Lab 3
//Implementing these functions using a premade stack + queue implemented with vectors

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Stack implementation
class my_Stack {
private:
	int size;
	int back;
	vector<int> vec;
public:
	my_Stack() {
		size = 0;
		back = -1;
		vec.reserve(30);
	}
	void push(int data) {
		vec.push_back(data);
		back++;
		size++;
	}
	void pop() {
		back--;
		size--;
	}
	int top() {
		return vec[back];
	}
	void printStack() {
		int counter = 0;
		while (counter <= back) {
			cout << vec[counter] << " ";
			counter++;
		}
		cout << endl;
	}
	int Size() {
		return size;
	}
	bool empty() {
		if (size == 0)
			return true;
		else
			return false;
	}
};

//Queue implementation
class my_Queue {
public:
	my_Queue();
	void enqueue(int data);
	void dequeue();
	int getFront();
	int getBack();
	void printQueue();
	int Size();
	bool empty();
private:
	int size, back, front;
	vector<int> vec;
};

my_Queue::my_Queue() {
	size = 0;
	back = -1;
	front = -1;
	vec.reserve(30);
}
void my_Queue::enqueue(int data) {
	vec.push_back(data);
	back = (back + 1) % 30;
	size++;
	if (front == -1)
		front = 0;
}
void my_Queue::dequeue() {
	front = (front + 1) % 30;
	size--;
}
int my_Queue::getFront() {
	return vec[front];
}
int my_Queue::getBack() {
	return vec[back];
}
void my_Queue::printQueue() {
	int counter = front;
	while (counter <= back) {
		cout << vec[counter] << " ";
		counter = (counter + 1) % 30;
	}
	cout << endl;
}
int my_Queue::Size() {
	return size;
}
bool my_Queue::empty() {
	if (size == 0)
		return true;
	else
		return false;
}

int main() {

	
	//Question 1 - Check if string is a palindrome
	//Using a stack to push the characters of the string onto the stack one at a time
	//Pop the values back off and compare to original string to check for a match
	/*
	my_Stack myStack;
	string palindrome;
	string palin2;
	cout << "Enter a word for a palindrome check." << endl;
	getline(cin, palindrome);
	int size = palindrome.size();
	char x;
	for (int i = 0; i < size; i++)
	{
		x = palindrome[i];
		myStack.push(x);
	}
	for (int i = 0; i < size; i++)
	{
		char temp;
		temp = myStack.top();
		myStack.pop();
		palin2 += temp;
	}

	if (palindrome == palin2)
		cout << palindrome << " is a palindrome!" << endl;

	else {
		cout << palindrome << " is not a palindrome." << endl;
	}

	/*  ---------------------------------------------------------  */

	//Question 2 - Convert to Binary
	/*
	cout << "Question 2..." << endl;
	int start;
	int counter = 0;
	string binary;
	my_Stack myStack1;
	cout << "Enter your decimal number to convert to binary." << endl;
	cin >> start;
	int initHold = start; //holds the inital decimal number
	while (start != 0)
	{
		if (start % 2 == 1)
			myStack1.push('1');

		if (start % 2 == 0)
			myStack1.push('0');

		start /= 2;
		counter++;
	}

	for (int i = 0; i < counter; i++)
	{
		char temp;
		temp = myStack1.top();
		binary += temp;
		myStack1.pop();
	}

	cout << initHold << " in binary is: " << binary << endl;

	/*  ------------------------------------------------------------  */

	//Question 3 - Calculate the value of a post-fix equation
	//Read in the equation character by character and push onto stack
	//Once an operator is found, pop last two integer values off of the stack and apply operator
	//*** Can only work with single digit integers currently
	/*
	my_Stack postStack;
	string theEquation;
	cout << "Please enter your post-fix equation. Please put spaces between the numbers and operands." << endl;
	cin >> theEquation;
	vector<char> equateVec(theEquation.begin(), theEquation.end());
	//int size = equateVec.size();
	
	for (int i = 0; i <= equateVec.size(); i++)
	{

		if (isdigit(equateVec[i]))	//find a way to collect the whole number and store as one
		{
			postStack.push(equateVec[i]);
		}

		int topVal = 0;
		int secVal = 0;

		switch (equateVec[i]) {

		case '/':
			topVal = postStack.top();
			postStack.pop();
			secVal = postStack.top();
			postStack.pop();
			postStack.push(secVal / topVal);
			break;
		case '+':
			topVal = postStack.top();
			postStack.pop();
			secVal = postStack.top();
			postStack.pop();
			postStack.push(secVal + topVal);
			break;

		case '-':
			topVal = postStack.top();
			postStack.pop();
			secVal = postStack.top();
			postStack.pop();
			postStack.push(secVal - topVal);
			break;

		case '*':
			topVal = postStack.top();
			postStack.pop();
			secVal = postStack.top();
			postStack.pop();
			postStack.push(secVal * topVal);
			break;

		}

	}

	cout << postStack.top() << endl;
	*/


	//Question 4 - Check the balance of a parenthesis
	//Have program parse string to find any brackets, if bracket is found push onto stack
	//Once the ending bracket is found, pop the stack and check if it matches the bracket
	//If not matching, unbalanced parenthesis
	my_Stack parenStack;
	string parenth;

	cout << "Enter your equation." << endl;
	getline(cin, parenth);
	const int size = parenth.size();

	for (int i = 0; i < size; i++)
	{
		char temp = parenth[i];
		char compare = parenStack.top();

		switch (parenth[i]) {

		case '(' :
			parenStack.push('(');
			break;

		case '{' :
			parenStack.push('{');
			break;

		case '[' :
			parenStack.push('[');
			break;

		case ')' : 
			if (compare == temp)
				cout << "Brackets match. " << endl;
			else if (compare != temp)
				cout << "Brackets don't match!" << endl;

			parenStack.pop();
			break;

		case '}':
			if (compare == temp)
				cout << "Brackets match. " << endl;
			else if (compare != temp)
				cout << "Brackets don't match!" << endl;

			parenStack.pop();
			break;

		case ']':
			if (compare == temp)
				cout << "Brackets match. " << endl;
			else if (compare != temp)
				cout << "Brackets don't match!" << endl;

			parenStack.pop();
			break;
		}




	}

	//Question 5 - Insert a value in the middle of a queue.
	//Logic - Need to find size of queue, divide by two to find the middle.
	//Enqueue the front of the initQueue to a new tempQueue until the middle is reached
	//At the middle value enqueue the userVar then proceed to enqueue the initQueue's values
	//Print the new tempQueue with the value added to the middle
	/*
	my_Queue initQueue;
	my_Queue tempQueue;

	
	initQueue.enqueue(1);
	initQueue.enqueue(2);
	initQueue.enqueue(3);
	initQueue.enqueue(4);
	initQueue.enqueue(5);
	initQueue.enqueue(6);

	cout << "Current queue values: ";
	initQueue.printQueue();
	int userVar;
	cout << "What is the value you would like to insert?" << endl;
	cin >> userVar;
	int size = initQueue.Size();
	int insertSize = size / 2;

	for (int i = 0; i < size; i++)
	{
		//Enqeueues the user values at the middle of the queue
		//then enqueues the following value that it "replaced"
		if (i == insertSize)
		{
			tempQueue.enqueue(userVar);
			tempQueue.enqueue(initQueue.getFront());
			initQueue.dequeue();
		}

		else if( i != insertSize){

			tempQueue.enqueue(initQueue.getFront());
			initQueue.dequeue();
		}

	}

	cout << "New queue with value " << userVar << " added: ";
	tempQueue.printQueue();
	*/
	return 0;
}
