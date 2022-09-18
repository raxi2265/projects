#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {//
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

vector<Transaction> Block::getTransactions() //newly added 
{
    return transactions;
}

void Block::setPreviousHash(string _previousHash) { //
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {//
    // TODO
    string toHash = toString();
    string hashed = sha256(toHash);
    //cout << "CALCULATE HASH CURRENT HASH" << hashed << endl;
    return hashed;
}

void Block::mineBlock(unsigned int difficulty) { //
    // TODO
    //idek what this is asking
    //find the value of the nonce such that the sha value of the string resulting from the data of the block 
    //do i have to recalculate the hash?
    //has the same number of 0s as the #difficulty?
    string myHash; 
    bool exit = false;
    while(!exit)
    {
        nonce = nonce + 1; //
        myHash = calculateHash();
        exit = true;
        for(int i = 0; i < difficulty; i++)
        {
            if(myHash[i] != '0')
            {
                exit = false;
                break;
            }
        }
    }
    hash = myHash;
    // for(int i = 0; i < difficulty; i++)
    // {}
    // do{
    //     nonce = nonce + 1;
    //     myHash = calculateHash();
    // }
    //cout << "MINEBLOCK CURRENT HASH" << myHash << endl;
    //find the value of the nonce such that the sha value of the stirng resulting from combining th edata of the block has the #difficulty characters = 0
}

string Block::toString() {//
    // TODO
    stringstream ss;
    ss << nonce << ", " << previousHash << ", " << timestamp  << ", ";
    for(int i = 0; i < transactions.size(); i++)
    {
        ss << transactions[i].getSender() << ", ";
        ss << transactions[i].getReceiver() << ", ";
        ss << transactions[i].getAmount() << ", ";
    }
    //cout << "STRING STREAM" << ss.str() << endl;
    return ss.str();
}

long long Block::getNonce() {//
    return nonce;
}

time_t Block::getTime(){//
    return timestamp;
}

string Block::getHash(){//
    return hash;
}

string Block::getPreviousHash(){//
    return previousHash; 
}

