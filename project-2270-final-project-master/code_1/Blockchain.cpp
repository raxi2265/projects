#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

//look for questions by looking for "?"

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) //source, destination, coins? 
{
    // TODO
    //src is the hash is that right? 
    int balance = getBalanceOfAddress(src); //getting the balance with getbalance function

    if(balance >= coins) { //if the balance of the sec address is greater than the number of coins transferred, add this transaction to the list of pending transactions
        Transaction newTransaction(src, dst, coins); //create a new trasnaction
        pending.push_back(newTransaction); //add this transaction into the pending transactions vector DO I HAVE TO PUSH TO A CERTAIN BLOCK OR IS THIS LINE OK
        balance -= coins; //IS THIS RIGHT OR NOT !!!!!!!!!!
    }
    // if not, print an error message
    else{
        cout << "ERROR: src's balance is less than the number of coins transferred. you don't have enough coins." << endl;
    }
}

bool Blockchain::isChainValid() { //
    // TODO
    //traverse the blockchain from the second block
    for(int i = 1; i < chain.size(); i++) //does it have to be chain.size()-1??
    {
        string  previousHash= chain[i-1].getHash(); //comparing the hash of the previous block
        string currHashPrev = chain[i].getPreviousHash(); //with the previous hash of the current block

        if(previousHash == currHashPrev) //they should be the same!!!!??
        {
            int pZeroCount = 0;
            // for(int i = 1; i < previousHash.size(); i++)  //check if the first #difficulty characters in all of the hashcodes except the first block are 0s
            // {
            //     if(previousHash[i] == 0) //check for the beginning zeros
            //     {
            //         pZeroCount++;
            //     }
            //     else //if the next i is not zero, break out of this entire loop
            //     {
            //         break; //IS BREAK HERE CORRECT?
            //     }
            // }
            for(int j = 0; j < difficulty; j++)
            {
                if(chain[i].getHash()[j] != '0')
                {
                    //exit = false;
                    return false;
                    break;
                }
            }
            // if(pZeroCount == difficulty) // check if the first #difficulty characters in the hashcodes are 0s
            // {
            //     return true;
            // }
        }
        else{
            return false;
        }
    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) { //WHY BOOLEAN
    // TODO
    //WHAT IS THIS SUPPOSED TO RETURN AND WHY ?
    Block newBlock(pending, time(nullptr),getLatestBlock().calculateHash()); //create a new block 
    newBlock.mineBlock(difficulty); // invoke the mineBlock function HOW DO YOU KNOW THE DIFFICULTY
    pending.clear(); // After successful return clear the lsit of pending transactions
    chain.push_back(newBlock); //push the block to the chain
    Transaction newTransaction("BFC", minerAddress, miningReward); //to reward the minerAddress, add a new transaction to the (now empty list of pending transactions) with src = BFC, dst = minerAddress, and amount = miningReward
    pending.push_back(newTransaction);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) { //
    // TODO
    int sent = 0;
    int received = 0;
    int balance = 0;
    for(int i = 0; i < chain.size(); i++) //looking through the blockchain to find the BLOCK
    {
       // cout << "YOU ARWE IN FIRST FOR LOOP" << endl;
        for(int j = 0; j < chain[i].getTransactions().size(); j++)
        {
           // cout << "YOU ARE IN SECOND FOR LOOP" << endl;
           // cout << "THIS IS " << chain[i].getTransactions()[j].getSender() << endl;
            if(chain[i].getTransactions()[j].getSender() == address)
            {
            //    cout << "YOU FOUND " << address << endl;
                sent += chain[i].getTransactions()[j].getAmount();
            }
            if(chain[i].getTransactions()[j].getReceiver() == address)
            {
              //  cout << "YOU FOUND " << address << endl;
                received += chain[i].getTransactions()[j].getAmount();
            }
        }
    // return balance;
    }
    balance = received - sent;
    return balance;
}

void Blockchain::prettyPrint() {
    // TODO
    for(int i = 0; i < chain.size(); i++)
    {
        //cout << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "BLOCK " << i << ":" << endl;
        cout << "Nonce: " << chain[i].getNonce() << endl;
        cout << "Hash: " << chain[i].getHash() << endl;
        cout << "Previous Hash: " << chain[i].getPreviousHash() << endl;
        cout << "Time of Transaction: " << chain[i].getTime() << endl;
        cout << "Transactions: " << endl;
        for(int j = 0; j < chain[i].getTransactions().size(); j++)
        {
            cout << "Transaction " << j << ":" << endl;
            cout << "\tSender: " << chain[i].getTransactions()[j].getSender() << endl;
            cout << "\tReceiver: " << chain[i].getTransactions()[j].getReceiver() << endl;
            cout << "\tAmount: " << chain[i].getTransactions()[j].getAmount() << endl;
        }
    }
}

vector<Block> Blockchain::getBlocks()
{
    return chain;
}