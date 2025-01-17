#pragma once

/*TODO: 

Fix rand()
Memory leaks
Tests
<T>
memset
naming convension
incorrectly public functions

*/

template<class T>
class Skiplist
{
private:
	template<class T> class Node
	{
		int key;
		Node** forward;

		Node::Node(int key, int level)
		{
			this->key = key;
			forward = new Node*[level + 1];
			memset(forward, 0, sizeof(Node*)*(level + 1));
		};
		~Node() {};
	};

	// Maximum level for this skip list 
	int MAXLVL;

	// P is the fraction of the nodes with level  
	// i pointers also having level i+1 pointers 
	float P;

	// current level of skip list 
	int level;

	// pointer to header node 
	Node<T>* header;

public:
	Skiplist(int, float);
	~Skiplist();

	int randomLevel();
	void insertElement(int);
	void deleteElement(int);
	bool searchElement(int);
};


template<class T>
Skiplist<T>::Skiplist(int MAXLVL, float P)
{
	this->MAXLVL = MAXLVL;
	this->P = P;
	level = 0;

	// create header node and initialize key to -1 
	header = new Node<T>(-1, MAXLVL);
}

template<class T>
Skiplist<T>::~Skiplist() {}

template<class T>
int Skiplist<T>::randomLevel()
{
	float r = (float)rand() / RAND_MAX;
	int lvl = 0;
	while (r < P && lvl < MAXLVL)
	{
		lvl++;
		r = (float)rand() / RAND_MAX;
	}
	return lvl;
}

template<class T>
void Skiplist<T>::insertElement(int key)
{
	Node *current = header;

	// create update array and initialize it 
	Node *update[MAXLVL + 1];
	memset(update, 0, sizeof(Node*)*(MAXLVL + 1));

	//    start from highest level of skip list
	//	move the current pointer forward while key
	//	is greater than key of node next to current
	//	Otherwise inserted current in update and
	//	move one level down and continue search
	
	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != NULL &&
			current->forward[i]->key < key)
		{
			current = current->forward[i];
		}
		update[i] = current;
	}

	// reached level 0 and forward pointer to
	//   right, which is desired position to
	//   insert key.
	
	current = current->forward[0];

	// if current is NULL that means we have reached
	//   to end of the level or current's key is not equal
	//   to key to insert that means we have to insert
	//   node between update[0] and current node 
	if (current == NULL || current->key != key)
	{
		// Generate a random level for node 
		int random_level = randomLevel();

		// If random level is greater than list's current 
		// level (node with highest level inserted in  
		// list so far), initialize update value with pointer 
		// to header for further use 
		if (random_level > level)
		{
			for (int i = level + 1; i < random_level + 1; i++)
				update[i] = header;

			// Update the list current level 
			level = random_level;
		}

		// create new node with random level generated 
		Node* n = new Node(key, level);

		// insert node by rearranging pointers  
		for (int i = 0; i <= random_level; i++)
		{
			n->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = n;
		}
	}
};

template<class T>
void Skiplist<T>::deleteElement(int key)
{
	Node *current = header;

	// create update array and initialize it 
	Node *update[MAXLVL + 1];
	memset(update, 0, sizeof(Node*)*(MAXLVL + 1));

	//    start from highest level of skip list
	//	move the current pointer forward while key
	//	is greater than key of node next to current
	//	Otherwise inserted current in update and
	//	move one level down and continue search
	
	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != NULL &&
			current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	// reached level 0 and forward pointer to
	//   right, which is possibly our desired node.
	current = current->forward[0];

	// If current node is target node 
	if (current != NULL && current->key == key)
	{
		/* start from lowest level and rearrange
		   pointers just like we do in singly linked list
		   to remove target node */
		for (int i = 0; i <= level; i++)
		{
			/* If at level i, next node is not target
			   node, break the loop, no need to move
			  further level */
			if (update[i]->forward[i] != current)
				break;

			update[i]->forward[i] = current->forward[i];
		}

		// Remove levels having no elements  
		while (level > 0 &&
			header->forward[level] == 0)
			level--;
	}
};

template<class T>
bool Skiplist<T>::searchElement(int key)
{
	Node *current = header;

	    //start from highest level of skip list
		//move the current pointer forward while key
		//is greater than key of node next to current
		//Otherwise inserted current in update and
		//move one level down and continue search

	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] &&
			current->forward[i]->key < key)
			current = current->forward[i];

	}

	// reached level 0 and advance pointer to
	//   right, which is possibly our desired node
	current = current->forward[0];

	// If current node have key equal to 
	// search key, we have found our target node 
	if (current && current->key == key)
		return True;

	return False;
}