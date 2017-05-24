/*
 * StructureController.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: nwhi5696
 */

#include "StructureController.h"
#include <iostream>

using namespace std;

StructureController::StructureController()
{
	wordNode = Node<string>();
	numberNode = Node<int>();
	numberArray = Array<int>(1);
}

void StructureController :: testNodeTypes()
{
	cout << "Here is a string node" << endl;
	cout << wordNode.getNodeData() << endl;
	cout << "Here is an uninitialized int node" << endl;
	cout << numberNode.getNodeData() << endl;
}

void StructureController :: testArrayTemplate()
{
	cout << "Array Template" << endl;
	Timer arrayTimer;
	arrayTimer.startTimer();
	int test [9];
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();
	arrayTimer.resetTimer();

	arrayTimer.startTimer();
	numberArray = Array<int>(9);
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();

}

void StructureController :: testIntArray()
{
	cout << "Creating an IntNodeArray" << endl;
	IntNodeArray temp = IntNodeArray(3);

	for(int spot = 0; spot < 3; spot++)
	{
		cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}

	for(int spot = 0; spot < 3; spot++)
	{
		temp.setAtIndex(spot, spot);
	}

	for(int spot = 0; spot < temp.getSize(); spot ++)
	{
		cout << temp.getFromIndex(spot) <<" is at " << spot << endl;
	}
}

void StructureController :: testAdvancedFeatures()
{
	int showDestructor = 0;

	if(showDestructor < 1)
	{
		Array<string> words = Array<string>(4);
		words.setAtIndex(0,"at zero");
		words.setAtIndex(3, "in the last spot");
		Array<string> copiedWords = Array<string>(words);
		cout << "These should match: " << endl;
		cout << words.getFromIndex(0) << "s should be same as " << copiedWords.getFromIndex(0) << endl;

		copiedWords.setAtIndex(3, "changed the contents of the copied Array");
	}
}

void StructureController :: testList()
{
	List<int> sample;
	sample.addFront(2);
	sample.addEnd(3);
	sample.addFront(3);
	cout << "This should be 1, 2, 3" << endl;

	for(int index = 1; index < sample.getSize(); index++)
	{
		//cout << sample.getFromIndex(index) << endl;
	}
}

void StructureController :: testListTiming()
{
	DoubleList<int> timingList;
	for(int index = 0; index < 10000; index++)
	{
		timingList.add(rand());
	}

	long slowTime [1000];
	long fastTime [1000];
	double averageSlow = 0.00, averageFast = 0.00;
	Timer doubleTimer;


	for(int index = 0;index < 1000; index++)
	{
		int randomIndex = rand() % 10000;
		doubleTimer.startTimer();
		timingList.getFromIndex(randomIndex);
		doubleTimer.stopTimer();
		slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
		doubleTimer.resetTimer();

				doubleTimer.startTimer();
				timingList.getFromIndexFast(randomIndex);
				doubleTimer.stopTimer();
				fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
				doubleTimer.resetTimer();

				averageSlow += slowTime[index];
				averageFast += fastTime[index];
	}

	averageSlow = averageSlow/1000;
	averageFast = averageFast/1000;

	cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds" << endl;

	cout << "The average speed for the gerFromIndexFast method was: " << averageFast << " microseconds." << endl;

	cout << "A time saving of: " << averageSlow - averageFast << " microseconds." << endl;
}

void StructureController :: testMemeQueue()

{
	Meme firstMeme("toddler fist! with pinwheel");
	Queue<Meme> memeQueue;
	memeQueue.add(firstMeme);
	Meme secondMeme;
	secondMeme.setHipsterQuotient(3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327886593615338182796823030195203530185296899577362259941389124972177528347913151);
	secondMeme.setMainstream(false);
	memeQueue.enqueue(secondMeme);
	Meme thirdMeme;
	thirdMeme.setDankness(9001);
	memeQueue.enqueue(thirdMeme);

	cout << "There are: " << memeQueue.getSize() << " memes in the data structure" << endl;

	Meme temp = memeQueue.dequeue();
	cout << "This should be 9001 and is: " << temp.getDankness() << endl;

	memeQueue.dequeue();
	cout << "This should be 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327886593615338182796823030195203530185296899577362259941389124972177528347913151 and is: " << temp.getHipsterQuotient() << endl;

	Meme tempPeek = memeQueue.peek();
	cout << "this should be toddler fist! with pinwheel and is: " << tempPeek.getTitle() << endl;

	memeQueue.remove(0);
	cout << "The number of memes is: " << memeQueue.getSize() << endl;
}

