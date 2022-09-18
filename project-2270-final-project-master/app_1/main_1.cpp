#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"
#include "../code_1/Blockchain.cpp"
#include "../code_1/Block.hpp"
#include "../code_1/Block.cpp"
#include "../code_1/Transaction.hpp"
#include "../code_1/Transaction.cpp"
#include "../code_1/sha256.hpp"
#include "../code_1/sha256.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    //buffCUoin.prettyPrint(); 

    cout << "Daenerys Targaryen mining first block ... " << endl;
    buffCUoin.minePendingTransactions("Daenerys Targaryen");
    //buffCUoin.prettyPrint(); 
    
    cout << "Daenerys Targaryen paid Michael Scott 1 BFC ... " << endl;
    buffCUoin.addTransaction("Daenerys Targaryen","Michael Scott", 1);

    cout << "Daenerys Targaryen paid asa 1 BFC ... " << endl;
    buffCUoin.addTransaction("Daenerys Targaryen","asa", 1);
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa");
    //buffCUoin.prettyPrint(); 
    
    cout << "asa paid Daenerys Targaryen 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","Daenerys Targaryen", 1);    
    cout << "Daenerys Targaryen paid Michael Scott 2 BFC ... " << endl;
    buffCUoin.addTransaction("Daenerys Targaryen","Michael Scott", 2);
    
    cout << "Michael Scott mining third block ... " << endl;
    buffCUoin.minePendingTransactions("Michael Scott");
    //buffCUoin.prettyPrint(); 
    
    cout << "Daenerys Targaryen mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("Daenerys Targaryen");
    //buffCUoin.prettyPrint();

    cout << "birwa mining fifth block ..." << endl;
    buffCUoin.minePendingTransactions("birwa");

    cout << "birwa mining sixth block ..." << endl;
    buffCUoin.minePendingTransactions("birwa");

    cout << "birwa paid rachel 2 BFC ... " << endl;
    buffCUoin.addTransaction("birwa","rachel", 2);

    cout << "rachel mining seventh block ..." << endl;
    buffCUoin.minePendingTransactions("rachel");

    cout << "rachel mining eigth block ..." << endl;
    buffCUoin.minePendingTransactions("rachel");

    cout << "birwa has " << buffCUoin.getBalanceOfAddress("birwa") << " BFC" << endl;
    cout << "rachel has " << buffCUoin.getBalanceOfAddress("rachel") << " BFC" << endl;

    cout << "birwa paid rachel 200 BFC ... " << endl;
    buffCUoin.addTransaction("birwa","rachel", 200);

    cout << "birwa has " << buffCUoin.getBalanceOfAddress("birwa") << " BFC" << endl;
    cout << "rachel has " << buffCUoin.getBalanceOfAddress("rachel") << " BFC" << endl;

    cout << "rachel mining ninth block ..." << endl;
    buffCUoin.minePendingTransactions("rachel");

    cout << "birwa has " << buffCUoin.getBalanceOfAddress("birwa") << " BFC" << endl;
    cout << "rachel has " << buffCUoin.getBalanceOfAddress("rachel") << " BFC" << endl;

    cout << "is chain valid? (1 for true, 0 for false)" << buffCUoin.isChainValid() << endl;

    buffCUoin.prettyPrint();



    vector<Block> blockchain = buffCUoin.getBlocks();

    string strinput;
    do{
        cout << "======Main Menu======" << endl;
        cout << "1. Add a transaction" << endl;
        cout << "2. Verify Blockchain" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "4. Show Balance" << endl;
        cout << "5. Print" << endl;
        cout << "6. Quit" << endl;

        cin >> strinput;
        while(true)
        {
            if(strinput == "1")
            {
                string src = "";
                string dst = "";
                int amount;
                cout << "Enter sender name: " << endl;
                cin >> src;
                cout << "Enter the receiver name: " << endl;
                cin >> dst;
                cout << "Enter amount: " << endl;
                cin >> amount; 
                if(!cin)
                {
                    cout << "it has to be an integer amount. Returning to main menu." << endl;
                    strinput.clear();
                    break;
                }
                buffCUoin.addTransaction(src, dst, amount);
                buffCUoin.prettyPrint();

                break;
            }
            else if(strinput == "2")
            {
                bool verify = buffCUoin.isChainValid();
                if(verify == true){
                    cout << "Valid Blockchain" << endl;
                }
                else{
                    cout << "Invalid blockchain" << endl;
                }
                break;
            }
            else if(strinput == "3")
            {
                string minerAdd = "";
                cout << "Enter miner address: " << endl;
                cin >> minerAdd;
                buffCUoin.minePendingTransactions(minerAdd);
                break;
            }
            else if(strinput == "4")
            {
                string address = "";
                cout << "Enter balance address: " << endl;
                cin >> address;
                cout << "Current balance: " << buffCUoin.getBalanceOfAddress(address) << endl;
                break;
            }
            else if(strinput == "5")
            {
                buffCUoin.prettyPrint();
                break;
            }
            else if(strinput == "6")
            {
                cout << "Goodbye!" << endl;
                break;
            }
            else
            {
                cout << "please enter a number 1-6" << endl;
                cin.clear();
                cin >> strinput;
            }
        }
    }
    while(strinput != "6");

}




























