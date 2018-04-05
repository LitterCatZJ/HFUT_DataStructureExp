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

#include"Queue.h"
#include<iostream>

using namespace std;
void interact();

int main()
{
//    ��д�㷨ʵ�������������⡣
//    <1>��ʼ��һ�����С�
//    <2>�ж��Ƿ�ӿա�
//    <3>�ж��Ƿ������
//    �������󳤶ȣ�MaxLen=100
//    ��һ�����ݣ����n��Ԫ�أ��ж϶���
//    �ڶ������ݣ���ѭ����ʽ��1��99��99��Ԫ����ӣ��ж���

    cout<<" <1>��ʼ��һ�����С�"<<endl;
    Queue<int> q;
    q.print();

    cout<<"<2>�ж��Ƿ�ӿա�"<<endl;
    cout<<"�����Ƿ�Ϊ�գ�"<<boolalpha<<q.isEmpty()<<endl;
    cout<<"<3>�ж��Ƿ������"<<endl;
    cout<<"��һ�����ݣ����n��Ԫ�أ��ж϶���"<<endl;
    q.randomCtor(30);
    cout<<"�����Ƿ�Ϊ����"<<q.isEmpty()<<endl;
    cout<<"�ڶ������ݣ���ѭ����ʽ��1��99��99��Ԫ����ӣ��ж���"<<endl;
    q.clear();
    for(int i=1;i<=99;i++)
        q.enqueue(i);
    cout<<"�����Ƿ�Ϊ����"<<q.isFull()<<endl;

//    <4>���
//    ��һ�����ݣ�4��7��8��12��20��50
//    �ڶ������ݣ�a,b,c,d,f,g
//    <5>����
//    <6>ȡ��ͷԪ��
//    <7>��ǰ������Ԫ�ظ���

    cout<<endl<<"<4>���"<<endl;
    int e1[]={4,7,8,12,20,50};
    char e2[]={'a','b','c','d','f','g'};
    for(int i=1;i<=2;i++){

        if(i==1) {
            cout<<"��һ�����ݣ�4��7��8��12��20��50"<<endl;
            q.clear();
            for(int i=0;i<6;i++)
                q.enqueue(e1[i]);

            q.print();
            cout<<"<5>����"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>ȡ��ͷԪ��:";
            int x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>��ǰ������Ԫ�ظ���:"<<q.count()<<endl;

        }
        else {
            Queue<char> q;
            cout<<"�ڶ������ݣ�a,b,c,d,f,g"<<endl;

            for(int i=0;i<sizeof(e2)/sizeof(e2[0]);i++)
                q.enqueue(e2[i]);
            q.print();
            cout<<"<5>����"<<endl;
            q.dequeue();
            q.print();
            cout<<"<6>ȡ��ͷԪ��:";
            char x;
            q.getFront(x);
            cout<<x<<endl;
            cout<<"<7>��ǰ������Ԫ�ظ���:"<<q.count()<<endl;

        }

    }
//
//    <8>��д�㷨ʵ��
//    �ٳ�ʼ����ѭ�����У�
//    �ڵ�������������ʱ����������ӣ�
//    �۵���������ż��ʱ����ͷ���ӣ�
//    �ܵ���������0ʱ���㷨�˳���
//    ��ÿ����������������ǰ�����е�����Ԫ�ء�
    cout<<endl<<"<8>��д�㷨ʵ��,�٢�..."<<endl;
    interact();

    return 0;
}
void interact()
{
    Queue<int> q;
    int num;
    cin>>num;
    while(num)
    {
        if(num%2==1)
            q.enqueue(num);
        else q.dequeue();
        q.print();
        cin>>num;
    }
}
