#pragma once
#include <string>
#include <vector>
#ifndef SEQUENCE_H
#define SEQUENCE_H
using namespace std;
class Sequence
{
public:
	Sequence(string filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
private:
	string dna;
	int lengthR;
};
#endif // !SEQUENCE_H

