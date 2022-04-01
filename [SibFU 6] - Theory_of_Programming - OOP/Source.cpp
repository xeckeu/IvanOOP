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
		temp->current->outData(temp->current->getText(), ofst);
		//ofst << "[Punctuation]: " << temp->current->textCounter() << endl << endl;
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

Text* Text::inText(ifstream& ifst) {
	Text* C;
	int K;
	ifst >> K;
	if (K == 1) {
		C = new Aphorism;
		ifst >> C->text;
	}
	else if (K == 2) {
		C = new Saying;
		ifst >> C->text;
	}
	else {
		return 0;
	}
	C->inData(ifst);
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

void Aphorism::inData(ifstream& ifst) {
	ifst >> author;
}

void Aphorism::outData(string text, ofstream& ofst) {
	ofst << "[Aphorism]: " << text << endl;
	ofst << "[Author]: " << author << endl;
	ofst << "[Punctuation]: " << textCounter() << endl << endl;
}

void Saying::inData(ifstream& ifst) {
	ifst >> country;
}

void Saying::outData(string text, ofstream& ofst) {
	ofst << "[Saying]: " << text << endl;
	ofst << "[Country]: " << country << endl;
	ofst << "[Punctuation]: " << textCounter() << endl << endl;
}