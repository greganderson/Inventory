#include <string>
#include <queue>
#include <map>

#include "warehouse.h"

using namespace std;

warehouse::warehouse() {
	// TODO: Implement
}
void warehouse::receive(string name, string upc) {
	/*
	queue<string> *q = new queue<string>;
	map<string, queue<string>* > *mq = new map<string, queue<string>* >;
	q->push("Hello");

	mq->insert(pair<string, queue<string>* >("whatever", q));

	for (map<string, queue<string>* >::iterator it = mq->begin(); it != mq->end(); ++it)
		cout << "[" << it->first << ", " << (it->second)->front() << "]" << endl;

	delete q;
	delete mq;

	//TODO: If the name is not in the map make a new vector.
	// vector<string> items;
	// items.push_back(upc);
	// wh[name] = items;

	//TODO: Otherwise simply add the item to the list.
	wh[name].push_back(upc);
	cout << wh[name].at(0) << endl;
	*/
}

void request(string upc, int amount) {
	// TODO: Implement
}
