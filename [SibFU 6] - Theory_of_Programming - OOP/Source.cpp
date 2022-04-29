#include "header.h"

Container::Container() {
	head = tail = new Node();
	head->current = tail->current = NULL;
	head->next = tail->next = NULL;
	head->prev = tail->prev = NULL;
	length = 0;
}

void Container::in(ifstream& ifst) {
	Node* temp;

	while (!ifst.eof()) {
		temp = new Node();
		temp->next = NULL;
		temp->prev = NULL;

		if (!length) {
			if ((head->current = Text::inText(ifst))) {
				tail = head;
				length++;
			}
		}
		else {
			if ((temp->current = Text::inText(ifst))) {
				tail->next = temp;
				head->prev = temp;
				temp->prev = tail;
				temp->next = head;
				tail = temp;
				length++;
			}
		}
	}
}

void Container::out(ofstream& ofst) {
	ofst << "Container contains " << length
		<< " elements." << endl << endl;
	Node* temp = head;
	for (int i = 0; i < length; i++) {
		ofst << i << ":\n";
		if ((!temp->current->getText().empty()) && (temp->current->getMark()))
			temp->current->outData(temp->current->getText(), temp->current->getMark(), ofst);
		else
			ofst << "Invalid element!" << endl << endl;
		if (temp->next) {
			temp = temp->next;
		}
	}
}

void Container::clear() {
	Node* temp = head;
	head->prev = NULL;
	tail->next = NULL;
	for (int i = 0; i < length; i++) {
		free(temp->current);
		if (temp->next) {
			temp = temp->next;
			free(temp->prev);
		}
	}
	length = 0;
}

void Container::sort() {
	if (length > 1) {
		Node* first = head;
		Node* second = head->next;
		Node* temp = new Node;
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - i - 1; j++) {
				if (first->current->Compare(second->current)) {
					temp->current = first->current;
					first->current = second->current;
					second->current = temp->current;
				}
				second = second->next;
			}
			first = first->next;
			second = first->next;
		}
	}
}

void Container::outFilter(ofstream& ofst) {
	Node* temp = head;
	for (int i = 0; i < length; i++) {
		ofst << i << ":\n";
		if ((!temp->current->getText().empty()) && (temp->current->getMark()))
			temp->current->outFilter(temp->current->getText(), temp->current->getMark(), ofst);
		else
			ofst << "Invalid element!" << endl << endl;
		if (temp->next) {
			temp = temp->next;
		}
	}
}

Text* Text::inText(ifstream& ifst) {
	Text* C;
	string nums = "9876543210";
	string temp = "";
	int mark = -1;
	int K = -1;
	getline(ifst, temp);
	if ((temp != "1") && (temp != "2") && (temp != "3")) {
		if (ifst.peek() == EOF) {
			return 0;
		}
		else {
			cout << "Invalid input data!" << endl << endl;
			system("pause");
			exit(1);
		}
	}
	else
		K = atoi(temp.c_str());

	if (K == 1) {
		C = new Aphorism;
	}
	else if (K == 2) {
		C = new Saying;
	}
	else if (K == 3) {
		C = new Riddle;
	}
	else {
		return 0;
	}
	getline(ifst, temp);
	if (!temp.empty())
		C->text = temp;
	C->inData(ifst);
	getline(ifst, temp);
	if (!temp.empty() && nums.find(temp) != -1) {
		mark = atoi(temp.c_str());
		if ((mark >= 0) && (mark <= 10))
			C->mark = mark;
		else
		{
			cout << "[Mark] Invalid input data!" << endl << endl;
			system("pause");
			exit(1);
		}
	}
	else {
		cout << "Invalid input data!" << endl << endl;
		system("pause");
		exit(1);
	}
	return C;
}

string Text::getText() {
	return text;
}

int Text::textCounter(string text) {
	int counter = 0;
	string punctuationMarks = ".,?!:;-_";
	for (auto m : punctuationMarks)
		counter += count(text.begin(), text.end(), m);
	return counter;
}

bool Text::Compare(Text* T) {
	return textCounter(text) < T->textCounter(T->text);
}

int Text::getMark() {
	return mark;
}

string Aphorism::getAuthor()
{
	return string(author);
}

void Aphorism::setAuthor(string author)
{
	this->author = author;
}

void Aphorism::inData(ifstream& ifst) {
	string temp;
	bool flag = false;
	getline(ifst, temp);
	if (!temp.empty()) {
		for (auto c : temp) {
			if (!isalpha(c))
			{
				if (c != ' ' && c != '-' && c != ',' && c != '.')
				{
					cout << "[Aphorism] Invalid Data!" << endl << endl;
					system("pause");
					exit(1);
				}
			}
		}
		flag = true;
	}
	if (flag)
		author = temp;
}

void Aphorism::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Aphorism]: " << text << endl;
	ofst << "[Author]: " << author << endl;
	ofst << "[Punctuation]: " << textCounter(text) << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Aphorism::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "";
}

string Saying::getCountry()
{
	return string(country);
}

void Saying::setCountry(string country)
{
	this->country = country;
}

void Saying::inData(ifstream& ifst) {
	string temp;
	bool flag = false;
	getline(ifst, temp);
	if (!temp.empty()) {
		for (auto c : temp) {
			if (!isalpha(c))
			{
				if (c != ' ' && c != '-' && c != ',' && c != '.')
				{
					cout << "[Saying] Invalid Data!" << endl << endl;
					system("pause");
					exit(1);
				}
			}
		}
		flag = true;
	}
	if (flag)
		country = temp;
}

void Saying::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Saying]: " << text << endl;
	ofst << "[Country]: " << country << endl;
	ofst << "[Punctuation]: " << textCounter(text) << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Saying::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "[Saying]: " << text << endl;
	ofst << "[Country]: " << country << endl;
	ofst << "[Punctuation]: " << textCounter(text) << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

string Riddle::getAnswer()
{
	return string(answer);
}

void Riddle::setAnswer(string answer)
{
	this->answer = answer;
}

void Riddle::inData(ifstream& ifst) {
	string temp;
	bool flag = false;
	getline(ifst, temp);
	if (!temp.empty()) {
		for (auto c : temp) {
			if (!isalpha(c))
			{
				if (c != ' ' && c != '-' && c != ',' && c != '.')
				{
					cout << "[Riddle] Invalid Data!" << endl << endl;
					system("pause");
					exit(1);
				}
			}
		}
		flag = true;
	}
	if (flag)
		answer = temp;
}

void Riddle::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Riddle]: " << text << endl;
	ofst << "[Answer]: " << answer << endl;
	ofst << "[Punctuation]: " << textCounter(text) << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Riddle::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "";
}