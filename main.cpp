#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>

using namespace std;

int main()
{

    int count = 0;
    int x;
    ifstream inFile;

    int bstHeight;
    int rbtHeight;
    int sptHeight;

    string data[3] = {"G:/sem_8/AA/c++/data/data_1.txt", "G:/sem_8/AA/c++/data/data_2.txt", "G:/sem_8/AA/c++/data/data_3.txt"}; // path to data files
    string path_search_data = "G:/sem_8/AA/c++/data/search_data.txt"; //search data

    //BST
    for (int i = 0; i < 3; i++)
    {
        bstHeight = 0;
        BST bst;
        string path = data[i];
        count = 0;
        inFile.open(path);

        if (!inFile)
        {
            cout << "Can't open file";
            exit(1);
        }
        auto start = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            count++;
            bst.put(x, count);
        }
        inFile.close();
        bstHeight = bst.height();
        auto time = std::chrono::high_resolution_clock::now() - start;

        long long time_taken = std::chrono::duration_cast<std::chrono::microseconds>(time).count();

        cout << "------------------------------------" << endl;
        cout << "Insert to BST....data_" << i + 1 << endl;
        cout << "Height = " << bstHeight << endl;
        cout << "Time taken = " << time_taken << " ms" << endl;

        //SEARCH...........

        inFile.open(path_search_data);
        if (!inFile)
        {
            cout << "Can't open file";
            exit(1);
        }
        auto start2 = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            bst.contains(x);
        }
        inFile.close();
        bstHeight = bst.height();
        auto time2 = std::chrono::high_resolution_clock::now() - start2;

        long long time_taken1 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();
        cout << "Search BST......" << endl;
        cout << "Height = " << bstHeight << endl;
        cout << "Time taken to search = " << time_taken1 << " ms" << endl;
    }

    //SPLAY
    for (int i = 0; i < 3; i++)
    {
        SplayTree spt1;
        sptHeight = 0;
        count = 0;
        string path = data[i];
        inFile.open(path);
        if (!inFile)
        {
            cout << "Can't to open file";
            exit(1);
        }
        auto start3 = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            count++;
            spt1.put(x, count);
        }
        inFile.close();
        sptHeight = spt1.height();
        auto time3 = std::chrono::high_resolution_clock::now() - start3;

        long long time_taken3 = std::chrono::duration_cast<std::chrono::microseconds>(time3).count();
        cout << "--------------------------------------" << endl;
        cout << "Insert to Splay tree....data_" << i + 1 << endl;
        cout << "Height = " << sptHeight << endl;
        cout << "Time taken = " << time_taken3 << " ms" << endl;

        // SEARCH
        inFile.open(path_search_data);
        if (!inFile)
        {
            cout << "Can't to open file";
            exit(1);
        }
        auto start4 = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            spt1.contains(x);
        }
        inFile.close();
        sptHeight = spt1.height();
        auto time4 = std::chrono::high_resolution_clock::now() - start4;

        long long time_taken4 = std::chrono::duration_cast<std::chrono::microseconds>(time4).count();
        cout << "Search Splay tree......" << endl;
        cout << "Height = " << sptHeight << endl;
        cout << "Time taken to search = " << time_taken4 << " ms" << endl;
    }

    // Red-black tree...........
    for (int k = 0; k < 3; k++)
    {
        string path = data[k];
        count = 0;
        rbtHeight = 0;
        RBTree rbt1;
        inFile.open(path);
        if (!inFile)
        {
            cout << "Can't to open file";
            exit(1); // terminate with error
        }
        auto start4 = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            count++;
            rbt1.put(x, count);
        }
        inFile.close();
        rbtHeight = rbt1.height();
        auto time4 = std::chrono::high_resolution_clock::now() - start4;

        long long time_taken5 = std::chrono::duration_cast<std::chrono::microseconds>(time4).count();

        cout << "--------------------------------------" << endl;
        cout << "Insert to Red-Black tree....data_" << k + 1 << endl;
        cout << "Height = " << rbtHeight << endl;
        cout << "Time taken = " << time_taken5 << " ms" << endl;

        //SEARCH
        inFile.open(path_search_data);
        if (!inFile)
        {
            cout << "Can't  open file";
            exit(1);
        }
        auto start6 = std::chrono::high_resolution_clock::now();
        while (inFile >> x)
        {
            rbt1.contains(x);
        }
        inFile.close();
        rbtHeight = rbt1.height();
        auto time6 = std::chrono::high_resolution_clock::now() - start6;

        long long time_taken6 = std::chrono::duration_cast<std::chrono::microseconds>(time6).count();
        cout << "Search Splay tree......" << endl;
        cout << "Height = " << rbtHeight << endl;
        cout << "Time taken to search = " << time_taken6 << " ms" << endl;
    }

    return 0;
}
