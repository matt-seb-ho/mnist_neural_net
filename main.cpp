#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include "neuralnet.hpp"

using namespace std;

typedef double nntype;

nntype percent_error(nntype approx, nntype exact){
	return abs(approx - exact) / exact;
}

int main () {
	vector<xor_input> training_set, test_set;
	training_set = get_inputs(100);
	test_set = get_inputs(100);
	vector<int> shapes = {2, 2};
	neural_net myXOR(shapes, 2, .1, .01);
	cout << "weight matrices" << endl;
	myXOR.weights[0].print();
	myXOR.weights[1].print();
	cout << "test percent correct before training: " << myXOR.test(test_set) << endl;
	myXOR.train(training_set);
	cout << "test percent correct after training: " << myXOR.test(test_set) << endl;
	cout << "weight matrices" << endl;
	myXOR.weights[0].print();
	myXOR.weights[1].print();
	return 0;
}
