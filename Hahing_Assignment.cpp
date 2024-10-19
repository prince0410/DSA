#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int getNextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

class HashTable
{
private:
    vector<list<pair<int, int>>> chainTable;
    vector<pair<int, int>> linearTable;
    vector<bool> isOccupied;
    int tableSize;

    int hashFunction(int key)
    {
        return key % tableSize;
    }

public:
    HashTable(int initialSize)
    {
        tableSize = getNextPrime(initialSize);
        chainTable.resize(tableSize);
        linearTable.resize(tableSize, {-1, -1});
        isOccupied.resize(tableSize, false);
    }

    void insertItemChaining(int studentID, int score)
    {
        int index = hashFunction(studentID);
        chainTable[index].push_back({studentID, score});
    }

    void insertItemLinearProbing(int studentID, int score)
    {
        int index = hashFunction(studentID);
        int originalIndex = index;

        while (isOccupied[index])
        {
            index = (index + 1) % tableSize;
            if (index == originalIndex)
            {
                cout << "Hash table is full. Cannot insert." << endl;
                return;
            }
        }

        linearTable[index] = {studentID, score};
        isOccupied[index] = true;
    }

    void deleteItemChaining(int studentID)
    {
        int index = hashFunction(studentID);
        auto &entries = chainTable[index];
        for (auto it = entries.begin(); it != entries.end(); ++it)
        {
            if (it->first == studentID)
            {
                entries.erase(it);
                cout << "Record with student ID " << studentID << " deleted using chaining." << endl;
                return;
            }
        }
        cout << "Record with student ID " << studentID << " not found in chaining." << endl;
    }

    void deleteItemLinearProbing(int studentID)
    {
        int index = hashFunction(studentID);
        int originalIndex = index;

        while (isOccupied[index])
        {
            if (linearTable[index].first == studentID)
            {
                linearTable[index] = {-1, -1};
                isOccupied[index] = false;
                cout << "Record with student ID " << studentID << " deleted using linear probing." << endl;
                return;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex)
            {
                break;
            }
        }
        cout << "Record with student ID " << studentID << " not found in linear probing." << endl;
    }

    void displayHashChaining()
    {
        cout << "Using Separate Chaining:" << endl;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "table[" << i << "]";
            for (auto &entry : chainTable[i])
            {
                cout << " --> (" << entry.first << ", " << entry.second << ")";
            }
            cout << endl;
        }
    }

    void displayHashLinearProbing()
    {
        cout << "Using Linear Probing:" << endl;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "table[" << i << "]";
            if (isOccupied[i])
            {
                cout << " --> (" << linearTable[i].first << ", " << linearTable[i].second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{
    int initialSize = 6;
    HashTable hashTable(initialSize);

    hashTable.insertItemChaining(231, 123);
    hashTable.insertItemChaining(326, 432);
    hashTable.insertItemChaining(212, 523);
    hashTable.insertItemChaining(321, 43);
    hashTable.insertItemChaining(433, 423);
    hashTable.insertItemChaining(262, 111);

    hashTable.displayHashChaining();
    cout << "After deleting record with student ID 212:" << endl;
    hashTable.deleteItemChaining(212);
    hashTable.displayHashChaining();

    cout << endl;

    hashTable.insertItemLinearProbing(231, 123);
    hashTable.insertItemLinearProbing(326, 432);
    hashTable.insertItemLinearProbing(212, 523);
    hashTable.insertItemLinearProbing(321, 43);
    hashTable.insertItemLinearProbing(433, 423);
    hashTable.insertItemLinearProbing(262, 111);

    hashTable.displayHashLinearProbing();
    cout << "After deleting record with student ID 212:" << endl;
    hashTable.deleteItemLinearProbing(212);
    hashTable.displayHashLinearProbing();

    cout << endl;

    cout << "prepared 23CE140_Prince" << endl;

    return 0;
}
