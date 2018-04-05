/**
 *Copyright:
 *This code is free software; you can redistribute it and/or modify
 *it under the terms of the GPL-3.0
 *
 * @author zhangjian
 * @date 2017.11
 *
 */

///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//����ͷ���ķ�������
template<typename Type>
class linkedList
{
private:
    struct Node
    {
        Type data;
        struct Node *next;
    };
    Node *root; //��
    int size;  //��¼�����С
public:
    linkedList();
    linkedList(Type*,int n,bool rear=true);
    virtual ~linkedList();

    void clearList();//�������
    void reCtor(Type* a,int n,bool rear=true);//�ع�
    int length() const;
    bool getElement(int i,/*Node* &*/Type& t) const;
    bool locate(Type x,/*Node*&*/int& t);
    bool listInsert(int i,Type x);
    bool listDelete(int i);
    void show() const;

    //�����������һ��Ԫ�ر��ֵ�������
    void incrementalInsert(const Type& x);
    //��ֵΪ������ż����ֵ�ֱ�ŵ�����������
    void seperateOddEven(linkedList<Type>& a,linkedList<Type>& b) const;
    //ɾ�����������������ظ�Ԫ��
    void removeDupEle();
    //��������ϲ���һ�����ϣ��������½ڵ�
    void mergelist(linkedList<Type>& b);
    int findK(int k);


};


//����λ��k��ֵ
template<typename Type>
int linkedList<Type>::findK(int k)
{
    Node *p=root,*q=root;//p��qָ������ĵ�һ�����,pΪ����ָ��
    int num = 0;
    while(p && num < k) {
        p = p -> next;
        num ++;
    }//���������ҵ�k��λ�ý��
    if(p == NULL ) {
        if(num != k) {//p��β������Ԫ�ظ���С��k
            return 0;
        }else {//p��β�ҵ�k�����ǡ��Ϊβ���
            cout<<q -> data;
        }
    }else {//�ҵ���k����㣬p��q����ƶ���p����β��qָ�ľ��ǵ�k��λ�õĽ��
        while(p) {
            p = p -> next;
            q = q -> next;
        }
        cout<<q -> data;
        return 1;
    }
}


//�෽��ʵ��
template<typename Type>
linkedList<Type>::linkedList()
{
    root=nullptr;
    size=0;
}

template<typename Type>
linkedList<Type>::linkedList(Type *a,int n,bool rear)
{
    //β�巨��������������������
    if(rear){
        Node *R,*u;
        R=root;
        for(int i=0;i<n;i++)
        {
            u=new Node;
            u->data=a[i];
            if(i==0) root=u;
            else R->next=u;
            R=u;

        }
        R->next=nullptr;
        size=n;
    }//ͷ�巨
    else{
        Node* u;
        for(int i=0;i<n;i++){
            u=new Node;
            u->data=a[i];
            u->next=root;
            root=u;
        }
        size=n;
    }
}

template<typename Type>
int linkedList<Type>::length() const
{
    return size;
}

template<typename Type>
bool linkedList<Type>::getElement(int i,/*Node *&*/Type& t) const
{
    Node *p=root;
    //�ҵ���Ӧλ�õĽڵ�
    for(int j=1;p&&j!=i;j++,p=p->next)
        continue;
    //�ձ�������Χ
    if(!p) return false;
    else {
        t=p->data;
        return true;
    }
}

template<typename Type>
bool linkedList<Type>::locate(Type x,/*Node *&*/int& t)
{
    Node *p=root;
    int ct=1;
    while(p&&p->data!=x)
    {
        p=p->next;ct++;
    }

    if(p==nullptr) return false;
    else {
        //t=p;
        t=ct;
        return true;
    }
}

//��ɾԪ�أ�����ͷ���
template<typename Type>
bool linkedList<Type>::listInsert(int i,Type x)
{
    if(i<1||i>size+1) return false;
    Node *p=new Node;
    p->next=root;
    //����ǰ���ڵ�
    for(int j=0;p&&j!=i-1;j++,p=p->next)
        continue;
    Node *u=new Node;
    u->data=x;
    u->next=p->next;
    if(size==0||p->next==root) root=u;//���ڵ�ĸ���
    p->next=u;

    size++;
}

