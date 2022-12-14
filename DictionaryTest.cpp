//-----------------------------------------------------------------------------
// DictionaryTest.cpp
// A test client for Dictionary ADT
//-----------------------------------------------------------------------------

#include"Dictionary.h"

using namespace std;

int main() {
	Dictionary D;
	cout << "D: " << endl;
	cout << D << endl;
	cout << "D.size() should be 0: " << D.size() << endl;

	// setValue(), getValue(), and contains() tests----------------------------

	cout << "setValue() test 1, insert into empty tree" << endl;
	D.setValue("two", 2);
	cout << "D: " << endl;
	cout << D << endl;

	cout << "contains() test 1" << endl;
	if (D.contains("two") == 0) {
		cout << "D does not contain key \"two\"" << endl;
	}
	else {
		cout << "two : " << D.getValue("two") << endl;
	}
	cout << endl;

	cout << "setValue() test 2, insert left into non-empty tree" << endl;
	D.setValue("one", 1);
	cout << "D: " << endl;
	cout << D << endl;
	
	cout << "contains() test 2" << endl;
	if (D.contains("one") == 0) {
		cout << "D does not contain key \"one\"" << endl;
	}
	else {
		cout << "one : " << D.getValue("one") << endl;
	}
	cout << endl;

	cout << "setValue() test 3, insert right into non-empty tree" << endl;
	D.setValue("three", 3);
	cout << "D: " << endl;
	cout << D << endl;

	cout << "contains() test 3" << endl;
	if (D.contains("three") == 0) {
		cout << "D does not contain key \"three\"" << endl;
	}
	else {
		cout << "three : " << D.getValue("three") << endl;
	}
	cout << endl;

	// iterate through all the nodes to check that they're properly linked
	D.begin();
	cout << "D.currentKey + D.currentVal (one, 1): " << D.currentKey() << ", " << D.currentVal() << endl;
	D.next();
	cout << "D.currentKey + D.currentVal (three, 3): " << D.currentKey() << ", " << D.currentVal() << endl;
	D.next();
	cout << "D.currentKey + D.currentVal (two, 2): " << D.currentKey() << ", " << D.currentVal() << endl;

	cout << "setValue() test 4, overwrite value" << endl;
	D.setValue("three", -1);
	cout << "D: " << endl;
	cout << D << endl;
	cout << endl;

	cout << "contains() test 4" << endl;
	if (D.contains("three") == 0) {
		cout << "D does not contain key \"three\"" << endl;
	}
	else {
		cout << "three : " << D.getValue("three") << endl;
	}
	cout << endl;

	cout << "contains() test 5" << endl;
	if (D.contains("five") == 0) {
		cout << "D does not contain key \"three\"" << endl;
	}
	else {
		cout << "three : " << D.getValue("three") << endl;
	}
	cout << endl;

	// == / equals() test
	Dictionary E;
	E.setValue("two", 2);
	E.setValue("one", 1);
	E.setValue("three", -1);

	cout << "E: " << endl;
	cout << E << endl;

	if (D == E) {
		cout << "D equals E!" << endl;
	}
	else {
		cout << "i f**ed up" << endl;
	}
	cout << endl;

	// current (iteration and hasCurrent()) tests------------------------------

	cout << "current test 1: hasCurrent()..." << endl;
	cout << "D.hasCurrent() (should be false, 0): " << D.hasCurrent() << endl;
	cout << endl;

	cout << "current test 2: begin()..." << endl;
	D.begin();
	cout << endl;

	cout << "current test 3: currentKey()..." << endl;
	cout << endl;
	cout << "D.hasCurrent() (should be true, 1): " << D.hasCurrent() << endl;
	cout << endl;
	cout << "D.currentKey(): " << D.currentKey() << endl;
	cout << endl;

	cout << "current test 4: end()..." << endl;
	D.end();
	cout << endl;
	cout << "current test 5: currentKey()..." << endl;
	cout << endl;
	cout << "D.currentKey(): " << D.currentKey() << endl;
	cout << endl;

	cout << "current test 5: end() after new insertion..." << endl;
	D.setValue("water", 4);
	D.end();
	cout << "D.currentKey(): " << D.currentKey() << endl;
	cout << endl;

	cout << "current test 6: prev() from end of tree..." << endl;
	D.prev();
	cout << "D.currentKey() should be two: " << D.currentKey() << endl;
	cout << endl;

	cout << "current test 7: prev() from internal..." << endl;
	D.prev();
	cout << "D.currentKey() should be three: " << D.currentKey() << endl;
	cout << endl;

	cout << "current test 8: prev() to beginning..." << endl;
	D.prev();
	cout << "D.currentKey() should be one: " << D.currentKey() << endl;
	cout << endl;

	D.begin();
	cout << "current test 10: next() after begin()..." << endl;
	D.next();
	cout << "D.currentKey() should be three: " << D.currentKey() << endl;
	cout << endl;

	cout << "D.size() should be 4: " << D.size() << endl;

	// remove() tests----------------------------------------------------------
	cout << "remove \"one\"" << endl;
	D.remove("one");
	cout << "D: " << endl;
	cout << D << endl;

	// deleting current
	cout << "remove \"three\"" << endl;
	D.remove("three");
	cout << "D: " << endl;
	cout << D << endl;

	// check that current IS undefined
	if (D.hasCurrent() == 0) {
		cout << "current is undefined" << endl;
	}
	else {
		cout << "error: current is defined" << endl;
	}
	cout << endl;

	// copy constructor test--------------------------------------------------
	Dictionary A;
	A.setValue("one", 1);
	A.setValue("two", 2);
	A.setValue("three", 3);
	A.setValue("water", 4);
	cout << "A: " << endl;
	cout << A << endl;
	cout << endl;

	Dictionary B = A;
	cout << "B: " << endl;
	cout << B << endl;
	cout << endl;

	Dictionary C;
	C.setValue("water", 4);

	C = A;

	cout << "C: " << endl;
	cout << C << endl;
	cout << endl;
	
	Dictionary Z;
	Z.setValue("c", 3);
	Z.setValue("b", 2);
	Z.setValue("a", 1);
	Z.begin();
	Z.clear();

	cout << "Z size: " << Z.size() << endl;

	Dictionary X;
	X.setValue("plaices", 1);
	X.setValue("ambusher", 2);
	X.setValue("crosby", 3);
	X.setValue("wattles", 4);
	X.setValue("pardoner", 5);
	X.setValue("pythons", 6);
	X.setValue("second", 7);
	X.setValue("forms", 8);
	X.setValue("impales", 9);
	X.setValue("pic", 10);

	cout << X << endl;

}