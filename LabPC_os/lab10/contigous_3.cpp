#include <iostream>
#include <string>
using namespace std;

class ContiguousFileAllocation
{
private:
    int num_blocks;        // total number of blocks
    int *allocation_table; // an array to store the allocation status of each block
public:
    ContiguousFileAllocation(int num_blocks)
    {
        this->num_blocks = num_blocks;
        allocation_table = new int[num_blocks];
        for (int i = 0; i < num_blocks; i++)
        {
            allocation_table[i] = -1; // -1 means unallocated
        }
    }

    void allocate(string filename, int start, int length)
    {
        for (int i = start; i < start + length; i++)
        {
            if (allocation_table[i] != -1)
            {
                cout << "Error: Blocks are not contiguous\n";
                return;
            }
        }
        for (int i = start; i < start + length; i++)
        {
            allocation_table[i] = get_file_id(filename);
        }
        cout << "File " << filename << " allocated successfully\n";
    }

    void deallocate(string filename)
    {
        int file_id = get_file_id(filename);
        for (int i = 0; i < num_blocks; i++)
        {
            if (allocation_table[i] == file_id)
            {
                allocation_table[i] = -1;
            }
        }
        cout << "File " << filename << " deallocated successfully\n";
    }

    void display_allocation_table()
    {
        cout << "Allocation Table:\n";
        for (int i = 0; i < num_blocks; i++)
        {
            if (allocation_table[i] == -1)
            {
                cout << "0 ";
            }
            else
            {
                cout << allocation_table[i] << " ";
            }
        }
        cout << "\n";
    }

private:
    int get_file_id(string filename)
    {
        if (filename == "factorial")
        {
            return 1;
        }
        else if (filename == "calculate")
        {
            return 2;
        }
        else if (filename == "simple_interest")
        {
            return 3;
        }
        return 0; // invalid filename
    }
};

int main()
{
    ContiguousFileAllocation cfa(25);

    cfa.allocate("factorial", 12, 6);
    cfa.display_allocation_table();

    cfa.allocate("calculate", 5, 3);
    cfa.display_allocation_table();

    cfa.allocate("simple_interest", 8, 4);
    cfa.display_allocation_table();
}