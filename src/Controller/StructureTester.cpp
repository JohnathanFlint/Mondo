///*
// * StructureTester.cpp
// *
// *  Created on: Apr 17, 2017
// *      Author: nwhi5696
// */
//
//#include "StructureTester.h"
//#include <iostream>
//
//using namespace std;
//
//StructureTester::StructureTester()
//{
//
//}
//
//StructureTester::~StructureTester()
//{
//}
//
//}
//
//void StructureTester :: testBinarySearchTreeOperations()
//
//{
//
//    BinarySearchTree<int> numbers;
//
//    numbers.insert(9843);
//
//    numbers.insert(10);
//
//    numbers.insert(43);
//
//    numbers.insert(-123);
//
//    numbers.insert(23465);
//
//    numbers.insert(10); // won't go in
//
//    numbers.insert(43243);
//
//    numbers.insert(-45677654);
//
//    numbers.insert(92165);
//
//
//
//    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
//
//    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
//
//    numbers.inOrderTraversal();
//
//
//
//    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
//
//    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
//
//}
//
//void StructureTester :: testBinarySearchData()
//
//{
//
//    FileController fileData;
//
//    Timer treeTimer;
//
//    treeTimer.startTimer();
//
//    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/cody.henrichsen/Documents/crimes.csv");
//
//    treeTimer.stopTimer();
//
//
//
//    int count = crimeTree.getSize();
//
//    int height = crimeTree.getHeight();
//
//    bool complete = crimeTree.isComplete();
//
//    bool balanced = crimeTree.isBalanced();
//
//
//
//    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
//
//    cout << "The time to read in the tree was: " << endl;
//
//    treeTimer.displayTimerInformation();
//
//
//
//}
//
//void StructureTester :: testAVLTreeOperations()
//
//{
//
//    AVLTree<int> numbers;
//
//    numbers.insert(9843);
//
//    numbers.insert(10);
//
//    numbers.insert(43);
//
//    numbers.insert(-123);
//
//    numbers.insert(23465);
//
//    numbers.insert(10); // won't go in
//
//    numbers.insert(43243);
//
//    numbers.insert(-45677654);
//
//    numbers.insert(92165);
//
//
//
//    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
//
//    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
//
//    numbers.inOrderTraversal();
//
//
//
//    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
//
//    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
//
//}
//
//void StructureTester :: testAVLData()
//
//{
//
//    FileController fileData;
//
//    Timer treeTimer;
//
//    treeTimer.startTimer();
//
//    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");
//
//    treeTimer.stopTimer();
//
//
//
//    int count = crimeTree.getSize();
//
//    int height = crimeTree.getHeight();
//
//    bool complete = crimeTree.isComplete();
//
//    bool balanced = crimeTree.isBalanced();
//
//
//
//    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
//
//    cout << "The time to read in the tree was: " << endl;
//
//    treeTimer.displayTimerInformation();
//
//}
//
//
