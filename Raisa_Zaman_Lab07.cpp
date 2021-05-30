//==========================================================
// Assignment- 07
// Name- Raisa Zaman
// Date- 04/1/2020
// Last edited- 7:31 PM
// Title: Implementation of a MinHeap
// Description:
//    This C++ console application loads a column of numbers, 
//and insert the number in a min heap, and then deletes the min heap. 
//
//==========================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct minHeap
{
private:
	vector<int> heap;
	int parent(int i);
	int cLeft(int i);
	int cRight(int i);
public:
	int size();
	void fixDelete(int dNum);
	void fixInsert(int iNum);
	void hInsert(int key);
	void printHeap();
	void hDelete();
	int top();
};

int minHeap::parent(int i)
{
	return (i - 1) / 2;
}

int minHeap::cLeft(int i)
{
	return (2 * i) + 1;
}

int minHeap::cRight(int i)
{
	return (2 * i) + 2;
}

int minHeap::size()
{
	return heap.size();
}

void minHeap::fixDelete(int i)
{
	int left = cLeft(i);
	int right = cRight(i);

	int largest = i;
	if (left < size() && heap[left] < heap[i])
		largest = left;

	if (right < size() && heap[right] < heap[largest])
		largest = right;

	if (largest != i)
	{
		swap(heap[i], heap[largest]);
		fixDelete(largest);
	}
}


void minHeap::fixInsert(int i)
{
	if (i && heap[parent(i)] > heap[i])
	{
		swap(heap[i], heap[parent(i)]);

		fixInsert(parent(i));
	}
}

void minHeap::hInsert(int key)
{
	heap.push_back(key);
	int index = size() - 1;
	fixInsert(index);
}

void minHeap::printHeap()
{
	int count = 0;
	for (int i = 0; i < size(); i++)
	{
		cout << heap[i] << " ";
		count++;
	}
	cout << endl;
	if (heap.size() != 0)
	{
		cout << "Last index of the heap " << count << endl;
	}
	else
	{
		cout << "No heap " << endl;
	}
	cout << endl;
}

void minHeap::hDelete()
{
	vector <int> numDelete;
	if (size() == 0)
	{
		cout << "Heap is empty." << endl;
	}
	numDelete.push_back(heap[0]);
	heap[0] = heap.back();
	heap.pop_back();
	fixDelete(0);
	for (int i = 0; i < numDelete.size(); i++)
	{
		cout << "Delete element: " << numDelete[i] << endl;
	}
}

int minHeap::top()
{
	if (size() == 0)
	{
		cout << "Heap is empty. " << endl;
	}
	return heap.at(0);
}

int main()
{
	ifstream new_file;
	minHeap heap;
	vector <int> elementDeleted;
	int num;
	new_file.open("minHeap.data");
	if (!new_file)
	{
		cout << "File minHeap.data Can't be opened" << endl << endl;
	}
	else
	{
		cout << "File minHeap.data successfully opened. " << endl << endl;
		cout << "Inserting the elements in the heap. " << endl << endl;
		while (new_file >> num)
		{
			cout << "First index of the heap " << 1 << endl;
			cout << "Insert " << num << endl;
			heap.hInsert(num);
			heap.printHeap();
			cout << endl;
		}
	}
	cout << "Done inserting the elements in the heap. " << endl << endl;
	cout << "Starting index of the heap " << 1 << endl;
	cout << "Final heap is ";
	heap.printHeap();
	cout << endl << endl;
	cout << "Deleting the elements in the heap. " << endl << endl;
	while (heap.size() != 0)
	{
		elementDeleted.push_back(heap.top());
		heap.hDelete();
		heap.printHeap();
	}
	cout << "Done deleting the elements in the heap. " << endl << endl;
	cout << "Deleted elements: ";
	for (int i = 0; i < elementDeleted.size(); i++)
	{
		cout << elementDeleted[i] << " ";
	}
	cout << endl;
	new_file.close();
	return 0;
}