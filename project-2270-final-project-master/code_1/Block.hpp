#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
private:
    long long nonce; // An arbitrary number crucial in mining
    vector<Transaction> transactions; //vector of transactions 
    string previousHash; // Hash of previous block
    time_t timestamp; // Time when mined 
    string hash; // Hash of this block
    
public:
    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);
    vector<Transaction> getTransactions(); //newly added 
    void setPreviousHash(string hash);
    string calculateHash();
    void mineBlock(unsigned int nDifficulty);
    long long getNonce();
    time_t getTime();
    string toString();
    string getHash(); //newly added 
    string getPreviousHash(); //newly added
};

