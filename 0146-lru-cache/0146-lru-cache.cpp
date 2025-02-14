
class LRUCache
{
public:
    int cap;
    struct Node
    {
        int key, value;
        Node *next, *prev;
        Node(int k, int v)
        {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };
    map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *temp)
    {
        Node *back = temp->prev;
        Node *front = temp->next;
        back->next = front;
        front->prev = back;
    }

    void addNode(int key, int value)
    {
        Node *newNode = new Node(key, value);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;

        mp[key] = newNode;
    }

    int get(int key)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            Node *temp = it->second;
            deleteNode(temp);
            mp.erase(key);
            put(temp->key, temp->value);
            return temp->value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            Node *temp = it->second;
            deleteNode(temp);
            mp.erase(temp->key);
            addNode(key, value);
        }
        else
        {
            if (mp.size() >= cap)
            {
                Node *leastUsed = tail->prev;
                deleteNode(leastUsed);
                mp.erase(leastUsed->key);
            }
            addNode(key, value);
        }
    }
};