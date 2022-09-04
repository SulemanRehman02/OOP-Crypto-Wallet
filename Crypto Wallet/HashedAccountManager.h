#ifndef HASHEDACCOUNTMANAGER_H
#define HASHEDACCOUNTMANAGER_H
#include <vector>
#include "TransactionHashed.h"
#include "AccountManager.h"
#include <cstdlib>
using namespace std;
class HashedAccountManager : public AccountManager
{
protected:
    vector<TransactionHashed*> log;
    public:
        HashedAccountManager();
        hashkeys(string sender_public_key, string reciever_public_key, double amount, ACC_TYPE T);
        ~HashedAccountManager();
        string ToString();/* Do not modify this function*/

};

HashedAccountManager::HashedAccountManager()

{
}
HashedAccountManager :: hashkeys(string sender_public_key, string reciever_public_key, double amount, ACC_TYPE T)
{
    TransactionHashed* hashedlog=new TransactionHashed(sender_public_key,reciever_public_key,amount,T);
    log.push_back(hashedlog);
    cout << "Done!" << endl;
}


#endif // HASHEDACCOUNTMANAGER_H
