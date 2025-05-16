#include <iostream>
using namespace std;
template <typename T>
class priority_queue
{

private:
    int *arr;
    int size;
    int capacity;
    // bool heap

    // private api for left child of index i
    int left_child_private(int index)
    {
        return 2 * index + 1;
    }

    // private api for  right child of index i
    int right_child_private(int index)
    {
        return 2 * index + 2;
    }

    // private api for parent child of index i
    int parent_private(int index)
    {
        return (index - 1) / 2;
    }

    // private api for heapify up-> max heapify
    void max_heapify_up(int index)
    {
        if (index && arr[parent_private(index)] < arr[index])
        {
            swap(arr[index], arr[parent_private(index)]);
            max_heapify_up(parent_private(index));
        }
    }

    // private api for heapify up-> min heapify
    void min_heapify_up(int index)
    {
        if (index && arr[parent_private(index)] > arr[index])
        {
            swap(arr[index], arr[parent_private(index)]);
            min_heapify_up(parent_private(index));
        }
    }

    // private api for heapify down ->max heapify
    void max_heapify_down_private(int index)
    {
        int left = left_child_private(index);
        int right = right_child_private(index);
        int largest = index;
        if (left < size && arr[left] > arr[index])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            max_heapify_down_private(largest);
        }
    }

    // private api for heapify down ->min heapify
    void min_heapify_down_private(int index)
    {
        int left = left_child_private(index);
        int right = right_child_private(index);
        int smallest = index;
        if (left < size && arr[left] < arr[index])
        {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            min_heapify_down_private(smallest);
        }
    }

    // private api for insert element and keep it as max heap
    void max_heap_insert_private(T element)
    {
        if (size == capacity)
        {
            cout << "overflow" << endl;
        }
        else
        {
            arr[size] = element;
            size++;
            max_heapify_up(size - 1);
        }
    }

    // private api for insert element and keep it as min heap
    void min_heap_insert_private(T element)
    {
        if (size == capacity)
        {
            cout << "overflow" << endl;
            return;
        }
        else
        {
            arr[size] = element;
            size++;
            min_heapify_up(size - 1);
        }
    }

    // private api for display priority queue
    void display_private()
    {
        cout << " priority queue elements are" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    // private api for extract max element from max heap
    T extract_max_private()
    {
        if (size == 0)
        {
            cout << "underflow" << endl;
            return -1;
        }
        else
        {
            T max = arr[0];
            arr[0] = arr[size - 1];
            size--;
            max_heapify_down_private(0);
            return max;
        }
    }

    // private api for extract min element from min heap
    T extract_min_private()
    {
        if (size == 0)
        {
            cout << "underflow" << endl;
            return -1;
        }
        else
        {
            T min = arr[0];
            arr[0] = arr[size - 1];
            size--;
            min_heapify_down_private(0);
            return min;
        }
    }

public:
    // Constructor
    priority_queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    } // member intializer
    // Destructor
    ~priority_queue()
    {
        delete[] arr;
    }

    // public api for left child of index i
    int left_child(int i)
    {
        return left_child_private(i);
    }

    // public api for  right child of index i
    int right_child(int i)
    {
        return right_child_private(i);
    }

    // public api for parent child of index i
    int parent(int i)
    {
        return parent_private(i);
    }

    // public api for insert element and keep it as max heap
    void max_heap_insert(T element)
    {
        max_heap_insert_private(element);
    }
    // public api for insert element and keep it as min heap
    void min_heap_insert(T element)
    {
        min_heap_insert_private(element);
    }

    // public api for display priority queue
    void display()
    {
        display_private();
    }
    // public api for extract max element
    T extract_max()
    {
        return extract_max_private();
    }
};

int main()
{
    priority_queue<int> pq(50);
    pq.max_heap_insert(10);
    pq.max_heap_insert(20);
    pq.max_heap_insert(30);
    pq.max_heap_insert(40);
    pq.max_heap_insert(15);
    pq.max_heap_insert(35);
    pq.max_heap_insert(45);
    pq.display();

    cout << "\n left child index of 0 is: " << pq.left_child(0) << endl;
    cout << "right child index of 0 is: " << pq.right_child(0) << endl;

    cout << "extract max element is: " << pq.extract_max() << endl;

    cout << "updated priority queue is: \n";
    pq.display();

    return 0;
}
