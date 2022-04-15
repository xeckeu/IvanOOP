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
		temp->current->outData(temp->current->getText(), temp->current->getMark(), ofst);
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
		temp->current->outFilter(temp->current->getText(), temp->current->getMark(), ofst);
		if (temp->next) {
			temp = temp->next;
		}
	}
}

Text* Text::inText(ifstream& ifst) {
	Text* C;
	int K;
	ifst >> K;
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
	ifst >> C->text;
	C->inData(ifst);
	ifst >> C->mark;
	return C;
}

string Text::getText() {
	return text;
}

int Text::textCounter() {
	int counter = 0;
	string punctuationMarks = ".,?!:;-";
	for (auto m : punctuationMarks)
		counter += count(this->text.begin(), this->text.end(), m);
	return counter;
}

bool Text::Compare(Text* T) {
	return textCounter() < T->textCounter();
}

int Text::getMark() {
	return mark;
}

void Aphorism::inData(ifstream& ifst) {
	ifst >> author;
}

void Aphorism::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Aphorism]: " << text << endl;
	ofst << "[Author]: " << author << endl;
	ofst << "[Punctuation]: " << textCounter() << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Aphorism::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "";
}

void Saying::inData(ifstream& ifst) {
	ifst >> country;
}

void Saying::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Saying]: " << text << endl;
	ofst << "[Country]: " << country << endl;
	ofst << "[Punctuation]: " << textCounter() << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Saying::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "[Saying]: " << text << endl;
	ofst << "[Country]: " << country << endl;
	ofst << "[Punctuation]: " << textCounter() << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Riddle::inData(ifstream& ifst) {
	ifst >> answer;
}

void Riddle::outData(string text, int mark, ofstream& ofst) {
	ofst << "[Riddle]: " << text << endl;
	ofst << "[Answer]: " << answer << endl;
	ofst << "[Punctuation]: " << textCounter() << endl;
	ofst << "[Mark]: " << mark << endl << endl;
}

void Riddle::outFilter(string text, int mark, ofstream& ofst) {
	ofst << "";
}