#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(string filename)
{

	ifstream dnafile(filename, ios::in);
	string temp;
	while (getline(dnafile, temp))
	{
		dna.append(temp);
	}
	lengthR = dna.length();
}
int Sequence::length()
{
	return lengthR;
}

int Sequence::numberOf(char base)
{
	return count(dna.begin(), dna.end(), base);
}

string Sequence::longestConsecutive()
{
	struct stringPos
	{
		string a;
		int b;
	}dnaPos[4] = { {"A",0},{ "G",0 },{ "C",0 },{ "T",0 } };
	while (string::npos != (dnaPos[0].b = dna.find(dnaPos[0].a)))
		dnaPos[0].a.append("A");
	dnaPos[0].a.erase(0, 1);
	while (string::npos != (dnaPos[1].b = dna.find(dnaPos[1].a)))
		dnaPos[1].a.append("G");
	dnaPos[1].a.erase(0, 1);
	while (string::npos != (dnaPos[2].b = dna.find(dnaPos[2].a)))
		dnaPos[2].a.append("C");
	dnaPos[2].a.erase(0, 1);
	while (string::npos != (dnaPos[3].b = dna.find(dnaPos[3].a)))
		dnaPos[3].a.append("T");
	dnaPos[3].a.erase(0, 1);
	bool (*compare)(stringPos, stringPos) = [](stringPos left, stringPos right) {
		if (left.a.length() == right.a.length())
			return(left.b < right.b);
		return left.a.length() > right.a.length();
	};
	sort(dnaPos, dnaPos + 4, compare);
	return dnaPos[0].a;
}
string Sequence::longestRepeated()
{
	char**a = new char*[lengthR + 100]{ 0 };
	for (int i = 0; i < lengthR; i++)
	{
		a[i] = &dna[i];
	}

	bool (*compare)(char*,char*)=[](char* left,char* right)
	{
		return strcmp(left, right) < 0;
	};
	sort(a, a + lengthR, compare);

	int max = 0;
	char* maxR = 0;

	for (int i = 0; i < lengthR - 1; i++)
	{
		int j = 0;
		char *last = a[i], *next = a[i + 1];
		while (*last && (*last++ == *next++))
			j++;
		if (j > max)
		{
			max = j;
			maxR = a[i];
		}
	}
	string longest;
	for (int i = 0; i < max; i++)
	{
		longest += maxR[i];
	}

	return longest;
}
