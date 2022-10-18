#pragma once
#include<iostream>
#include "Block.hpp"
#include "Transaction.hpp"

#include <vector>

using namespace std;

class Blockchain {
    private:
        unsigned int difficulty;
        vector<Block> chain; //THIS IS THE BLOCKCHAIN
        vector<Transaction> pending;
        int miningReward;

    public:
       Blockchain(); 
       void addTransaction(string src, string dst, int coins);
       bool isChainValid();
       bool minePendingTransactions(string minerAddress);
       int getBalanceOfAddress(string address);
       void prettyPrint();
       vector<Block> getBlocks(); //newly added

    private:
        Block getLatestBlock();
};
