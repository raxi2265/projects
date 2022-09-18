
This is a project that I completed for my data structures class. It's a menu driven simulator of a coin called "BuffCUoin" and its blockchain. We begin by adding some transactions to the code when it first runs. Then, we are prompted with a menu. There are menu steps 1-6:

======Main Menu======

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


    The basic functionality included the function implementation for the class Blockchain and
    the class Block with a print function to display the contents of each block.
    Starting off, we began with this list of functions which depend on the next for functionality:
    
        toString(): Uses a stringstream to create a string of all of the information stored in a block, which can be used in calculateHash
            |
      calculateHash(): uses the string from the toString function to calculate a hash from the sha256 function
            |
        mineBlock(): checks if a hash has the #difficulty number of 0s 
            |
    minePendingTransactions(): mines and creates a new block to add to the blockchain 

    First was toString, then calculateHash, and so on. As the next calls on the previous function,
    we determined it would be best to start at the first function. 

    Once that was complete, we could proceed to the following functions:

        addTransaction()
        isChainValid()
        getBalanceOfAddress()
        prettyPrint()









    

    




    




