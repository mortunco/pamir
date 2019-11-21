#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
using namespace std;

struct Read {
	string name;
	string seq;
	int location;
	int location_in_contig;
};

struct contig {
	string data;
	vector<Read> read_information;
};

struct Node {
	string seq;
	int indegree;
	vector<pair<int, int>> neighbors; // Read, Weight
	Node(): indegree(0) {}
};

typedef vector<Node> Graph;

class assembler {
private:
	static const int SEED = 92821; // must be prime
	const int max_contig_size;
	const int min_glue_size;

	Graph graph;

private:
	bool validate(const string &a, const string &b, int glue_sz);

public:
	assembler();
	assembler(int, int);
	~assembler();
	vector<contig> path();
	vector<int> topsort();

public:
	vector<contig> assemble(vector<string> reads);
};
