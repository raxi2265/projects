UNIVERSITY OF COLORADO BOULDER
CSCI 2270 FINAL PROJECT 

---------------------------------------------------------------------------------------------
READ ME
---------------------------------------------------------------------------------------------

Rachel Xie and Birwa Balar
Professor Zagrodzki
26 April 2022

---------------------------------------------------------------------------------------------

INTRODUCTION:
    In this project, designed and implemented a toy cryptocurrency called Buff-CUoin. This included blocks, holding a nonce, vector of transactions, the hash of the previous block, and its own hash. The transactions held information about the sender, receiver, and amount. All of the blocks were stored in a vector, known as the blockchain.

---------------------------------------------------------------------------------------------

REQUIREMENTS:
    The functionality of the project included calculating a hash for a block, adding transactions, mining pending transactions, checking the validity of the blockchain, check balance, and printing the information stored in the blockchain. Other requirements included supporting the functionality of the blockchain, transactions, pending transactions, crypto mining, rewarding miners, balance checking, and validity checking. The completion of the Block.cpp and Blockchain.cpp files as well as ensuring all components are tested and function correctly was required.

---------------------------------------------------------------------------------------------

PROCESS OF DEVELOPMENT:
Before we began writing out the code, we spent hours on research cryptocurrency and Bitcoin to get a better understanding of the ideas and concepts entailed in the project. Terms such as nonce, difficulty, and blockchain were not familiar to us. 

    The basic functionality included the function implementation for the class Blockchain and
    the class Block with a print function to display the contents of each block.
    Starting off, we began with this list of functions which depend on the next for functionality:
    
        toString()
            |
      calculateHash() (calls toString)
            |
        mineBlock() (calls calculateHash)
            |
    minePendingTransactions() (calls mineBlock)

    First was toString, then calculateHash, and so on. As the next calls on the previous function,
    we determined it would be best to start at the first function. 

    Once that was complete, we could proceed to the following functions:

        addTransaction()
        isChainValid()
        getBalanceOfAddress()
        prettyPrint()

Testing of the functions included creating a main.cpp where we implemented a text-based interface to our blockchain. The suggested template was a menu, which is what we used to display and call our functions ensuring they work correctly. The first three options of the menu were given, we added to that the 4th and 5th options to fit how we wanted to test our 
    program.

        1. Add a transaction
            Prompts user input for the sender, receiver, and amount. Calls the add
            transaction function with the user input values. Lastly, prints this
            information out.
        2. Verify Blockchain
            First calls the isChainValid function and assigns the return bool of that
            function to a local bool variable. Using if statements with that return variable,
            a message is printed saying "valid blockchain" or "invalid blockchain".
        3. Mine Pending Transactions
            Prompts user input for the miner address. Using that address of the user inputs, 
            the minePendingTransactions function is called.
        4. Show Balance
            Prompts user input for the balance address. Using that address of the user inputs,
            the getBalanceOfAddress function is called.
        5. Print
            Calls the prettyPrint function to print out the information of each block.
        6. Quit
            Exits out of the menu loop.

    Moreover, the use of TA Office Hours were used when testing and debugging to ensure
    the program is doing what is expected. 





    

    




    