template<typename Type>
bool linkedList<Type>::listDelete(int i)
{
    if(i<1||i>size) return false;
    Node *p=new Node;
    p->next=root;
    for(int k=0;p&&k!=i-1;k++,p=p->next)
        continue;
    if(p->next==root)
        root=root->next;
    else {
        Node *u=p->next;
        p->next=u->next;
        delete u;
    }

    size--;
    if(size==0) root=nullptr;
    return true;

}

template<typename Type>
void linkedList<Type>::clearList()
{
    Node* p=root,*u;
    while(p)
    {
        u=p->next;
        delete p;
        p=u;
    }
    root=nullptr;
    size=0;
}

template<typename Type>
void linkedList<Type>::reCtor(Type* a,int n,bool rear)
{
    this->clearList();
    //β�巨��������������ͬ��
    if(rear){
        Node *r,*u;
        for(int i=0;i<n;i++,size++)
        {
            u=new Node;
            u->data=a[i];
            if(size==0) root=u;
            else r->next=u;
            r=u;
        }
        r->next=nullptr;//���һ��ָ����Ϊ��
    }
    //ͷ�巨
    else {
        Node *u;
//        u->next=nullptr;
        for(int i=0;i<n;i++) {
            u=new Node;
            u->data=a[i];
            u->next=root;
            root=u;
        }
    }
    size=n;
}


template<typename Type>
void linkedList<Type>::show() const
{
    cout<<size<<":( ";
    Node *p=root;
    while(p)
    {
        cout<<p->data;
        if(p->next!=nullptr) cout<<" -> ";
        p=p->next;
    }
    cout<<" )"<<endl;
}
template<typename Type>
linkedList<Type>::~linkedList()
{
    Node* p=root;
    Node* t;
    while(p)
    {
        t=p->next;
        delete p;
        p=t;
    }
}


template<typename Type>
void linkedList<Type>::incrementalInsert(const Type& x)
{
    Node *p=root;
    Node *u=new Node;
    u->data=x;
    if(p->data>x)//����Ϊ��һ��Ԫ��
    {
        u->next=root;
        root=u;
        return;
    }

    while(p->next&&p->next->data<x)
        p=p->next;
    if(p->next==nullptr)//����Ϊ���һ��Ԫ��
    {
        p->next=u;
        u->next=nullptr;
    }
    else{
        Node* t=p->next;
        p->next=u;
        u->next=t;
    }
    size++;
}

template<typename Type>
void linkedList<Type>::seperateOddEven(linkedList<Type>& a,
                            linkedList<Type>& b) const
{
    Node *p=root;
    while(p)
    {
        if((p->data)%2==0)
            a.listInsert(a.length()+1,p->data);
        else
            b.listInsert(b.length()+1,p->data);
        p=p->next;
    }
}

template<typename Type>
void linkedList<Type>::removeDupEle()
{
    //������ָ�룬һ��ָ��ǰԪ�أ�һ������������
    //��ֵ�뵱ǰԪ�ز�ͬ�ǰ�ֵ�ŵ���ǰԪ�غ���
    //���ı����������
    Node *a=root;
    Node *b=a->next;
    int ct=1;
    while(b)
    {
        if(a->data!=b->data&&b!=a->next)
        {
            a->next->data=b->data;
            a=a->next;ct++;
            b=b->next;
        }
        else b=b->next;
    }
    size=ct;
    //a֮��Ľڵ�ȫ���ͷ�
    Node* u=a->next,*t;
    a->next=nullptr;
    while(u){
        t=u->next;
        delete u;
        u=t;
    }
}

//�ı�����ڵ�����ӣ�ɨ��������ͬԪ������
template<typename Type>
void linkedList<Type>::mergelist(linkedList<Type>& b)
{
    Node *t1=this->root;
    Node *t2=b.root,*u,*t;
    //ͷ�������

    if(this->root==nullptr){
        root=b.root;
        size=b.length();
        return;
    }

    if(t2->data<t1->data)
    {
        u=t2->next;
        t2->next=t1;
        root=t2;
        t2=u;

    }
    if(t1->data==t2->data) t2=t2->next;
    while(t2&&t1->next)
    {
        if(t1->next->data==t2->data) {t1=t1->next;t2=t2->next;}
        else if(t1->next->data<t2->data) t1=t1->next;
        else{
            u=t1->next;
            t=t2->next;
            t1->next=t2;
            t2->next=u;
            t2=t;
            t1=t1->next;
            size++;
        }
    }
    //b������Ԫ��ȫ�渽�ӵ������
    if(t2) t1->next=t2;
    while(t2)
    {
        size++;
        t2=t2->next;
    }

}