//     bool quit = false;
//     while(!quit)
//         {
//         int option;
//         string inputLine;
//         cout << "======Main Menu======" << endl;
//         cout << "1. Add a transaction" << endl;
//         cout << "2. Verify Blockchain" << endl;
//         cout << "3. Mine Pending Transactions" << endl;
//         cout << "4. Show Balance" << endl;
//         cout << "5. Print" << endl;
//         cout << "6. Quit" << endl;
//         //what happens if you dont put 123456
        
//         cin >> inputLine;
//         if(inputLine == "1" || inputLine == "2" || inputLine == "3" || inputLine == "4" || inputLine == "5" || inputLine == "6")
//         {
//             option = stoi(inputLine);
//         }
//        //else{
//        //     cout << "Please enter a number 1-6" << endl;
//       //  }
        
//         switch(option){
//             case 1:{
//                     string src = "";
//                     string dst = "";
//                     int amount;
//                     cout << "Enter sender name: " << endl;
//                     cin >> src;
//                     cout << "Enter the receiver name: " << endl;
//                     cin >> dst;
//                     cout << "Enter amount: " << endl;
//                     cin >> amount; 
//                     buffCUoin.addTransaction(src, dst, amount);
//                     buffCUoin.prettyPrint();

//                     break;
//                 }
//             case 2:{
//                 bool verify = buffCUoin.isChainValid();
//                 if(verify == true){
//                     cout << "Valid Blockchain" << endl;
//                 }
//                 else{
//                     cout << "Invalid blockchain" << endl;
//                 }
//                 break;
//             }
//             case 3:{
//                 string minerAdd = "";
//                 cout << "Enter miner address: " << endl;
//                 cin >> minerAdd;
//                 buffCUoin.minePendingTransactions(minerAdd);
//                 break;
//             }
//             case 4:{
//                 string address = "";
//                 cout << "Enter balance address: " << endl;
//                 cin >> address;
//                 cout << "Current balance: " << buffCUoin.getBalanceOfAddress(address) << endl;
//                 break;

//                 //When I enter e53c86926f10dd7767bb31108447ce5ca2102e0ba428e0b116371f11709e5458 I get 10 which is correct i think!! 
//             }
//             case 5:{
//                 buffCUoin.prettyPrint();
//                 break;
//             }
//             case 6:{
//                 quit = true;
//             }
//             default:{
//                 cout << "you have to enter a number between 1 and 6" << endl;
//             }
//         }
//     }
//     return 0;
// }


// /*---------------------TESTING AND OUTCOMES-------------------

// enter 1
// sender name: asa
// receiver name:  maciej (hash address of his block: dbc6726e5f9d0870b94e9ad88dd7cce880328dc4c0e501a164118e50f00fe855)
// amount: 9
// enter 5
//     BLOCK 4:
//     Nonce: 41983
//     Hash: dbc6726e5f9d0870b94e9ad88dd7cce880328dc4c0e501a164118e50f00fe855
//     Previous Hash: 0000025b4ac62a342df32e4ec29c0f35bedaf138cbde8ff6cdbdc2930c1b6d69
//     Time of Transaction: 1650319642
//     Transactions: 
//     Transaction 0:
//             Sender: BFC
//             Receiver: maciej
//             Amount: 10

// enter 3
//     miner address: dbc6726e5f9d0870b94e9ad88dd7cce880328dc4c0e501a164118e50f00fe855
//     enter 5
//     BLOCK 4:
//     Nonce: 41983
//     Hash: dbc6726e5f9d0870b94e9ad88dd7cce880328dc4c0e501a164118e50f00fe855
//     Previous Hash: 0000025b4ac62a342df32e4ec29c0f35bedaf138cbde8ff6cdbdc2930c1b6d69
//     Time of Transaction: 1650319642
//     Transactions: 
//     Transaction 0:
//             Sender: BFC
//             Receiver: maciej
//             Amount: 10


//     BLOCK 5:
//     Nonce: 390969
//     Hash: d0c35182eef612d1b22f5e824f6cac431b724377c43ac6e9c0ddda1cc1499718
//     Previous Hash: 00000c9690e810dbca8dc28c030aadeb7446ac6e85b3476ee04bc83342a5ae24
//     Time of Transaction: 1650319678
//     Transactions: 
//     Transaction 0:
//             Sender: BFC
//             Receiver: ashutosh
//             Amount: 10
//     Transaction 1:
//             Sender: asa
//             Receiver: maciej
//             Amount: 9


// */