void StructureController :: testNumberStack()
{
	Stack<int> intStack;
	intStack.push(3);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.push(9);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.pop();
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.push(54);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.push(9001);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.add(33);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.remove(3);
	cout << "The size is: " << intStack.getSize() << endl;
	intStack.push(42);
	cout << "The size is: " << intStack.getSize() << endl;
	cout << "The top node has a value of" << intStack.peek() << endl;

}

void StructureController :: testGraph()
{
		Graph<string> connectedWords;

		connectedWords.addVertex("Stonewards"); //0
		connectedWords.addVertex("Bondsmiths"); //1
		connectedWords.addVertex("Windrunners"); //2
		connectedWords.addVertex("Skybreakers"); //3
		connectedWords.addVertex("Dustbringers"); //4
		connectedWords.addVertex("Edgedancers"); //5
		connectedWords.addVertex("Truthwatchers"); //6
		connectedWords.addVertex("Lightweaver"); //7
		connectedWords.addVertex("Elsecaller"); //8
		connectedWords.addVertex("Willshaper"); //9
		connectedWords.addVertex("Cohesion"); //10
		connectedWords.addVertex("Tension"); //11
		connectedWords.addVertex("Adhesion"); //12
		connectedWords.addVertex("Gravitation"); //13
		connectedWords.addVertex("Division"); //14
		connectedWords.addVertex("Abrasion"); //15
		connectedWords.addVertex("Progression"); //16
		connectedWords.addVertex("Illumination"); //17
		connectedWords.addVertex("Transformation"); //18
		connectedWords.addVertex("Transportation"); //19

		connectedWords.addEdge(0,10);
		connectedWords.addEdge(0,11);
		connectedWords.addEdge(1,11);
		connectedWords.addEdge(1,12);
		connectedWords.addEdge(2,12);
		connectedWords.addEdge(2,13);
		connectedWords.addEdge(3,13);
		connectedWords.addEdge(3,14);
		connectedWords.addEdge(4,14);
		connectedWords.addEdge(4,15);
		connectedWords.addEdge(5,15);
		connectedWords.addEdge(5,16);
		connectedWords.addEdge(6,16);
		connectedWords.addEdge(6,17);
		connectedWords.addEdge(7,17);
		connectedWords.addEdge(7,18);
		connectedWords.addEdge(8,18);
		connectedWords.addEdge(8,19);
		connectedWords.addEdge(9,19);
		connectedWords.addEdge(9,10);

		connectedWords.depthFirstTraversal(connectedWords, 0);

}

void StructureController :: testBinarySearchTreeOperations()

{

    BinarySearchTree<int> numbers;

    numbers.insert(9843);

    numbers.insert(10);

    numbers.insert(43);

    numbers.insert(-123);

    numbers.insert(23465);

    numbers.insert(10); // won't go in

    numbers.insert(43243);

    numbers.insert(-45677654);

    numbers.insert(92165);



    cout << "Size should be 8 and is: " << numbers.getSize() << endl;

    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;

    numbers.inOrderTraversal();



    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;

    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;

}

void StructureController :: testBinarySearchData()

{

    FileController fileData;

    Timer treeTimer;

    treeTimer.startTimer();

    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/cody.henrichsen/Documents/crimes.csv");

    treeTimer.stopTimer();



    int count = crimeTree.getSize();

    int height = crimeTree.getHeight();

    bool complete = crimeTree.isComplete();

    bool balanced = crimeTree.isBalanced();



    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;

    cout << "The time to read in the tree was: " << endl;

    treeTimer.displayTimerInfo();



}

void StructureController :: testAVLTreeOperations()

{

    AVLTree<int> numbers;

    numbers.insert(9843);

    numbers.insert(10);

    numbers.insert(43);

    numbers.insert(-123);

    numbers.insert(23465);

    numbers.insert(10); // won't go in

    numbers.insert(43243);

    numbers.insert(-45677654);

    numbers.insert(92165);



    cout << "Size should be 8 and is: " << numbers.getSize() << endl;

    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;

    numbers.inOrderTraversal();



    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;

    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;

}

void StructureController :: testAVLData()

{

    FileController fileData;

    Timer treeTimer;

    treeTimer.startTimer();

    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");

    treeTimer.stopTimer();



    int count = crimeTree.getSize();

    int height = crimeTree.getHeight();

    bool complete = crimeTree.isComplete();

    bool balanced = crimeTree.isBalanced();



    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;

    cout << "The time to read in the tree was: " << endl;

    treeTimer.displayTimerInfo();

}

void StructureController :: start()
{
	//cout << "Going to test the IntNodeArray" << endl;
	//testIntArray();
	//cout << "Finished IntArrayNode testing" << endl;

	//testArrayTemplate();
	//testAdvancedFeatures();
	//testMemeQueue();
	//testList();
	//testNumberStack();
	//testGraph();
}




