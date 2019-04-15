#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
}NODE;

class LinkList
{
private:
    NODE *head;
public:
    LinkList() { head = NULL; }
    ~LinkList();
    bool isEmpty() { return head == NULL; }
    int Length();
    int GetElem(int i, int *e);
    int LocateElem(int e);
    bool PriorElem(int cur_e, int *pre_e);
    bool NextElem(int cur_e, int *next_e);
    bool Insert(int i, int e);
    bool Delete(int i, int *e);
    NODE * Reverse();
};
//��������
LinkList::~LinkList()//�����һ��
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}

//��ȡ������
int LinkList::Length()
{
    NODE *p = head;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

int LinkList::GetElem(int i, int *e)//*e�Ƿ��ص�Ԫ��
{
    NODE *p = head;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) return -1;
    *e = p->data;
    return *e;
}

int LinkList::LocateElem(int e)
{
    int i = 0;
    NODE *p = head;
    while (p != NULL)
    {
        if (p->data == e)
            return i;
        else p = p->next;
        i++;
    }
    cout << "���в�����ָ��Ԫ��" << endl;
    return -1;
    //exit(0);
}

bool LinkList::PriorElem(int cur_e, int *pre_e)
{
    NODE *p = head;
    if (p->data == cur_e) return false;//��ͷ��㣬��������һ��Ԫ��
    while (p->next != NULL)
    {
        if (p->next->data == cur_e)
        {
            *pre_e = p->data;
            return true;
        }
        else
            p = p->next;
    }
    return false;//�����겻���ڻ���ֻ��һ��ͷ���

}

bool LinkList::NextElem(int cur_e, int *next_e)
{
    NODE *p = head;
    if (head == NULL || head->next == NULL) return false;
    while (p->next != NULL)
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return true;
        }
        else
            p = p->next;
    }
    return false;
}

bool LinkList::Insert(int i, int e)
{
    NODE *p = head,*s;
    int count = 0;

    if (i == 0)
    {
        s = (NODE *)new NODE[1];
        s->data = e;
        s->next = p;
        head = s;
        return true;
    }
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL)
        return false;//����β��
    s= (NODE *)new NODE[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ɾ��ָ��λ�õ�Ԫ�أ�����ɾ����Ԫ�ظ���*e
bool LinkList::Delete(int i, int *e)
{
    NODE *p = head, *s;
    if (p == NULL) return false;
    int j = 0;
    if (i == 0)
    {
        head = head->next;
        *e = p->data;
        delete p;
        p = NULL;
        return true;
    }
    while (p&&j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    s = p->next;
    p->next = p->next->next;
    *e = s->data;
    delete s;
    s = NULL;
    return true;
}

//��תһ������
NODE* LinkList::Reverse()
{
    if (head == NULL || head->next == NULL) return head;
    NODE *p = head,*q=head->next,*r;
    head->next = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}


int main()
{
    int a = 0;
    int *p = &a;
    LinkList li;
    li.Insert(0, 5);
    li.Insert(1, 4);
    li.Insert(2, 12);
    li.Insert(3, 5);
    li.Insert(4, 6);
    li.Insert(5, 7);
    li.Insert(6,10);
    li.Insert(4,66);
    cout <<"������"<< li.Length()<<endl;
    cout << "����Ԫ�ص�ֵ�ǣ�";
    for (int i = 0;i < li.Length();i++)//����������
    {
        cout<<li.GetElem(i,p)<<" ";
    }
    cout << endl;

    cout<<"��5������: "<<li.GetElem(5,p)<<endl;
}
