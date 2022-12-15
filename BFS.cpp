/**
 * PROBLEM 7: Clone Graph
 * MARIAH SALGADO
 * WILLIAM LUA
 **/
class Solution {
public:
    Node* cloneGraph(Node* node) { //Stores the address of any variable of type 'node' 
        if (!node) { //Check if root is Null
            return NULL;
        }
        Node* copy = new Node(node -> val, {}); //Allocate a new node that has the same value as our input
        copies[node] = copy; //Assigning the value in the hash table at key 'node'
        queue<Node*> todo;
        todo.push(node); //Push the node onto the queue
        while (!todo.empty()) {
            Node* cur = todo.front(); //Get the current node (Front of the queue)
            todo.pop(); //Delete the current node off of our queue
            for (Node* neighbor : cur -> neighbors) { //Looping thrugh all of the current node's neighbors
                if (copies.find(neighbor) == copies.end()) { //Visit current node
                    copies[neighbor] = new Node(neighbor -> val, {});
                    todo.push(neighbor); //Append n of current node onto neighbors
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies; //A hash table with Key as a Node and value also as a Node
};
