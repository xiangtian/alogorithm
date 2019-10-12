#include <iostream>
#include <queue>
using namespace std;

class QueueNode
{
public:
    QueueNode(int val, int remain)
        : val(val), remain(remain)
    {
    }
    int val, remain;
};

void findOne(int N)
{
std:
    queue<QueueNode> queue;
    queue.push(QueueNode(1, 1));
    bool found = false;
    while (!queue.empty())
    {
        std::vector<bool> bn(N, false);
        int size = queue.size();
        while (size--)
        {
            QueueNode q = queue.front();
            if (q.remain == 0)
            {
                std::cout << "Val:" << q.val << " M:" << (q.val / N) << std::endl;
                found = true;
                break;
            }
            queue.pop();

            int tmp = q.val * 10;
            if (!bn[tmp % N])
            {
                bn[tmp % N] = true;
                queue.push(QueueNode(tmp, tmp % N));
            }
            if (!bn[(tmp + 1) % N])
            {
                bn[(tmp + 1) % N] = true;
                queue.push(QueueNode((tmp + 1), (tmp + 1) % N));
            }
        }

        if (found)
        {
            break;
        }
    }
}

int main()
{
    int N = 5;
    findOne(N);
    return 0;
}
