#include <iostream>

class t_list_node
{
protected:
    int data;
    t_list_node* next;
public:
	t_list_node(int data = 0, t_list_node* next = nullptr) : data(data), next(next)
	{
        data = data;
        next = next;
	}
	~t_list_node() {}

	t_list_node* createNode(int data)
	{
        t_list_node* head_node = new t_list_node;
        head_node->data = data;
        return head_node;
	}

	void pushNode(t_list_node* new_node)
	{
        t_list_node* iterator = this;
        for (; iterator->next != nullptr; iterator = iterator->next);
        iterator->next = new_node;
	}

	void showList()
	{
        t_list_node* it = next;
        for (; it != nullptr; it = it->next) std::cout << it->data << '\t';
        std::cout << std::endl;
    }

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/*
  _   _ ________          __  ______ ______       _______ _    _ _____  ______  _____ 
 | \ | |  ____\ \        / / |  ____|  ____|   /\|__   __| |  | |  __ \|  ____|/ ____|
 |  \| | |__   \ \  /\  / /  | |__  | |__     /  \  | |  | |  | | |__) | |__  | (___  
 | . ` |  __|   \ \/  \/ /   |  __| |  __|   / /\ \ | |  | |  | |  _  /|  __|  \___ \ 
 | |\  | |____   \  /\  /    | |    | |____ / ____ \| |  | |__| | | \ \| |____ ____) |
 |_| \_|______|   \/  \/     |_|    |______/_/    \_\_|   \____/|_|  \_\______|_____/ 
*/
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////                                                                                 


    t_list_node* linear_search(t_list_node* head, int value)
    {
        unsigned searchCount = 0;       // чтобы возвращать не только поинтер, а какое по порядку было число
        while(head != nullptr)
        {
            if (head->data == value) 
            {
                std::cout << "Your value was found at attempt N: " << searchCount << "   Value is at address:" << std::endl;
                break;
            }
            
            else if (head->next == nullptr & head->data != value)       // проверка на то что нет введенного числа
            {
                std::cerr << "There is no such number. Last node at address:" << std::endl; 
                break;
            }

            else
            {
                head = head->next; 
                searchCount++;
            }
        }
        return head;
    }
};
        


int main()
{
    t_list_node mainList;

    for (int i = 0; i < 49; i++)
    {
        t_list_node* new_node = mainList.createNode(i);
        mainList.pushNode(new_node);
    }
    mainList.showList();

    t_list_node* pFound = mainList.linear_search(&mainList, 5);
    std::cout << pFound << std::endl;
}