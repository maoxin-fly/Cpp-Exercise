#include <iostream>
using namespace std;

//单链表节点结构
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){};//初始化

};

//定义自己的链表
class MyListNode
{
public:
    ListNode *head;//链表头节点指针
    int size;//链表长度
    MyListNode()//构造函数
    {
        head = new ListNode(0);//头节点为0
        size = 0;//长度为0
    };
    ~MyListNode(){};

    //functions
    //基本操作-----------------------------
    int get(int index);//查-------获取索引节点数值
    void addAtHead(int val);//增-------插入头
    void addAtTail(int val);//增-------插入尾
    void addAtIndex(int index, int val);//增-------按索引插入
    void deleteAtIndex(int index);//删
    //遍历-----------------------------
    void Iteration_Loop(ListNode *head);//迭代法遍历
    void Recursive_Loop(ListNode *p);//递归法遍历
    //逆序列表-----------------------------
    ListNode *Reversed_ListNode(ListNode *head);//递归法逆转，返回逆转列表头节点
    //找中间节点-----------------------------
    ListNode *LinkListMiddleNode(ListNode *head);
    //找倒数第K个节点-----------------------------
    ListNode *LinkListKthNode(ListNode *head, int K);





};


//函数定义
//=========================================================================================================================    
// Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
int MyListNode::get(int index) 
{
    if(index<0 || index > (size-1)) return -1;//索引比0小或者比最大索引大，返回-1
    ListNode *cur = head;//辅助指针指向第0个节点
    while(index)//不等于0就循环
    {
        cur = cur->next;//循环index次遍历到第index个节点
        index --;
    } 
    return cur->val;//指向数值输出
}

// Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
void MyListNode::addAtHead(int val) 
{
    if(size == 0)//如果第一次插入，直接把头节点换成这个数
    {
        head->val = val;
        size ++;
    }
    else
    {
        ListNode *newnode = new ListNode(val);//创建新节点
        newnode->next = head;//将新节点连接到头节点
        head = newnode;//指定新节点为头节点
        size ++;//长度加1
    }
    
}

//Append a node of value val to the last element of the linked list. 
void MyListNode::addAtTail(int val) 
{
    ListNode *cur = head;//辅助指针从头指针开始
    while(cur->next) cur = cur->next;//遍历到最后一个节点,如果是空链表，则直接不循环，指针还是在头指针
    ListNode *newnode = new ListNode(val);//创造新节点并赋值
    newnode->next = cur->next;//复制原最后节点的next信息,空节点
    cur->next = newnode;//连接最后一个新节点和上一个节点
    size ++;//长度加1
}

// Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
void MyListNode::addAtIndex(int index, int val) 
{
    if(index <= 0) addAtHead(val);//插入index的时候，如果下标是=0,就相当于从头插入，所以要包含<=
    else if(index == size) addAtTail(val);
    else if(index > size) return;
    else
    {
        ListNode *newnode = new ListNode(val);
        ListNode *cur = head;//辅助指针从头指针开始
        while(index--) cur = cur->next;//遍历到第index-1的节点，循环次数是index次 但是辅助指针是从头指针开始而不是第一个节点
        newnode->next = cur->next;//连接index
        cur->next = newnode;//连接前一个
        size ++;//长度+1
    }
}

//Delete the index-th node in the linked list, if the index is valid. 
void MyListNode::deleteAtIndex(int index) {
    if(index < 0 || index >= size) return ;
    ListNode *cur = head;//从头指针开始
    while(index--){//遍历到index-1的位置,循环次数是index次
        cur = cur->next;
    }
    cur->next = cur->next->next;//相当于直接跨过了index节点
    size--;
}


//迭代法访问链表
void MyListNode::Iteration_Loop(ListNode *head)
{
    for(ListNode *p = head;p != NULL;p = p->next)
    {
        cout<<p->val<<endl;
    }
}

//递归法访问链表
void MyListNode::Recursive_Loop(ListNode *p)
{
    if(p != NULL)
    {
        cout<<p->val<<endl;//操作要放在前面才行
        Recursive_Loop(p->next);
    }
    else return;
    
}

//反转链表
//递归法逆转，返回逆转列表头节点
// 1 -> 2 -> 3 -> 4 ===========> 4 -> 3 -> 2 -> 1
ListNode *MyListNode::Reversed_ListNode(ListNode *head)//返回指针类型,会把head链表改变
{
    //Base case
    if(head == NULL || head->next == NULL)//判断是否为空链表，和是否是末节点，如果是直接返回该节点
    {
        return head;
    }
    //如果该节点不是末节点，就开始递归下一个
    //Step1: 先要下一步递归
    ListNode *next_ListNode = Reversed_ListNode(head->next);
    //Step2： 进行节点操作, 断 + 连
    head->next->next = head;//下下节点指回来
    head->next = NULL;//暂时断开下节点
    //Step3: 返回结果，实际开始递归
    return next_ListNode;
}

//寻找链表中间节点
//定义两个指针节点，一块一慢。
// 1 -> 2 -> 3 -> 4 -> 5
ListNode *MyListNode::LinkListMiddleNode(ListNode *head)
{
    //定义两节点
    ListNode *i = head;
    ListNode *j = head;
    //循环节点
    while(j != NULL && j->next != NULL)//*****注意必须是与，如果是或就会无限循环，空节点的下一个不满足!=NULL
    {
        i = i->next;
        j = j->next->next;//两倍速
        // cout<<i->val<<endl;
    }
    // cout<<"ll"<<endl;
    return i;
}

//寻找链表倒数第K个节点
//两个指针，一块一慢
//画个图看看
ListNode *MyListNode::LinkListKthNode(ListNode *head, int K)
{
    //定义两节点
    ListNode *i = head;
    ListNode *j = head;
    //先移动快节点
    for(int c = 0; c<K;c++)//eg 2
    {
        j = j->next;
    }
    //两个同步移动，知道快节点为null
    while(j != NULL)
    {
        i = i->next;
        j = j->next;
    }
    return i;
}

//主函数
//=========================================================================================================================
int main(int argc,char *argv[])
{
    MyListNode *my = new MyListNode;
    cout<<my->size<<" "<<my->head->val<<endl;
    cout<<my->get(2)<<" "<<my->get(0)<<endl;
    my->addAtHead(1);
    my->addAtHead(2);
    my->addAtTail(3);
    my->addAtIndex(1,5);
    cout<<"Iteration: "<<endl;
    my->Iteration_Loop(my->head);
    cout<<"Middle: "<<endl;
    cout<<my->LinkListMiddleNode(my->head)->val<<endl;
    cout<<"2th: "<<endl;
    cout<<my->LinkListKthNode(my->head,2)->val<<endl;
    cout<<"Recursive: "<<endl;
    my->Recursive_Loop(my->head);
    cout<<"Rerversed: "<<endl;
    ListNode *reverse_note = my->Reversed_ListNode(my->head);//reverse_note成为反转链表的头节点，my->head变成尾节点
    my->head = reverse_note;//重新设置头节点
    cout<<reverse_note->val<<endl;
    my->Recursive_Loop(my->head);
    my->Iteration_Loop(my->head);
    cout<<"Middle: "<<endl;
    my->addAtTail(7);
    my->Iteration_Loop(my->head);
    cout<<my->LinkListMiddleNode(my->head)->val<<endl;
    cout<<"2th: "<<endl;
    cout<<my->LinkListKthNode(my->head,2)->val<<endl;
    cout<<my->LinkListKthNode(my->head,1)->val<<endl;


    return 0;
}
