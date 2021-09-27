#include <iostream>
using namespace std;

//������ڵ�ṹ
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){};//��ʼ��

};

//�����Լ�������
class MyListNode
{
public:
    ListNode *head;//����ͷ�ڵ�ָ��
    int size;//������
    MyListNode()//���캯��
    {
        head = new ListNode(0);//ͷ�ڵ�Ϊ0
        size = 0;//����Ϊ0
    };
    ~MyListNode(){};

    //functions
    //��������-------------------------
    int get(int index);//��-------��ȡ�����ڵ���ֵ
    void addAtHead(int val);//��-------����ͷ
    void addAtTail(int val);//��-------����β
    void addAtIndex(int index, int val);//��-------����������
    void deleteAtIndex(int index);//ɾ
    //����-----------------------------
    void Iteration_Loop();//����������
    void Recursive_Loop(ListNode *p);//�ݹ鷨����
};


//��������
//=========================================================================================================================    
// Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
int MyListNode::get(int index) 
{
    if(index<0 || index > (size-1)) return -1;//������0С���߱���������󣬷���-1
    ListNode *cur = head;//����ָ��ָ���0���ڵ�
    while(index)//������0��ѭ��
    {
        cur = cur->next;//ѭ��index�α�������index���ڵ�
        index --;
    } 
    return cur->val;//ָ����ֵ���
}

// Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. 
void MyListNode::addAtHead(int val) 
{
    if(size == 0)//�����һ�β��룬ֱ�Ӱ�ͷ�ڵ㻻�������
    {
        head->val = val;
        size ++;
    }
    else
    {
        ListNode *newnode = new ListNode(val);//�����½ڵ�
        newnode->next = head;//���½ڵ����ӵ�ͷ�ڵ�
        head = newnode;//ָ���½ڵ�Ϊͷ�ڵ�
        size ++;//���ȼ�1
    }
    
}

//Append a node of value val to the last element of the linked list. 
void MyListNode::addAtTail(int val) 
{
    ListNode *cur = head;//����ָ���ͷָ�뿪ʼ
    while(cur->next) cur = cur->next;//���������һ���ڵ�,����ǿ�������ֱ�Ӳ�ѭ����ָ�뻹����ͷָ��
    ListNode *newnode = new ListNode(val);//�����½ڵ㲢��ֵ
    newnode->next = cur->next;//����ԭ���ڵ��next��Ϣ,�սڵ�
    cur->next = newnode;//�������һ���½ڵ����һ���ڵ�
    size ++;//���ȼ�1
}

// Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. 
void MyListNode::addAtIndex(int index, int val) 
{
    if(index <= 0) addAtHead(val);//����index��ʱ������±���=0,���൱�ڴ�ͷ���룬����Ҫ����<=
    else if(index == size) addAtTail(val);
    else if(index > size) return;
    else
    {
        ListNode *newnode = new ListNode(val);
        ListNode *cur = head;//����ָ���ͷָ�뿪ʼ
        while(index--) cur = cur->next;//��������index-1�Ľڵ㣬ѭ��������index�� ���Ǹ���ָ���Ǵ�ͷָ�뿪ʼ�����ǵ�һ���ڵ�
        newnode->next = cur->next;//����index
        cur->next = newnode;//����ǰһ��
        size ++;//����+1
    }
}

//Delete the index-th node in the linked list, if the index is valid. 
void MyListNode::deleteAtIndex(int index) {
    if(index < 0 || index >= size) return ;
    ListNode *cur = head;//��ͷָ�뿪ʼ
    while(index--){//������index-1��λ��,ѭ��������index��
        cur = cur->next;
    }
    cur->next = cur->next->next;//�൱��ֱ�ӿ����index�ڵ�
    size--;
}


//��������������
void MyListNode::Iteration_Loop()
{
    for(ListNode *p = head;p != NULL;p = p->next)
    {
        cout<<p->val<<endl;
    }
}

//�ݹ鷨��������
void MyListNode::Recursive_Loop(ListNode *p)
{
    cout<<p->val<<endl;//����Ҫ����ǰ�����
    Recursive_Loop(p->next);
}

//������
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
    my->Iteration_Loop();
    cout<<"Recursive: "<<endl;
    my->Recursive_Loop(my->head);
    return 0;
}